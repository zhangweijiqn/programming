//
// Created by zhangweijiqn on 2020/11/1.
//

#include<iostream>
#include"sort.h"
using namespace std;

void selectSort(int a[], int n) {
    int min;
    for(int i=0;i<n;++i){
        min=i;
        for(int j=i+1;j<n;++j){
            if(a[min]>a[j])min=j;
        }
        swap(a, min, i);
    }
}

int main(){
    int a[] = {5,3,2,6,1,7,0,9};
    printArr(a,8);
    selectSort(a,8);
    printArr(a,8);
}