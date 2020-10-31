//
// Created by zhangweijiqn on 2020/10/29.'
// 时间复杂度 O(n^2)
//

#include<iostream>
#include "sort.h"
using namespace std;

void insertSort(int arr[], int n) {
    int tmp, i, j;
    for(i=1; i<n;++i) {
        tmp = arr[i];
        for(j=i-1;j>=0;--j) {
            if(tmp < arr[j] ) {
               arr[j+1] = arr[j];
            } else{
                // arr[j+1] = tmp 写在这里执行总是不对，问题在哪？
                break;
            }
        }
        arr[j+1] = tmp;
    }
}

int main() {
    int arr[] = {5,3,2,6,1,7,0,9};
    printArr(arr,8);
    insertSort(arr, 8);
    printArr(arr,8);
}