//
//  main.cpp
//  算法期末大作业
//
//  Created by 陈以勒 on 2021/6/19.
//  Copyright © 2021 陈以勒. All rights reserved.
//

#include<iostream>
#include <string.h>
using namespace std;
const int MAX = 1000;
int main(){
    int sumTime = 0;
    int middleTime;
    int totalweight;
    int surplusTime;
    int num;
    cout << "==========产品加工问题========" << endl;
    cout << "==========输入加工个数========" << endl;
    cin >> num;
    int time[MAX] = {0};
    cout << "=======输入加工品加工时长======" << endl;
    for(int i = 1; i <= num;i++){
        cin >> time[i];
        sumTime += time[i];
    }
    middleTime = sumTime / 2;
    totalweight = middleTime;
    int ans[MAX][MAX];
    for(int j = 0; j <= middleTime; j++){
        ans[0][j] = 0;
    }
    for(int i = 0; i <= num; i++){
        ans[i][0] = 0;
    }
    cout << "机器1加工过程:" << endl;
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= middleTime; j++){
            if(time[i] > j){
                ans[i][j] = ans[i-1][j];
                cout << "[" << i << "][" << j << "]:" << ans[i][j] << " ";
            }else{
                 ans[i][j] = max(ans[i-1][j],ans[i-1][j-time[i]]+time[i]);
                cout << "[" << i << "][" << j << "]:" << ans[i][j] << " ";
            }
        }
        cout << endl;
    }
    surplusTime = sumTime -ans[num][totalweight];
    cout << "=========加工最短时间为=======" << endl;
    cout << max(surplusTime, ans[num][totalweight]) << endl;
}

