#ifndef INVERSE_H
#define INVERSE_H

#include <vector> 
typedef std::vector<std::vector<int>> matrix;
typedef std::vector<std::vector<float>> float_matrix;

matrix cofactor(matrix A, int p, int q, int n);
int det(matrix A, int n);
matrix adjoint(matrix A);
float_matrix inverse(matrix A);

#endif