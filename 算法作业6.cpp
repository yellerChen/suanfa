//
//  main.cpp
//  算法作业6
//
//  Created by 陈以勒 on 2021/4/19.
//  Copyright © 2021 陈以勒. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAXSIZE 1000

//先用二分归并排序将数组从小到大排序
void merge(int a[], int left, int mid, int right){
    int i,k;
    int *tmp = (int *)malloc((right-left+1)*sizeof(int));
    int left1 = left;
    int left2 = mid;
    int right1 = mid+1;
    int right2 = right;
    for(k = 0; left1 <= left2 && right1 <= right2; k++){
        if(a[left1] <= a[right1])
            tmp[k] = a[left1++];
        else
            tmp[k]=a[right1++];
    }
    
    if(left1 <= left2){
        for(i = left1; i <= left2; i++)
            tmp[k++] = a[i];
    }

    if(right1 <= right2){
        for(i = right1; i <= right2; i++)
            tmp[k++] = a[i];
    }
    for(i = 0; i < right-left+1; i++){
        a[left+i] = tmp[i];
    }
    free(tmp);
    return;
}
void merge_sort(int a[], int left, int right)
{
    int mid = 0;
    if(left < right)
    {
        mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid+1, right);
        merge(a, left, mid, right);
    }
    return;
}

int select(int a[], int left, int right, int k){
    int n = right - left;
    if (n < 5){     //若少于5个不用分组直接二分归并后输出中位数
        merge_sort(a, left, right-1);
        return a[left+k-1];
    }
    int i;
    int s=n / 5;    //5个数一组，共s组
    int *m = new int[s];//中位数数组
    for (i = 0; i < s; i++){
        merge_sort(a, left+i*5, left+i*5+5-1);  //5个分为一组进行排序
        m[i] = a[left+i*5+2];   //每组中位数存入中位数数组m里
    }
    merge_sort(m, 0, i-1);  //将中位数数组进行排序
    int mid = m[i/2];
    int *a1 = new int[n];
    int *a2 = new int[n];
    int *a3 = new int[n];
    int num1 = 0, num2 = 0, num3 = 0;
    for(int i = left; i < right; i++){
        if(a[i] < mid)
            a1[num1++] = a[i];
        else if(a[i] == mid)
            a2[num2++] = a[i];
        else
            a3[num3++] = a[i];
    }
    if(num1 >= k)   //若第k小于num1，说明k值在num1中，继续递归select
        return select(a1, 0, num1, k);
    if (num1+num2 >= k)    //若k在num1和num1+num2之间，k值只可能刚好是mid
        return mid;
    else    //注意，因为前面已经占据了num1+num2个值，所以在mid后面的值中找k值时要减掉num1+num2个数
        return select(a3, 0, num3, k-num1-num2);
}


int main()
{
    int n;
    int k;
    int a[MAXSIZE];
    cout << "输入数组大小：";
    cin >> n;
    cout << "输入数据：";
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "输入所求的第几小元素：";
    cin >> k;
    cout << "第" << k << "小元素：";
    cout << select(a,0,n,k) << endl;
    return 0;
}

