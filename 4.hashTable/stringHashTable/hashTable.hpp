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
	void add(const std::string key, const int value);
	bool findValueByKey(const std::string key, int& value);
	bool findKeyByValue(std::string& key, const int value);
	void clearAll();
	bool deleteByKey(const std::string delKey, int& value);
private:
	Vector vector;
	int hashIndex(const std::string key)const;
};

#endif