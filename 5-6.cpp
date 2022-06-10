//信息管理系统 要进行加密解密 登入系统操作

#include<iostream>
#include<cstring>
using namespace std;

const int N=20;

class User{
    private:
        string username[N],password[N];         //字符串数组
        static int num;                         //静态变量
    public:
        User(string name,string pass)
        {
            username[num]=name;
            password[num]=pass;
            for(int i=0;password[num][i]!='\0';i++)         //密码加密
            {
                password[num][i]+=i;    
            }
            num++;
        }

        void Adduser(string name,string pass)                    //添加
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
            for(int j=0;j<num;j++)          //遍历字符串数组寻找是否有目标字符串
            {
                if(username[j]==name)       //字符串数组中存在一字符串等于键入字符串
                {
                    for(int i=0;pass[i]!='\0';i++)
                    {
                        if(password[j][i]!=pass[i]+i)       //进行加密配对
                            return -1;
                    }
                    return j;               //找到了字符串数组元素下标
                }
            }
            return -1;
        }

};

int User::num=0;                        //静态变量用来记录字符串数组的上界

int main()
{
    string name,pass;
    User u1("Zhr","947");               //先创建并传值对象          //为什么只有第一个创建的字符串进不去？
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