#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void sort(char *p,int n,int L) 
{
    int i,j;char c;
	for(i=n;i<L;i++)
	{
		for(j=n;j<L-i+n;j++)
		{
			if(p[j]>p[j+1])
			{
			  c = p[j];
			  p[j] =p[j+1];
			  p[j+1]=c;
			}
		}
	}
}



int main()
{
    char str[55];
    char tmp;
    int L,i,j;
    while(1)
    {
        cin>>str;
        if(str[0]=='#')
            break;
        L=strlen(str)-1;
        for(i=L;i>0;i--)        //�ж��ַ����Ƿ�Ϊ��ȫ����
        {
            if(str[i]>str[i-1])
                break;
        }
        if(i==0)
            cout<<"No Successor"<<endl;
        else if(i==L)       //�����һλ���ֵ�һ����С�ַ�
        {
            tmp=str[i];
            str[i]=str[i-1];
            str[i-1]=tmp;
            cout<<str<<endl;
        }
        else{
            for(j=L;j>=i;j--)           //��i����β����Ѱ����ӽ�i-1�Ľϴ�������ɽ���
            {
                if(str[j]>str[i-1])
                    break;
            }
            tmp=str[i-1];
            str[i-1]=str[j];
            str[j]=tmp;

            sort(str,i,L);
            cout<<str<<endl;
        }
    }

    return 0;
}