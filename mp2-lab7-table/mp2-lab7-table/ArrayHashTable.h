#pragma once
#include "HashTable.h"
#include "Record.h"


class ArrayHashTable : public HashTable
{
protected:
	Record* pRecs;
	int TabSize;
	int HashStep;
	int CurrPos;
	Record Del;
	Record Free;

	int GetNextPos(int pos)
	{
		return (pos + HashStep) % TabSize;
	}
public:
	ArrayHashTable(int Size = 100, int Step = 7);
	~ArrayHashTable();

	bool IsFull() const
	{
		return DataCount >= TabSize;
	}
	void Print(std::ostream& os)
	{
		for (Reset(); !IsEnd(); GoNext()) {
			os << pRecs[CurrPos] << std::endl;
		}
		Reset();
		os << std::endl;
	}

	bool FindRecord(TKey _key);
	bool InsRecord(Record rec);
	bool DelRecord(TKey k);

	const Record& GetCurrentRecord() const override;

	void Reset();
	bool IsEnd() const;
	void GoNext();

	TKey GetKey() const;
	TValue GetValue() const;
};