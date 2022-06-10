#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int i,j;
    int flag=0;
    string str_1,str_2;
    
    while(getline(cin,str_1))
    {
        str_2="";
        for(i=0;i<str_1.length();i++)
        {
            if(str_1[i]=='\"' && flag==0)
            {
                str_2+='`';
                str_2+='`';
                flag=1;
                continue;
            }
            if(str_1[i]=='\"'&&flag==1)
            {
                str_2+='\'';
                str_2+='\'';
                flag=0;
                continue;
            }
            str_2+=str_1[i];
        }
        cout<<str_2<<endl;
    }
    return 0;
}