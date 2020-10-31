//
// Created by zhangweijiqn on 2020/10/29.
// reference: https://www.cnblogs.com/wanglei5205/p/8733524.html
// 记住 adjust 函数 和 heapSort 两个函数，时间复杂度 NlogN
//

#include <iostream>
#include "sort.h"
using namespace std;
void adjust(int arr[], int n, int index) {
    int left = 2 * index + 1, right = 2 * index + 2, maxIdx = index;
    if(left < n && arr[left] > arr[maxIdx]) maxIdx = left;
    if(right < n && arr[right] > arr[maxIdx]) maxIdx = right;
    if(maxIdx != index) {           // 左右孩子如果发生了和父节点交换，需要继续调整孩子节点
        swap(arr, maxIdx, index);
        adjust(arr, n, maxIdx);     // 关键在这里的递归向下调整 和 下面的从下向上调整
    }
}

void heapSort(int arr[], int n) {
    int i;
    for(i=n/2-1;i>=0;--i) {     // 从下向上调整，构建大根堆
        adjust(arr, n, i);
    }
    // 调整大根堆，输出排序结果
    for(i=n-1;i>=1;--i){
        swap(arr,0,i);
        adjust(arr, i, 0);
    }
}

int main() {
    int arr[] = {8, 1, 14, 3, 21, 5, 7, 10};
    printArr(arr,8);
    heapSort(arr, 8);
    printArr(arr,8);
}
