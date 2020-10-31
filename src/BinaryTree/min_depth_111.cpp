/* Created by zhangweijiqn on 2020/10/15.
* 题目：二叉树的最小深度
        * 思路：
*      方法一：递归，DFS遍历，比较简单；
*/
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main() {
    Solution *s = new Solution();
    cout<<s->minDepth(CreatTree())<<endl;

    Solution2 *s2 = new Solution2();
    cout<<s2->minDepth(CreatTree())<<endl;
}