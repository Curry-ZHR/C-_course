#include<iostream>
#include<Cmath>
#include<cstdlib>
using namespace std;

class Ctriangle
{
private:
    double A,B,C;  //设三条边
public:
    Ctriangle(double a=0,double b=0,double c=0)  //创建一个构造函数初始化
    {
        A=a,B=b,C=c;
    }

    void Set_func(double a,double b,double c)     //把形参传入私有数据元素中
    {
        if(a+b>c&&a+c>b&&b+c>a)
        {
            A=a;
            B=b;
            C=c;
        }
        else
        {
		    cout<<"输入三边值无法构成三角形"<<endl;
            exit(0);
        }
        
    }

    double Area(double a,double b,double c)
    {
        double p=(a+b+c)/2;                     //在函数内新建一个p变量用于存放周长
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    double Circle(double a,double b,double c)
    {
        return a+b+c;
    }

    
};

int main()
{
	Ctriangle delta;
    double x,y,z;

    cout<<"请输入三角形三边值:"<<endl;
    cout<<"A=";
    cin>>x;
    cout<<"B=";
    cin>>y;
    cout<<"C=";
    cin>>z;
	
    delta.Set_func(x,y,z);
    

    cout<<"C:"<<delta.Circle(x,y,z)<<endl;
    cout<<"S:"<<delta.Area(x,y,z)<<endl;


    return 0;
}
