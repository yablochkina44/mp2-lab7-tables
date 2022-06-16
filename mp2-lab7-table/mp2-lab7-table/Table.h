#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Record.h"

typedef int TKey;
typedef string TValue;

struct Record
{
	TKey Key;
	TValue Value;
	Record(TKey k = -1, TValue Val = "und") {
		Key = k;
		Value = Val;
	}

	virtual int operator==(const Record& tr) { return Key == tr.Key; }
	virtual void operator=(const Record& tr) { Key = tr.Key; Value = tr.Value; }
	virtual int operator!=(const Record& tr) { return Key != tr.Key; }
	virtual int operator>(const Record& tr) { return Key < tr.Key; }
	virtual int operator<(const Record& tr) { return Key > tr.Key; }
	virtual int operator>=(const Record& tr) { return Key <= tr.Key; }
	virtual int operator<=(const Record& tr) { return Key >= tr.Key; }
	friend ostream& operator<<(std::ostream& os, Record rec)
	{
		os << rec.Key << ":    " << rec.Value;
		return os;
	}

	friend class ArrayTable;
	friend class ScanTable;
	friend class SortTable;

};



class Table
{
protected:
	int DataCount; // кол-во записей в таблице
	int Efficiency; // показатель эффективности выполнениия операций
public:
	Table() { DataCount = 0, Efficiency = 0; };
	virtual ~Table() {};
	int GetDataCount()const { return DataCount; }
	int GetEfficiency()const { return Efficiency; }
	virtual const Record& GetCurrentRecord() const = 0;
	void SetDataCount(int D) { DataCount = D; }
	void SetEfficiency(int E) { Efficiency = E; }
	void ClearEfficiency() { Efficiency = 0; }
	
	bool IsEmpty() const { return DataCount == 0; }
	virtual bool IsFull() const = 0;

	
	virtual bool FindRecord(TKey)  = 0;
	virtual bool InsRecord(Record) = 0;
	virtual bool DelRecord(TKey) = 0;
	virtual void Print(std::ostream& os) = 0;

	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() const = 0;

	virtual TKey GetKey() const = 0;
	virtual TValue GetValue() const = 0;

	friend ostream& operator<<(ostream& os, Table& tab)
	{
		os << "Printing a table ..." << endl;
		for (tab.Reset(); !tab.IsEnd(); tab.GoNext())
		{
			os << "Key:" << tab.GetKey()<<"   "
			   << " Value:" << tab.GetValue() << endl;
		}
		return os;
	}
};