//
// Created by zhangweijiqn on 2020/10/28.
//

#ifndef PROGRAMMING_SORT_H
#define PROGRAMMING_SORT_H

#include<iostream>
using namespace std;

void printArr(int arr[], int count) {
    cout<<endl;
    for(int i=0;i<count;++i){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

void swap(int arr[], int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

#endif //PROGRAMMING_SORT_H
