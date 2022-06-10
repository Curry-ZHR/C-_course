#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
using namespace std;
stack<int> s;
queue<int> q;
int n=0;
/*
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
*/
//由队列入栈 
//runtime error的原因可能是数组开太小 为确保两个函数中开的数组大小相同 我们可以直接把n设为全局变量
string judge(int n,int *arr)        //arr是目标出栈序列  v是进栈前的序列
{
    
    for(int i=0;i<n;i++)
        q.push(arr[i]);     //将目标输出序列入队
                              
    for(int j=1;j<=n;j++)
    {
        s.push(j);          //1 2 3 4 5逐个入栈
        while(!s.empty() && s.top()==q.front())
        {
			//只要top等于front那么我们就一直出栈出队 直到不等为止 
            s.pop();
            q.pop();
        }
    }
    
    if(s.empty())
    {
        return "Yes";
    }
    else{
        return "No";
    }
}

int main()
{
    int flag=0;       //连续两次输入n=0时就退出循环
    cin>>n;
    while(n!=0)
    {
        while(1)
        {
            int arr[n];    
           
            cin>>arr[0];
            if(arr[0]==0)
            {
                cout<<endl;
                break;
            }
            for(int i=1;i<n;i++)
            {
                cin>>arr[i];  
            }
            
            string result=judge(n,arr);
            cout<<result<<endl;
        }
        cin>>n;     
    }
	
	return 0;
}