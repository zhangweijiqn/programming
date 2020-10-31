/*
* Created by zhangweijiqn on 2020/10/31.
 * 题目：给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号+和-。
 *      对于数组中的任意一个整数，你都可以从+或-中选择一个符号添加在前面。返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 思路：1. 递归进行遍历搜索，时间复杂度O(2^N)。
 *      2. 动态规划，状态转义方程：dp[i] = dp[i - num] + dp[i + num]
*/

#include<iostream>
using namespace std;

int num = 0;

int recursiveSearch(int a[], int n, int target, int pos, int r) {
    cout<<pos<<" "<<r<<endl;
    if(pos >= n) return 0;
    if(pos == n-1) {
        if(target == r) {
            return 1;
        } else {
            return 0;
        }
    }
    return recursiveSearch(a, n, target, pos +1, r - a[pos]) + recursiveSearch(a, n, target, pos +1, r + a[pos]);
}

int findTargetSumWays1(int a[], int n, int target) {
    return recursiveSearch(a, 5, target, -1, 0);
}

int main(){
    int a[] = {1, 1, 1, 1, 1};
    cout<<findTargetSumWays1(a, 5, 3)<<endl;
}