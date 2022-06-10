#include<iostream>
#include<string.h>
using namespace std;

class Student{
    private:
        char No[10];
        char Name[10];
        char course[5][20];
        double score[5];    //五门课
        double aver,sum;
        int number;
    public:
        Student()
        {}                     //安排一个地址空间

        ~Student()
        {}

        void input()
        {
            int j,k;
            cout<<"学号:";   
            cin>>No;
            cout<<"姓名:";   
            cin>>Name;
            cout<<"科目总数:";  
            cin>>number;
            cout<<"课程:";
            for(j=0;j<number;j++)
                cin>>course[j];
            cout<<"得分:";
            for(k=0;k<number;k++)
                cin>>score[k];
        }

        void Average_Score()
        {
            int i;
            sum=0;
            for(i=0;i<number;i++)
                sum+=score[i];
            aver=sum/number;
        }

        void output()
        {
            int i,j;
            cout<<"学号:"<<No<<"\n"<<"姓名:"<<Name<<endl;
            cout<<"课程:";
            for(j=0;j<number;j++)
                cout<<course[j]<<" ";
            cout<<endl;
            cout<<"成绩:";
            for(i=0;i<number;i++)
                cout<<score[i]<<endl;
            cout<<"平均成绩:"<<aver<<endl;
        }
};

int main()
{
    Student b[100];      //对象数组
    int i,j;
    char x;
    x='0';

    for(i=0;x!='a';i++)
    {
        cout<<i+1<<"号";
        b[i].input();
        cout<<"按a结束输入，按其他键继续输入...";
        cin>>x;
    }

    for(j=0;j<i;j++)
    {
        b[j].Average_Score();       //计算平均得分
        b[j].output();              //输出？
    }
    
    return 0;
}