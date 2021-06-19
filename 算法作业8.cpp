//
//  main.cpp
//  算法作业8
//

#include<iostream>
using namespace std;
const int MAX=10000000;
int const M=7;

//求最少次数的乘法括号划分方式
void Matrix_Chain(int *p,int Length,int m[][M],int s[][M])
{
    int q,n=Length-1;
    for(int i=1;i<=n;i++) m[i][i]=0;
    for(int l=2;l<=n;l++)     /* 矩阵链的长度 */
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;         /* 等价于 l=j-i+1 */
            m[i][j]=MAX;
            for(int k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}

//递归
void print_optimal_parens(int s[][M],int i,int j)
{
    if(i == j) cout<<"A"<<i;
    else
    {
        cout<<"(";
        print_optimal_parens(s,i,s[i][j]);
        print_optimal_parens(s,s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int num;
    cout << "请输入矩阵个数：" << endl;
    cin >> num;
    int p[num];
    cout << "请给定向量P：" << endl;
    for(int i = 0; i <= num; i++){
       cin >> p[i];
    }
    int m[M][M],s[M][M];
    Matrix_Chain(p,M,m,s);
    cout <<"当num=" << num << "时最优解为: " << endl;
    cout << m[1][num];
    cout<< endl << "括号化方案为：" << endl;
    print_optimal_parens(s,1,6);
    cout << endl;
    return 0;
}
//6
//30,35,15,5,10,20,25
