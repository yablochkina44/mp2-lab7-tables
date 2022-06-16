#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Table.h"
#include"Record.h"

class ArrayTable :public Table
{
protected:
	Record* pRecs;
	int TabSize;
	int CurrPos;
public:
	ArrayTable(int Size = 100)
	{
		TabSize = Size;
		pRecs = new Record[Size];
		CurrPos = -1;
	}
	~ArrayTable()
	{
		delete[]pRecs;
	}

	bool IsFull() const { return DataCount == TabSize; }
	
	int GetTabSize() const { return TabSize; }
	TKey GetKey(void) const { return pRecs[CurrPos].Key;}
	TValue GetValue(void) const { return pRecs[CurrPos].Value; }
	
	void Reset() { CurrPos = 0;};

	void GoNext()
	{
		if (!IsEnd())
		{
			CurrPos++;
		}
		
	};
	bool IsEnd() const{ return CurrPos == DataCount; };
	
	const Record& GetCurrentRecord() const
	{
		if (!IsEnd() && !IsEmpty())
			return pRecs[CurrPos];
		else
		{
			throw std::exception("Table is empty\n");
		}
	}
	int GetCurrentPos() { return CurrPos; }
	int SetCurrentPos(int pos)
	{
		CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
		return IsEnd();
	};
	
	friend SortTable;
};
