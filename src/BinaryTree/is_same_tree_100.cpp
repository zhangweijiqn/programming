/*
     Created by zhangweijiqn on 2020/10/15.
     题目：给定两个二叉树，编写一个函数来检验它们是否相同。如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
     思路：
            深度优先方式：主要考察二叉树的遍历，递归和非递归均可；
            广度优先方式：层序遍历，使用两个queue，在queue操作的过程中进行判断
     时间复杂度：O(n)，每个节点只遍历一次
*/
#include<iostream>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {         // 注意空指针的情况处理
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val != q->val) {
            return false;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};