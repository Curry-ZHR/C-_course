#include <iostream>

using namespace std;

int flag=0;

class Clock{
    private:
        int H,M,S;
    public:
        Clock(int H=0,int M=0,int S=0)
        {
            this->H=H;
            this->M=M;
            this->S=S;
        }

        void SetTime(int h,int m,int s)
        {
            H=h,M=m,S=s;
        }                                   //设置时间



        void apply_1(int n)
        {
            int t1,t2;
            S=S+n;
            if(S>60)
            {
                t1=S;
                t1=t1/60;
                S=S%60;
                M=M+t1;
                if(M>60)
                {
                    t2=M;
                    t2=t2/60;
                    M=M%60;
                    H=H+t2;
                    if(H>=24)
                    {
                        H=H%24;
                        flag=1;
                    }
                }
            }
        }

        void ShowTime()
        {
            cout<<H<<":"<<M<<":"<<S;
        }

        int Get_H()
        {
            return  H;
        }

        int Get_M()
        {
            return M;
        }

        int Get_S()
        {
            return S;
        }
};

class Date{
    private:
        int Year,Month,Day;
    public:
        Date(int year,int month,int day)
        {
            Year=year;
            Month=month;
            Day=day;
        }

        void SetDate(int y,int m,int d)
        {
            Year=y;
            Month=m;
            Day=d;
        }

        void ShowDate()
        {
            cout<<Year<<"年"<<Month<<"月"<<Day<<"日";
        }

        void apply_2()
        {
            if(Year%4==0&&Year%100!=0 || Year%400 == 0)         //闰年
            {
                switch (Month){
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:{
                        Day+=1;
                        if(Day>31)
                        {
                            Day=1;
                            Month+=1;
                        }
                       break; 
                    }
                    case 12:{
                        Day+=1;
                        if(Day>31)
                        {
                            Day=1;
                            Year+=1;
                            Month=1;
                        }
                        break;
                    }

                    case 2:{
                        Day+=1;
                        if(Day>29)
                        {
                            Day=1;
                            Month+=1;
                        }
                        break;
                    }
                    
                    case 4:
                    case 6:
                    case 9:
                    case 11:{
                        Day+=1;
                        if(Day>30)
                        {
                            Day=1;
                            Month+=1;
                        }
                        break;
                    }
                }
            }
            else{
                switch (Month){
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:{
                        Day+=1;
                        if(Day>31)
                        {
                            Day=1;
                            Month+=1;
                        }
                       break; 
                    }
                    case 12:{
                        Day+=1;
                        if(Day>31)
                        {
                            Day=1;
                            Year+=1;
                            Month=1;
                        }
                        break;
                    }

                    case 2:{
                        Day+=1;
                        if(Day>28)
                        {
                            Day=1;
                            Month+=1;
                        }
                        break;
                    }
                    
                    case 4:
                    case 6:
                    case 9:
                    case 11:{
                        Day+=1;
                        if(Day>30)
                        {
                            Day=1;
                            Month+=1;
                        }
                        break;
                    }
                }
            }
        }
};

class ClockWithDate:public Clock,public Date{       //直接合并进行操作 没有加入新元素
    private:
        int sec;                                    //增加的秒数
    public:
        ClockWithDate(int sec,int H,int M,int S,int Year,int Month,int Day):Clock(H,M,S),Date(Year,Month,Day)
        {
            this->sec=sec;
        }

        void apply_sec()
        {
            apply_1(sec);
            if(flag==1)
            {
                apply_2();
            }

        }

        void Show()
        {
            cout<<"加时间后的日期时间为:";
            Date::ShowDate();
            Clock::ShowTime();
        }
};

int main()
{
    int sec,hour,minute,seconds;
    int year,month,day;
    int h,m,s;

    cout<<"请输入日期:";
    cin>>year>>month>>day;
    cout<<"请输入时间:";
    cin>>hour>>minute>>seconds;

    cout<<"请输入增加的秒数:";
    cin>>sec;

    cout<<"日期时间:";
    cout<<year<<"年"<<month<<"月"<<day<<"日";
    cout<<hour<<":"<<minute<<":"<<seconds<<endl;

    ClockWithDate A(sec,hour,minute,seconds,year,month,day);    //对象赋值初始化
    A.apply_sec();                                              //调用对象中的成员函数

    h=A.Get_H(),m=A.Get_M(),s=A.Get_S();
    if(s>=60)
    {
        s=s%60;
        m=m+1;
        if(m>=60)
        {
            m=m%60;
            h=h+1;
            if(h>=24)
            {
                h=h%24;
            }
        }
    }
    
    A.SetTime(h,m,s);
    A.Show();

    return 0;
}