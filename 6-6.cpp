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
        }                                   //����ʱ��



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
            cout<<Year<<"��"<<Month<<"��"<<Day<<"��";
        }

        void apply_2()
        {
            if(Year%4==0&&Year%100!=0 || Year%400 == 0)         //����
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

class ClockWithDate:public Clock,public Date{       //ֱ�Ӻϲ����в��� û�м�����Ԫ��
    private:
        int sec;                                    //���ӵ�����
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
            cout<<"��ʱ��������ʱ��Ϊ:";
            Date::ShowDate();
            Clock::ShowTime();
        }
};

int main()
{
    int sec,hour,minute,seconds;
    int year,month,day;
    int h,m,s;

    cout<<"����������:";
    cin>>year>>month>>day;
    cout<<"������ʱ��:";
    cin>>hour>>minute>>seconds;

    cout<<"���������ӵ�����:";
    cin>>sec;

    cout<<"����ʱ��:";
    cout<<year<<"��"<<month<<"��"<<day<<"��";
    cout<<hour<<":"<<minute<<":"<<seconds<<endl;

    ClockWithDate A(sec,hour,minute,seconds,year,month,day);    //����ֵ��ʼ��
    A.apply_sec();                                              //���ö����еĳ�Ա����

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