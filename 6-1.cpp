#include<iostream>
#include<cmath>

using namespace std;
const double PI = 3.14159;

    //�ֱ𴴽�������ͬ�������� ������ͬ�����������⣿

class Point                     //������
{
    private:
        int X,Y;
    public:
        Point(int X=0,int Y=0)
        {
            this->X=X;
            this->Y=Y;
        }

        void move(int OffX,int OffY)    //����ƶ�
        {
            X+=OffX,Y+=OffY;
        }

        void ShowXY()
        {
            cout<<"("<<X<<","<<Y<<")"<<endl;
        }
};

class Circle: protected Point
{
    private:
        double radius;
    public:
        Circle(double R,int X,int Y):Point(X,Y)         //�Ի��ഫֵ��ʼ�� ������ֱ�ӳ�ʼ��
        {
            radius=R;
        }

        double area()
        {
            return PI*radius*radius;
        }

        void ShowCircle()
        {
            cout<<"Centre of circle:";
            ShowXY();
            cout<<"radius:"<<radius<<endl;
            cout<<"area:"<<area()<<endl;  
        }
};

class Rectangle: protected Point
{
    private:
        double length,height;
    public:
        Rectangle(double Length,double Height,int X,int Y):Point(X,Y)                        //�Ƚ��г�ʼ��
        {
            length=Length,height=Height;
        }

        double area()
        {
            return length*height/2;                               //��*��/2
        }

        void ShowRectangle()
        {
            cout<<"Centre of Rectangle:";                         //�Ըõ�Ϊ���ĵ������ε����
            ShowXY();
            cout<<"length:"<<length<<"\n"<<"height"<<height<<endl;
            cout<<"area:"<<area()<<endl;                          //�����ĸ���
        }
};

int main()
{
   //���м���ֵ���ﵽЧ��

    double R,length,height;
    int X,Y;

    cout<<"Input the location of this point:"<<endl;
    cin>>X>>Y;

    cout<<"Please Input the length and the height:"<<endl;
    cin>>length>>height;

    cout<<"Please Input the radius:"<<endl;
    cin>>R;                      

    Rectangle A(length,height,X,Y);
    Circle B(R,X,Y);

    A.ShowRectangle();
    B.ShowCircle();



    return 0;
}