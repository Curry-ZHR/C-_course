#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;

/*
先对已给出的字符串进行编码
然后再次输入字符，要求输出这个新字符串的编码
*/

int code[8][1<<8];

int readchar()      //直接return可以跳出循环
{
while(1){
    int ch=getchar();
    if(ch!='\n'&&ch!='\r')  //刚开始输入的二进制串是字符串
        return ch;
    }
}
int readint(int n)          //n为读取的位数 把二进制数串转为十进制
{
    int sum=0;
    while(n){
    sum=sum*2+readchar()-'0';
    n--;
    }
    return sum;
}
bool readcode()
{
    memset(code,0,sizeof(code));        //为code数组全部置0
    code[1][0]=readchar();          //读第一个数 如果是0则继续读下去 如果是1则跳过这个数
    for(int i=2;i<=7;i++){
    for(int j=0;j<(1<<i)-1;j++){    //(1<<i)-1是 2的i次方-1 即i位数全为1时
        int ch=getchar();
        if(ch==EOF) return false;   //读到EOF说明程序结束
        if(ch=='\n') return true;   //\n说明程序换行 但是还没有结束
        code[i][j]=ch;
    }
    }
}
int main()
{
while(readcode()){
    while(1){
    int len=readint(3);         //读取前三位，来判断后面要读取的位数
    if(len==0) {
        break;
    }
while(1){
    int v=readint(len);
    if(v==(1<<len)-1) 
        break;                  //全1跳出
    printf("%c",code[len][v]);
    }
}
    cout<<endl;
}
    return 0;
}