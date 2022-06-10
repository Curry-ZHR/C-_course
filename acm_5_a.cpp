#include<iostream>
#include<string.h>
using namespace std;
const int maxn =100000+5;
//利用链表来实现字符位置的改变
int cur,last;

/*
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
*/


int main()
{
    char str[maxn];
    int next[maxn];   //str先进行+1操作 再开始输入 说明字符串第一个元素从下标1开始
    while(scanf("%s",str+1)==1) //EOF通过ctrl+Z 再按回车表示文件末尾
    {   
        cur=last=0;     //当前下标和上一个下标
        next[0]=0;      //next[0]先置0 字符串从下标1开始 如果碰到0则表示字符串结束
        int len=strlen(str+1);
        for(int i=1;i<=len;i++)     //用两个数组来当链表 很巧
        {
            if(str[i]=='[')
            {
                cur=0;
            }
            else if(str[i]==']')    //坏字符结束
            {
                cur=last;
            }
            else{
                next[i]=next[cur];
                next[cur]=i;
                if(cur==last)   
                    last=i;
                cur=i;      //移动cur光标 当前光标要改变
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