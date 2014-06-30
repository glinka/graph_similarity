#ifndef UTIL_FNS_H_
#define UTIL_FNS_H_

#include <string>
#include <vector>
#include <fstream>


template <typename T>
void save_matrix(const std::vector< std::vector<T> >& A, std::ofstream& output_file, const std::string header="", const char delim=',');

template <typename T>
void save_vector(const std::vector<T>& v, std::ofstream& output_file, const std::string header="", const char delim='\n');

#include "util_fns.tpp"

#endif
