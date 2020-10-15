/* Created by zhangweijiqn on 2020/10/14.
* 不同的二叉搜索树 一
 * 题目：给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 *
 * 思路：动态规划
 * 给定一个有序序列 1⋯n，为了构建出一棵二叉搜索树，我们可以遍历每个数字 i，将该数字作为树根，将 1⋯(i−1) 序列作为左子树，将 (i+1)⋯n 序列作为右子树。
 * 接着我们可以按照同样的方式递归构建左子树和右子树。左子树和右子树的组合为二者元素的笛卡尔积，即个数为乘积。
 * 由此可见，原问题可以分解成规模较小的两个子问题，且子问题的解可以复用。因此，我们可以想到使用动态规划来求解本题。
 * G(n): 长度为 n 的序列能构成的不同二叉搜索树的个数。
 * G(n)=
        n
        ∑ G(i−1)⋅G(n−i)
       i=1
 * G(0)=1,G(1)=1v
 *
 * 时间复杂度：时间复杂度 : O(n^2)，其中 n 表示二叉搜索树的节点个数。
*/

#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {          // 外层遍历 i，求 G(2) 到 G(n)，注意只能从小往大求，动态规划思想
            for (int j = 1; j <= i; ++j) {      // 内层遍历 j，按照公式计算每个G(i)
                G[i] += G[j - 1] * G[i - j];    // 看似简单，这两层循环但写出来还是有些难度的
            }
        }
        return G[n];
    }
};

int main() {
    Solution *s = new Solution();
    cout<<s->numTrees(3)<<endl;
}