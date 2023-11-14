#pragma once
#include"./TTable.h"
#include<cstring>

class TSortedTable : public TTable {
public:
	TSortedTable(const int _Max) : TTable(_Max) {};

	virtual int Search(std::string, bool* flag)override;
	virtual void Push(std::string, int)override;
	virtual void Del(std::string)override;
};