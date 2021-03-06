/*
* Created by zhangweijiqn on 2020/10/31.
 * 题目：给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
    你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
    字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
    思路：1. 循环遍历
        2. 动态规划
*/

#include<iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    if(t.empty() || s.empty()) return false;

    for(int i=0,j=0;i<s.length(),j<t.length();++j){         // 双指针法
        if(s[i] == t[j]) {
            if(i == s.length()-1) {
                return true;
            }
            ++i;
        }
    }
    return false;
}

int main() {
    string s = "abc";
    string t = "ahbgdc";
    cout<<isSubsequence(s,t)<<endl;
}