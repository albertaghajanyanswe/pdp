#include "bubbleSort.hpp"


int main() {
    srand(time(0));
    int array[10];
    std::cout << "\nINT ARRAY         --->  ";
    for(int i = 0; i < 10; ++i) {
        array[i] = rand() % 100;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << "\nSorted by incressing     --->  ";
    bubbleSort(array, 10, sizeof(int), compareInt1);
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl <<"\nSorted by decressing    --->  ";
    bubbleSort (array, 10, sizeof(int), compareInt2);
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n\n\nCHAR ARRAY        --->  ";
    char arr[10] = {'Y', 'W', 'B', 'A', 'C', 'D', 'F', 'E', 'K', 'H'};
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i]<<" ";
    }
     bubbleSort (arr, 10, sizeof(char), compareChar1);
     std::cout << std::endl << "\nSorted by incressing     --->  ";
     for (int i = 0; i < 10; ++i) {
            std::cout << arr[i]<<" ";
    }
    std::cout << std::endl;
    bubbleSort (arr, 10, sizeof(char), compareChar2);
    std::cout << std::endl<<"Sorted by decressing    --->  ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i]<<" ";
    }
    std::cout << std::endl << std::endl;
    return 0;
}
