#include "BalanceTreeTable.h"
int BalanceTreeTable::LeftBalIns(TreeNode*& p)
{
    int res = 0; 
    Efficiency++;
    if (p->Balance == 1)
    {
        p->Balance = 0;
        res = 0;

    }
    else if (p->Balance == 0)
    {
        p->Balance = -1;
        res = 1;
    }
    else
    {
        TreeNode* left = p->pLeft;
        if (left->Balance == -1) // перевес в левом поддереве слева
        {
            p->pLeft = left->pRight;
            left->pRight = p;
            p->Balance = left->Balance = 0;
            p = left;
        }
        else if (left->Balance == 1) // перевес в левом поддереве справа
        {
            TreeNode* right = left->pRight;
            left->pRight = right->pLeft;
            p->pLeft = right->pRight;
            right->pLeft = left;
            right->pRight = p;
            if (right->Balance == -1)
            {
                right->Balance = 0;
                left->Balance = 1;
                p->Balance = 1;
            }
            else
            {
                right->Balance = 1;
                left->Balance = 0;
                p->Balance = 0;
            }
            res = 0;
            p = right;
        }
    }
    return res;
}
int BalanceTreeTable::RightBalIns(TreeNode*& p)
{
    int res = 0;
    Efficiency++;
    if (p->Balance == 0)
    {
        p->Balance = 1;
        res = 1;
    }
    else if (p->Balance == -1)
    {
        p->Balance = 0;
        res = 0;
    }
    else
    {
        TreeNode* right = p->pRight;
        if (right->Balance == 1) // перевес в правом поддереве справа
        {
            p->pRight = right->pLeft;
            right->pLeft = p;
            p->Balance = right->Balance = 0;
            p = right;
        }
        else if (right->Balance == -1) // перевес в правом поддереве слева
        {
            TreeNode* left = right->pLeft;
            right->pLeft = left->pRight;
            p->pRight = left->pLeft;
            left->pRight = right;
            left->pLeft = p;
            if (left->Balance == -1)
            {
                left->Balance = -1;
                right->Balance = 0;
                p->Balance = 0;
            }
            else
            {
                left->Balance = 0;
                right->Balance = -1;
                p->Balance = -1;
            }
            res = 0;
            p = left;
        }
    }
    return res;
}
int BalanceTreeTable::LeftBalDel(TreeNode*& p)
{
    int res = 0; 
    Efficiency++;
    if (p->Balance == 1)
    {
        p->Balance = 0;
        res = 0;

    }
    else if (p->Balance == -1)
    {
        p->Balance = -1;
        res = 1;
    }
    else
    {
        TreeNode* left = p->pLeft;
        if (left->Balance == -1) // перевес в левом поддереве слева
        {
            p->pLeft = left->pRight;
            left->pRight = p;
            p->Balance = left->Balance = 0;
            p = left;
        }
        else if (left->Balance == 1) // перевес в левом поддереве справа
        {
            TreeNode* right = left->pRight;
            left->pRight = right->pLeft;
            p->pLeft = right->pRight;
            right->pLeft = left;
            right->pRight = p;
            if (right->Balance == -1)
            {
                right->Balance = 0;
                left->Balance = 0;
                p->Balance = 1;
            }
            else
            {
                right->Balance = 0;
                left->Balance = -1;
                p->Balance = 0;
            }
            res = 0;
            p = right;
        }
    }
    return res;
}
int BalanceTreeTable::RightBalDel(TreeNode*& p)
{
    int res = 0; 
    Efficiency++;
    if (p->Balance == 1)
    {
        p->Balance = 1;
        res = 1;

    }
    else if (p->Balance == -1)
    {
        p->Balance = 0;
        res = 0;
    }
    else
    {
        TreeNode* right = p->pRight;
        if (right->Balance == -1) // перевес в правом поддереве слева
        {
            p->pRight = right->pLeft;
            right->pLeft = p;
            p->Balance = right->Balance = 0;
            p = right;
        }
        else if (right->Balance == 1) // перевес в правом поддереве справа
        {
            TreeNode* left = right->pRight;
            right->pLeft = left->pRight;
            p->pRight = left->pLeft;
            left->pRight = right;
            left->pLeft = p;
            if (left->Balance == -1)
            {
                left->Balance = 0;
                right->Balance = 0;
                p->Balance = 1;
            }
            else
            {
                left->Balance = 0;
                right->Balance = -1;
                p->Balance = 0;
            }
            res = 0;
            p = left;
        }
    }
    return res;
}
int BalanceTreeTable::InsBalance(TreeNode*& p, Record rec)
{
    int res = 0;
    if (p == NULL)
    {
        p = new TreeNode(rec.Key,rec.Value,NULL,NULL);
        res = 1;
        DataCount++;
    }
    else if (p->Key > rec.Key)
    {
        int tmp = InsBalance(p->pLeft, rec);
        if (tmp == 1)
        {
            res = LeftBalIns(p);
        }
    }
    else
    {
        int tmp = InsBalance(p->pRight, rec);
        if (tmp == 1)
        {
            res = RightBalIns(p);
        }
    }
    return res;
}
int BalanceTreeTable::DelBalance(TreeNode*& p, TKey key)
{
    int res = 0;
    Efficiency++;
    if (p == NULL)
    {
        return res;
    }
    if (key > p->Key)
    {
        int tmp = DelBalance(p->pRight, key);
        if (tmp != 0)
        {
            res = LeftBalDel(p);
        }
    }
    else if (key < p->Key)
    {
        int tmp = DelBalance(p->pLeft, key);
        if (tmp != 0)
        {
            res = RightBalDel(p);
        }
    }
    else
    {
        DataCount;
        if (p->pLeft == NULL && p->pRight == NULL) 
        {
            delete p;
            p = NULL;
            res = -1;
        }
        else if (p->pLeft != NULL && p->pRight == NULL)
        {
            p->Value = p->pLeft->Value;
            p->Key = p->pLeft->Key;
            delete p->pLeft;
            p->pLeft = NULL;
            p->Balance = 0;
            res = -1;
        }
        else if (p->pLeft == NULL && p->pRight != NULL)
        {
            p->Value = p->pRight->Value;
            p->Key = p->pRight->Key;
            delete p->pRight;
            p->pRight = NULL;
            p->Balance = 0;
            res = 1;
        }
        else  // удаление вершины с двумя потомками
        {
            TreeNode* pl = p->pLeft;
            TreeNode* pr = p->pRight;
            TreeNode* pmax = FindMax(pl);
            p->Key = pmax->Key;
            p->Value = pmax->Value;
            int tmp = DelBalance(p->pLeft, pmax->Key);
            if (tmp != 0)
            {
                res = RightBalDel(p->pRight);
            }
        }
        return res;
    }
}
TreeNode* BalanceTreeTable::FindMax(TreeNode* p) const
{
    while (p)
    {
        p = p->pRight;
    }
    return p;
}
bool BalanceTreeTable::InsRecord(Record rec)
{
    if (FindRecord(rec.Key))
    {
        return false;
    }
    InsBalance(pRoot, rec);
    return true;
}
