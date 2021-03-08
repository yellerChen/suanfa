//
//  main.cpp
//  算法作业1
//
//  Created by 陈以勒 on 2021/3/8.
//  Copyright © 2021 陈以勒. All rights reserved.
//


#include<iostream>
using namespace std;

#define X 10000
const int N = 6;
int edge[N] = {0};
bool visit[N];
int graph[N][N] = { { X, 3, 1, X, X, X},  //INF代表两点之间不可达
                    { 3, X, 6, 4, 7, X},
                    { 1, 6, X, 5, X, 1},
                    { X, 4, 5, X, 6, 8},
                    { X, 7, X, 6, X, 2},
                    { X, X, 1, 8, 2, X}
                  };

int prim(int spot){//prim算法
    
    int index = spot;
    int i = 0;
    int j = 0;
    int sum = 0;
    memset(visit,false, sizeof(visit));
    visit[spot] = true;
    
    cout << "最小生成树: ";
    cout << index << " ";
    for(i = 0; i < N; i++){
        edge[i] = graph[index][i];
    }
    for(i = 1; i < N; i++){
        
        int value = X;
        
        for(j = 0; j < N; j++){//找到未访问过的最小权值的点
            if(!visit[j] && edge[j] < value){
                value = edge[j];
                index = j;
            }
        }
        
        visit[index] = true;//标记刚刚找到的点
        cout << index << " ";
        sum += edge[index];// 累加权值
        
        for(j = 0; j < N; j++){//更新数组edge的值
            if(!visit[j] && edge[j] > graph[index][j]){
                edge[j] = graph[index][j];
            }
        }
    }

    cout << endl;
    cout << "最短距离: ";
    return sum;
}
int main(){
    
    cout << prim(0) << endl;
    return 0;
}
