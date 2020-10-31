#include<iostream>
#include<stack>
#include<queue>
#include "TreeNode.h"
using namespace std;
/**
 * Definition for a binary tree ptr.
 *
 * 二叉树的遍历：
 *  （1）深度优先DFS，包括先序、中序、后序遍历，深度非递归实现用 stack ；
 *  （2）广度优先遍历BFS，包括层次遍历，广度非递归实现用 queue；
 *
 * 题目：PreOrderTravel, InorderTravel, PostOrderTravel
 * 思路：三种遍历都可以采用递归形式，代码非常简短；
 *      也可以采用非递归的形式，三种整体逻辑都是从左子树开始一直遍历到叶子节点，区别在于输出节点的顺序（先序遍历提前输出，中序遍历将stack的top输出，后续遍历非叶子节点要遍历两次再进行输出）
 *      这里为了简化，遍历的结果直接print，也可以传递一个vector类型参数，将遍历的结果push到vector中。
 * stack: empty, pop, push, size, top
 *
 *  通用的处理逻辑：
 *  XXXOrderTravel(TreeNode* root){
        std::stack<TreeNode *> s;               // 定义栈
        TreeNode * ptr = root;                  // 定义遍历tree的指针
        while(ptr != nullptr || !s.empty()){    //
            while (ptr != nullptr) {            // 判断 ptr 是否 nullptr
                                //
                                s.push(ptr);                    // 入栈 or 打印，这一步不同遍历操作不同
                                ptr = ptr->left;                // 继续向下
            }
            if (!s.empty()) {
                                ptr = s.top();                  // 取栈顶元素
                                //cout<<" "<<ptr->val;
                                s.pop();
                                ptr = ptr->right;               // 注意这一步的处理，当前节点打印完后指向 right
            }
        }
 *
 */

void PreOrderTravel(TreeNode *root) {
    if(root == nullptr)return;
    cout<<" "<<root->val;
    PreOrderTravel(root->left);
    PreOrderTravel(root->right);
}

void InOrderTravel(TreeNode *root) {
    if(root == nullptr) return;
    InOrderTravel(root->left);
    cout<<" "<<root->val;
    InOrderTravel(root->right);
}

void PostOrderTravel(TreeNode *root){
    if (root==nullptr)return;
    PostOrderTravel(root->left);
    PostOrderTravel(root->right);
    cout<<" "<<root->val;
}

void PreOrderTravel2(TreeNode *root){
    // 先进后出-->stack，先左子树，再遍历栈
    std::stack<TreeNode *> s;
    TreeNode *ptr = root;      //首先声明遍历指针
    while(ptr != nullptr || !s.empty()){
        while(ptr != nullptr) {
            cout<<" "<<ptr->val;            // pre-order root和left直接遍历不需要缓存
            if (ptr->right != nullptr) {    // 只需要将right缓存入栈
                s.push(ptr->right);       // 也可以直接存储 ptr->right，下面取的时候用 ptr
            }
            ptr = ptr->left;
        }
        if (!s.empty()) {
            ptr = s.top();
            s.pop();
        }
    }
}

void InOrderTravel2(TreeNode *root){
    // 先进后出-->stack，先左子树入栈 while ptr + if stack
    // 前序遍历和中序遍历看似实现风格一样，但是实际上前者是在指针迭代时访问结点值，后者是在栈顶访问结点值
    std::stack<TreeNode *> s;
    TreeNode * ptr = root;
    while(ptr != nullptr || !s.empty()){
        while (ptr != nullptr) {
            s.push(ptr);
            ptr = ptr->left;
        }
        if (!s.empty()) {
            ptr = s.top();
            cout<<" "<<ptr->val;
            s.pop();
            ptr = ptr->right;       // 注意这一步的处理，当前节点打印完后指向 right
        }
    }
}

void PostOrderTravel2(TreeNode *root) {
    // 先进后出-->stack，依然先访问左子树，再判断右子树
    // 后序遍历难度稍大一些，不管怎么样遍历，需要记录是否栈内访问过
    struct TreeTmp {
        TreeNode * ptr;
        bool visited;
        TreeTmp(TreeNode * ptr, bool visited):ptr(ptr),visited(visited){}
    };

    std::stack<TreeTmp *> s;
    TreeNode * ptr = root;
    while(ptr != nullptr || !s.empty()){
        while (ptr != nullptr) {
            TreeTmp * tmp = new TreeTmp(ptr,false);
            s.push(tmp);
            ptr = ptr->left;
        }
        if (!s.empty()) {
            TreeTmp * tmp = s.top();
            if (!tmp->visited) {
                ptr = tmp->ptr->right;
                tmp->visited = true;
            } else {
                cout<<" "<<tmp->ptr->val;
                s.pop();
                ptr = nullptr;
            }
        }
    }
}

void PreOrderTravel3(TreeNode *root){
    // 先进后出-->stack，先右进再左进，每个root不需要入栈，先序非递归遍历是最简单的实现
    // 先序root是遍历的时候访问，中序入栈后访问top
    std::stack<TreeNode *> s;
    TreeNode * ptr = root;
    s.push(root);
    while(!s.empty()){
        ptr = s.top();
        cout<<" "<<ptr->val;
        s.pop();
        if(ptr->right != nullptr) s.push(ptr->right);
        if(ptr->left != nullptr) s.push(ptr->left);
    }
}

void LevelTravel(TreeNode *root) {
    // 先进先出，队列实现，比较简单
    TreeNode * ptr;
    std::queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()) {
        ptr = q.front();
        cout<<" "<<ptr->val;
        q.pop();
        if (ptr->left != nullptr) q.push(ptr->left);
        if (ptr->right != nullptr) q.push(ptr->right);
    }
}

void DFSTravel(TreeNode *root, int level) {
    if(root == nullptr) return;
    cout<<" "<<level<<":"<<root->val;
    DFSTravel(root->left, level+1);
    DFSTravel(root->right, level+1);
}

int main(){
    TreeNode *root = CreatTree();
    cout<<endl<<"PreOrderTravel:"<<endl;

    // 递归遍历，时间复杂度O(n)，空间复杂度O(n)
    PreOrderTravel(root);
    cout<<endl<<"InOrderTravel:"<<endl;
    InOrderTravel(root);
    cout<<endl<<"PostOrderTravel:"<<endl;
    PostOrderTravel(root);
    cout<<endl<<"PreOrderTravel2:"<<endl;

    // 非递归遍历，时间复杂度O(n)，空间复杂度O(n)
    PreOrderTravel2(root);
    cout<<endl<<"PreOrderTravel3:"<<endl;
    PreOrderTravel3(root);  // 更简单实现方式
    cout<<endl<<"InOrderTravel2:"<<endl;
    InOrderTravel2(root);
    cout<<endl<<"PostOrderTravel2:"<<endl;
    PostOrderTravel2(root);

    // 层次遍历
    cout<<endl<<"LevelTravel:"<<endl;
    LevelTravel(root);
    cout<<endl;

    // 深度优先遍历，DFS = PreOrder
    DFSTravel(root, 0);
}