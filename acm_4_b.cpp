#include<string>
#include<set>
#include<sstream>
#include<iostream>

using namespace std;


set<string> arr;

int main()
{
    string s,tmp;
                    //EOFͨ��ctrl+Z �ٰ��س���ʾ�ļ�ĩβ
    while(cin>>s)       //��һ�λس� �ո񶼽�����һ��ѭ��
    {
        tmp="";
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]))
            {
                s[i]=tolower(s[i]);
                tmp+=s[i];
            }
            else{   //������ַ����еĿո� �����ŵ�
                s[i] = ' ';     //c++��''��""һ����ʾ�ַ� һ����ʾ�ַ���      //��Ϊ��
            }
        }
        arr.insert(tmp);

        //Ϊʲô���ﲻ��
        /*
        stringstream ss(s);     //���ַ���s����������ss��
        //��������ss����tmp   ����ַ���ƴ�ӣ�
        while(ss >> tmp) arr.insert(tmp);
        */
    }
    
    for(set<string>::iterator it=arr.begin();it!=arr.end();++it)
    {
        cout<< *it<<endl;
    }
    
    return 0;
}
