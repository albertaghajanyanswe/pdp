#include "vector.hpp"
#include <iostream>


Vector::Vector()
        :size(5)
{
    table = new List[size];
    /*for (int i = 0; i < size; i++) {
		table[i] = nullptr;
    }*/
}

Vector::Vector(int size)
        :size(size)
{
    table = new List[size];
    /*for (int i = 0; i < size; i++) {
		table[i] = nullptr;
    }*/
}

Vector::Vector(const Vector& orig) {
	table = new List[orig.size];
    for (int i = 0; i < size; ++i) {
		table[i] = orig.table[i];
    }
}

Vector::~Vector() {
    std::cout << "desctructor" << std::endl;
	clearTable();
    delete[] table;
}

void Vector::clearTable() {
	for (int i =0; i < size; i++) {
        table[i].clear();
    }
}


void Vector::printVector()const {
    std::cout << "Size = " << this->size << std::endl;
    std::cout << "\n\n*********** Vector ***********\n\n";
    for (int i = 0; i < this->size; i++) {
        table[i].printList();
        std::cout << std::endl;
    }
	std::cout << "\n******** End Vector *********\n\n";
}

int Vector::getSize()const {
    return size;
}

int Vector::getCount()const {
	int lenght = 0;
	 for (int i = 0; i < this->size; i++) {
		 lenght += table[i].getCount();
	 }
    return lenght;
}

bool Vector::insert(const int index, const int key, const int value) {
	return table[index].pushFront(key, value);
}

bool Vector::getValueByKey(int index, int key, int& value) {
	return table[index].getValueByKey(key, value);
}

bool Vector::getKeyByValue(int& key, int value) {
	for (int i = 0; i < size; i++) {
		if (table[i].getKeyByValue(key, value)) {
			return true;
		}
	}
	return false;
}

bool Vector::deleteByKey(int index, const int delKey, int& value) {
	return table[index].deleteByKey(delKey, value);
}
