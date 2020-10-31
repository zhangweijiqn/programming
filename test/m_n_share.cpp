/*
* Created by zhangweijiqn on 2020/10/29.
 * N个苹果分给M个人，有多少种分法
 * N个学生分给M个班，有多少种分法
 * N个人分给M辆车，每辆车最大K个人，M<N<M*K，有多少种分法
 *
 * 思路：递归，这个题有一定难度，不会的话可以换一道
 *
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> result(3);
static int num = 0;
void foo(int n, int m, int p) {     // n是要分几个人，p是分到了第几个位置，m是可以分到几个上，正常情况下会有limit
    if (n == 0) {                   // 所有待分的人已经分完
        for(int i=0;i<result.size();++i){
            cout<<" "<<result[i];
        }
        cout<<endl;
        num = num + 1;
        return;
    }
    for (int i=p; i<m; i++) {
        result[i] = result[i] + 1;  // 先分配一个，其余的递归，递归的过程中可能继续分配
        foo(n-1, m, i);          // 每个 p 位置通过foo递归分配
        result[i] = result[i] - 1;  // 分配完再恢复进行下一轮
    }
}

int main() {
    foo(5, 3, 0);
    cout<<"total count:"<<num<<endl;
}

