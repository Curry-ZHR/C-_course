#include<iostream>
#include<stdlib.h>
using namespace std;

int count=0;
void itoc(char str[],int n)
{
    while(n>0)
    {
        str[count++]=n%10+'0';
        n=n/10;
    }
}

int main()
{
    int n,j;
    char str[50];

    cout<<"����һ����:"<<endl;
    cin>>n;

    itoc(str,n);

    for(j=0;j<count;j++)
        cout<<str[j];
    cout<<endl;

    cout<<count<<"λ��"<<endl;
    return 0;
}
