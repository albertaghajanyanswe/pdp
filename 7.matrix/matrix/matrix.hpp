#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

namespace Matrix2D {
    class Matrix {

        private:
            int **myMatrix;
            int row;
            int colum;

        public:
            Matrix();
            Matrix(int row, int colum);
            Matrix( const Matrix & matrix);
            //Matrix(Matrix&& matrix);
            ~Matrix();

            int getRow() const;
            void setRow(int row);
            int getColum()const;
            void setColum(int colum);
            int** getMatrix()const;                  

            friend std::ostream &operator<<(std::ostream &output, const Matrix &matrix );
            friend std::istream &operator>>(std::istream &input, const Matrix &matrix );
            bool operator==(const Matrix& right) const;
            Matrix& operator=(const Matrix &right);
            //Matrix& operator=(Matrix&& other);
            Matrix operator+(const Matrix& matrix)const;
            //Matrix operator+(Matrix&& matrix)const;
            Matrix operator-(const Matrix& matrix)const;
            Matrix operator*(const Matrix& matrix)const;
            int* operator[](int i);
    };

    std::ostream &operator<<(std::ostream &output, const Matrix &matrix );
    std::istream &operator>>(std::istream &input, const Matrix &matrix );
}
#endif

