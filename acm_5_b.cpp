#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

const int maxd=20;      //��󲻳���20��


int s[1<<maxd];            //���������
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
        memset(s,0,sizeof(s));      //ȫ������
        int k;
        int n=(1<<D)-1;     //nΪ�������

        for(int i=0;i<I;i++)
        {
            k=1;
            while(1)
            {
                s[k]=!s[k];
                k=s[k]?(k*2):(k*2+1);
                if(k>n)
                    break;      //���k���������ѭ�� ��ʼ��һ��ѭ��
            }
        }
        cout<<(k/2)<<endl;          //˫��ѭ������֮�� �����һ��k��ֵ
    }
    return 0;
}



