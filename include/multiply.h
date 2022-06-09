#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <vector> 
typedef std::vector<std::vector<int>> matrix;

matrix add(matrix A, matrix B, int split_idx, int multiplier=1);
matrix multiply(matrix A, matrix B);

#endif