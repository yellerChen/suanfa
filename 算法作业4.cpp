//
//  main.cpp
//  算法作业4
//
//  Created by 陈以勒 on 2021/3/29.
//  Copyright © 2021 陈以勒. All rights reserved.
//

#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX_SIZE = 10;
const int STRAT = 1;
typedef struct {
    int num;
}element;

void merge(element a[], int left, int middle, int right){
    int i = left;
    int j = middle + 1;
    int index = 0;
    element* flag = (element *)malloc(sizeof(int) * MAX_SIZE);
    while(i <= middle && j <= right){
        if(a[i].num < a[j].num)
            flag[index++].num = a[i++].num;
        else
            flag[index++].num = a[j++].num;
    }
    while(i <= middle){
        flag[index++].num = a[i++].num;
    }
    while(j <= right){
        flag[index++].num = a[j++].num;
    }
    for (int q = left; q <= right; q++) {
            a[q].num = flag[q - left].num;
        }
}

void merge_sort(element a[], int left, int right){
    if(left >= right)return;
    int middle = (left + right) / 2;
    merge_sort(a, left, middle);
    merge_sort(a, middle + 1, right);
    merge(a, left, middle, right);
}
int main(){
    element a[MAX_SIZE + 1];
    srand(time(NULL));
    for(int i = 1; i <= MAX_SIZE; i++){
        a[i].num = rand() / 100;
    }
    cout << "初始数组：";
    for(int i = 1; i <= MAX_SIZE; i++)
        cout << a[i].num << " ";
    cout << endl;
    merge_sort(a, STRAT, MAX_SIZE);
    cout << "二分归并排序后的数组：";
    for(int i = 1; i <= MAX_SIZE; i++)
        cout << a[i].num << " ";
    cout << endl;
    
}
