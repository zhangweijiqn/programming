//
// Created by zhangweijiqn on 2020/10/28.
//

#include "sort.h"
using namespace std;

void bubbleSort(int arr[], int count){
    if(arr == nullptr || count == 0) {
        return;
    }
    int tmp;
    for(int i=0;i<count;++i) {
        for(int j=i+1; j<count; ++j){
            if(arr[i]>arr[j]){
                swap(arr, i, j);
            }
        }
    }
}

int main(){
    int a[] = {5,3,2,6,1,7,0,9};
    printArr(a,8);
    bubbleSort(a,8);
    printArr(a,8);
}


