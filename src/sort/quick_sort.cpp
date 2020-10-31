//
// Created by zhangweijiqn on 2020/10/28.
//

#include "sort.h"
using namespace std;

void quickSort(int arr[], int start, int end){
    if(arr == nullptr || start >= end) return;
    int i=start, j=end, tmp = arr[start];
    while (i < j) {
        while(arr[j]>tmp && start <j)j--;   // 先看右
        if (i < j) {
            arr[i++] = arr[j];
        }
        while(arr[i]<tmp && i <end)i++;
        if (i<j) {
            arr[j--]=arr[i];
        }
    }
    arr[i] = tmp;
    quickSort(arr,start,i-1);
    quickSort(arr,i+1,end);
}

int main(){
    int a[] = {5,3,2,6,1,7,0,9};
    printArr(a,8);
    quickSort(a,0,7);
    printArr(a,8);
}