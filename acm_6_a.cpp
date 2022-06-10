#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
//next_permutation 下一个排列组合stl

//对已给字母进行重排序
//所给字母每个都要用上
//下一个排序要仅大于他 是最接近输入数的数
//若没有比当前字符串更大的
int main()
{
    while(1)
    {
        string str;
        cin>>str;
        if(str[0]=='#')
            break;
    
        if(next_permutation(str.begin(),str.end()))       //开头和结尾的下标
        {
            cout<<str<<endl;
        }
        else{
            cout<<"No Successor"<<endl;
        }
    
      
    }
    return 0;
}