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
//�ɶ�����ջ 
//runtime error��ԭ����������鿪̫С Ϊȷ�����������п��������С��ͬ ���ǿ���ֱ�Ӱ�n��Ϊȫ�ֱ���
string judge(int n,int *arr)        //arr��Ŀ���ջ����  v�ǽ�ջǰ������
{
    
    for(int i=0;i<n;i++)
        q.push(arr[i]);     //��Ŀ������������
                              
    for(int j=1;j<=n;j++)
    {
        s.push(j);          //1 2 3 4 5�����ջ
        while(!s.empty() && s.top()==q.front())
        {
			//ֻҪtop����front��ô���Ǿ�һֱ��ջ���� ֱ������Ϊֹ 
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
    int flag=0;       //������������n=0ʱ���˳�ѭ��
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