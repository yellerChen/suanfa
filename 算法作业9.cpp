//
//  main.cpp
//  算法作业9
//

//LCS算法

//#include<iostream>
//#include<cstring>
//#include<stack>
//#include<algorithm>
//#define MAX 1010
//using namespace std;
//int dp[MAX][MAX];
//int c[MAX][MAX];//存储删除信息 1删除x，2删除y，3删除两个
//
//
//int main()
//{
//    char a[MAX];
//    char b[MAX];
//    char temp[MAX];
//    cout << "===========依次输入两个序列===========" << endl;
//    cin>>a>>b;
//    //获取两条序列长度
//    int la=strlen(a);
//    int lb=strlen(b);
//    memset(dp,0,sizeof(dp));
//    memset(c,0,sizeof(c));
//    for(int i=1; i<=la; i++)
//    {
//        for(int j=1; j<=lb; j++)
//        {
//            if(a[i-1]==b[j-1])
//            {
//                //序列a=序列b时dp+=1，记录子序列长度
//                dp[i][j]=dp[i-1][j-1]+1;
//                c[i][j]=3;
//            }
//            else
//            {
//                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                if(dp[i][j-1]>=dp[i-1][j])
//                    c[i][j]=2;
//                else c[i][j]=1;
//            }
//
//        }
//    }
//    cout<<"===========最长子序列长度为==========="<<dp[la][lb]<<endl;
//    cout<<"=============最长子序列为============" << endl;
//    int m=la,n=lb,i=0;
//    while(m&&n)
//    {
//        if(c[m][n]==1){
//            a[m--]=' ';
//        }
//        else if(c[m][n]==2)
//        {
//            b[n--]=' ';
//        }
//        else
//        {
//            temp[i++]=a[m-1];
//             a[m--]=' ';
//            b[n--]=' ';
//        }
//    }
//    for(int j=i-1;j>=0;j--)
//        if(temp[j]!=' ')
//            cout<<temp[j];
//    cout << endl;
//    return 0;
//}



//背包算法

#include<iostream>
#include <string.h>
using namespace std;
const int MAX = 1000;
int main(){
    int totalweight;
    int num;
    cout << "==========背包问题========" << endl;
    cout << "======输入背包最大载重======" << endl;
    cin >> totalweight;
    cout << "========输入物品个数=======" << endl;
    cin >> num;
    int weight[MAX] = {0};
    int value[MAX] = {0};
    cout << "=====输入商品重量和价值=====" << endl;
    for(int i = 1; i <= num;i++)
        cin >> weight[i] >> value[i];
    int c[MAX][MAX];
    for(int j = 0; j <= totalweight; j++){
        c[0][j] = 0;
    }
    for(int i = 0; i <= num; i++){
        c[i][0] = 0;
    }
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= totalweight; j++){
            if(j < weight[i]){
                c[i][j] = c[i-1][j];
//                cout << "[" << i << "],[" << j << "]:" << c[i][j] << " ";
            }else{
                 c[i][j] = max(c[i-1][j],c[i-1][j-weight[i]]+value[i]);
//                cout << "[" << i << "],[" << j << "]:" << c[i][j];
            }
        }
        cout << endl;
    }
    cout << "=====背包最大价值为=====" << endl;
    cout << c[num][totalweight] << endl;
}

