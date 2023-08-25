#include "checkFunction.hpp"
#include <iostream>
//#include "matrix.hpp"

bool check::checkInput(int& row,  int& colum) {
    std::cout << "Row   : ";
    std::cin >> row;
    if (std::cin.fail() || 0 >= row) {
        std::cout << "\nRow is incorrect\n";
        return false;
    }
    std::cout << "Colum : ";
    std::cin >> colum;
    if (std::cin.fail() || 0 >= colum) {
        std::cout << "\nColum is incorrect\n";
        return false;
    }
	return true;
}

bool check::inputMatrix(Matrix2D::Matrix & matrix, int i) {
    std::cout << "\nEnter matrix " << i << "\n";
    std::cin >> matrix;
}

bool check::printMatrix(Matrix2D::Matrix & matrix, int i) {
    std::cout << "\nMatrix "<< i << "\n\n";
    std::cout << matrix;
}

bool check::equalMatrix(Matrix2D::Matrix & matrix1, Matrix2D::Matrix & matrix2) {
    if (matrix1 == matrix2) {
        std::cout << "\n matrix1 = matrix2\n";
        return true;
    } else {
        std::cout << "\nmatrix1 != matrix2\n";
        return false;
    }
}
void check::chooseOperation(char operation, const Matrix2D::Matrix& matrix1, const Matrix2D::Matrix& matrix2) {
    switch(operation) {
        case '+' : {
            Matrix2D::Matrix result = matrix1 + matrix2;
            std::cout << "\nSum of two Matrix\n";
            std::cout << result;
            break;
        }
        case '-' : {
            Matrix2D::Matrix result = matrix1 - matrix2;
            std::cout << "\nDivid of two Matrix\n";
            std::cout << result;
            break;
	      }
        case '*' : {
            Matrix2D::Matrix result = matrix1 * matrix2;
            std::cout << "\nMultiple Matrix\n";
            std::cout << result;
            break;
        }
    }
}

bool check::checkOperation(char operation) {
    if (('+' != operation) && ('-' != operation) && ('*' != operation)) {
        return false;
    }
	return true;
}

//i ev j arjeqner@ poxum em

bool check::checkIJ(int& i, int& j, Matrix2D::Matrix& matrix) {
    std::cout << "\nSimulate [] operator.\n";
    std::cout << "Matrix2 row index: ";
    std::cin >> i;
    std::cout << "Matrix2 colum index: ";
    std::cin >> j;
    if (i >= matrix.getRow() || j >= matrix.getColum() || 0 > i || 0 > j) {
        std::cout << "\nEntered incorrect index\n";
        return false;
    } 
	std::cout << "\nmatrix2[" << i << "][" << j << "] = " << matrix[i][j] << "\n";
    return true;
}

