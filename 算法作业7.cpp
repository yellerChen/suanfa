//
//  main.cpp
//  算法作业7
//
//  Created by 陈以勒 on 2021/5/31.
//  Copyright © 2021 陈以勒. All rights reserved.
//

#include <iostream>
using namespace std;

const int M = 5;
const int N = 6;
//总收益
int F[M][N]={0};
//投资x元每个项目的获益情况,横坐标为项目，纵坐标为x元
int f[M][N] = {0, 0, 0, 0, 0, 0,
               0,11,12,13,14,15,
               0, 0, 5,10,15,20,
               0, 2,10,30,32,40,
               0,20,21,22,23,24};

int max(int F[M][N], int f[M][N], int number, int money){
    for (int i = 1; i <= number; i++){
        for (int j = 0; j <= money; j++){
            F[i][j] = 0;
            for (int k = 0; k <= j; k++){
                if (F[i][j] < f[i][k] + F[i-1][j-k])
                    F[i][j] = f[i][k] + F[i-1][j-k];
            }
        }
    }
    return F[number][money];
}

int main()
{
    cout<<"最大利益为："<<max(F, f, 4, 5)<<endl;
    return 0;
}
