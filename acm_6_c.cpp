#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
//����
//��̬�滮��������
/*
0.20
2.00
0.00
*/
/*
0.20 ��4�ַ�������
2.00 ��293�ַ�������
*/
long long dp[33000];
int a[]={5,10,20,50,100,200,500,1000,2000,5000,10000};

int main()
{
    dp[0]=1;
    for(int i=0;i<11;i++)
    {
        for(int j=5;j<=30000;j+=5)
        {   //������
            if(j>=a[i])
                dp[j]+=dp[j-a[i]];
        }
    }
        int a,b;
        //������Ľ�������ܵķ�����
        while(~scanf("%d.%d",&a,&b))
        {
            long long x=a*100+b;
            if(x==0)
                break;
            printf("%6.2lf%17lld\n",(double)x/100.0,dp[x]);
        }
    
    return 0;
}