#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <stdio.h>
#include "SortTable.h"
#include "ArrayTable.h"
#include "ScanTable.h"
#include "TreeTable.h"
#include "ArrayHashTable.h"
#include "BalanceTreeTable.h"
using namespace std;

Table* table;
bool result = true;
int Eff = 0;
int countrec = 0;
int diapkey = 0;
int maxsize = 0;



void CreateTable(int t)
{
	cout << "Введите количество записей, диапазон ключей, и размер таблицы.\n";
	cin >> countrec >> diapkey >> maxsize;
	switch (t)
	{
	case 1: {
		table = new ScanTable(maxsize);
		break;
	}

	case 2: {
		table = new SortTable(maxsize);
		break;
	}

	case 3: {
		table = new ArrayHashTable(maxsize);
		break;
	}

	case 4: {
		table = new TreeTable();
		break;
	}
	case 5: {
		table = new BalanceTreeTable();
		break;
	}
	default:
		break;
	}

	srand(time(NULL));

	Record NewRecord;

	for (int i = 0; i < countrec; i++)
	{
		NewRecord.Key = rand() % diapkey;
		NewRecord.Value = "value#" + to_string(NewRecord.Key);
		bool b=table->InsRecord(NewRecord);
		cout << b << endl;
	}
}

void Insert()
{
	Record rec;
	cout << "Ключ : " << endl;
	cin >> rec.Key;
	cout << " Запись :" << endl;
	cin >> rec.Value;


	Eff = table->GetEfficiency();
	cout << (table->InsRecord(rec)) << endl; 
	cout << "Эффективность: " << table->GetEfficiency() - Eff << endl;
}

void Find()
{
	TKey key;
	cout << "Введите ключ для поиска " << endl;
	cin >> key;

	Eff = table->GetEfficiency();
	cout << (table->FindRecord(key)) << endl;
	cout << "Эффективность: " << table->GetEfficiency() - Eff << endl;
}

void Delete()
{
	TKey key;
	cout << "Введите ключ для удаления " << endl;
	cin >> key;

	Eff = table->GetEfficiency();
	cout << (table->DelRecord(key)) << endl;
	cout << "Эффективность: " << table->GetEfficiency() - Eff << endl;

}

void main() {
	int q = 0;
	setlocale(LC_ALL, "Russian");
	int type;
	while (true) {
		cout << "1. Создать таблицу " << endl;
		cout << "2. Печать таблицы" << endl;
		cout << "3. Поиск " << endl;
		cout << "4. Удалить элемент " << endl;
		cout << "5. Вставить элемент " << endl;
		cin >> q;

		switch (q)
		{
		case 1:
		{
			cout << "1. ScanTable\n";
			cout << "2. SortTable\n";
			cout << "3. ArrayHashTable\n";
			cout << "4. TreeTable\n";
			cout << "5. BalanceTreeTable\n";
			cin >> type;
			CreateTable(type);
			break;
		}
		case 2:
		{
			table->Print(cout);
			break;
		}
		case 3:
		{
			Find();
			break;
		}
		case 4:
		{
			Delete();
			break;
		}
		case  5:
		{
			Insert();
			break;
		}
		default:
			break;
		}
	}

}
