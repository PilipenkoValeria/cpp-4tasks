#pragma once
#include "HashTable.h"

class Iterator {
private:
	Element* now;
	HashTable* hashList;
	int counter;
public:
	Iterator(HashTable*& hashTable);
	~Iterator();
	bool hasNext();
	void start();
	void next();
	int seeElem();
};