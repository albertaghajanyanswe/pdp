#include "checkFunction.hpp"
#include <iostream>

int main() {
    int row = 0;
    int colum = 0;
    char operation = '\0';
    int choose = 0;
    do {
        std::cout << "\n*** Matrix 1 ***\n";
        if (false == check::checkInput(row, colum)) {
            return 0;
        }
        Matrix2D::Matrix matrix1(row,colum);
        check::inputMatrix(matrix1, 1);
        check::printMatrix(matrix1, 1);

        std::cout << "\n*** Matrix 2 ***\n";
        if (false == check::checkInput(row, colum)) {
            return 0;
        }
        Matrix2D::Matrix matrix2(row,colum);
        check::inputMatrix(matrix2, 2);
        check::printMatrix(matrix2, 2);
        check::equalMatrix(matrix1, matrix2);

        int i = 0, j = 0;
        check::checkIJ(i, j, matrix2);

        do {
            std::cout << "\nOperation + or - or * ";
            std::cin >> operation;
        } while (!(check::checkOperation(operation)));
        check::chooseOperation(operation, matrix1, matrix2);

        std::cout << "Press 0 - Exit, Press any number to continue : ";
        std::cin >> choose;
        if ('0' == choose) {
            return 0;
        }
    } while (0 != choose);

    return 0;
}
