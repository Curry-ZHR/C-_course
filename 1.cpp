#include<iostream>
#include<Cmath>
#include<cstdlib>
using namespace std;

class Ctriangle
{
private:
    double A,B,C;  //��������
public:
    Ctriangle(double a=0,double b=0,double c=0)  //����һ�����캯����ʼ��
    {
        A=a,B=b,C=c;
    }

    void Set_func(double a,double b,double c)     //���βδ���˽������Ԫ����
    {
        if(a+b>c&&a+c>b&&b+c>a)
        {
            A=a;
            B=b;
            C=c;
        }
        else
        {
		    cout<<"��������ֵ�޷�����������"<<endl;
            exit(0);
        }
        
    }

    double Area(double a,double b,double c)
    {
        double p=(a+b+c)/2;                     //�ں������½�һ��p�������ڴ���ܳ�
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

    cout<<"����������������ֵ:"<<endl;
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
