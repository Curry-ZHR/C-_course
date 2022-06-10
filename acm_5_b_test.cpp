#include<iostream>
#include<cstring>
using namespace std;

const int maxd=20;
int s[1<<maxd];

int main()
{
    int D,I;
    int n,tag=0;
    cin>>n;
    while(scanf("%d",&D))
    {
        int k=1;
        int flag=0;
        if(D==-1)
            break;
        if(scanf("%d",&I))
        {
            for(;flag<D-1;)
            {
                if(I%2){
                    k=k*2;
                    I=(I+1)/2;
                    flag++;
                }
                else{
                    k=k*2+1;
                    I/=2;
                    flag++;
                }
            }
        }
        cout<<k<<endl;
    }

    return 0;
}