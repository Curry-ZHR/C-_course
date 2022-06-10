#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
//存疑
//动态规划背包问题
/*
0.20
2.00
0.00
*/
/*
0.20 有4种方法补上
2.00 有293种方法补上
*/
long long dp[33000];
int a[]={5,10,20,50,100,200,500,1000,2000,5000,10000};

int main()
{
    dp[0]=1;
    for(int i=0;i<11;i++)
    {
        for(int j=5;j<=30000;j+=5)
        {   //填表过程
            if(j>=a[i])
                dp[j]+=dp[j-a[i]];
        }
    }
        int a,b;
        //最后填表的结果就是总的方法数
        while(~scanf("%d.%d",&a,&b))
        {
            long long x=a*100+b;
            if(x==0)
                break;
            printf("%6.2lf%17lld\n",(double)x/100.0,dp[x]);
        }
    
    return 0;
}