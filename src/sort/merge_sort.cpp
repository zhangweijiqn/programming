//
// Created by zhangweijiqn on 2020/11/1.
//

#include<iostream>
#include "sort.h"
using namespace std;

void merge(int a[], int r[], int start, int end) {
    int mid = (start + end) / 2;
    int index=start,i=start,j=mid+1;
    while(i<=mid&&j<=end){
        if(a[i]>a[j]){
            r[index++] = a[j++];
        }else{
            r[index++] = a[i++];
        }
    }
    while(i<=mid)r[index++]=a[i++];
    while(j<=end)r[index++]=a[j++];
    for (index = start; index <= end; index++) a[index] = r[index];
}

void mergeSortRecursive(int a[], int r[], int start, int end) {
    if(a == nullptr || start >= end) return;
    int mid = (start + end) / 2;
    mergeSortRecursive(a, r, start, mid);
    mergeSortRecursive(a, r, mid+1, end);
    merge(a, r, start, end);
}

void mergeSort(int a[], int n){
    int r[n];           // 注意需要借助一个额外的数组进行两个有序序列的merge，定义在最外层传入
    mergeSortRecursive(a, r, 0, n-1);
}

int main(){
    int a[] = {5,3,2,6,1,7,0,9};
    printArr(a,8);
    mergeSort(a,8);
    printArr(a,8);
}