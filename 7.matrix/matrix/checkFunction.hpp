#ifndef CHECKFUNCTION_H
#define CHECKFUNCTION_H

#include "matrix.hpp"

namespace check {
    bool checkInput(int& row,  int& colum);
    void chooseOperation(char operation, const Matrix2D::Matrix& matrix1, const Matrix2D::Matrix& matrix2);
    bool checkOperation(char operation);
    bool checkIJ(int& i, int& j, int row, int colum);
    bool inputMatrix(Matrix2D::Matrix & matrix, int i);
    bool printMatrix(Matrix2D::Matrix & matrix, int i);
    bool equalMatrix(Matrix2D::Matrix & matrix1, Matrix2D::Matrix & matrix2);
    bool checkIJ(int& i, int& j, Matrix2D::Matrix& matrix);
}

#endif
