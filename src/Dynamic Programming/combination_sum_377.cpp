/*
* Created by zhangweijiqn on 2020/10/31.
 * reference: 背包问题总结：https://leetcode-cn.com/problems/combination-sum-iv/solution/xi-wang-yong-yi-chong-gui-lu-gao-ding-bei-bao-wen-/
 * 题目：给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
  示例： nums = [1, 2, 3]
        target = 4
        所有可能的组合为：
        (1, 1, 1, 1)
        (1, 1, 2)
        (1, 2, 1)
        (1, 3)
        (2, 1, 1)
        (2, 2)
        (3, 1)
        请注意，顺序不同的序列被视作不同的组合。
        因此输出为 7。
    思路：1. 可以通过递归实现，耗时非常大；
        2. 动态规划，状态转义方程：dp[i] = sum{dp[i - num] for num in nums and if i >= num}

*/

#include <iostream>
#include <vector>
using namespace std;

int num = 0;

void recursiveSearch(vector<int>& nums, int target) {
    if(target<0)return;
    if(target==0) {
        num+=1;
        return;
    }
    for(int i=0;i<nums.size();++i){
        recursiveSearch(nums, target-nums[i]);
    }
}

int combinationSum(vector<int>& nums, int target) {
    recursiveSearch(nums, target);
    return num;
}

int combinationSum2(vector<int>& nums, int target) {
    vector<int> dp(nums.size()+1, 0);
    dp[0] = 1;
    for(int i=1;i<=target;++i) {
        for(int j=0;j<nums.size();++j) {
            if(i>=nums[j]) {
                dp[i] += dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}


int main() {
    int a[] =  {1, 2, 3};
    vector<int> nums(a,a + 3);
    int target = 4;
    cout<<combinationSum(nums, target)<<endl;
    cout<<combinationSum2(nums, target)<<endl;
}