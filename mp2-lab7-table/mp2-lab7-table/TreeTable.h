#pragma once
#include <stack>
#include <stdio.h>
#include "Table.h"
#include "TreeNode.h"
#include "Record.h"
using namespace std;

struct TreeNode
{
public:
	TKey Key;
	TValue Value;
	TreeNode* pLeft;
	TreeNode* pRight;
	int Balance;
	virtual void Print(ostream& os) { os << Key << " " << Value; }
	
	TreeNode(TKey _key = -1, TValue _val = "", TreeNode* _pLeft = NULL,
		TreeNode* _pRight = NULL)
	{
		Key = _key;
		Value = _val;
		pRight = _pRight;
		pLeft = _pLeft;
		Balance = 0;
	}
	virtual int operator==(const TreeNode& tr) { return Key == tr.Key; }
	virtual int operator!=(const TreeNode& tr) { return Key != tr.Key; }
	virtual int operator>(const TreeNode& tr) { return Key < tr.Key; }
	virtual int operator<(const TreeNode& tr) { return Key > tr.Key; }
	virtual int operator>=(const TreeNode& tr) { return Key <= tr.Key; }
	virtual int operator<=(const TreeNode& tr) { return Key >= tr.Key; }
	friend class TreeTable;

};





class TreeTable : public Table
{
protected:
	TreeNode* pRoot;
	TreeNode* pCurr;
	TreeNode* pPrev;
	int CurrPos;
	int Level;
	stack<TreeNode*> stack;

	

public:
	TreeTable() : Table()
	{
		CurrPos = 0;
		Level = 0;
		pRoot = NULL;
		pCurr = NULL;
		pPrev = NULL;
	}
	~TreeTable()
	{
		DelRec(pRoot);
	}
	void DelRec(TreeNode* pD);
	void PrintRec(ostream& os, TreeNode* tmp, int level);

	virtual bool IsFull() const;

	bool FindRecord(TKey);
	bool InsRecord(Record);
	bool DelRecord(TKey);

	TKey GetKey() const;
	TValue GetValue() const;
	const Record& GetCurrentRecord() const override;
	void Reset();
	bool IsEnd() const;
	void GoNext();

	void PrintRec(TreeNode* pNode);
	void Print(std::ostream& os);

};