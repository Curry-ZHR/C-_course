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

void create()   //创建头节点
{
    phead=(link *)malloc(sizeof(link));
    phead->pnext=NULL;
    phead->ch=' ';
}


//让头指针指向[后面一个元素
int main()
{
    char str[maxn];
    while(scanf("%s",str)==1) //EOF通过ctrl+Z 再按回车表示文件末尾
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