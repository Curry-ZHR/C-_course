#include<iostream>
using namespace std;

        //模拟电子时钟运行！  可以选择是否打印出每一秒
class Clock{
    private:
        int Hour,Minute,Second,hour,minute,second;
    public:
        Clock(int a=0,int b=0,int c=0)
        {
            Hour=a,Minute=b,Second=c;           //对准备设置的当前时间进行初始化
        }

        ~Clock()
        {}                                      //析构函数

        void SetClock()                         //设置当前时间 无需设形参 直接用类内私有数据成员
        {
            cout<<"请输入当前时间:";
            cin>>Hour>>Minute>>Second;
        }

        void SetAlarm(int hour,int minute,int second)        //形参和私有数据成员链接
        {                                                       //设置闹钟
            this->hour=hour,this->minute=minute,this->second=second;    //this指针指向当前对象 表示当前对象的地址
        }

        void run()
        {
            while((Hour!=hour)||(Minute!=minute)||(Second!=second))     //私有数据成员在类内可以运行
            {
                Second++;
                if(Second==59)
                {
                    Second=0;
                    Minute++;
                    if(Minute==59)
                    {
                        Minute=0;
                        Hour++;
                        if(Hour==24){
                            Hour=0;
                        }
                    }
                }
                cout<<Hour<<"时"<<Minute<<"分"<<Second<<"秒"<<endl;
            }
            cout<<"时间到:"<<Hour<<"时"<<Minute<<"分"<<Second<<"秒";
        }     
};

int main()
{
    Clock MyClock;
    int hour,minute,seconds;

    MyClock.SetClock();     //设置当前时间

    cout<<"设置闹钟时间:";
    cin>>hour>>minute>>seconds;
    MyClock.SetAlarm(hour,minute,seconds);
    MyClock.run();
    return 0;
}