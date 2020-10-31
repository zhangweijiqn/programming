/*
* Created by zhangweijiqn on 2020/10/28.
 * 题目：给定一个二叉树，原地将它展开为一个单链表（展开的顺序为前序遍历）。
 * 思路：可以借助前序遍历，递归和非递归形式。
 *      1. 递归的情况下，先序遍历，将结果写入list中，再遍历list
 *      2. 非递归情况下，可以直接对指针进行操作
*/

#include <iostream>
#include <stack>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        preorderTravel(root);
    }

    TreeNode* preorderTravel(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode *ptr = root, *pre = root;

        while(ptr != nullptr || !s.empty()) {
            while(ptr!= nullptr) {
                pre->right = ptr;
                pre->left = nullptr;
                if(ptr->right != nullptr) {
                    s.push(ptr);
                }
                ptr = ptr->left;
            }
            if(s.size()!=0){
                ptr = s.top();
                s.pop();
            }
        }
        return root;
    }
};

class Solution2 {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorderTraversal(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = l.at(i - 1), *curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
        if (root != NULL) {
            l.push_back(root);
            preorderTraversal(root->left, l);
            preorderTraversal(root->right, l);
        }
    }
};