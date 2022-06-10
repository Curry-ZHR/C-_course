#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        string  name;               //定义一个字符串的时候 要么全写成char name[20] 后面所有跟随的字符串遍历都要写char name[20]
        string  sex;                //要么直接写 char *name 或 string name
        string  ID;
        string  born;         //出生年月直接写成字符串？
    public:
        
        Person(string Name, string Sex, string id, string Born)        //构造函数
        {                                                                                   //带参数构造函数
            name=Name;
            sex=Sex;
            ID=id;
            born=Born;
        }
        

        void show()
        {
            cout<<"姓名:"<<name<<endl<<"性别:"<<sex<<endl<<"身份证号:"<<ID<<endl<<"出生年月:"<<born<<endl;
        }
};

class Student:virtual public  Person
{
    private:
        string Stu_no;
        int score;
    public:
        Student( string name, string sex, string ID, string born, string Stu_no,int score):Person(name,sex,ID,born)  //字符串在虚基类声明时也不用打括号
        {                                                                                                       //构造函数
            this->score=score;
            this->Stu_no=Stu_no;
        }

        
        void show()
        {
            cout<<"学号:"<<Stu_no<<endl<<"成绩:"<<score<<endl;
        }
};

class Teacher:virtual public Person
{
    private:
        string title;
    public:
        Teacher( string name, string sex, string ID, string born, string ttl):Person(name,sex,ID,born)
        {
            title=ttl;
        }

        void show()
        {
            cout<<"职称:"<<title<<endl;
        }
};

class Stu_Tech:public Student,public Teacher
{
    public:
        Stu_Tech( string name, string sex, string ID, string born, string Stu_no,int score, string title)
            :Person(name,sex,ID,born),Student(name,sex,ID,born,Stu_no,score),Teacher(name,sex,ID,born,title)     //虚基类只在最远派生类中构造一次
            {
                
            }
        
        void show()
        {
            cout<<"Stu-Tech 信息:"<<endl;
            Student::show();
            Teacher::show();
        }
};

int main()
{
    string name,sex,ID,born,Stu_no,title;
    int score;
    cout<<"名字:";  cin>>name;
    cout<<"性别:";  cin>>sex;
    cout<<"身份证号:";  cin>>ID;
    cout<<"出生年月:";  cin>>born;
    cout<<"学号:";  cin>>Stu_no;
    cout<<"成绩:";   cin>>score;
    cout<<"职称:";  cin>>title;

    Stu_Tech ST(name,sex,ID,born,Stu_no,score,title);

    ST.show();
    return 0;
}