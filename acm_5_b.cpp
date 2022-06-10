#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

const int maxd=20;      //最大不超过20层


int s[1<<maxd];            //最大结点数组
int main()
{
    int D,I;
    int l,flag=0;
    cin>>l;
    while(scanf("%d%d",&D,&I)==2 && flag<l)
    {
        flag++;
        if(D==-1)
            break;
        memset(s,0,sizeof(s));      //全部置零
        int k;
        int n=(1<<D)-1;     //n为最大结点编号

        for(int i=0;i<I;i++)
        {
            k=1;
            while(1)
            {
                s[k]=!s[k];
                k=s[k]?(k*2):(k*2+1);
                if(k>n)
                    break;      //如果k超界则结束循环 开始下一次循环
            }
        }
        cout<<(k/2)<<endl;          //双重循环结束之后 求最后一个k的值
    }
    return 0;
}



