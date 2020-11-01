/*
 * 计算 n 分位数，要求算法复杂度小于全排列
 *
 * 思路：最简单的是全排列之后，再取分位数，但是不满足时间复杂度要求
 *      注意快排可以用来找 topK 或者 Kth 分位数，只需要在 pivot 的一边寻找。
 *      时间复杂度计算：n + n/2 + n/4 + ... O(2n)级别
 *      分位数 position 计算公式： position = 1+（n-1）*p， p是第几分位数的倒数，比如四分位数 0.25, 0.5, 0.75
 *
 */

#include <iostream>
using namespace std;

class Solution {               // 先排序再取 quantile，排序的过程中也会判断
public:
    int quickSort(int a[], int start, int end, int q){
        if(a == nullptr || start > end) return INT_MIN;
        int tmp = a[start];
        int i=start, j=end;
        while(i < j) {
            while(a[j] > tmp && i<j) --j;
            if(i<j) {
                a[i++] = a[j];
            }
            while(a[i] < tmp && i<j)++i;
            if(i<j) {
                a[j--] = a[i];
            }
        }
        a[i] = tmp;
        if(q==i)return a[i];
        if(q<i) return quickSort(a, start, i-1, q);
        else return quickSort(a, i+1, end, q);
    }

    void getThreeQuantile(int a[], int n) {
        int q1 = n/3, q2 = n*2/3;       // 3 分位数
        int r1 = quickSort(a, 0, n-1, q1);
        int r2 = quickSort(a, 0, n-1, q2);
        cout<<"3-q:"<<r1<<","<<r2<<endl;
    }

    void getHalfQuantile(int a[], int n) {
        int q1 = n/2;                   // 中位数
        int r1 = quickSort(a, 0, n-1, q1);
        cout<<"2-q:"<<r1<<endl;
    }
};

int main() {
    int a[] = {1,2,3,8,9,10,4,5,6,7};   // 假设数组都大于 0

    Solution *s1 = new Solution();
    s1->getHalfQuantile(a, 10);
    s1->getThreeQuantile(a, 10);

    return 0;
}