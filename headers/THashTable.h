#pragma once
#include"../submodules/TList/TList.h"
#include<string>

class THashTable {
	class pair {
		std::string key;
		int data;
	public:
		pair(std::string _key = "", int _data = 0) :key(_key), data(_data) {};
		pair(const pair& _pair) {
			key = _pair.key;
			data = _pair.data;
		}
		pair& operator =(const pair& _pair) {
			key = _pair.key;
			data = _pair.data;
			return *this;
		}
		bool operator ==(const pair& _pair) {
			return _pair.key == key;
		}
		pair& operator +(const pair& _pair) {
			data += _pair.data;
			return *this;
		}
		friend std::ostream& operator <<(std::ostream& os, const pair& _pair);
	};
	TList<pair>* listsArray;
	size_t opCount, size;
public:
	THashTable(size_t Max = 100);
	~THashTable();

	void Print();
	size_t GetCountOp();

	size_t Search(std::string _key, bool& isFound);
	void Push(std::string _key, int _data);
	void Del(std::string _key);
private:
	bool IsEmpty();
	bool IsFull();

	size_t hash(std::string _key);
	friend std::ostream& operator <<(std::ostream& os, const pair& _pair);
};