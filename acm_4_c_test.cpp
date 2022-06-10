#include<iostream>
#include<queue> 
#include<vector> 
#include<set>
using namespace std;
int main()
{
	set<int> s;
	s.insert(1);
	int i1=1,i2=1,i3=1,cnt=1;
	set<int>::iterator it1;     //迭代器
	it1=s.begin();
	while(cnt<1500){
		i1=(*it1)*2;
		i2=(*it1)*3;
		i3=(*it1)*5;
		s.insert(i1);
		s.insert(i2);
		s.insert(i3);
		it1++;          //迭代器从集合头部开始向下遍历
		cnt++;
	}
    printf("The 1500'th ugly number is %d.\n",(*it1));
	return 0;
}