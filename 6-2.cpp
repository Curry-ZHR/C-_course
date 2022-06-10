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
            this->Dorm_num=Dorm_num;        //宿舍楼编号
            this->Dorm_count=Dorm_count;    //宿舍数
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

    cout<<"请输入教学楼的相关信息:"<<endl;
    cout<<"教学楼编号:";    cin>>teach_num;
    cout<<"层数:";          cin>>floor1;
    cout<<"教室数:";        cin>>classroom;
    cout<<"总面积:";        cin>>area1;
    
    cout<<"请输入宿舍楼相关信息:"<<endl;
    cout<<"宿舍楼编号:";    cin>>Dorm_num;
    cout<<"层数:";          cin>>floor2;
    cout<<"宿舍数";         cin>>Dorm_count;
    cout<<"总面积:";        cin>>area2;
    cout<<"容纳学生总人数:"; cin>>Student_num;

    Teach_Building A(teach_num,floor1,classroom,area1);
    Dorm_Building B(Dorm_num,Dorm_count,Student_num,floor2,area2);

    A.Show_Teach_Building();
    B.Show_Dorm_Building();
    return 0;
}