#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

//���д�ǽ
//��һ��Ϊ������������
//ÿ������������һ�зֱ�Ϊǽ��������k�Ĵ�С
//��������������Ϊ���������ʾǽ�������˵�
//��ĳ��λ��ǽ��ȳ���k ��Ӹ��п�ʼ�����Ҳ�����ǽ ֱ�Ӱ�����ǽɾ�� ��һ�����е�ǽ�ĺ�ȶ�-1
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
//ǽ������������100
const int MAX=110;
int l[MAX],r[MAX],wall[MAX],mark[MAX];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(wall,0,sizeof(wall));     //��ʼ��Ϊ0
        memset(mark,0,sizeof(mark));

        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            int m1,m2;      //ǽ������
            scanf("%d%d%d%d",l+i,&m1,r+i,&m2);
            if(l[i]>r[i])
                swap(l[i],r[i]);        //��������ֵ
            for(int j=0;j<105;j++)
            {
                if(l[i]<=j && j<=r[i])
                    wall[j]++;          //�ȼ�¼��ÿһ��ǽ�ĺ��
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
                {   //ĳ��i����ǽ
                    if(l[j]<=i && i<=r[j] &&!mark[j])
                    {   //Ѱ�����Ҳ��ǽ  ̰������ɾ�����ǽ
                        if(maxright<r[j])
                        {
                            maxright=r[j];
                            mr=j;
                        }
                    }
                }
                mark[mr]=1;         //����ǽ�ѱ�ɾ��
                ans++;
                for(int z=i;z<=maxright;z++)    //ǽ�ĺ������-1
                {
                    wall[z]--;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

