#include<iostream>
using namespace std;

int main()
{
    int x=0,y=0,z=0;
    int count=1;
    system("pause");
    for(x=0;x<=20;x++)
    {
        y=(100-7*x)/4;
        z=(300+3*x)/4;
        if((z%3==0)&&(x+y+z==0)&&(5*x+3*y+z/3==100))
        {
            cout<<"����"<<count<<endl;
            cout<<"����="<<x<<endl;
            cout<<"ĸ��="<<y<<endl;
            cout<<"С��="<<z<<endl;
            count++;
            cout<<endl;
        }
    }
    return 0;
}