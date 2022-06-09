#include <iostream> 
#include <vector> 
typedef std::vector<std::vector<int>> matrix;
typedef std::vector<std::vector<float>> float_matrix;


matrix cofactor(matrix A, int p, int q, int n){
    // initialization 
    int N = A.size(); 
    int i=0, j=0;
    matrix tmp(N);
    for (int row=0; row<N; row++){
        for (int col=0; col<N; col++){
            tmp[row].push_back(0);
        }
    }

    // compute cofactor matrix 
    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            if (row != p && col != q){
                tmp[i][j++] = A[row][col];
                if (j == n-1){
                    j = 0;
                    i++;
                }
            }
        }
    }
    return tmp;
}

int det(matrix A, int n){
    // calculate determinant 
    int D = 0;
    if (n == 1) return A[0][0];
    int sign = 1;

    for (int i=0; i<n; i++){
        matrix tmp = cofactor(A, 0, i, n);
        D += sign * A[0][i] * det(tmp, n-1);
        sign *= -1;
    }
    return D;
}

matrix adjoint(matrix A){
    // initialization 
    int N = A.size();
    matrix adj(N); 
    for (int row=0; row<N; row++){
        for (int col=0; col<N; col++){
            adj[row].push_back(0);
        }
    }

    // compute adjoint matrix 
    if (N == 1) adj[0][0] = 1;
    int sign = 1;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            matrix tmp = cofactor(A, i, j, N);
            sign = ((i+j)%2 == 0)? 1: -1;
            adj[j][i] = sign * det(tmp, N-1);
        }
    }
    return adj;
}

float_matrix inverse(matrix A){
    // initialization
    int N = A.size();
    float_matrix inv(N); 
    for (int row=0; row<N; row++){
        for (int col=0; col<N; col++){
            inv[row].push_back(0);
        }
    }
    
    // compute inverse matrix
    int D = det(A, N);
    matrix adj = adjoint(A);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            inv[i][j] = adj[i][j]/float(D);
        }
    }
    return inv; 
}