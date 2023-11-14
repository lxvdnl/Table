#pragma once
#include<iostream>

template<typename T>
class TList {
public:
	template<typename T>
	class TLink
	{
	public:
		T Data;
		TLink* pNext;
		TLink(T _Data = T(), TLink* _pNext = NULL) : Data(_Data), pNext(_pNext) {};
	};
protected:
	TLink<T>* pFirst;
public:
	TList();
	~TList();

	bool IsEmpty();

	void InsFirst(T);
	void InsLast(T);
	void Ins(T);
	
	T DelFirst();
	T DelLast();
	size_t Del(T val);

	bool Found(const T val);

	void Print();
};


template<typename T>
TList<T>::TList() {
	pFirst = NULL;
}

template<typename T>
TList<T>::~TList() {
	while (!IsEmpty()) {
		DelFirst();
	}
}

template<typename T>
bool TList<T>::IsEmpty() {
	if (pFirst == NULL) return true;
	return false;
}

template<typename T>
void TList<T>::InsFirst(T val) {
	if (IsEmpty()) {
		pFirst = new TLink<T>(val);
	}
	else {
		TLink<T>* tmp = new TLink<T>(val, pFirst);
		pFirst = tmp;
	}
}

template<typename T>
void TList<T>::InsLast(T val) {
	if (IsEmpty()) {
		pFirst = new TLink<T>(val);
		return;
	}
	TLink<T>* tmp = pFirst;
	while (tmp->pNext != NULL) {
		tmp = tmp->pNext;
	}
	tmp->pNext = new TLink<T>(val);
}

template<typename T>
void TList<T>::Ins(T val) {
	if (!IsEmpty()) {
		TLink<T>* tmp = pFirst;
		while (tmp != nullptr) {
			if (tmp->Data == val) {
				tmp->Data = tmp->Data + val;
				return;
			}
			tmp = tmp->pNext;
		}
	}
}

template<typename T>
T TList<T>::DelFirst() {
	TLink<T> *tmp = pFirst;
	T val = tmp->Data;
	pFirst = pFirst->pNext;
	delete tmp;
	return val;
}

template<typename T>
T TList<T>::DelLast() {
	if (IsEmpty()) {
		std::cerr << "List is empty" << std::endl;
		return T();
	}
	if (pFirst->pNext == NULL) {
		return DelFirst();
	}
	TLink<T>* tmp = pFirst->pNext;
	while (tmp->pNext != NULL) {
		tmp = tmp->pNext;
	}
	return Del(tmp);
}

template<typename T>
size_t TList<T>::Del(T val) {
	size_t countOp = 1;
	if (val == pFirst->Data) DelFirst();
	else{
		TLink<T>* tmp = pFirst;
		while (tmp->pNext != nullptr) {
			countOp++;
			if (tmp->pNext->Data == val) {
				TLink<T>* forDel = tmp->pNext;
				tmp->pNext = tmp->pNext->pNext;
				delete forDel;
				return countOp;
			}
			tmp = tmp->pNext;
		}
	}
	return countOp;
}

template<typename T>
bool TList<T>::Found(const T val) {
	TLink<T>* tmp = pFirst;
	while (tmp != nullptr) {
		if (tmp->Data == val) return true;
		tmp = tmp->pNext;
	}
	return false;
}

template<typename T>
void TList<T>::Print() {
	if (!IsEmpty()) {
		TLink<T>* tmp = pFirst;
		std::cout << tmp->Data;
		tmp = tmp->pNext;
		while (tmp != nullptr) {
			std::cout << "   " << tmp->Data;
			tmp = tmp->pNext;
		}
	}
}