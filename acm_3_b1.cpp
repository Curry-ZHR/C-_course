#include<stdio.h>
#include<string.h>
#define maxd 100    //开辟数组大小
#define BIG 10000

/*
7 9
5
DR 2 1 5
DC 4 3 6 7 9
IC 1 3
IR 2 2 4
EX 1 2 6 5
4
4 8
5 5
7 8
6 5
0 0
*/
/*解法一 直接模拟操作    算出电子表格 每次查询及阻碍电子表格中找值*/

int r,c,n;
int d[maxd][maxd],d2[maxd][maxd];
int ans[maxd][maxd],cols[maxd]; //cols是列

void copy(char type,int p,int q)
{
    if(type=='R')//处理一行
    {
        for(int i=1;i<=c;i++)
            d[p][i]=d2[q][i];   //q确定行      //d2是原数组？
    }
    else{//处理一列
        for(int i=1;i<=r;i++)
            d[i][p]=d2[i][q];   //q确定列
    }
}

void del(char type)
{
    memcpy(d2,d,sizeof(d));     //直接为d2赋值d
    int cnt= (type=='R'?r:c);   //选行还是列
    int cnt2=0;
    for(int i=1;i<=cnt;i++)
    {
        if(!cols[i])            //cols是什么数组？  只要cols[i]这一列为空 则应该覆盖这一列
            copy(type,++cnt2,i);
    }
    if(type=='R')   //cnt2是用来计数的 看删除后表格还剩多少行或列
        r=cnt2;
    else
        c=cnt2;
}

void ins(char type)
{
    memcpy(d2,d,sizeof(d));
    int cnt= (type=='R'?r:c);
    int cnt2=0;
    for(int i=1;i<=cnt;i++)
    {
        if(cols[i])     //cols[i]这一列不为空则可以插入
            copy(type,++cnt2,0);       //插入数据则要从行或列的第一个元素开始
        copy(type,++cnt2,i);    //?
    }
    if(type=='R')
        r=cnt2;
    else
        c=cnt2;
}

int main()
{
    int r1,c1,r2,c2,q,kase=0;
    char cmd[10];       //操作字符串
    memset(d,0,sizeof(d));
    while(scanf("%d%d%d",&r,&c,&n)==3 && r) //为什么这里要进行逻辑运算?
    {
        int r0=r,c0=c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)       //我们并不关心数组元素值，而关心数组间的元素进行了怎样的操作
                d[i][j]=i*BIG+j;        //只是单纯的为数组赋值
        while(n--)
        {
            scanf("%s",cmd);
            if(cmd[0]=='E')     //交换
            {
                scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
                //执行交换操作
                int t=d[r1][c1];
                d[r1][c1]=d[r2][c2];
                d[r2][c2]=t;
            }
            else{
                int a,x;
                scanf("%d",&a);     //a为操作的行列的数目
                memset(cols,0,sizeof(cols));    //cols为即将进行操作的行列的行号或列号作标记
                for(int i=0;i<a;i++)
                {
                    scanf("%d",&x);
                    cols[x]=1;
                }
                if(cmd[0]='D')
                    del(cmd[1]);
                else
                    ins(cmd[1]);
            }
        }
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                ans[d[i][j]/BIG][d[i][j]%BIG] =i*BIG+j;
            }
    }       
    if(kase > 0) 
        printf("\n");
    
    printf("Spreadsheet #%d\n", ++kase);
    
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d", &r1, &c1);
        printf("Cell data in (%d,%d) ", r1, c1);
        if(ans[r1][c1] == 0) 
            printf("GONE\n");
        else 
            printf("moved to (%d,%d)\n", ans[r1][c1]/BIG, ans[r1][c1]%BIG);
    }

    return 0;
}