//
//  main.cpp
//  算法作业10 装载问题（01背包问题）
//
//  Created by 陈以勒 on 2021/5/17.
//  Copyright © 2021 陈以勒. All rights reserved.
//



#include<iostream>
using namespace std;

#define NUM 100
int n; //集装箱数量
int c1,c2; //轮船载重量
int cw; //当前轮船载重量
int r; //剩余集装箱重量
int w[100],bestw,x[100],bestx[100];  //最优载重,最优解

//t从1开始
void BackTrack(int t)
{
    //到达叶子节点
    if(t>n){
        cout << cw << endl;
        if(cw > bestw){
            for(int i = 1; i <= n; i++){
                if(x[i])
                    bestx[i] = i;
                else
                    bestx[i]=x[i];
            }
            bestw = cw;
            return;
        }
    }else{
        r -= w[t]; //更新剩余集装箱重量
        if(cw + w[t] <= c1){ //没有超出载重量，判断是否可以向左
            x[t] = 1;
            cw += w[t];
            cout << "1:" << t << " " << bestw << endl;
            BackTrack(t+1);
            cw -= w[t]; //cw要还原原先的载重，因为还要判断其他路线才能找到最优解
            
        }
        if(cw + r > bestw){ //判断是否可以向右
            cout << "2:" << t << " " << bestw << endl;
            x[t] = 0;
            BackTrack(t+1);
            
        }
        r += w[t]; //还原剩余集装箱重量走其他路线
    }
}

int main(){
    //读入数据；
    cout << "请输入AB船的容量c1、c2:";
    cin  >> c1 >> c2;
    cout << "输入物品的数量:";
    cin >> n;
    cout << "依次输入物品的质量:";
    for(int i = 1; i <= n; i++){//初始化，bestw=0
        cin >> w[i];
        r += w[i];
    }
    //递归回溯
    BackTrack(1);
    if(r-bestw > c2)//无解
        cout << "没有装载方案" << endl;
    else{//有解
        cout << "最有载重为:" << bestw << endl;
        cout << "分别为第" ;
        for(int i = 1; i <= n; i++)
            if(bestx[i])
                cout << bestx[i] << " ";
        cout << "个箱子" << endl;
    }
    return 0;
}
