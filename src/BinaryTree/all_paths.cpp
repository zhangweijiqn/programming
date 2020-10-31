/*
* Created by zhangweijiqn on 2020/10/30.
 * 问题：打印二叉树所有路径
 * 思路：两种方式：
 *          1，深度优先，实现简单；
 *          2，广度优先
*/

#include<iostream>
#include<vector>
#include "TreeNode.h"
using namespace std;

vector<vector<TreeNode *> > paths;

void getBTPaths(TreeNode *root, vector<TreeNode *> path){
    if(root== nullptr)return;
    path.push_back(root);
    if (root->left == nullptr && root->right== nullptr) {
        paths.push_back(path);
        return;
    }
    getBTPaths(root->left, path);
    getBTPaths(root->right, path);
}

void getPaths(TreeNode *root) {
    vector<TreeNode *> path;
    getBTPaths(root, path);
}

int main(){
    TreeNode *root = CreatTree();
    getPaths(root);
    for(int i=0;i<paths.size();++i) {
        for (int j = 0; j < paths[0].size(); ++j) {
            cout<<" "<<paths[i][j]->val;
        }
        cout<<endl;
    }
}
