#include<set>
#include<iostream>

using namespace std;
int N;
struct IP{
	int a,b,c,d;
	string str;
};
void erjinzhi(string &ss,int x)
{
	for(int i=7;i>=0;i--){
		int c=(x>>i)&1;
		char cc=c+0x30;
		ss+=cc;
	}	
}
void reerjinzhi(string s)
{
	int i1=0,i2=0,i3=0,i4=0;
	for(int i=0;i<8;i++){
		i1=i1*2+s[i]-'0';
	}	
	for(int i=8;i<16;i++){
		i2=i2*2+s[i]-'0';
	}
	for(int i=16;i<24;i++){
		i3=i3*2+s[i]-'0';
	}
	for(int i=24;i<32;i++){
		i4=i4*2+s[i]-'0';
	}
	cout<<i1<<"."<<i2<<"."<<i3<<"."<<i4<<endl;
}
int main()
{
	
	while(cin>>N){
	
	int i1,i2,i3,i4;
	IP ip[N];	
	for(int i=0;i<N;i++){
		string s1,s2,s3,s4;
		scanf("%d.%d.%d.%d",&i1,&i2,&i3,&i4);
		ip[i].a=i1;ip[i].b=i2;ip[i].c=i3;ip[i].d=i4;
		erjinzhi(s1,i1);ip[i].str+=s1;	
		erjinzhi(s2,i2);ip[i].str+=s2;
		erjinzhi(s3,i3);ip[i].str+=s3;
		erjinzhi(s4,i4);ip[i].str+=s4;
				
	}

	int i;
	for(i=0;i<=31;i++){
		set<char> jihe;
		for(int j=0;j<N;j++){
			jihe.insert(ip[j].str[i]);          //按列进行插入 如果该列所有数相同，这次进入
		}
		if(jihe.size()!=1) break; 
	}

	string ans1,ans2;
	for(int m=0;m<=i-1;m++){
		ans1+=ip[0].str[m];
		ans2+='1';
	} 
	for(int m=i;m<=31;m++){
		ans1+='0';
		ans2+='0';
	}

	reerjinzhi(ans1);
	reerjinzhi(ans2);

	}
	return 0;	
}
