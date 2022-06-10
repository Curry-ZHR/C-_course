#include<iostream>
#include<cstring>
using namespace std;
/*
4
16
H 1 1
H 1 3
H 2 1
H 2 2
H 2 3
H 3 2
H 4 2
H 4 3
V 1 1
V 2 1
V 2 2
V 2 3
V 3 2
V 4 1
V 4 2
V 4 3
*/

int *flag=new int[144];             //最大为9
bool judge(int x,int size){         //n=4时 x 1~12              判断语句有问题
    bool ok=true;
    for(int i=x;i<x+size;i++)
    {
        if((flag[i]==1)&&(flag[i+(size*3)]==1));   //1对应4 13对应16
        else{
            ok=false;
            break;
        }
    }
    for(int j=x+12;j<x+12+size;j++)
    {
        if((flag[j]==1)&&(flag[j+(size*3)]==1));
        else{
            ok=false;
            break;
        }
    }
    return ok;
}

int main()
{
    int j=0,a=0;        //a,b用来充当承接连接点的临时值
    int temp=0,size;
    int n=0,m=0;            //n为点数 m为边数
    int times=1;
    string str;
    while(cin>>n>>m){
    //若该点在某一条线上 就将标记数组中该点的位置置1
    temp=(n*(n-1))*2;

    int tag[10]={0};
    for(int k=0;k<temp;k++)
        flag[k]=0;

    while(getline(cin,str)){
        if(str[0]=='H')
        {                                                                  //3*i表示第几行要加的下标基数
            flag[str[4]-'0'-1+3*(str[2]-'0'-1)]=1;                  //横着的
        }   // 行 列
        if(str[0]=='V')
        {
            flag[12+str[4]-'0'-1+3*(str[2]-'0'-1)]=1;          
        }   // 列 行
        j++;
        if(j>m)
            break;                                              //一个构造好的边标记数组
    }
    /*
    for(int k=0;k<temp;k++)
    {
        a++;
        cout<<flag[k]<<" ";
        if(a%(n-1)==0)
            cout<<endl;
    }*/
    
    for(int size=1;size<=n;size++)
    {
        for(int x=1;x+size<=n;x++)
        {
            if(judge(x,size))               //判断有问题？
            {
                cout<<"aaa";
                tag[size]++;
            }
        }
    }
    
    if (times != 1)
	{
		cout << "\n**********************************\n\n";
	}
	cout << "Problem #" << times << endl << endl;
        
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=tag[i];
    }
    cout<<ans;
    if(ans)
    {
        for(int i=1;i<=n;i++)
        {
            if(tag[i])
            {
                cout<<tag[i]<< " square (s) of size " << i << endl;
            }
        }
    }
    else
	{
		cout << "No completed squares can be found." << endl;
	}
        times++;
    }
    return 0;
}