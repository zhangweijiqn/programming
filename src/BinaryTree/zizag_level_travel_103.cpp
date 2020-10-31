/*
 Created by zhangweijiqn on 2020/10/15.
 * 题目：给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 *
 * 思路：最直观的方法是 BFS，逐层遍历树。BFS 在每层的默认顺序是从左到右，因此需要调整 BFS 算法以生成锯齿序列。
 *      正常使用queue层序遍历，每一层都是从左到右，这里偶数层将从左到右的元素不断insert到临时结果的front，但该种情况下不知道level分隔在哪；可以使用DFS，递归的形式下知道level，然后将结按上述顺序写入 results[level]，但这种效率很低。
 *      如果需要 FIFO （先进先出）的顺序，则将新元素添加到队列尾部，后插入的元素就可以排在后面。如果需要 FILO （先进后出）的顺序，则将新元素添加到队列首部，后插入的元素就可以排在前面。
        最关键的是使用「双端队列」遍历，可以在队列的任一端插入元素。

 *
 * 补充：deque （double-ended queue，双端队列）是一种具有队列和栈的性质的数据结构。双端队列中的元素可以从两端弹出，其限定插入和删除操作在表的两端进行。
*/
#include <iostream>
#include <vector>
#include <deque>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == nullptr) return res;
        deque<TreeNode*> q;         // deque 双端队列(double-ended queue)，效率比 vector 头部insert效率高很多
        TreeNode* cur;
        q.push_front(root);
        bool odd = true;//此时是奇数行
        while(!q.empty()){
            vector<int> layer;      // 存储一层的元素
            for(int i=q.size()-1; i>=0; --i){
                if(odd){    //奇数行 从前往后取节点 孩子自左向右压入双端队列尾，正常的层次遍历 queue操作
                    cur = q.front();
                    q.pop_front();
                    layer.push_back(cur->val);
                    if(cur->left) q.push_back(cur->left);
                    if(cur->right) q.push_back(cur->right);
                }
                else{       //偶数行 从后往前取节点 孩子自右向左压入双端队列头，与正常的层次遍历 queue 操作都相反
                    cur = q.back();
                    q.pop_back();
                    layer.push_back(cur->val);
                    if(cur->right) q.push_front(cur->right);
                    if(cur->left) q.push_front(cur->left);
                }
            }
            odd = !odd;
            res.push_back(layer);
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    auto r = s->zigzagLevelOrder(CreatTree());
    for(int i=0;i<r.size();++i){
        for(int j=0;j<r[i].size();++j){
            cout<<" "<<r[i][j];
        }
        cout<<endl;
    }
}