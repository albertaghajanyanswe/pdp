#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "vector.hpp"

class HashTable
{
public:
	HashTable();
	~HashTable();
	void print()const;
	int getSize()const;
	bool isEmpty()const;
	void add(const int key, const int value);
	bool findValueByKey(const int key, int& value);
	bool findKeyByValue(int& key, const int value);
	void clearAll();
	bool deleteByKey(const int delKey, int& value);
private:
	Vector vector;
	int hashIndex(const int key)const;
};

#endif