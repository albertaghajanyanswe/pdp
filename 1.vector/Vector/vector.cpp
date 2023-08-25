#include "vector.hpp"
#include <iostream>


Vector::Vector(const int size) {
	if (!InitVector(0,size)) {
		std::cout << "Can not Create Object" << std::endl;
	}
}

Vector::Vector(const Vector& vec) {
	if (!InitVector(vec.vector, vec.size)) {
		std::cout << "Can not Create Object" << std::endl;
	}
}

bool Vector::InitVector(const int* const p1, const int s) {
	this->size = s;
	if (!(this -> vector = new int[size])) {
		return false;
	}
	for (int i = 0; i < this->size; i++) {
		if (0 == p1) {
			vector[i] = 0;
		}
		else {
			vector[i] = p1[i];
		}
	}
	return true;
}

Vector::~Vector() {
	std::cout << "Desctructor called. Pragramm ended." << std::endl;
	delete[] vector;
}


const Vector& Vector::Show()const {
	std::cout << "Size = " << this->size << "\t" << "Address = " << this->vector << std::endl;
	std::cout << "\n*** Vector ***\n";
	for (int i = 0; i < this->size; i++) {
		std::cout << i << "  ->  " << this->vector[i] << std::endl;
	}
	std::cout << std::endl << std::endl;
	return *this;
}

int Vector::getSize()const {
	return size;
}



bool Vector::insert(const int& index, const int& value) {
	if (index < 0 || index > size)  {
		return false;
	}
	int *temp = vector;
	vector = new int[++size];
	for (int i = 0; i < index; i++) {
		vector[i] = temp[i];
	}
	vector[index] = value;
	for (int i = index + 1; i < size; i++) {
		vector[i] = temp[i - 1];
	}
	delete []temp;
	return true;
}


bool Vector::remove(const int index) {
	if (index < 0 || index>size)  {
		return false;
	}
	int *temp = vector;
	vector = new int[--size];
	for (int i = 0; i < size; i++) {
		if (i < index) {
			vector[i] = temp[i];
		}
		else {
			vector[i] = temp[i + 1];
		}
	}
	delete[]temp;
	return true;
}

int Vector::retrieve(int index) {
	if (index >= getSize() || index < 0) {
		std::cout << "Incorrect index\n";
        return -1;
    }
	return vector[index];;
}
