#ifndef KERNEL_FNS_H
#define KERNEL_FNS_H

#include <vector>

namespace kernels {
  double gaussian_kernel(const std::vector< double >& x1, const std::vector< double >& x2);
  double l2_kernel(const std::vector<double>& x1, const std::vector<double>& x2);
}

#endif
