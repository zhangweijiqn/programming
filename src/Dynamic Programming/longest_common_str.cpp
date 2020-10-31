/*
* Created by zhangweijiqn on 2020/10/31.
 * 题目：求两个字符串的相似度，最长公共子序列，输出长度和具体字符串。
 * 思路：动态规划，注意最长公共子序列不是唯一的
*/
#include<iostream>
using namespace std;

struct DP {
    string s;
    int l;
    DP(){
        this->s="";
        this->l = 0;
    }
    DP(string s,int l) {
        this->s = s;
        this->l = l;
    }
};

DP getLongestCommonStr(string a, string b){
    if(a.empty() || b.empty()) return DP();

    int i,j;
    DP dp[a.length()+1][b.length()+1];

    for(i=0;i<a.length();++i)dp[i][0]=DP();
    for(j=0;j<b.length();++j)dp[0][j]=DP();

    for(int i=0;i<a.length();++i){
        for(int j=0;j<b.length();++j){
            if(a[i]==b[j]){
                dp[i+1][j+1] = DP(dp[i][j].s + a[i], dp[i][j].l+1);
            } else {
                if(dp[i+1][j].l>dp[i][j+1].l) {
                    dp[i+1][j+1] = DP(dp[i+1][j].s, dp[i+1][j].l);
                } else {
                    dp[i+1][j+1] = DP(dp[i][j+1].s, dp[i][j+1].l);
                }
            }
        }
    }

    // 打印 dp table
    for(int i=1;i<=a.length();++i) {
        for (int j = 1; j <= b.length(); ++j) {
            cout << "\t" << dp[i][j].l<<","<<dp[i][j].s;
        }
        cout << endl;
    }

    return dp[a.length()][b.length()];
}

int main(){
    string a = "13542687";
    string b = "148675";
    DP dp = getLongestCommonStr(a,b);
    cout<<dp.l<<":"<<dp.s<<endl;
}
