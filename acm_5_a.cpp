#include<iostream>
#include<string.h>
using namespace std;
const int maxn =100000+5;
//����������ʵ���ַ�λ�õĸı�
int cur,last;

/*
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
*/


int main()
{
    char str[maxn];
    int next[maxn];   //str�Ƚ���+1���� �ٿ�ʼ���� ˵���ַ�����һ��Ԫ�ش��±�1��ʼ
    while(scanf("%s",str+1)==1) //EOFͨ��ctrl+Z �ٰ��س���ʾ�ļ�ĩβ
    {   
        cur=last=0;     //��ǰ�±����һ���±�
        next[0]=0;      //next[0]����0 �ַ������±�1��ʼ �������0���ʾ�ַ�������
        int len=strlen(str+1);
        for(int i=1;i<=len;i++)     //������������������ ����
        {
            if(str[i]=='[')
            {
                cur=0;
            }
            else if(str[i]==']')    //���ַ�����
            {
                cur=last;
            }
            else{
                next[i]=next[cur];
                next[cur]=i;
                if(cur==last)   
                    last=i;
                cur=i;      //�ƶ�cur��� ��ǰ���Ҫ�ı�
            }
        }
        for(int i=next[0];i!=0;i=next[i])
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}