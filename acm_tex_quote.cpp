#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j;
    int flag=0;
    string str_1,str_2;
    while(getline(cin,str_1)){                         //������ո�ķ���
    for(i=0;i<str_1.length();i++)
    {
        if(str_1[i]=='\"'&&flag==0)             //˵����ǰ˫����
        {
            flag=1;
            str_2=str_1.substr(i+1,str_1.length());
            str_1[i]='`';
            str_1[i+1]='`';
            str_1=str_1.substr(0,i+2);              //����ҿ�
            str_1=str_1+str_2;
        }
        if(str_1[i]=='\"'&&flag==1)                //��˫����
        {
            flag=0;
            str_2=str_1.substr(i+1,str_1.length());
            str_1[i]='\'';
            str_1[i+1]='\'';
            str_1=str_1.substr(0,i+2);
            str_1=str_1+str_2;
        }                                               //����ûд��
    }
    cout<<str_1<<endl;
    }
    
    return 0;

} 