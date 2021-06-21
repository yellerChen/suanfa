//
//  main.cpp
//  算法作业12
//
//  Created by 陈以勒 on 2021/5/31.
//  Copyright © 2021 陈以勒. All rights reserved.
//

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool f[105][105];//存两个点是否连通
int color[105];//存每个点的颜色
int num=0;//num用来存储答案数
int n,k,m;
bool check(int sum){
    for(int i=1;i<=sum;i++){
        if(f[i][sum]==true&&color[i]==color[sum]){//当两个图连通时且颜色一样就冲突
            return false;
        }
    }
    return true;
}
void dfs(int s){
    if(s>n){
        num++;//搜到n+1个点，也就是走完了
        return;
    }
    for(int i=1;i<=m;i++){
        color[s]=i;//把颜色存下来
        if(check(s)==true){
            dfs(s+1);
        }else{
            color[s]=0;//如果冲突则重新打回0
        }
    }
}
int main(){
    cout << "请依次输入图的顶点数、边数、颜色数：";
    cin>>n>>k>>m;
    cout << "请输入图的边连接情况：";
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        //因为是无向图所以两边都要true
        f[x][y]=true;
        f[y][x]=true;
    }
    memset(color,0,sizeof(color));
    dfs(1);
    cout<<num<<endl;
    return 0;
}
