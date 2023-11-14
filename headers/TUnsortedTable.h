#pragma once
#include"./TTable.h"
#include<string>

class TUnsortedTable : public TTable {
public:
	TUnsortedTable(const int _Max) : TTable(_Max) {};

	virtual int Search(std::string, bool* = NULL)override;
	virtual void Push(std::string, int)override;
	virtual void Del(std::string)override;
};