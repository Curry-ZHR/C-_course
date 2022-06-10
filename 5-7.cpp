#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class String{
    private:
        char *Str;
        char *Upperstr;
    public:
        String()
        {
            Str='\0';
        }
    

        void InputString(char *Str);
        bool IsSubstring(const char *str);
        bool IsSubstring(const String &str);        //引用
        int str2num();
        void toUppercase();
};
void String::InputString(char *Str)         //读入对象中
{
    this->Str=new char(strlen(Str)+1);      //私有数据  不能直接对其赋值！
    strcpy(this->Str,Str);
    this->Str[strlen(Str)]='\0';            //将外部变量和内部私有数据成员链接
}   


bool String::IsSubstring(const char *str)       //常变量    str是一个常变量字符串！
{
    int i,j,k;
    for(i=0;Str[i]!='\0';i++)       //主串
    {
        for(j=i;k=0;Str[j]!='\0' && str[k]==Str[j])     //子串
            j++,k++;
        if(str[k]=='\0')
            return true;
    }
    return false;
}

bool String::IsSubstring(const String &str)     //函数重载  str是一个对象！
{
    char *pstr=str.Str;                         //指针指向Str
    int i,j,k,len;

    len=strlen(Str);                            //Str私有数据成员
    for(i=0;i<len;i++)
    {
        for(j=i;k=0;Str[j]!='\0'&&pstr[k]==Str[j])      //Str为主串 pstr为子串
            j++,k++;
        if(pstr[k]=='\0')
            return true;
    }
    return false;

}

int String::str2num()
{
    int i,j;
    int len;
    int num=0;

    len=strlen(Str);
    j=0;
    for(i=len;i>0;i--)
    {
        num+=(Str[i-1]-'0')*pow(10,j);
        j++;
    }   
//    cout<<num;                  //输出并返回num
    return num;
}

void String::toUppercase()
{
    int i,len;
    len=strlen(Str);

    for(i=0;i<len;i++)
    {
        if(Str[i]>='a'&&Str[i]<='z')
        {
            Upperstr[i]=Str[i]-32;
            cout<<Upperstr[i];
        }
    }
}

int main()
{
    String sstr,A,B;
    int i,num;
    char   string[100],string_1[100],string_2[100],string_3[100];           //为什么一定要是静态数组 动态内存分配为什么不行？
    bool flag1,flag2;


    cout<<"输入第一个字符串:";
    cin>>string_3;
    cout<<"输入第二个字符串:";
    cin>>string;

    sstr.InputString(string_3);
    flag1=sstr.IsSubstring(string);

    if(flag1==true)
    {
        cout<<"第二个字符串是第一个的子串"<<endl;
    }
    else{
        cout<<"第二个字符串不是第一个的子串"<<endl;
    }

    cout<<"请输入一个数字串:"<<endl;
    cin>>string_1;
    A.InputString(string_1);
    num=A.str2num();
    cout<<"数字串转数字为："<<num<<endl;

    
    cout<<"请输入一个字母串:"<<endl;
    cin>>string_2;
    B.InputString(string_2);
    B.toUppercase();

    return 0;
}