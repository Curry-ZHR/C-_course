#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
//next_permutation ��һ���������stl

//���Ѹ���ĸ����������
//������ĸÿ����Ҫ����
//��һ������Ҫ�������� ����ӽ�����������
//��û�бȵ�ǰ�ַ��������
int main()
{
    while(1)
    {
        string str;
        cin>>str;
        if(str[0]=='#')
            break;
    
        if(next_permutation(str.begin(),str.end()))       //��ͷ�ͽ�β���±�
        {
            cout<<str<<endl;
        }
        else{
            cout<<"No Successor"<<endl;
        }
    
      
    }
    return 0;
}