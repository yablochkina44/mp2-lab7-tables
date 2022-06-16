#pragma once
#include "ArrayHashTable.h"

ArrayHashTable::ArrayHashTable(int Size, int Step) : TabSize(Size), HashStep(Step)
{
	pRecs = new Record[TabSize];
	Free.Key=-1;
	Del.Key=-2;
	for (int i = 0; i < TabSize; i++)
	{
		pRecs[i] = Free;
	}
}

ArrayHashTable::~ArrayHashTable()
{
	delete[] pRecs;
}

bool ArrayHashTable::FindRecord(TKey key)
{
	int flag = -1;
	int Currpos = HashFunc(key) % TabSize;

	for (int i = 0; i < TabSize; i++) {
		Efficiency++;

		if (pRecs[Currpos].Key == key) {
			CurrPos = Currpos;
			return true;
		}

		if (pRecs[Currpos] == Del && flag == -1) {
			Currpos = Currpos;
			flag = 1;
		}

		if (pRecs[Currpos] == Free) {
			if (flag == -1)
				CurrPos = Currpos;
			break;
		}

		Currpos = (Currpos + HashStep) % TabSize;
	}

	return false;
}

bool ArrayHashTable::InsRecord(Record rec)
{
		if (IsFull()) return false;
		if (FindRecord(rec.Key)) return false;
		pRecs[CurrPos] = rec;
		DataCount++;
		Efficiency++;
		return true;
}

bool ArrayHashTable::DelRecord(TKey k)
{
	if (IsEmpty()) return false;
	if (!FindRecord(k)) return false;
	pRecs[CurrPos] = Free;
	for (Reset(); !IsEnd(); GoNext()) {
		if (pRecs[CurrPos].Key == k) {
			pRecs[CurrPos] = Del;
		}
		Efficiency++;
	}

	DataCount--;
	return true;
}

void ArrayHashTable::Reset()
{
	for (CurrPos = 0; CurrPos < TabSize; CurrPos++)
		if (pRecs[CurrPos] != Del && pRecs[CurrPos] != Free)
			return;
	
}

bool ArrayHashTable::IsEnd() const
{
	return CurrPos == TabSize;
}

void ArrayHashTable::GoNext()
{
	for (CurrPos++; CurrPos < TabSize; CurrPos++)
		if (pRecs[CurrPos] != Del && pRecs[CurrPos] != Free)
			return;
}

TKey ArrayHashTable::GetKey() const
{
	return pRecs[CurrPos].Key;
}
const Record& ArrayHashTable::GetCurrentRecord() const
{
	if (!IsEnd() && !IsEmpty())
	{
		return pRecs[CurrPos];
	}
	else
	{
		throw std::exception();
	}
}

TValue ArrayHashTable::GetValue() const
{
	return pRecs[CurrPos].Value;
}