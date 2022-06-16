#pragma once
#include "Table.h"

class HashTable : public Table
{
protected:
	int HashFunc(TKey key)
	{
		return key;
	}
};