#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"ScanTable.h"

bool ScanTable::FindRecord(TKey k) 
{	
	for (int i = 0; i < DataCount; i++)
	{
		if (pRecs[i].Key == k)
		{
			CurrPos = i;
			return true;
		}
		Efficiency++;
	}
	CurrPos = DataCount;
	return false;
}

bool ScanTable::InsRecord(Record rec) 
{
	if (IsFull()) {
		return false;
	}
	if (FindRecord(rec.Key))
	{
		return false;
	}
	pRecs[CurrPos] = rec;
	
	DataCount++;
	Efficiency++;
	return true;

}
bool ScanTable::DelRecord(TKey k)
{	
	if (IsEmpty())
		return false;
	if (!FindRecord(k))
		return false;
	pRecs[CurrPos] = pRecs[DataCount - 1];
	DataCount--;
	Efficiency++;
	return true;
}