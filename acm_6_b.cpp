#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

//按列穿墙
//第一行为测试用例数量
//每个测试用例第一行分别为墙的数量和k的大小
//测试用例后续行为两个坐标表示墙的两个端点
//若某个位置墙厚度超过k 则从该列开始到最右侧的最长的墙 直接把这条墙删除 这一后面列的墙的厚度都-1
/*
2
3 1
2 0 4 0
0 1 1 1
1 2 2 2
7 3
0 0 3 0
6 1 8 1
2 3 6 3
4 4 6 4
0 5 1 5
5 6 7 6
1 7 3 7
*/
//墙的数量不超过100
const int MAX=110;
int l[MAX],r[MAX],wall[MAX],mark[MAX];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(wall,0,sizeof(wall));     //初始化为0
        memset(mark,0,sizeof(mark));

        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            int m1,m2;      //墙所在行
            scanf("%d%d%d%d",l+i,&m1,r+i,&m2);
            if(l[i]>r[i])
                swap(l[i],r[i]);        //交换整数值
            for(int j=0;j<105;j++)
            {
                if(l[i]<=j && j<=r[i])
                    wall[j]++;          //先记录好每一列墙的厚度
                else if(j>r[i])
                    break;
            }
        }

        int ans=0;
        int maxright,mr;
        for(int i=0;i<105;i++)
        {
            while(wall[i]>k)
            {
                maxright=0;
                for(int j=0;j<n;j++)
                {   //某行i列有墙
                    if(l[j]<=i && i<=r[j] &&!mark[j])
                    {   //寻找最右侧的墙  贪心首先删除最长的墙
                        if(maxright<r[j])
                        {
                            maxright=r[j];
                            mr=j;
                        }
                    }
                }
                mark[mr]=1;         //该条墙已被删除
                ans++;
                for(int z=i;z<=maxright;z++)    //墙的厚度整体-1
                {
                    wall[z]--;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

