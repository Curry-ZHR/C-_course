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
        bool IsSubstring(const String &str);        //����
        int str2num();
        void toUppercase();
};
void String::InputString(char *Str)         //���������
{
    this->Str=new char(strlen(Str)+1);      //˽������  ����ֱ�Ӷ��丳ֵ��
    strcpy(this->Str,Str);
    this->Str[strlen(Str)]='\0';            //���ⲿ�������ڲ�˽�����ݳ�Ա����
}   


bool String::IsSubstring(const char *str)       //������    str��һ���������ַ�����
{
    int i,j,k;
    for(i=0;Str[i]!='\0';i++)       //����
    {
        for(j=i;k=0;Str[j]!='\0' && str[k]==Str[j])     //�Ӵ�
            j++,k++;
        if(str[k]=='\0')
            return true;
    }
    return false;
}

bool String::IsSubstring(const String &str)     //��������  str��һ������
{
    char *pstr=str.Str;                         //ָ��ָ��Str
    int i,j,k,len;

    len=strlen(Str);                            //Str˽�����ݳ�Ա
    for(i=0;i<len;i++)
    {
        for(j=i;k=0;Str[j]!='\0'&&pstr[k]==Str[j])      //StrΪ���� pstrΪ�Ӵ�
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
//    cout<<num;                  //���������num
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
    char   string[100],string_1[100],string_2[100],string_3[100];           //Ϊʲôһ��Ҫ�Ǿ�̬���� ��̬�ڴ����Ϊʲô���У�
    bool flag1,flag2;


    cout<<"�����һ���ַ���:";
    cin>>string_3;
    cout<<"����ڶ����ַ���:";
    cin>>string;

    sstr.InputString(string_3);
    flag1=sstr.IsSubstring(string);

    if(flag1==true)
    {
        cout<<"�ڶ����ַ����ǵ�һ�����Ӵ�"<<endl;
    }
    else{
        cout<<"�ڶ����ַ������ǵ�һ�����Ӵ�"<<endl;
    }

    cout<<"������һ�����ִ�:"<<endl;
    cin>>string_1;
    A.InputString(string_1);
    num=A.str2num();
    cout<<"���ִ�ת����Ϊ��"<<num<<endl;

    
    cout<<"������һ����ĸ��:"<<endl;
    cin>>string_2;
    B.InputString(string_2);
    B.toUppercase();

    return 0;
}