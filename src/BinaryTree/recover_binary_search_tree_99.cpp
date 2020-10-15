/* Created by zhangweijiqn on 2020/10/14.
 *  题目：二叉搜索树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
 *  思路：需要考虑两个节点被错误地交换后对原二叉搜索树造成了什么影响。对于二叉搜索树，我们知道如果对其进行中序遍历，得到的值序列是递增有序的，而如果我们错误地交换了两个节点，等价于在这个值序列中交换了两个值，破坏了值序列的递增性。
 *      如果有两个，我们记为 i 和 j（i<j 且 a_i>a_{i+1} && a_j>a_{j+1}），那么对应被错误交换的节点即为 a_i 对应的节点和 a_{j+1}对应的节点
 *  方法一：显式中序遍历，开辟一个新数组 nums 来记录中序遍历得到的值序列，然后线性遍历找到两个位置 i 和 j，并重新遍历原二叉搜索树修改对应节点的值完成修复。
 *  方法二（推荐）：隐式中序遍历，由于我们只关心中序遍历的值序列中每个相邻的位置的大小关系是否满足条件，且错误交换后最多两个位置不满足条件，因此在中序遍历的过程我们只需要维护当前中序遍历到的最后一个节点 \textit{pred}pred，然后在遍历到下一个节点的时候，看两个节点的值是否满足前者小于后者即可，如果不满足说明找到了一个交换的节点，且在找到两次以后就可以终止遍历。
 *
 *  时间复杂度：O(n)，存在O(1) ?
*/

#include <iostream>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;   // 维护遍历到的前一个值，用于和当前值比较

        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pred != nullptr && root->val < pred->val) {
                y = root;
                if (x == nullptr) {
                    x = pred;
                }
                else break;
            }
            pred = root;
            root = root->right;
        }

        swap(x->val, y->val);
    }
};