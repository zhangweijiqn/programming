/*
 Created by zhangweijiqn on 2020/10/15.
 * 题目：二叉树的最大深度
 * 思路：
 *      方法一：递归，DFS遍历，比较简单；
 *      方法二：非递归，BFS，二叉树的层次遍历的次数就是最大层数
*/
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while (!Q.empty()) {
            int sz = Q.size();
            while (sz > 0) {
                TreeNode* node = Q.front();Q.pop();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                sz -= 1;
            }
            ans += 1;
        }
        return ans;
    }
};
