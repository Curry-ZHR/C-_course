//��Ϣ����ϵͳ Ҫ���м��ܽ��� ����ϵͳ����

#include<iostream>
#include<cstring>
using namespace std;

const int N=20;

class User{
    private:
        string username[N],password[N];         //�ַ�������
        static int num;                         //��̬����
    public:
        User(string name,string pass)
        {
            username[num]=name;
            password[num]=pass;
            for(int i=0;password[num][i]!='\0';i++)         //�������
            {
                password[num][i]+=i;    
            }
            num++;
        }

        void Adduser(string name,string pass)                    //���
        {
            username[num]=name;
            password[num]=pass;
            for(int i=0;password[num][i]!='\0';i++)
            {
                password[num][i]+=i;
            }
            num++;
        }

        int login(string name,string pass)
        {
            for(int j=0;j<num;j++)          //�����ַ�������Ѱ���Ƿ���Ŀ���ַ���
            {
                if(username[j]==name)       //�ַ��������д���һ�ַ������ڼ����ַ���
                {
                    for(int i=0;pass[i]!='\0';i++)
                    {
                        if(password[j][i]!=pass[i]+i)       //���м������
                            return -1;
                    }
                    return j;               //�ҵ����ַ�������Ԫ���±�
                }
            }
            return -1;
        }

};

int User::num=0;                        //��̬����������¼�ַ���������Ͻ�

int main()
{
    string name,pass;
    User u1("Zhr","947");               //�ȴ�������ֵ����          //Ϊʲôֻ�е�һ���������ַ�������ȥ��
    u1.Adduser("Cjy","947259");
    u1.Adduser("Lx","951753");
    u1.Adduser("Hk","zizi");

    cout<<"Input username:";
    cin>>name;
    cout<<"Input password:";
    cin>>pass;

    if(u1.login(name,pass)>0)
    {
        cout<<"Success login!"<<endl;
    }
    else{
        cout<<"login fail!"<<endl;
    }

    return 0;
}