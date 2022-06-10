#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
using namespace std;

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
int N;
//runtime error的原因可能是数组开太小 为确保两个函数中开的数组大小相同 我们可以直接把n设为全局变量
bool panduan(int arr[])
{
    int cur=1; 
	stack<int> sta;
	for(int i=0;i<N;i++){
		while(cur<=arr[i]){
			sta.push(cur);
			cur++;
		}
		if(sta.top()!=arr[i])
			return false;
		else sta.pop();
	}
	return true;
}


int main()
{
	//N=5;
	cin>>N;
	while(N!=0){		
		while(1){
			int arr[N];
			cin>>arr[0];
			if(arr[0]==0) {
				cout<<endl;
				break;
			}	
			for(int i=1;i<N;i++){
				cin>>arr[i];
			}
			if(panduan(arr)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}		
		cin>>N;
	}

	return 0;
}