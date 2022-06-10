#include<iostream>
#include<queue> 
#include<vector> 
#include<set>
using namespace std;

typedef long long LL;
const int base[3]={2,3,5};
      
int main()
{   //声明优先队列   用中括号 不是小括号
    priority_queue<LL,vector<LL>,greater<LL>> arr;
    //要保证没有重复的  用集合来确保没有重复的元素
    set<LL> s;              //集合要设成longlong类型 超过int表示上限
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


