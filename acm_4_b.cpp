#include<string>
#include<set>
#include<sstream>
#include<iostream>

using namespace std;


set<string> arr;

int main()
{
    string s,tmp;
                    //EOF通过ctrl+Z 再按回车表示文件末尾
    while(cin>>s)       //按一次回车 空格都进入下一个循环
    {
        tmp="";
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]))
            {
                s[i]=tolower(s[i]);
                tmp+=s[i];
            }
            else{   //清除掉字符串中的空格 标点符号等
                s[i] = ' ';     //c++中''和""一个表示字符 一个表示字符串      //赋为空
            }
        }
        arr.insert(tmp);

        //为什么这里不用
        /*
        stringstream ss(s);     //将字符串s放入输入流ss中
        //将输入流ss给到tmp   多个字符串拼接？
        while(ss >> tmp) arr.insert(tmp);
        */
    }
    
    for(set<string>::iterator it=arr.begin();it!=arr.end();++it)
    {
        cout<< *it<<endl;
    }
    
    return 0;
}
