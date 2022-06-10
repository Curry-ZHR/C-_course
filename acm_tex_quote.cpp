#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j;
    int flag=0;
    string str_1,str_2;
    while(getline(cin,str_1)){                         //输出带空格的方法
    for(i=0;i<str_1.length();i++)
    {
        if(str_1[i]=='\"'&&flag==0)             //说明是前双引号
        {
            flag=1;
            str_2=str_1.substr(i+1,str_1.length());
            str_1[i]='`';
            str_1[i+1]='`';
            str_1=str_1.substr(0,i+2);              //左闭右开
            str_1=str_1+str_2;
        }
        if(str_1[i]=='\"'&&flag==1)                //后双引号
        {
            flag=0;
            str_2=str_1.substr(i+1,str_1.length());
            str_1[i]='\'';
            str_1[i+1]='\'';
            str_1=str_1.substr(0,i+2);
            str_1=str_1+str_2;
        }                                               //长度没写够
    }
    cout<<str_1<<endl;
    }
    
    return 0;

} 