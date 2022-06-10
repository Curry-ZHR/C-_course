#include <iostream>

using namespace std;

class Clock{
    private:
        int H,M,S;
    public:
        Clock(int H=0,int M=0,int S=0)      //构造函数
        {
            this->H=H;
            this->M=M;
            this->S=S;                  //初始化
        }

        void SetTime(int h,int m,int s)
        {
            H=h,M=m,S=s;
        }

        void ShowTime()
        {
            cout<<H<<":"<<M<<":"<<S;
        }

        int getH()
        {
            return H;
        }
        int getM()
        {
            return M;
        }
        int getS()
        {
            return S;
        }
         
};

class NewClock:public Clock
{
    private:
        string flag;
    public:
        NewClock(int H,int M,int S):Clock(H,M,S)
        {
        }

        NewClock()
        {

        }

        void show()
        {
            if(getH()>=12)
            {
                SetTime(getH()-12,getM(),getS());
                cout<<"PM"<<" ";
                ShowTime();
            }
            else{
                cout<<"AM"<<" ";
                ShowTime();
            }
        }
};

int main()
{
    NewClock NC;
    int hour,minute,seconds;

    cout<<"输入时间:";
    cin>>hour>>minute>>seconds;

    NC.SetTime(hour,minute,seconds);
    NC.show();
    
    return 0;
}