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

//为什么报错信息是内存不足？

//不定长数组 每个木块高度不同
//0<n<25

/*
move a over b 块a上的块返回其原来位置 再把a放到b的堆栈顶部
move a onto b 把块a 块b上的块全部返回原位置 并把块a放到块b上
pile a over b 把块a和堆叠在a上的所有块移到b上，移动前，把b之上的所有块返回原位
pile a onto b 把块a及之上的块放到有块b的堆栈的顶部 
*/
 
const int maxn=30;
int n;
vector<int> pile[maxn];		//pile木桩  用来做块的存储单位

//vector相当于一个被封装了方法的数组 可以更简便的对这个数组进行操作 

//找块a目前在哪个桩中，且当前桩的高度 
//寻找块a 
void find_block(int a,int& p,int& h)
{
	for(p=0;p<n;p++)
	{//vector中size表示大小 
		for(h=0;h<pile[p].size();h++)
		{	//pile是一个二维数组   利用vector创建动态二维数组更快 
			if(pile[p][h]==a)
				return; 
		}
	}
}
//把a之上的所有块回归原位 
//把第p堆高度为h的木块上方所有木块回归原位 
void clear_above(int p,int h)//h为块a的高度 
{
	for(int i=h+1;i<pile[p].size();i++)
	{
		int c=pile[p][i];	//把块a上面的所有块回归原位 
		pile[c].push_back(c);	
	}
	pile[p].resize(h+1);	//对处理后的桩重新设置大小 
	//pile只保留下标0~h的元素 
}

//第p堆高度为h的块及其之上所有块移动到p2堆顶
void pile_onto(int p,int h,int p2)
{
	for(int i=h;i<pile[p].size();i++)
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);		//为pile[p]堆重新设置大小 
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
		pile[i].push_back(i);	//为每一个堆放入第一个块 和下标相同
	
	while(cin>>s1)
	{
		if(s1=="quit")
			break;
		cin>>a>>s2>>b;
		
		int pa,pb,ha,hb;		//p为所属堆 h为高度
		find_block(a,pa,ha);
		find_block(b,pb,hb);	//确定两个块的所属堆和高度
		
		//这里的语句对于四种命令的处理很巧妙 
		if(pa==pb)
			continue;		//两个块不能在一个堆中 直接忽略！
		if(s2=="onto")		//只要是onto 块b上的所有块必须回到原位置
			clear_above(pb,hb);
		if(s1=="move")		//只要是move 块b上的所有块必须回原位置
			clear_above(pa,ha); 
			
		pile_onto(pa,ha,pb);	
	} 
	
	print();
	
	return 0;
}


