#include<iostream>
using namespace std;

int ctof(int c)
{
    int f;
    f=1.8*c+32;
    return f;
}

int ftoc(int f)
{
    int c;
    c=(5*f-160)/9;
    return c;
}
int main()
{
    int c,f;
    cout<<"摄氏温度为:";
    cin>>c;
    cout<<"华氏温度为：";
    cin>>f;

    cout<<"摄氏转华氏："<<ctof(c)<<endl;
    cout<<"华氏转摄氏："<<ftoc(f)<<endl;

    return 0;
}