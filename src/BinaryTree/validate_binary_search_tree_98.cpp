/* Created by zhangweijiqn on 2020/10/14.
 * 题目：给定一个二叉树，判断其是否是一个有效的二叉搜索树。
        假设一个二叉搜索树具有如下特征：
        节点的左子树只包含小于当前节点的数。
        节点的右子树只包含大于当前节点的数。
        所有左子树和右子树自身必须也是二叉搜索树。
 *
 * 思路：
 *      方法一: 递归，设计一个递归函数 helper(root, lower, upper) 来递归判断，函数表示考虑以 root 为根的子树，判断子树中所有节点的值是否都在 (l,r)的范围内（注意是开区间）。如果 root 节点的值 val 不在 (l,r) 的范围内说明不满足条件直接返回，否则我们要继续递归调用检查它的左右子树是否满足，如果都满足才说明这是一棵二叉搜索树。
 *      方法二：中序遍历，二叉搜索树「中序遍历」得到的值构成的序列一定是升序的，这启示我们在中序遍历的时候实时检查当前节点的值是否大于前一个中序遍历到的节点的值即可。
*/
#include <iostream>
#include <stack>
#include "TreeNode.h"
using namespace std;

struct Result {
    bool isBST;
    long min;
    long max;
    Result(bool isBST, long min, long max):isBST(isBST),min(min),max(max){}
};

class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {     // 递归要带的两个参数，lower 和 upper用于比较
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {       // 递归遍历
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST2(TreeNode* root) {      // 中序遍历，注意只能非递归的实现方式，否则就是上面的递归遍历
        stack<TreeNode*> stack;
        long inorder = (long)LONG_MIN;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};

int main(){
//    TreeNode *root = CreatTree();
    TreeNode *root = CreatBinarySearchTree();
    Solution *s = new Solution();
    cout<<s->isValidBST(root)<<endl;
    cout<<s->isValidBST2(root)<<endl;
}