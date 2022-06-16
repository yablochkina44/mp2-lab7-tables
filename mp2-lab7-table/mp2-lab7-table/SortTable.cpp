#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"SortTable.h"
SortTable::SortTable(const ScanTable& tab) {
	//*this = tab;
}
SortTable& SortTable::operator=(const ScanTable& tab) {
	if (pRecs != NULL) {
		delete[]pRecs;
		delete[]pBuff;
		pRecs = NULL;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	pRecs = new Record[TabSize];
	pBuff = new Record[TabSize];
	for (int i = 0; i < DataCount; i++) {
		pRecs[i] = tab.pRecs[i];
	}
	QuickSort();
	CurrPos = 0;
	return *this;
}


bool SortTable::FindRecord(TKey k)
{//barkashina
	int left = 0; int right = DataCount - 1;
	int midl;
	while (left <= right)
	{
		Efficiency++;
		midl = (left + right) / 2;
		if (pRecs[midl].Key < k)
			left = midl + 1;
		else if (pRecs[midl].Key > k)
			right = midl - 1;
		else
		{
			CurrPos = midl;
			return true;
		}
	
	}
	CurrPos = left;
	return false;

}
bool SortTable::InsRecord(Record rec) 
{
	
	if (IsFull()||FindRecord(rec.Key))
	{
		return false;
	}
	for (int i = DataCount - 1; i >= CurrPos; i--)
	{
		Efficiency++;
		pRecs[i + 1] = pRecs[i];
	}
	pRecs[CurrPos] = rec;
	DataCount++;
	Efficiency++;
	return true;
	
}
bool SortTable::DelRecord(TKey k)
{
	
	if (IsEmpty())
		return false;
	if (!FindRecord(k))
		return false;
	for (int i = CurrPos; i < DataCount - 1; i++)
	{
		pRecs[i] = pRecs[i + 1];
		Efficiency++;
	}
	DataCount--;
	
	return true;
}
void SortTable::QuickSort()
{
	QuickSorter(0, DataCount - 1);// or QuickSorter(0, DataCount)???
}
void SortTable::QuickSorter(int start, int finish)
{
	int s = start; int f = finish;
	int k = (s + f) / 2;
	int m = pRecs[k].Key;
	while (s < f)
	{
		while (pRecs[s].Key < m) { s++; Efficiency++; }
		while (pRecs[f].Key > m) { f--; Efficiency++; }
		if (s <= f)
		{
			Record t = pRecs[s];
			pRecs[s] = pRecs[f];
			pRecs[f] = t;
			s++; f--;
			Efficiency++;
		}
	}
	if (start < f)
		QuickSorter(start, f);
	if (s < finish)
		QuickSorter(s, finish);
}
void SortTable::SelectSort()
{
	int index = 0;
	for (int i = 0; i < DataCount; i++)
	{
		index = i;
		for (int j = i + 1; j < DataCount; j++)
		{
			Efficiency++;
			if (pRecs[j] < pRecs[index])
			{
				index = j;
			}
		}
		if (i != index)
		{
			Efficiency++;
			Record temp;
			pRecs[i] = temp;
			pRecs[i] = pRecs[index];
			pRecs[index] = temp;
		}
	}
}