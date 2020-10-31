/*
 * 计算 n 分位数，要求算法复杂度小于全排列
 *
 * 思路：最简单的是全排列之后，再取分位数，但是不满足时间复杂度要求
 *      注意快排可以用来找 topK，只需要在 pivot 的一边寻找。
 *
 *      分位数 position 计算公式： position = 1+（n-1）*p， p是第几分位数的倒数，比如四分位数 0.25, 0.5, 0.75
 *
 */

#include <iostream>
using namespace std;

class Solution1 {               // 先排序再取 quantile，排序的过程中也会判断
public:
    int m;
    int n;
    void quickSort(int a[], int start, int end, int q1, int q2){
        if(a == nullptr || start >= end) return;
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
        if(i==q1) {
            m=a[i];
        }
        if(i==q2){
            n=a[i];
        }
//    if(m>0 && n>0) return;
        quickSort(a, start, i-1, q1, q2);
        quickSort(a, i+1, end, q1, q2);
    }

    void getQuantile(int a[], int n) {
        int q1 = n/3, q2 = n*2/3;       // 3 分位数
        quickSort(a, 0, n-1, q1, q2);
        if (m==0) {
            m = a[q1];
        }
        if (n==0) {
            n=a[q2];
        }
    }
};



int main() {
    int a[] = {1,2,3,8,9,10,4,5,6,7};   // 假设数组都大于 0

    Solution1 *s1 = new Solution1();
    s1->getQuantile(a, 10);
    cout<<s1->m<<" "<<s1->n<<endl;


    return 0;
}