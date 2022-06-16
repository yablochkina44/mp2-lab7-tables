#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"ScanTable.h"

class SortTable :public ScanTable 
{
private:
	Record* pBuff;
public:
	SortTable(int Size = 100) :ScanTable(Size) {
		pBuff = new Record[DataCount];
	}
	~SortTable() {
		delete[]pBuff;
	}
	SortTable(const ScanTable& tab);

	bool FindRecord(TKey) override;
	bool InsRecord(Record) override;
	bool DelRecord(TKey) override;

	void SelectSort();
	void QuickSorter(int start, int finish);
	void QuickSort();
	SortTable& operator=(const ScanTable& tab);

	void Print(std::ostream& os)
	{
		for (int i = 0; i < DataCount; i++) {
			os << pRecs[i] << std::endl;
		}
		os << std::endl;
	}
	
	
	
	
	
	
	
	
	
};