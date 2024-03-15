#include<iostream>
#include <cmath>

bool *increasingRowsModulo(int** matrix, size_t r, size_t c) {
    
    bool* result;

    result = new bool[r];

    for (int i = 0; i < r; i++) {
        bool is_increasing = true;
        for (int j = 1; j < c; j++) {
            if (std::fabs(matrix[i][j]) <= std::fabs(matrix[i][j-1])) {
                is_increasing = false;
                break;
            }
        }
        result[i] = is_increasing;
    }
    return result;
}