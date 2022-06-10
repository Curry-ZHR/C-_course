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

const int max_n=32;           //略大于32即可
int arr[100001][max_n]={0};           //二维数组记录ip地址个数
int mask[max_n]={0};                //掩码
int min_ip[max_n]={0};              //ip

void itob(int num2,int j,int i) 
{ 
    while(num2!=0)              //辗转相除
    {
        if(num2%2)
        {
            arr[i][j]=1;
        }
        num2/=2;
        j--;
    }
}

int btoi(int *a,int i,int j)     //从i到j
{
    int m=j-i;
    int result=0;
    for(int k=i;k<=j;k++)
    {
        result+=a[k]*pow(2,m--);
    }
    return result;
}

//将输入十进制改二进制
void change_1(int a,int b,int c,int d,int i)
{
    itob(d,31,i);
    itob(c,23,i);
    itob(b,15,i);
    itob(a,7,i);
}

//二进制改十进制
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
    int min_tag=32;                      //在所有标记中找到下标最小的来划分连续1和连续0                     //IP
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
        change_1(a[i],b[i],c[i],d[i],i);            //十进制转二进制  arr为全局变量
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
            if(arr[k][j]!=arr[0][j])                     //与运算不同则终止循环!
            {
                tag=j;                                  //列
                if(min_tag>tag)
                {
                    min_tag=tag;                        //找到最低的所有ip不同的位
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