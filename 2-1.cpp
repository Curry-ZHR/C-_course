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
    cout<<"�����¶�Ϊ:";
    cin>>c;
    cout<<"�����¶�Ϊ��";
    cin>>f;

    cout<<"����ת���ϣ�"<<ctof(c)<<endl;
    cout<<"����ת���ϣ�"<<ftoc(f)<<endl;

    return 0;
}