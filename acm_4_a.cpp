#include<cstdio>
#include<string>
#include<vector> 
#include<iostream>
using namespace std;
/*
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit

*/

//Ϊʲô������Ϣ���ڴ治�㣿

//���������� ÿ��ľ��߶Ȳ�ͬ
//0<n<25

/*
move a over b ��a�ϵĿ鷵����ԭ��λ�� �ٰ�a�ŵ�b�Ķ�ջ����
move a onto b �ѿ�a ��b�ϵĿ�ȫ������ԭλ�� ���ѿ�a�ŵ���b��
pile a over b �ѿ�a�Ͷѵ���a�ϵ����п��Ƶ�b�ϣ��ƶ�ǰ����b֮�ϵ����п鷵��ԭλ
pile a onto b �ѿ�a��֮�ϵĿ�ŵ��п�b�Ķ�ջ�Ķ��� 
*/
 
const int maxn=30;
int n;
vector<int> pile[maxn];		//pileľ׮  ��������Ĵ洢��λ

//vector�൱��һ������װ�˷��������� ���Ը����Ķ����������в��� 

//�ҿ�aĿǰ���ĸ�׮�У��ҵ�ǰ׮�ĸ߶� 
//Ѱ�ҿ�a 
void find_block(int a,int& p,int& h)
{
	for(p=0;p<n;p++)
	{//vector��size��ʾ��С 
		for(h=0;h<pile[p].size();h++)
		{	//pile��һ����ά����   ����vector������̬��ά������� 
			if(pile[p][h]==a)
				return; 
		}
	}
}
//��a֮�ϵ����п�ع�ԭλ 
//�ѵ�p�Ѹ߶�Ϊh��ľ���Ϸ�����ľ��ع�ԭλ 
void clear_above(int p,int h)//hΪ��a�ĸ߶� 
{
	for(int i=h+1;i<pile[p].size();i++)
	{
		int c=pile[p][i];	//�ѿ�a��������п�ع�ԭλ 
		pile[c].push_back(c);	
	}
	pile[p].resize(h+1);	//�Դ�����׮�������ô�С 
	//pileֻ�����±�0~h��Ԫ�� 
}

//��p�Ѹ߶�Ϊh�Ŀ鼰��֮�����п��ƶ���p2�Ѷ�
void pile_onto(int p,int h,int p2)
{
	for(int i=h;i<pile[p].size();i++)
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);		//Ϊpile[p]���������ô�С 
 } 
 
 
void print()
{
	for(int i=0;i<n;i++)
	{
		printf("%d:",i);
		for(int j=0;j<pile[i].size();j++)
		{
			printf(" %d",pile[i][j]);
		}
		printf("\n");
	}
	
} 
 
 
int main()
{
	int a,b;
	cin>>n;
	string s1,s2;
	for(int i=0;i<n;i++)
		pile[i].push_back(i);	//Ϊÿһ���ѷ����һ���� ���±���ͬ
	
	while(cin>>s1)
	{
		if(s1=="quit")
			break;
		cin>>a>>s2>>b;
		
		int pa,pb,ha,hb;		//pΪ������ hΪ�߶�
		find_block(a,pa,ha);
		find_block(b,pb,hb);	//ȷ��������������Ѻ͸߶�
		
		//�������������������Ĵ�������� 
		if(pa==pb)
			continue;		//�����鲻����һ������ ֱ�Ӻ��ԣ�
		if(s2=="onto")		//ֻҪ��onto ��b�ϵ����п����ص�ԭλ��
			clear_above(pb,hb);
		if(s1=="move")		//ֻҪ��move ��b�ϵ����п�����ԭλ��
			clear_above(pa,ha); 
			
		pile_onto(pa,ha,pb);	
	} 
	
	print();
	
	return 0;
}


