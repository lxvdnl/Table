#pragma once
#include<iostream>
#include<string>

class TBalanceTree {
	struct obj {
		std::string key;
		int data;
		obj(std::string _key = "", int _data = 0) : key(_key), data(_data) {};
	};
	class TNode {
	public:		
		obj data;
		TNode* pLeft;
		TNode* pRight;
		short balanceRatio;
		TNode(std::string _key, int _data, short _balanceRatio = 0) : pLeft(nullptr), pRight(nullptr), balanceRatio(_balanceRatio) { data.key = _key; data.data = _data; };
	};
	TNode* pRoot;
	int count_op;
public:
	TBalanceTree() : pRoot(nullptr), count_op(0) {};
	~TBalanceTree() {};

	bool IsEmpty();
	bool IsFull();

	TNode* Search(std::string, bool&);
	void Push(std::string, int);
	void Del(std::string);

	int GetCountOp() {
		return count_op;
	}
	void Print();
private:
	void PrintLTR(const TNode*);
	TNode* GetPrevNode(const TNode*);
};
