#include<iostream>
using namespace std;

const double PI = 3.14159;

class Table                                 //Table��������¼��
{
    private:
        float h;
    public:
        Table(float h)
        {
            this->h=h;
        }

        float Gethigh()
        {
            return h;
        }

        void Show_h()
        {
            cout<<"high:"<<h<<endl;
        }
};

class Circle                            //Circle������¼Բ�����
{   
    private:
        double radius;
    public:
        Circle(double R)
        {
            radius=R;
        }

        double area()
        {
            return PI*radius*radius;
        }

        void Show_area()
        {
            cout<<"area:"<<area()<<endl;
        }
};

class RoundTable:protected Table,protected Circle           //RoundTable��������¼��num����hΪ�ߣ������ΪCircle��Բ���������
{
    private:
        int num;
    public:
        RoundTable(int num,float h,double R):Table(h),Circle(R)
        {
            this->num=num;
        }

        void Show_RoundTable()
        {
            Show_h();
            Show_area();

            cout<<"RoundTable:"<<num*area()<<endl;
        }
};

int main()
{
    int num;
    float h;
    double R;

    cout<<"Input h:";
    cin>>h;

    cout<<"Input R:";
    cin>>R;

    cout<<"Input num:";
    cin>>num;

    RoundTable A(num,h,R);

    A.Show_RoundTable();
    return 0;
}