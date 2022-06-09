#include "../include/multiply.h"
#include "../include/inverse.h"

#include <iostream> 
#include <vector> 
typedef std::vector<std::vector<int>> matrix;


int main(){
    matrix A = {{1,  0,  0,  0},
                {0,  2,  0,  0},
                {0,  0,  3,  0},
                {0,  0,  0,  4}};
    matrix B = {{1,  2,  3,  4},
                {2,  4,  6,  8},
                {3,  6,  9, 12},
                {4,  8, 12, 16}};

    // test 1-1
    std::cout << "--- test 1-1 --- \n";
    int D1 = det(A, A.size());
    if (D1 == 0) std::cout << "Singular matrix, can't find its inverse\n";
    else{
        float_matrix inv = inverse(A);
        for (int i=0; i<A.size(); i++){
            for (int j=0; j<A[0].size(); j++){
                std::cout << inv[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // test 1-2
    std::cout << "--- test 1-2 --- \n";
    int D2 = det(B, B.size());
    if (D2 == 0) std::cout << "Singular matrix, can't find its inverse\n";
    else{
        float_matrix inv = inverse(B);
        for (int i=0; i<B.size(); i++){
            for (int j=0; j<B[0].size(); j++){
                std::cout << inv[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // test 2 
    std::cout << "--- test 2 --- \n";
    matrix result_matrix = multiply(A,B);
    for (int i=0; i<A.size(); i++){
        for (int j=0; j<B[0].size(); j++){
            std::cout << result_matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}