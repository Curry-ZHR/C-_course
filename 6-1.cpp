#include<iostream>
#include<cmath>

using namespace std;
const double PI = 3.14159;

    //分别创建两个不同的派生类 还会有同名函数的问题？

class Point                     //点坐标
{
    private:
        int X,Y;
    public:
        Point(int X=0,int Y=0)
        {
            this->X=X;
            this->Y=Y;
        }

        void move(int OffX,int OffY)    //点的移动
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
        Circle(double R,int X,int Y):Point(X,Y)         //对基类传值初始化 派生类直接初始化
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
        Rectangle(double Length,double Height,int X,int Y):Point(X,Y)                        //先进行初始化
        {
            length=Length,height=Height;
        }

        double area()
        {
            return length*height/2;                               //底*高/2
        }

        void ShowRectangle()
        {
            cout<<"Centre of Rectangle:";                         //以该点为中心的三角形的面积
            ShowXY();
            cout<<"length:"<<length<<"\n"<<"height"<<height<<endl;
            cout<<"area:"<<area()<<endl;                          //函数的覆盖
        }
};

int main()
{
   //自行键入值来达到效果

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