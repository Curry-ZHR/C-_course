#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;

/*
�ȶ��Ѹ������ַ������б���
Ȼ���ٴ������ַ���Ҫ�����������ַ����ı���
*/

int code[8][1<<8];

int readchar()      //ֱ��return��������ѭ��
{
while(1){
    int ch=getchar();
    if(ch!='\n'&&ch!='\r')  //�տ�ʼ����Ķ����ƴ����ַ���
        return ch;
    }
}
int readint(int n)          //nΪ��ȡ��λ�� �Ѷ���������תΪʮ����
{
    int sum=0;
    while(n){
    sum=sum*2+readchar()-'0';
    n--;
    }
    return sum;
}
bool readcode()
{
    memset(code,0,sizeof(code));        //Ϊcode����ȫ����0
    code[1][0]=readchar();          //����һ���� �����0���������ȥ �����1�����������
    for(int i=2;i<=7;i++){
    for(int j=0;j<(1<<i)-1;j++){    //(1<<i)-1�� 2��i�η�-1 ��iλ��ȫΪ1ʱ
        int ch=getchar();
        if(ch==EOF) return false;   //����EOF˵���������
        if(ch=='\n') return true;   //\n˵�������� ���ǻ�û�н���
        code[i][j]=ch;
    }
    }
}
int main()
{
while(readcode()){
    while(1){
    int len=readint(3);         //��ȡǰ��λ�����жϺ���Ҫ��ȡ��λ��
    if(len==0) {
        break;
    }
while(1){
    int v=readint(len);
    if(v==(1<<len)-1) 
        break;                  //ȫ1����
    printf("%c",code[len][v]);
    }
}
    cout<<endl;
}
    return 0;
}