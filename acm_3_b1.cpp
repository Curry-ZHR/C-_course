#include<stdio.h>
#include<string.h>
#define maxd 100    //���������С
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
/*�ⷨһ ֱ��ģ�����    ������ӱ�� ÿ�β�ѯ���谭���ӱ������ֵ*/

int r,c,n;
int d[maxd][maxd],d2[maxd][maxd];
int ans[maxd][maxd],cols[maxd]; //cols����

void copy(char type,int p,int q)
{
    if(type=='R')//����һ��
    {
        for(int i=1;i<=c;i++)
            d[p][i]=d2[q][i];   //qȷ����      //d2��ԭ���飿
    }
    else{//����һ��
        for(int i=1;i<=r;i++)
            d[i][p]=d2[i][q];   //qȷ����
    }
}

void del(char type)
{
    memcpy(d2,d,sizeof(d));     //ֱ��Ϊd2��ֵd
    int cnt= (type=='R'?r:c);   //ѡ�л�����
    int cnt2=0;
    for(int i=1;i<=cnt;i++)
    {
        if(!cols[i])            //cols��ʲô���飿  ֻҪcols[i]��һ��Ϊ�� ��Ӧ�ø�����һ��
            copy(type,++cnt2,i);
    }
    if(type=='R')   //cnt2������������ ��ɾ������ʣ�����л���
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
        if(cols[i])     //cols[i]��һ�в�Ϊ������Բ���
            copy(type,++cnt2,0);       //����������Ҫ���л��еĵ�һ��Ԫ�ؿ�ʼ
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
    char cmd[10];       //�����ַ���
    memset(d,0,sizeof(d));
    while(scanf("%d%d%d",&r,&c,&n)==3 && r) //Ϊʲô����Ҫ�����߼�����?
    {
        int r0=r,c0=c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)       //���ǲ�����������Ԫ��ֵ��������������Ԫ�ؽ����������Ĳ���
                d[i][j]=i*BIG+j;        //ֻ�ǵ�����Ϊ���鸳ֵ
        while(n--)
        {
            scanf("%s",cmd);
            if(cmd[0]=='E')     //����
            {
                scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
                //ִ�н�������
                int t=d[r1][c1];
                d[r1][c1]=d[r2][c2];
                d[r2][c2]=t;
            }
            else{
                int a,x;
                scanf("%d",&a);     //aΪ���������е���Ŀ
                memset(cols,0,sizeof(cols));    //colsΪ�������в��������е��кŻ��к������
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