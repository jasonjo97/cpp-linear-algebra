#include <iostream> 
#include <vector> 
typedef std::vector<std::vector<int>> matrix;


matrix add(matrix A, matrix B, int split_idx, int multiplier=1){
    for (int i=0; i<split_idx; i++){
        for (int j=0; j<split_idx; j++){
            A[i][j] += multiplier * B[i][j];
        }
    }
    return A;
}

matrix multiply(matrix A, matrix B){
    int col1 = A[0].size();
    int row1 = A.size();
    int col2 = B[0].size();
    int row2 = B.size();

    if (col1 != row2) {
        std::cout << "Error: The number of columns in Matrix "
                        "A must be equal to the number of rows in Matirx B\n"; 
        return {};
    }

    std::vector<int> result_row(col2, 0);
    matrix result_matrix(row1, result_row);

    if (col1 == 1) result_matrix[0][0] = A[0][0] * B[0][0];
    else{
        int split_idx = col1/2;

        std::vector<int> submatrix_row(split_idx, 0);
        matrix submatrix_00(split_idx, submatrix_row);
        matrix submatrix_01(split_idx, submatrix_row);
        matrix submatrix_10(split_idx, submatrix_row);
        matrix submatrix_11(split_idx, submatrix_row);

        matrix a00(split_idx, submatrix_row);
        matrix a01(split_idx, submatrix_row);
        matrix a10(split_idx, submatrix_row);
        matrix a11(split_idx, submatrix_row);
        matrix b00(split_idx, submatrix_row);
        matrix b01(split_idx, submatrix_row);
        matrix b10(split_idx, submatrix_row);
        matrix b11(split_idx, submatrix_row);

        for (int i=0; i<split_idx; i++){
            for (int j=0; j<split_idx; j++){
                a00[i][j] = A[i][j];
                a01[i][j] = A[i][j+split_idx];
                a10[i][j] = A[i+split_idx][j];
                a11[i][j] = A[i+split_idx][j+split_idx];

                b00[i][j] = B[i][j];
                b01[i][j] = B[i][j+split_idx];
                b10[i][j] = B[i+split_idx][j];
                b11[i][j] = B[i+split_idx][j+split_idx];
            }
        }

        matrix m1 = multiply(add(a00, a11, split_idx), add(b00, b11, split_idx));
        matrix m2 = multiply(add(a10, a11, split_idx), b00);
        matrix m3 = multiply(a00, add(b01, b11, split_idx, -1));
        matrix m4 = multiply(a11, add(b10, b00, split_idx, -1));
        matrix m5 = multiply(add(a00, a01, split_idx), b11);
        matrix m6 = multiply(add(a10, a00, split_idx, -1), add(b00, b01, split_idx));
        matrix m7 = multiply(add(a01, a11, split_idx, -1), add(b10, b11, split_idx));

        submatrix_00 = add(add(add(m1, m4, split_idx), m5, split_idx, -1), m7, split_idx); 
        submatrix_01 = add(m3, m5, split_idx);
        submatrix_10 = add(m2, m4, split_idx);
        submatrix_11 = add(add(add(m1, m2, split_idx, -1), m3, split_idx), m6, split_idx);

        for (int i=0; i<split_idx; i++){
            for (int j=0; j<split_idx; j++){
                result_matrix[i][j] = submatrix_00[i][j];
                result_matrix[i][j+split_idx] = submatrix_01[i][j];
                result_matrix[i+split_idx][j] = submatrix_10[i][j];
                result_matrix[i+split_idx][j+split_idx] = submatrix_11[i][j];
            }
        }
    }

    return result_matrix;
}