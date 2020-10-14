#include<iostream>
#include<stack>
#include<queue>
using namespace std;
/**
 * Definition for a binary tree ptr.
 *
 * PreOrderTravel, InorderTravel, PostOrderTravel
 * 都是从左子树开始一直遍历到叶子节点，区别在于输出节点的顺序
 *
 * stack: empty, pop, push, size, top
 */

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *CreatTree(){
    TreeNode *root = new TreeNode();
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

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
                s.push(ptr);       // 也可以直接存储 ptr->right，下面取的时候用 ptr
            }
            ptr = ptr->left;
        }
        if (!s.empty()) {
            ptr = s.top()->right;
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

int main(){
    TreeNode *root = CreatTree();
    cout<<endl<<"PreOrderTravel:"<<endl;

    // 递归遍历
    PreOrderTravel(root);
    cout<<endl<<"InOrderTravel:"<<endl;
    InOrderTravel(root);
    cout<<endl<<"PostOrderTravel:"<<endl;
    PostOrderTravel(root);
    cout<<endl<<"PreOrderTravel2:"<<endl;

    // 非递归遍历
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
}