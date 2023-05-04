#include "Iterator.h"

Iterator::Iterator(HashTable*& hashTable)
{
	counter = 0;
	hashList = hashTable;
	now = hashList->table[0];
}

Iterator::~Iterator()
{
}

bool Iterator::hasNext()
{
	if (counter <= hashList->count) { return true; }
	return false;
}

void Iterator::start()
{
	if (hashList->count == 0) {
		throw IteratorWrongCountException();
	}
	now = hashList->table[0];
	counter++;
}

void Iterator::next()
{
	now = hashList->table[counter];
	counter++;
}

int Iterator::seeElem()
{
	return now->data;
}