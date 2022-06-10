#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        string  name;               //����һ���ַ�����ʱ�� Ҫôȫд��char name[20] �������и�����ַ���������Ҫдchar name[20]
        string  sex;                //Ҫôֱ��д char *name �� string name
        string  ID;
        string  born;         //��������ֱ��д���ַ�����
    public:
        
        Person(string Name, string Sex, string id, string Born)        //���캯��
        {                                                                                   //���������캯��
            name=Name;
            sex=Sex;
            ID=id;
            born=Born;
        }
        

        void show()
        {
            cout<<"����:"<<name<<endl<<"�Ա�:"<<sex<<endl<<"���֤��:"<<ID<<endl<<"��������:"<<born<<endl;
        }
};

class Student:virtual public  Person
{
    private:
        string Stu_no;
        int score;
    public:
        Student( string name, string sex, string ID, string born, string Stu_no,int score):Person(name,sex,ID,born)  //�ַ��������������ʱҲ���ô�����
        {                                                                                                       //���캯��
            this->score=score;
            this->Stu_no=Stu_no;
        }

        
        void show()
        {
            cout<<"ѧ��:"<<Stu_no<<endl<<"�ɼ�:"<<score<<endl;
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
            cout<<"ְ��:"<<title<<endl;
        }
};

class Stu_Tech:public Student,public Teacher
{
    public:
        Stu_Tech( string name, string sex, string ID, string born, string Stu_no,int score, string title)
            :Person(name,sex,ID,born),Student(name,sex,ID,born,Stu_no,score),Teacher(name,sex,ID,born,title)     //�����ֻ����Զ�������й���һ��
            {
                
            }
        
        void show()
        {
            cout<<"Stu-Tech ��Ϣ:"<<endl;
            Student::show();
            Teacher::show();
        }
};

int main()
{
    string name,sex,ID,born,Stu_no,title;
    int score;
    cout<<"����:";  cin>>name;
    cout<<"�Ա�:";  cin>>sex;
    cout<<"���֤��:";  cin>>ID;
    cout<<"��������:";  cin>>born;
    cout<<"ѧ��:";  cin>>Stu_no;
    cout<<"�ɼ�:";   cin>>score;
    cout<<"ְ��:";  cin>>title;

    Stu_Tech ST(name,sex,ID,born,Stu_no,score,title);

    ST.show();
    return 0;
}