/*定义Location类 重载运算符+ - 实现平面位置的移动*/
#include<iostream>
using namespace std;

class Location{
    private:
        int x,y;                    //坐标
    public:
        Location(int x=0,int y=0)
        {
            this->x=x;
            this->y=y;
        }

        void display()
        {
            cout<<"("<<x<<","<<y<<")"<<endl;
        }

        Location operator +(Location B);
        Location operator -(Location B);

};

Location Location::operator+(Location B)
{
    return Location(x+B.x,y+B.y);
} 

Location Location::operator-(Location B)
{
    return Location(x-B.x,y-B.y);
}

int main()
{
    int x1,y1,x2,y2;
    cout<<"please input location 1:";
    cin>>x1>>y1;
    Location A(x1,y1);
    cout<<"please input location 2:";
    cin>>x2>>y2;
    Location B(x2,y2);

    Location C;

    C=A+B;
    cout<<"C=A+B=";
    C.display();

    C=A-B;
    cout<<"C=A-B=";
    C.display();

    C=B-A;
    cout<<"C=B-A=";
    C.display();

    return 0;
}