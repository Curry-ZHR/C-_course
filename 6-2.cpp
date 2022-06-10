#include<iostream>
#include<cmath>

using namespace std;

class Building{
    private:
        int floor,TotalArea;
    public:
        Building(int floor=0,int TotalArea=0)
        {
            this->floor=floor;
            this->TotalArea=TotalArea;
        }

        void Show_Building()
        {
            cout<<"floor:"<<floor<<"\n"<<"TotalArea:"<<TotalArea<<"\n";

        }
};

class Teach_Building:protected Building
{
    private:
        int teach_num,classroom;
    public:
        Teach_Building(int teach_num,int classroom,int floor,int TotalArea):Building(floor,TotalArea)
        {
            this->classroom=classroom;
            this->teach_num=teach_num;
        }

        void Show_Teach_Building()
        {
            Show_Building();
            cout<<"teach_num:"<<teach_num<<"\n"<<"classroom:"<<classroom<<endl;
        }
};

class Dorm_Building:protected Building
{
    private:
        int Dorm_num,Dorm_count,Student_num;
    public:
        Dorm_Building(int Dorm_num,int Dorm_count,int Student_num,int floor,int TotalArea):Building(floor,TotalArea)
        {
            this->Dorm_num=Dorm_num;        //����¥���
            this->Dorm_count=Dorm_count;    //������
            this->Student_num=Student_num;
        }

        void Show_Dorm_Building()
        {
            Show_Building();
            cout<<"Dorm_num:"<<Dorm_num<<"\n"<<"Dorm_count:"<<Dorm_count<<"\n"<<"Student_num:"<<Student_num<<endl;
        }
};

int main()
{
    int floor1,floor2,area1,area2;
    int teach_num,classroom;
    int Dorm_num,Dorm_count,Student_num;

    cout<<"�������ѧ¥�������Ϣ:"<<endl;
    cout<<"��ѧ¥���:";    cin>>teach_num;
    cout<<"����:";          cin>>floor1;
    cout<<"������:";        cin>>classroom;
    cout<<"�����:";        cin>>area1;
    
    cout<<"����������¥�����Ϣ:"<<endl;
    cout<<"����¥���:";    cin>>Dorm_num;
    cout<<"����:";          cin>>floor2;
    cout<<"������";         cin>>Dorm_count;
    cout<<"�����:";        cin>>area2;
    cout<<"����ѧ��������:"; cin>>Student_num;

    Teach_Building A(teach_num,floor1,classroom,area1);
    Dorm_Building B(Dorm_num,Dorm_count,Student_num,floor2,area2);

    A.Show_Teach_Building();
    B.Show_Dorm_Building();
    return 0;
}