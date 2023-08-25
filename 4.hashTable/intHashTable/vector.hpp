#ifndef VECTOR_H
#define VECTOR_H

#include "list.hpp"

class Vector {
public:

	Vector();
	Vector(const int size);
	Vector(const Vector& orig);
	~Vector();
	void clearTable();
	void printVector()const;
	int getSize()const;
	int getCount()const;
	bool insert(const int index, const int key, const int value);
	bool getValueByKey(int index, int key, int& value);
	bool getKeyByValue(int& key, int value);
	bool deleteByKey(int index, const int delKey, int& value);

private:
    List* table;
    int size;
};

#endif

