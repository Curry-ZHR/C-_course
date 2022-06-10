#include<iostream>
#include<math.h>
using namespace std;
/*
3
194.85.160.177
194.85.160.183
194.85.160.178

3
194.85.159.178
194.85.160.177
194.85.160.178
*/

const int max_n=32;           //�Դ���32����
int arr[100001][max_n]={0};           //��ά�����¼ip��ַ����
int mask[max_n]={0};                //����
int min_ip[max_n]={0};              //ip

void itob(int num2,int j,int i) 
{ 
    while(num2!=0)              //շת���
    {
        if(num2%2)
        {
            arr[i][j]=1;
        }
        num2/=2;
        j--;
    }
}

int btoi(int *a,int i,int j)     //��i��j
{
    int m=j-i;
    int result=0;
    for(int k=i;k<=j;k++)
    {
        result+=a[k]*pow(2,m--);
    }
    return result;
}

//������ʮ���ƸĶ�����
void change_1(int a,int b,int c,int d,int i)
{
    itob(d,31,i);
    itob(c,23,i);
    itob(b,15,i);
    itob(a,7,i);
}

//�����Ƹ�ʮ����
void change_2(int num[max_n])
{
    int a,b,c,d;
    a=btoi(num,0,7);
    b=btoi(num,8,15);
    c=btoi(num,16,23);
    d=btoi(num,24,31);
    cout<<a<<'.'<<b<<'.'<<c<<'.'<<d<<endl;
}

int main()
{
    int tag=0;
    int min_tag=32;                      //�����б�����ҵ��±���С������������1������0                     //IP
    int *a,*b,*c,*d;
    int num=0;

    while(cin>>num){
    
    for(int i=0;i<num;i++)
    {
        a=new int(num);
        b=new int(num);
        c=new int(num);
        d=new int(num);
        scanf("%d.%d.%d.%d",&a[i],&b[i],&c[i],&d[i]);
        change_1(a[i],b[i],c[i],d[i],i);            //ʮ����ת������  arrΪȫ�ֱ���
    }
/*
    for(int k=0;k<num;k++)
    {
        for(int j=0;j<32;j++)
        {
            cout<<arr[k][j];
        }
        cout<<endl;
    }*/
    
    for(int k=0;k<num;k++)
    {
        for(int j=0;j<32;j++)
        {
            if(arr[k][j]!=arr[0][j])                     //�����㲻ͬ����ֹѭ��!
            {
                tag=j;                                  //��
                if(min_tag>tag)
                {
                    min_tag=tag;                        //�ҵ���͵�����ip��ͬ��λ
                }
                break;
            }
        }
    }
    for(int i=0;i<min_tag;i++)
    {
        mask[i]=1;
        min_ip[i]=arr[0][i];
    }
/*
    for(int i=0;i<max_n;i++)
    {
        printf("%d",mask[i]);
    }
    printf("\n");
    for(int j=0;j<max_n;j++)
    {
        printf("%d",min_ip[j]);
    }
    printf("\n");*/

    change_2(min_ip);
    change_2(mask);

    /*int a[8]={1,1,0,0,0,0,1,0};
    int result;
    result=btoi(a,0,7);
    printf("%d",result);*/
    }
    return 0;

}