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
int HashTable::hashIndex(const std::string key)const {
	int sum = 0;
	char symbol = key[0];
	int i = 0;
	while ('\0' != key[i]) {
		sum += (int)symbol;
		++i;
		symbol = key[i];
	}
	return (sum % (vector.getSize()));
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

void HashTable::add(const std::string key, const int value) {
	int index = hashIndex(key);
	vector.insert(index, key, value);
}

bool HashTable::findValueByKey(const std::string key, int& value) {
	int index = hashIndex(key);
	return vector.getValueByKey(index, key, value);
}

bool HashTable::findKeyByValue(std::string& key, const int value) {
	for (int i = 0; i < vector.getSize(); i++) {
		if (vector.getKeyByValue(key, value)) {
			return true;
		}
	}
	return false;
}

bool HashTable::deleteByKey(const std::string delKey, int& value) {
	int index = hashIndex(delKey);
	return vector.deleteByKey(index, delKey, value);
}
