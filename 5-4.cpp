#include<iostream>
using namespace std;

        //ģ�����ʱ�����У�  ����ѡ���Ƿ��ӡ��ÿһ��
class Clock{
    private:
        int Hour,Minute,Second,hour,minute,second;
    public:
        Clock(int a=0,int b=0,int c=0)
        {
            Hour=a,Minute=b,Second=c;           //��׼�����õĵ�ǰʱ����г�ʼ��
        }

        ~Clock()
        {}                                      //��������

        void SetClock()                         //���õ�ǰʱ�� �������β� ֱ��������˽�����ݳ�Ա
        {
            cout<<"�����뵱ǰʱ��:";
            cin>>Hour>>Minute>>Second;
        }

        void SetAlarm(int hour,int minute,int second)        //�βκ�˽�����ݳ�Ա����
        {                                                       //��������
            this->hour=hour,this->minute=minute,this->second=second;    //thisָ��ָ��ǰ���� ��ʾ��ǰ����ĵ�ַ
        }

        void run()
        {
            while((Hour!=hour)||(Minute!=minute)||(Second!=second))     //˽�����ݳ�Ա�����ڿ�������
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
                cout<<Hour<<"ʱ"<<Minute<<"��"<<Second<<"��"<<endl;
            }
            cout<<"ʱ�䵽:"<<Hour<<"ʱ"<<Minute<<"��"<<Second<<"��";
        }     
};

int main()
{
    Clock MyClock;
    int hour,minute,seconds;

    MyClock.SetClock();     //���õ�ǰʱ��

    cout<<"��������ʱ��:";
    cin>>hour>>minute>>seconds;
    MyClock.SetAlarm(hour,minute,seconds);
    MyClock.run();
    return 0;
}