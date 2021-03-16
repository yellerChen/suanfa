//
//  main.cpp
//  算法作业2
//
//  Created by 陈以勒 on 2021/3/15.
//  Copyright © 2021 陈以勒. All rights reserved.
//


#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
int k, i, j;

//Floyd算法
const int N = 4;
int map[N][N] = {
                    {  0,  2,  6,  4},
                    {INF,  0,  3,INF},
                    {  7,INF,  0,  1},
                    {  5,INF, 12,  0}
};

void Floyd(){
    for(k = 0; k < N; k++){
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(map[i][j] < 0x3f3f3f3f)
                cout << map[i][j] << " ";
            else
                cout << "# ";
        }
        cout << endl;
    }
}


//Dijkstra算法
const int n = 8;
int d[n][n] = {
                {  0,  1,INF,INF,INF,INF,INF,INF},
                {INF,  0,INF,  2,INF,INF,INF,INF},
                {  2,INF,  0,INF,INF,INF,INF,INF},
                {INF,INF,  1,  0,INF,  8,INF,INF},
                {INF,INF,INF,  2,  0,INF,  2,INF},
                {INF,INF,INF,INF,  2,  0,INF,INF},
                {INF,INF,INF,INF,INF,  3,  0,  3},
                {INF,INF,INF,INF,INF,  2,INF,  0}
    
};
int dis[n] = {0};
int vis[n] = {0};
void Dijkstra(int q){
    //把初始点到所有点的距离计入dis中
    for(i = 0; i< n; i++)
        dis[i] = d[q][i];
    //做过中转点的点vis标记为1
    vis[q] = 1;
    //大循环，共循环n次
    for(int t = 0 ; t < n; t++){
        
        int min = INF;
        int flag = 0;
        //找出dis中最短的距离，并标记所在点
        for(i = 0; i < n; i++){
            if(min > dis[i] && !vis[i]){
                flag = i;
                min = dis[i];
            }
        }
        vis[flag] = 1;
        //如果中转点到i点的距离加上原初始点到falg点的距离
        //小于原初始点到i点的距离就改变dis[i]
        for(i = 0; i < n; i++){
            if(dis[i] > dis[flag] + d[flag][i])
                dis[i] = dis[flag] + d[flag][i];
        }
    }
    //题目要求仅显示0点到n-1点的距离
    cout << dis[n - 1] << endl;
}

int main(){

    cout << "Floyd算法结果：" << endl;
    Floyd();
    cout << "Dijkstra算法结果：" << endl;
    Dijkstra(0);
    return 0;
}
