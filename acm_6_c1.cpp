#include <cstdio>
#include <cstring>
 
 
int c[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};//”≤±“√Ê∂Ó
long long d[30010];
 
int main()
{
    d[0]=1;//init
    for(int i=0;i<11;++i){//√∂æŸ11÷÷”≤±“£¨
        for(int j=c[i];j<=30000;++j){//…˝–Ú√∂æŸÀ˘”–Ω∂Ó◊¥Ã¨
            d[j]+=d[j-c[i]];
        }
    }
    double a;
 
    while(~scanf("%lf",&a),a){
        int A=int(a*100+0.5);       
        printf("%6.2lf%17lld\n",a,d[A]);
    }
    return 0;
}

