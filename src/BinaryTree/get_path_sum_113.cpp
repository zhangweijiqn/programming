/*
 Created by zhangweijiqn on 2020/10/20.
 * 题目：给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 思路：
 *      方法一：深度优先搜索：第一个想到的是递归，由于输出的是path，相当于递归的过程中要将path都保存下来，最终保存满足条件的
 *      方法二：广度优先搜索：遍历这棵树。当我们遍历到叶子节点，且此时路径和恰为目标和时，我们就找到了一条满足条件的路径。
 *             主要问题是输出path：为了节省空间，我们使用哈希表记录树中的每一个节点的父节点。每次找到一个满足条件的节点，我们就从该节点出发不断向父节点迭代，即可还原出从根节点到当前节点的路径。
 * 时间复杂度：O(n^2)
*/

#include<iostream>
#include <queue>
#include<unordered_map>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<int> > ret;

    void dfs(TreeNode* root, int sum, vector<int>& path) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            ret.push_back(path);
        }
        dfs(root->left, sum, path);
        dfs(root->right, sum, path);
        //path.pop_back();      // 也可以将path定义到 ret 级别，但每次需要执行此步骤
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root, sum, path);
        return ret;
    }
};

class Solution2 {
public:
    vector<vector<int>> ret;
    unordered_map<TreeNode*, TreeNode*> parent;

    void getPath(TreeNode* node) {
        vector<int> tmp;
        while (node != nullptr) {
            tmp.emplace_back(node->val);
            node = parent[node];
        }
        reverse(tmp.begin(), tmp.end());
        ret.emplace_back(tmp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return ret;
        }

        queue<TreeNode*> que_node;
        queue<int> que_sum;
        que_node.emplace(root);
        que_sum.emplace(0);

        while (!que_node.empty()) {
            TreeNode* node = que_node.front();
            que_node.pop();
            int rec = que_sum.front() + node->val;
            que_sum.pop();

            if (node->left == nullptr && node->right == nullptr) {
                if (rec == sum) {
                    getPath(node);
                }
            } else {
                if (node->left != nullptr) {
                    parent[node->left] = node;
                    que_node.emplace(node->left);
                    que_sum.emplace(rec);
                }
                if (node->right != nullptr) {
                    parent[node->right] = node;
                    que_node.emplace(node->right);
                    que_sum.emplace(rec);
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int> > r = s->pathSum(CreatTree(),7);
    if(r.size()==0) {
        cout<<"not found!"<<endl;
    } else {
        cout<<"found!"<<endl;
    }
}