#include<iostream>
#include<string.h>
using namespace std;
const int maxn=100000+5;
typedef struct linklist
{
    char ch;
    struct linklist *pnext;
}link;
link *pnew;
link *phead;

void create()   //����ͷ�ڵ�
{
    phead=(link *)malloc(sizeof(link));
    phead->pnext=NULL;
    phead->ch=' ';
}


//��ͷָ��ָ��[����һ��Ԫ��
int main()
{
    char str[maxn];
    while(scanf("%s",str)==1) //EOFͨ��ctrl+Z �ٰ��س���ʾ�ļ�ĩβ
    {
        int len=strlen(str); 
        for(int i=0;i<len;i++)
        {
            if(str[i]=='[')
            {

            }
            else if(str[i]==']')
            {

            }
            else{
                
            }
        }  
    }
    return 0;
}