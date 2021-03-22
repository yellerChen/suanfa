//
//  main.cpp
//  算法作业3
//
//  Created by 陈以勒 on 2021/3/22.
//  Copyright © 2021 陈以勒. All rights reserved.
//

#include <iostream>
using namespace std;
const int N = 10;
int T[N] = {2, 4, 5, 7, 8, 9, 13, 16, 24, 33};

//顺序查找
int OrSearch(int x){
    for(int i = 0; i < N; i++){
        if(T[i] == x)
            return i;
    }
    return 0;
}

//二分查找
int BiSearch(int x){
    int left = 0;
    int right = N - 1;
    int flag;
    while(left <= right){
        flag = left + (right - left) / 2;
        if(T[flag] == x)
            return flag;
        else if(T[flag] > x)
            right = flag - 1;
        else
            left = flag + 1;
    }
    return 0;
}

int main() {
    int x;
    cin >> x;
    cout << OrSearch(x) << endl;
    cout << BiSearch(x) << endl;
    return 0;
}
