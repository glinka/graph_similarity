#include <cmath>
#include "kernels.h"

namespace kernels {

  double l2_kernel(const std::vector<double>& x1, const std::vector<double>& x2) {
    double norm = 0;
    for(int i = 0; i < x1.size(); i++) {
      norm += pow(x1[i] - x2[i], 2);
    }
    return sqrt(norm);
  }

  double gaussian_kernel(const std::vector< double >& x1, const std::vector< double >& x2) {
    double epsilon = 10;
    double norm = 0;
    for(int i = 0; i < x1.size(); i++) {
      norm += pow(x1[i] - x2[i], 2);
    }
    return exp(-norm/epsilon);
  }

}


