#include "hashTable.hpp"
#include <iostream>

HashTable::HashTable()
{ }

HashTable::~HashTable() {
	clearAll();
}

void HashTable::clearAll() {
	vector.clearTable();
}
int HashTable::hashIndex(const int key)const {
	return (key % (vector.getSize()));
}

int HashTable::getSize()const {
	return vector.getCount();
}

void HashTable::print()const {
	vector.printVector();
}

bool HashTable::isEmpty() const {
	return 0 == getSize();
}

void HashTable::add(const int key, const int value) {
	int index = hashIndex(key);
	vector.insert(index, key, value);
}

bool HashTable::findValueByKey(const int key, int& value) {
	int index = hashIndex(key);
	return vector.getValueByKey(index, key, value);
}

bool HashTable::findKeyByValue(int& key, const int value) {
	for (int i = 0; i < vector.getSize(); i++) {
		if (vector.getKeyByValue(key, value)) {
			return true;
		}
	}
	return false;
}

bool HashTable::deleteByKey(const int delKey, int& value) {
	int index = hashIndex(delKey);
	return vector.deleteByKey(index, delKey, value);
}
