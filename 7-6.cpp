/*����һ��shape������ ������Rectangle���Circle�� ������������������
�ؼ����������ʹ��*/
#include<iostream>
#include<cmath>
using namespace std;

const double Pi=3.14159;

//�������д��д��麯�� ��������˵ȫ�Ǵ��麯����
class Shape{
    virtual double area()const =0;      //areaΪ����
    virtual void show()=0;
};

class Rectangle:public Shape{
    private:
        int x,y;
    public:
    Rectangle(int x=0,int y=0)                          //����������������ٸ������ำֵ
    {
        this->x=x,this->y=y;
    }
        
    void show(){
        cout<<"Rectangle:";
    }
    
    double area()const{
        return x*y;
    }
};

class Circle:public Shape{
    private:
        int radius;
    public:
    Circle(int R=0)
    {
        radius=R;
    }
        void show()
        {
            cout<<"Circle:";
        }
        double area()const{
            return Pi*radius*radius;
            
        }
};

int main()
{
    int radius,x,y;
    cout<<"please input Rectangle's length and weight:";
    cin>>x>>y;
    Rectangle A(x,y);

    cout<<"please input Circle's radius:";
    cin>>radius;
    Circle B(radius);

    A.show();
    cout<<A.area()<<endl;
    B.show();
    cout<<B.area()<<endl;

    return 0;
}