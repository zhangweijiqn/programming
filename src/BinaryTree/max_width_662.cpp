/*
* Created by zhangweijiqn on 2020/10/29.
 * 题目：给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。
 * 思路：直观感觉，广度优先搜索的层次遍历，需要注意的是宽度的定义，不是每层的个数，由于使用的是queue，需要记录每个元素的depth，同时还要记录position编号来计算宽度。
 *
*/

#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

struct TreeInfo {
    TreeNode * p;
    int depth;
    int position;
    TreeInfo(TreeNode *p, int depth){
        this->p = p;
        this->depth = depth;
    }
    TreeInfo(TreeNode *p, int depth, int pos){
        this->p = p;
        this->depth = depth;
        this->position = pos;       // 子节点的 pos 按照父节点编号为： 2n, 2n+1，联想堆的定义，也是一棵完全二叉树，并且这样的编号
    }
};

int getTreeWidth(TreeNode *root) {
    queue<TreeInfo *> q;
    int maxWidth = 0, start_pos = 1, end_pos = 1, curDepth = 0;
    TreeInfo *ptr = new TreeInfo(root, curDepth,start_pos);
    q.push(ptr);
    while(ptr != nullptr && !q.empty()) {
        ptr = q.front();
        cout<<ptr->p->val<<" "<<ptr->depth<<" "<<ptr->position<<endl;
        q.pop();
        if (ptr->depth != curDepth) {
            maxWidth = max(end_pos-start_pos + 1, maxWidth);
            curDepth = ptr->depth;
            start_pos = ptr->position;
            end_pos = ptr->position;
        }
        end_pos = ptr->position;
        if (ptr->p->left != nullptr) {
            q.push(new TreeInfo(ptr->p->left, curDepth + 1, 2 * ptr->position));
        }
        if (ptr->p->right != nullptr) {
            q.push(new TreeInfo(ptr->p->right, curDepth + 1, 2 * ptr->position + 1));
        }
    }
    maxWidth = max(end_pos-start_pos +1, maxWidth);
    return maxWidth;
}

int getNormalTreeWidth(TreeNode *root) {
    queue<TreeInfo *> q;
    int maxWidth = 0, curWidth = 1, curDepth = 0;
    TreeInfo *ptr = new TreeInfo(root, curDepth);
    q.push(ptr);
    while(ptr != nullptr && !q.empty()) {
        ptr = q.front();
        cout<<ptr->p->val<<" "<<ptr->depth<<endl;
        q.pop();
        if (ptr->depth != curDepth) {
            maxWidth = max(curWidth, maxWidth);
            curDepth = ptr->depth;
            curWidth = 1;
        } else {
            curWidth += 1;
        }
        if (ptr->p->left != nullptr) {
            q.push(new TreeInfo(ptr->p->left, curDepth + 1));
        }
        if (ptr->p->right != nullptr) {
            q.push(new TreeInfo(ptr->p->right, curDepth + 1));
        }
    }
    maxWidth = max(curWidth, maxWidth);
    return maxWidth;
}

int main() {
    TreeNode *root = CreatTree();
    cout<<"create tree"<<endl;
    int w = getNormalTreeWidth(root);       // 这里的 width 按照每层个数定义
    cout<<"width:"<<w<<endl;

    int w2 = getTreeWidth(root);       // 这里的 width 按照每层宽度定义
    cout<<"width2:"<<w2<<endl;
}