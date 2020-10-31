/*
* Created by zhangweijiqn on 2020/10/28.
 *
 * 和 题目99 类型相同，都是要深入理解题意。
 *
 * 题目：给定一个非空二叉树，返回其最大路径和。本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 思路：深入理解题意，考虑实现一个简化的函数 maxGain(node)，该函数计算二叉树中的一个节点的最大贡献值，具体而言，就是在以该节点为根节点的子树中寻找以该节点为起点的一条路径，使得该路径上的节点值之和最大。
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

int maxG = INT_MIN;

int maxGain(TreeNode* root) {
    if(root->left == nullptr && root->right == nullptr) {
        return root->val;
    }
    int leftPathSumtravel = max(maxGain(root->left), 0);
    int rightPathSumtravel = max(maxGain(root->right), 0);
    int maxGain = root->val + leftPathSumtravel + rightPathSumtravel;
    maxG = max(maxG, maxGain);
    return root->val + max(leftPathSumtravel, rightPathSumtravel);      // 当前节点的最大贡献值
}

int maxPathSum(TreeNode* root) {
    return maxGain(root);
}

