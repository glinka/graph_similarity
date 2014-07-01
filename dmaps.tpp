#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <Eigen/Geometry>
#include <cmath>

template <typename T>
void dmaps::map(std::vector< T > &input_data, Kernel_Function<T>* kernel_fn, std::vector<double>& eigvals, std::vector< std::vector<double> >& eigvects, std::vector< std::vector<double> >& W_out, const double weight_threshold) {
  int ndata = input_data.size();
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> W(ndata, ndata);
  int thresholded_entries = 0;
  for(int i = 0; i < ndata; i++) {
    for(int j = 0; j < ndata; j++) {
      W(i,j) = kernel_fn->kernel(input_data[i], input_data[j]);
      if(W(i,j) < weight_threshold) {
	W(i,j) = 0;
	thresholded_entries++;
      }
    }
  }
  Eigen::VectorXd Degs = W.rowwise().sum();
  Eigen::MatrixXd D_half_inv = Eigen::MatrixXd::Zero(ndata, ndata);
  for(int i = 0; i < ndata; i++) {
    D_half_inv(i,i) = pow(Degs[i], -0.5);
  }
  // normalize W
  // row stochasticize W
  // markovinize W
  Eigen::MatrixXd S = D_half_inv*W*D_half_inv;
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> es(S);
  Eigen::VectorXd evals = es.eigenvalues();
  Eigen::MatrixXd evects = D_half_inv*es.eigenvectors();
  double *eigvals_ptr = evals.data();
  double *eigvects_ptr = evects.data();
  double *W_ptr = W.data();
  // possible to create W, eigvals, eigvects on heap and reference directly
  // into vector? seems not
  // std::vector< std::vector<double> > W(ndata);
  // std::vector< std::vector<double> > eigvects(ndata);
  // std::vector<double> eigvals(eigvals_ptr, eigvals_ptr + ndata);
  for(int j = 0; j < ndata; j++) {
    W_out[j] = std::vector<double>(W_ptr + j*ndata, W_ptr + (j+1)*ndata);
    eigvects[j] = std::vector<double>(eigvects_ptr + j*ndata, eigvects_ptr + (j+1)*ndata);
  }
  eigvals = std::vector<double>(eigvals_ptr, eigvals_ptr + ndata);
  // my_allocator myalloc = new my_allocator(eigvects_ptr);
  // std::vector< double >* eigvals = new std::vector< double >(myalloc);
  // dmaps_output* out = new dmaps_output;
  // (*out).W = W_;
  // (*out).eigvects = eigvects;
  // (*out).eigvals = eigvals;
  // return out;
} 
