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
	bool insert(const int index, const std::string key, const int value);
	bool getValueByKey(int index, std::string key, int& value);
	bool getKeyByValue(std::string& key, int value);
	bool deleteByKey(int index, const std::string delKey, int& value);

private:
    List* table;
    int size;
};

#endif

