/*
* Created by zhangweijiqn on 2020/10/31.
 * 题目：摆动序列
 *  如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
    例如，[1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3)是正负交替出现的。相反, [1,4,7,2,5]和[1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
    1.给定一个整数序列，返回作为摆动序列的最长子序列的长度。
    2.
    通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。
 * 思路：一维动态规划
*/

#include<iostream>
using namespace std;

int wiggleMaxLength1(int a[], int n) {      //找最长连续序列
    if (a == nullptr || n < 1) return 0;
    if (n<2) return n;

    int dp[n];              // 定义动规数组
    dp[0] = 1;
    dp[1] = 2;
    bool isUp = dp[1] - dp[0] > 0;

    int max = dp[1];        // 记录最大

    for(int i=2;i<n;++i) {
        if((a[i]>a[i-1] && !isUp) || (a[i]<a[i-1] && isUp)){
            dp[i] = dp[i-1] + 1;
        } else {
            dp[i] = 2;
        }
        cout<<i<<" "<<isUp<<" "<<a[i]<<" "<<a[i-1]<<" "<<dp[i]<<endl;

        if(dp[i] > max) max = dp[i];
        isUp = a[i]-a[i-1] > 0;
    }

    return max;
}

int wiggleMaxLength2(int a[], int n) {      //可以删除元素情况下，求最大摆动序列，贪心，easiest
    if (n < 2)
        return n;
    int prevdiff = a[1] - a[0];
    int count = prevdiff != 0 ? 2 : 1;
    for (int i = 2; i < n; i++) {
        int diff = a[i] - a[i - 1];
        if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
            count++;
            prevdiff = diff;
        }
    }
    return count;
}

int wiggleMaxLength3(int nums[], int n) {   //可以删除元素情况下，求最大摆动序列，动规
    if (n < 2)
        return n;
    int up[n];
    int down[n];
    up[0] = down[0] = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            up[i] = down[i - 1] + 1;
            down[i] = down[i - 1];
        } else if (nums[i] < nums[i - 1]) {
            down[i] = up[i - 1] + 1;
            up[i] = up[i - 1];
        } else {
            down[i] = down[i - 1];
            up[i] = up[i - 1];
        }
    }
    return max(down[n - 1], up[n - 1]);
}

int main() {
    int a[] = {1,7,4,9,2,5,8,3};
    cout<<wiggleMaxLength1(a, 8)<<endl;

    int a1[] = {1,4,7,2,5};
    cout<<wiggleMaxLength1(a1, 5)<<endl;

    int a2[] = {1,17,5,10,13,15,10,5,16,8};
    cout<<wiggleMaxLength2(a2, 10)<<endl;
    cout<<wiggleMaxLength3(a2, 10)<<endl;
}
