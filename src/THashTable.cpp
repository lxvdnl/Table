#include"../headers/THashTable.h"

THashTable::THashTable(size_t MAX) {
	opCount = 1;
	size = MAX;
	listsArray = new TList<pair>[size];
}

THashTable::~THashTable() {
	for (size_t i = 0; i < size; i++) {
		listsArray[i].~TList();
	}
	delete[] listsArray;
}

bool THashTable::IsEmpty() {
	for (size_t i = 0; i < size; i++) {
		if (!listsArray[i].IsEmpty()) return false;
	}
	return true;
}

bool THashTable::IsFull() {
	try {
		TList<pair>::TLink<pair>* tmp = new TList<pair>::TLink<pair>(pair());
		delete tmp;
	}
	catch (...) {
		return true;
	}
	return false;
}

size_t THashTable::GetCountOp() {
	return opCount;
}

size_t THashTable::Search(std::string _key, bool& isFound) {
	opCount = 1;
	size_t place = hash(_key);
	THashTable::pair _pair(_key);
	if (listsArray[place].Found(_pair)) {  isFound = true; return place; }
	else {
		isFound = false; return place;
	}
}

size_t THashTable::hash(std::string _key) {
	size_t convolution = 0;
	for (size_t i = 0; i < _key.size(); i++) {
		convolution += size_t(_key[i]);
	}
	convolution %= size;
	return convolution;
}

void THashTable::Push(std::string _key, int _data) {
	opCount = 1;
	if (!IsFull()) {
		bool isFound;
		size_t place = Search(_key, isFound);
		THashTable::pair _pair(_key, _data);
		if (!isFound) {
			listsArray[place].InsFirst(_pair);
		}
		else {
			listsArray[place].Ins(_pair);
		}
	}
}

void THashTable::Del(std::string _key) {
	THashTable::pair _pair(_key);
	opCount = listsArray[hash(_key)].Del(_pair);
}

void THashTable::Print() {
	for (size_t i = 0; i < size; i++) {
		if (!listsArray[i].IsEmpty()) {
			std::cout << i + 1 << ":   ";
			listsArray[i].Print();
			std::cout << std::endl;
		}
	}
}



std::ostream& operator <<(std::ostream& os, const THashTable::pair& _pair) {
	os << _pair.key << " (" << _pair.data << ")";
	return os;
}