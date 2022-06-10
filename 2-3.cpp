#include<iostream>
using namespace std;

void swap1(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;            
}

void swap(int *a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

int main()
{
    int x,y;
    cin>>x>>y;
    
    swap1(&x,&y);
    cout<<"交换后："<<x<<" "<<y<<endl;

    swap(&x,&y);
    cout<<"交换后:"<<x<<" "<<y<<endl;

    return 0;
}