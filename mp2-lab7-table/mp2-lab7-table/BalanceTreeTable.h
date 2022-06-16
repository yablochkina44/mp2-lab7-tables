#pragma once
#include "Record.h"
#include "TreeTable.h"
class BalanceTreeTable : public TreeTable
{
    int LeftBalIns(TreeNode*& p); 
    int RightBalIns(TreeNode*& p); 
    int LeftBalDel(TreeNode*& p);
    int RightBalDel(TreeNode*& p);
    int InsBalance(TreeNode*& p, Record rec);
    int DelBalance(TreeNode*& p, TKey key);
    TreeNode* FindMax(TreeNode* p) const;
public:
    bool InsRecord(Record rec);

};

