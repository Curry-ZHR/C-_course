#include<iostream>
#include<queue> 
#include<vector> 
#include<set>
using namespace std;

typedef long long LL;
const int base[3]={2,3,5};
      
int main()
{   //�������ȶ���   �������� ����С����
    priority_queue<LL,vector<LL>,greater<LL>> arr;
    //Ҫ��֤û���ظ���  �ü�����ȷ��û���ظ���Ԫ��
    set<LL> s;              //����Ҫ���longlong���� ����int��ʾ����
    arr.push(1); 
    s.insert(1);   
    for(int j=1;;j++)
    {
        LL x= arr.top();
        arr.pop();
        if(j==1500)
        {
            printf("The 1500'th ugly number is %lld.\n",x);
            break;
        }
        for(int i=0;i<3;i++)
        {
            LL a=x*base[i];
            if(!s.count(a)) 
            {
                s.insert(a);
                arr.push(a);
            }
        }
    }

    return 0;
}


