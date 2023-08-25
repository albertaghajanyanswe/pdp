#ifndef bubleSort
#define bubleSort

#include <iostream>
#include <ctime>
#include <cstdlib>

void mySwap(void* p1, void* p2,size_t sizeOfElement);
void bubbleSort(void* array, size_t sizeOfArray, size_t sizeOfElement, int (*compare)(const void*p1, const void*p2));

int compareInt1(const void * p1, const void * p2);
int compareInt2(const void * p1, const void * p2);
int compareChar1( const void *p1, const void *p2);
int compareChar2( const void *p1, const void *p2);

#endif
