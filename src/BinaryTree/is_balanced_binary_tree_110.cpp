/*
 * Created by zhangweijiqn on 2020/10/15.
 * 题目：给定一个二叉树，判断它是否是高度平衡的二叉树。本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 思路：1. 应该是个递归问题，需要在递归中计算height，同时判断是否是平衡树
 *      2. 两层递归，外层判断是否平衡树，内层求数的高度
*/

#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;          //巧妙的地方就在这里，正常的递归用来计算左右子树的最大深度，返回值里没办法带有是否非平衡二叉树，这里用 -1 标识
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;       // 时间复杂度O(n)
    }
};

class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(height(root->left), height(root->right)) + 1;
        }
    }
    // 总的时间复杂度达到 O(n2)
};
