#include "bubbleSort.hpp"

void mySwap(void* p1, void* p2,size_t sizeOfElement) {
    for (int i = 0; i < sizeOfElement; ++i) {
        char x = *((char*)p1 + i);
        char y = *((char*)p2 +i);
        char* ptrx = ((char*)p1 + i);
        char* ptry = ((char*)p2 + i);
        char temp = x;
        *ptrx = y;
        *ptry = temp;
    }
}

void bubbleSort(void* array, size_t sizeOfArray, size_t sizeOfElement, int (*compare)(const void*p1, const void*p2)) {
    for(int i = 0; i < sizeOfArray; ++i) {
        for(int j = 0; j < sizeOfArray - 1; ++j) {
            void* p1 = (char*)array + (j * sizeOfElement);
            void* p2 = (char*)array + ((j + 1) * sizeOfElement);
            if (compare(p1, p2) > 0) {
                mySwap(p1, p2,sizeOfElement);
            }
        }
    }
}

int compareInt1(const void * p1, const void * p2) {
    return ( *(int*)p1 - *(int*)p2 );
}

int compareInt2(const void * p1, const void * p2) {
    return ( *(int*)p2 - *(int*)p1 );
}
int compareChar1( const void *p1, const void *p2) {
    return ( *(char*)p1 - *(char*)p2 );
}
int compareChar2( const void *p1, const void *p2) {
    return ( *(char*)p2 - *(char*)p1 );
}

