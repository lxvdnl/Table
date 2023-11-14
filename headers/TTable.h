#pragma once
#include<iostream>
#include<cstring>

class TTable {
public:
	struct obj{
		std::string key;
		int data;
		obj& operator =(const obj& _obj) {
			key = _obj.key;
			data = _obj.data;
			return *this;
		}
	};
	obj* arr;
	const int MAX;
	int cur_size, count_op;
public:
	TTable(const int _MAX) : MAX(_MAX), cur_size(0), count_op(0) {
		arr = new obj[MAX];
	}
	~TTable() {
		delete[] arr;
	}

	bool IsEmpty();
	bool IsFull();
	int GetCountOp();

	friend std::ostream& operator <<(std::ostream&, const TTable&);
protected:
	virtual int Search(std::string, bool*) = 0;
	virtual void Push(std::string, int) = 0;
	virtual void Del(std::string) = 0;
};