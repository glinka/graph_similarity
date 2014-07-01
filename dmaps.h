#ifndef DMAPS_H
#define DMAPS_H
#include <vector>
#include "kernel_function.h"

class dmaps {
 private:
 public:
  template <typename T>
    static void map(std::vector< T > &input_data, Kernel_Function<T>* kernel_fn, std::vector<double>& eigvals, std::vector< std::vector<double> >& eigvects, std::vector< std::vector<double> >& W, const double weight_threshold = 0);
};

#include "dmaps.tpp"
#endif
