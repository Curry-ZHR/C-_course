#include<iostream>
#include<string.h>
using namespace std;

class Student{
    private:
        char No[10];
        char Name[10];
        char course[5][20];
        double score[5];    //���ſ�
        double aver,sum;
        int number;
    public:
        Student()
        {}                     //����һ����ַ�ռ�

        ~Student()
        {}

        void input()
        {
            int j,k;
            cout<<"ѧ��:";   
            cin>>No;
            cout<<"����:";   
            cin>>Name;
            cout<<"��Ŀ����:";  
            cin>>number;
            cout<<"�γ�:";
            for(j=0;j<number;j++)
                cin>>course[j];
            cout<<"�÷�:";
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
            cout<<"ѧ��:"<<No<<"\n"<<"����:"<<Name<<endl;
            cout<<"�γ�:";
            for(j=0;j<number;j++)
                cout<<course[j]<<" ";
            cout<<endl;
            cout<<"�ɼ�:";
            for(i=0;i<number;i++)
                cout<<score[i]<<endl;
            cout<<"ƽ���ɼ�:"<<aver<<endl;
        }
};

int main()
{
    Student b[100];      //��������
    int i,j;
    char x;
    x='0';

    for(i=0;x!='a';i++)
    {
        cout<<i+1<<"��";
        b[i].input();
        cout<<"��a�������룬����������������...";
        cin>>x;
    }

    for(j=0;j<i;j++)
    {
        b[j].Average_Score();       //����ƽ���÷�
        b[j].output();              //�����
    }
    
    return 0;
}