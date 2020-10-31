/*
 * Created by zhangweijiqn on 2020/10/15.
 * 题目：给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 思路：二叉树层次遍历，然后将每层结果插入到vector结果的头部
*/

#include<iostream>
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto levelOrder = vector<vector<int>>();
        if (!root) {
            return levelOrder;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto level = vector<int>();
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            levelOrder.push_back(level);
        }
        reverse(levelOrder.begin(), levelOrder.end());
        return levelOrder;
    }
};