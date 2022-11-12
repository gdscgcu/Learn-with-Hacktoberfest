// Data Structures and Algorithms - HASH TABLE
// https://www.programiz.com/dsa/hash-table
#include <bits/stdc++.h>
using namespace std;

class HashTable {
	int capacity;
	list<int> *table;

public: 
	HashTable(int V);
	void insertItem(int key, int data);
	void removeItem(int key);

	bool checkPrime(int n) {
		int i;
		if (n == 1 || n == 0) return false;
		for (int i = 2; i < n / 2; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}

	int getPrime(int n) {
		if (n % 2 == 0) n++;
		while (!checkPrime(n)) n += 2;
		return n;
	}

	int HashFunction(int key) {
		return (key % capacity);
	}
	void displayHash();
};

HashTable::HashTable(int c) {
	int size = getPrime(c);
	this -> capacity = size;
	table = new list<int>[capacity];
}

void HashTable::insertItem(int key, int data) {
	int index = HashFunction(key);
	table[index].push_back(data);
}

void HashTable::removeItem(int key) {
	int index = HashFunction(key);
	list<int>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == key) break;
	}

	if (i != table[index].end()) table[index].erase(i);
}

void HashTable::displayHash() {
	for (int i = 0; i < capacity; i++) {
		cout << "table[" << i << "]";
		for (auto x : table[i]) {
			cout << x << ' ';
		}
		cout << '\n';
	} 
}

int main() {
	int key[] = {231, 321, 212, 321, 433, 262};
	int data[] = {123, 432, 523, 43, 423, 111};
	int size = sizeof(key) / sizeof(key[0]);

	HashTable h(size);

	for (int i = 0; i < size; i++)
	h.insertItem(key[i], data[i]);

	h.removeItem(12);
	h.displayHash();
}
