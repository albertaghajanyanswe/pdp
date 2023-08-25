#include "matrix.hpp"
#include <iostream>

Matrix2D::Matrix::Matrix():
    myMatrix(nullptr),
    row(0),
    colum(0)
{ }


Matrix2D::Matrix::Matrix(int row,int colum)
    : row(row),
    colum(colum)
{
    this -> myMatrix = new int*[row];
    for (int i = 0; i < (this -> row); ++i){
        this -> myMatrix[i] = new int[colum];
    }

    for (int i = 0; i < (this -> row); ++i){
        for (int j = 0; j < (this -> colum); ++j){
            myMatrix[i][j] = 0;
        }
    }
}

Matrix2D::Matrix::Matrix( const Matrix & matrix) :
    row(matrix.row),
    colum(matrix.colum)
{
    this -> myMatrix = new int*[row];
    for (int i = 0; i < row; i++) {
        this -> myMatrix[i] = new int[colum];
        for (int j = 0; j < colum; j++) {
            this -> myMatrix[i][j] = matrix.myMatrix[i][j];
        }
    }
}

/*
Move constructor, operator= , operator+ gorcoxutyunnern ogtagorceluc
segmentation fault a gcum, chem karum uxxem
*/

/*
Matrix2D::Matrix::Matrix(Matrix&& matrix):
    row(matrix.row),
    colum(matrix.colum),
    myMatrix(matrix.myMatrix)
{
    std::cout << "\nMove Constructor\n";
    matrix.myMatrix = nullptr;
}
*/
/*
************** Move operator = ********************

Matrix2D::Matrix& Matrix2D::Matrix::operator=(Matrix&& other) {
    std::cout << "Move = operator\n";
    if (this != &other) {
        for (int i = 0; i < row; ++i) {
            delete [] myMatrix[i];
        }
        delete [] myMatrix;
        myMatrix = nullptr;

        this -> row = other.row;
        this -> colum = other.colum;
        this -> myMatrix = other.myMatrix;

        other.row = 0;
        other.colum = 0;
        other.myMatrix = nullptr;
    }
    return *this;
}
*/

Matrix2D::Matrix::~Matrix() {
    for (int i = 0; i < row; ++i) {
        delete [] myMatrix[i];
    }
    delete [] myMatrix;
    myMatrix = nullptr;
}

int Matrix2D::Matrix::getRow() const {
    return this -> row;
}
void Matrix2D::Matrix::setRow(int row) {
    this -> row = row;
}


int Matrix2D::Matrix::getColum() const {
    return this -> colum;
}
void Matrix2D::Matrix::setColum(int colum) {
    this -> colum = colum;
}


int** Matrix2D::Matrix::getMatrix() const {
    return this -> myMatrix;
}

std::ostream& Matrix2D::operator << (std::ostream &output, const Matrix &matrix) {
    for (int i = 0; i < matrix.row; i++) {
        for(int j = 0; j < matrix.colum; j++) {
            output << matrix.myMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return output;
}

std::istream& Matrix2D::operator >> (std::istream  &input, const Matrix &matrix) {
    for (int i = 0; i < matrix.row; i++) {
        for(int j = 0; j < matrix.colum; j++) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            input >> matrix.myMatrix[i][j];
        }
    }
    return input;
}

Matrix2D::Matrix Matrix2D::Matrix::operator + (const Matrix2D::Matrix& matrix) const {
    std::cout << "operator +\n";
    if (this -> row != matrix.row || this -> colum != matrix.colum){
        std::cout << "\nThe rows and columns must be equal\n";
        return (*this);
    }
    Matrix result(this -> row, this -> colum);
    for (int i = 0; i < (this -> row); ++i){
        for (int j = 0; j < (this -> colum); ++j){
            result.myMatrix[i][j] = this -> myMatrix[i][j] + matrix.myMatrix[i][j];
        }
    }
    return result;
}

Matrix2D::Matrix Matrix2D::Matrix::operator-(const Matrix& matrix) const {
    if (this -> row != matrix.row || this -> colum != matrix.colum){
        std::cout << "\nThe rows and columns must be equal.\n";
        return (*this);
    }
    Matrix result(this -> row, this -> colum);
    for (int i = 0; i < this -> row; ++i){
        for (int j = 0; j < this -> colum; ++j){
            result.myMatrix[i][j] = this -> myMatrix[i][j] - matrix.myMatrix[i][j];
        }
    }
    return result;
}

Matrix2D::Matrix Matrix2D::Matrix::operator*(const Matrix& matrix) const {
    if (this -> row != matrix.colum){
        std::cout << "\nRow of first matrix must be equal to column of second matrix\n";
        return (*this);
    }
    Matrix result(this -> row, matrix.colum);
    for (int i = 0; i < this -> row; ++i) {
        for (int j = 0; j < matrix.colum; ++j) {
            for (int k = 0; k < this ->  colum; k++) {
                result.myMatrix[i][j] += (this -> myMatrix[i][k] * matrix.myMatrix[k][j]);
            }
        }
    }
    return result;
}

Matrix2D::Matrix& Matrix2D::Matrix::operator = (const Matrix &right) {
    if (&right != this) {
        for (int i = 0; i < row; ++i) {
            delete[] this->myMatrix[i];
        }
        delete[] this-> myMatrix;
        this -> myMatrix = nullptr;

        this->row = right.row;
        this->colum = right.colum;

        //Create new matrix
        this->myMatrix = new int*[right.row];
        for (int i = 0; i < this->row; ++i) {
            this->myMatrix[i] = new int[right.colum];
        }

        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->colum; ++j) {
                this->myMatrix[i][j] = right.myMatrix[i][j];
            }
        }
    }
    return *this;
}

bool Matrix2D::Matrix::operator==(const Matrix& right) const {
    if (this -> row != right.row || this -> colum != right.colum) {
        return false;
    }
    for (int i = 0; i < right.row; ++i) {
        for (int j = 0; j < right.colum; j++) {
            if (this -> myMatrix[i][j] != right.myMatrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int * Matrix2D::Matrix::operator[](int i) {
    if (0 > i || i >= this-> row || i >= this -> colum) {
        return nullptr;
    }
    return this->myMatrix[i];
}
