/*��ͨ������vehicle������car truck boat ������һ���麯��������ʾ������Ϣ*/
#include<iostream>
using namespace std;

class vehicle{
    private:
        int power;
    public:
        vehicle(int power=0)
        {
            this->power=power;
        }

        virtual void display()
        {
            cout<<"power:"<<power;
        }

        int get_power()
        {
            return power;
        }
};

class car:public vehicle{
    private:
        int seat;                       //�ؿ���
    public:
        car(int seat=0,int power=0):vehicle(power)
        {
            this->seat=seat;
        }
        void display()
        {
            cout<<"car's power:"<<get_power()<<" "<<"seat:"<<seat<<endl;
        }
};

class truck:public vehicle{
    private:
        int load;                       //�ػ���
    public:
        truck(int load=0,int power=0):vehicle(power)
        {
            this->load=load;
        }
        void display()
        {
            cout<<"truck's power:"<<get_power()<<" "<<"load:"<<load<<endl;
        }
};

class boat:public vehicle{
    private:
        int displacement;               //��ˮ��
    public:
        boat(int displacement=0,int power=0):vehicle(power)
        {
            this->displacement=displacement;
        }  
        void display()
        {
            cout<<"boat's power:"<<get_power()<<" "<<"displacement:"<<displacement<<endl;
        }
};

int main()
{
    int power,seat,load,displacement;
    cout<<"please input car's power and seat:";
    cin>>power>>seat;
    car A(seat,power);

    cout<<"please input truck's power and load:";
    cin>>power>>load;
    truck B(load,power);

    cout<<"please input boat's power and displacement:";
    cin>>power>>displacement;
    boat C(displacement,power);

    A.display();
    B.display();
    C.display();


    return 0;
}