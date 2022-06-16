#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"ArrayTable.h"
class ScanTable :public ArrayTable {
public:
	
	ScanTable(int Size = 100) : ArrayTable(Size) {}
	bool FindRecord(TKey) override;
	bool InsRecord(Record) override;
	bool DelRecord(TKey) override;
	void Print(std::ostream& os)
	{
		for (int i = 0; i < DataCount; i++) {
			os << pRecs[i] << std::endl;
		}
		os << std::endl;
	}
};