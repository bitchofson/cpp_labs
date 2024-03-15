#include <iostream>
#include "bool_vector.hpp"


void initialize(int** arr,  size_t r, size_t c);
void printMatrix(int** arr, size_t r, size_t c);

int main() {

    size_t r, c;
    std::cout << "Введите количество строк матрицы: ";
	std::cin >> r;
	std::cout << "Введите количество стобцов матрицы:";
	std::cin >> c;

    int** matrix;
    matrix = new int* [r];

    initialize(matrix, r, c);
    printMatrix(matrix, r, c);
    bool* bool_vector = increasingRowsModulo(matrix, r, c);

    std::cout << "Результат: ";
    for (int i = 0; i < r; i++) {
        std::cout << (bool)bool_vector[i] << " ";
    }
    std::cout << std::endl;
    
    delete bool_vector;

    for (size_t i = 0; i < r; i++) {
		delete matrix[i];
	}

    return 0;
}

void initialize(int** arr, size_t r, size_t c) {
    std::cout << "Введите элементы матрицы: " << std::endl;
	for (size_t i = 0; i < r; i++) {
		arr[i] = new int[c];
		for (size_t j = 0; j < c; j++) {
            std::cout << "[" << i << "][" << j << "]=";
			std::cin >> arr[i][j];
	    }
    }
}

void printMatrix(int** arr, size_t r, size_t c) {
    std::cout << std::endl << "Матрица:" << std::endl;
	for (size_t i = 0; i < r; i++) {
		for (size_t j = 0; j < c; j++) {
				std::cout << arr[i][j] << " ";	
		}
		std::cout << std::endl;
	}
    std::cout << std::endl;
}
