#include<iostream>
using namespace std;

int main()
{
    float v[12];
    float output,test=0;
    int i,flag;
    for(i=0;i<12;i++)
    {
        cin>>v[i];
        test+=v[i];
    }
    test=test/12;
    flag=int(test*100+0.5);
    
    output=(float)flag/100;
    cout<<"$"<<output;               //ǿ������ת��
    return 0;
}