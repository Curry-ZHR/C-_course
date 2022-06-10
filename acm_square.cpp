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

int *flag=new int[144];             //���Ϊ9
bool judge(int x,int size){         //n=4ʱ x 1~12              �ж����������
    bool ok=true;
    for(int i=x;i<x+size;i++)
    {
        if((flag[i]==1)&&(flag[i+(size*3)]==1));   //1��Ӧ4 13��Ӧ16
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
    int j=0,a=0;        //a,b�����䵱�н����ӵ����ʱֵ
    int temp=0,size;
    int n=0,m=0;            //nΪ���� mΪ����
    int times=1;
    string str;
    while(cin>>n>>m){
    //���õ���ĳһ������ �ͽ���������иõ��λ����1
    temp=(n*(n-1))*2;

    int tag[10]={0};
    for(int k=0;k<temp;k++)
        flag[k]=0;

    while(getline(cin,str)){
        if(str[0]=='H')
        {                                                                  //3*i��ʾ�ڼ���Ҫ�ӵ��±����
            flag[str[4]-'0'-1+3*(str[2]-'0'-1)]=1;                  //���ŵ�
        }   // �� ��
        if(str[0]=='V')
        {
            flag[12+str[4]-'0'-1+3*(str[2]-'0'-1)]=1;          
        }   // �� ��
        j++;
        if(j>m)
            break;                                              //һ������õı߱������
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
            if(judge(x,size))               //�ж������⣿
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