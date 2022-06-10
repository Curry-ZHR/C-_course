#include<iostream>
#include<cmath>

using namespace std;

class CData{
    private:
        int year,month,date;
    public:
        CData(int a=0,int b=0,int c=0)        //初始化
        {
            year=a,month=b,date=c;
        }

        void Set_func(int a,int b,int c)    //设置函数 将私有数据成员与形参结合
        {
            year=a,month=b,date=c;
        }

        void NewDay(int &a,int &b,int &c)          //用形参表示 使用引用符表示其形参能改变实参值
        {
            switch(b)
            {  
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                {
                    if(c!=31)
                        c+=1;
                    else
                    {
                        b+=1;
                        c=1;
                    }
                }
                break;

                case 2:         //考虑闰年的问题
                {
                    if(a%400==0||a%4==0&&a%100==0)         //闰年
                    {
                        if(c!=29)
                            c+=1;
                        else
                        {
                            b+=1;
                            c=1;
                        }
                    }
                    else
                    {
                        if(c!=28)
                            c+=1;
                        else
                        {
                            b+=1;
                            c=1;
                        }
                    }
                }

                case 4:
                case 6:
                case 9:
                case 11:
                {
                    if(c!=30)
                        c+=1;
                    else
                    {
                        b+=1;
                        c=1;
                    }
                }

            }
                    
        }
};

int main()
{
    int year,month,date;
    CData day;
    cout<<"请输入日期:"<<endl;
    cin>>year>>month>>date;

    day.Set_func(year,month,date);
    day.NewDay(year,month,date);

    cout<<year<<" "<<month<<" "<<date;

    return 0;
}