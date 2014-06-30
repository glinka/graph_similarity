#ifndef DMAPS_H
#define DMAPS_H
#include <vector>

struct dmaps_output {
  std::vector< std::vector<double> > W;
  std::vector< std::vector<double> > eigvects;
  std::vector<double> eigvals;
};
  
class dmaps {
 private:
 public:
  template <typename T>
    static void map(std::vector< T > &input_data, double (*kernel_fn)(const T&,const T&), std::vector<double>& eigvals, std::vector< std::vector<double> >& eigvects, std::vector< std::vector<double> >& W, const double weight_threshold = 0);
};

#include "dmaps.tpp"
#endif
