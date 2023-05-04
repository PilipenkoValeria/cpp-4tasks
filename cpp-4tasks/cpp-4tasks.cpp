#include "HashTable.h"
#include "Iterator.h"
#include "iostream"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	try {
		HashTable* example = new HashTable(-4);
	}
	catch (WrongSizeException) {
		cout << "Отрицательный размер таблицы!" <<  endl;
	}

	try {
		HashTable* example = new HashTable(0);
	}
	catch (WrongSizeException) {
		 cout << "Размер таблицы не равен нулю!" <<  endl;
	}

	HashTable* example = new HashTable();
	try {
		example->printElem();
	}
	catch (NoElemException) {
		 cout << "HashTable пуста!" <<  endl;
	}

	try {
		Iterator iter(example);
		iter.start();
	}
	catch (IteratorWrongCountException) {
		 cout << "Итератор не может быть запущен, таблица пуста!" <<  endl;
	}

	example->addElem(4, 1);
	try {
		example->addElem(75, 1);
	}
	catch (CopyOfElementException) {
		 cout << "Элемент уже существует в таблице!" <<  endl;
	}
	


	HashTable* table = new HashTable(5);
	table->addElem(566, 1);
	table->addElem(3221, 2);
	table->addElem(221, 3);
	table->addElem(3234, 4);
	table->addElem(113578, 5);
	cout << "Вывод на экран" << endl;
	table->printElem();
	cout << endl;
	cout << "Удаляем элемент с ключом 3" <<  endl;
	cout << endl;
	table->removeElem(3);
	cout << "Поиск элемента с ключом 4:" << table->findElem(4) <<  endl;
	cout <<  endl;

	cout << "Работа итератора" <<  endl;
	Iterator iter(table);
	iter.start();
	while (iter.hasNext()) {
		 cout << iter.seeElem() <<  endl;
		iter.next();
	}

	cout << "Удаляем table" <<  endl;
	cout << table->isEmpty() <<  endl;
	table->doEmpty();
	cout << table->isEmpty() <<  endl;
	try {
		Iterator iter(table);
		iter.start();
	}
	catch (IteratorWrongCountException) {
		 cout << "Итератор не может быть запущен, таблица пуста!" <<  endl;
	}
}