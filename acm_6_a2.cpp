#include<stdio.h>
#include<string.h>
 
void sort(char *p,int n,int L) 
{
    int i,j;char c;
	for(i=n;i<L;i++)
	{
		for(j=n;j<L-i+n;j++)
		{
			if(p[j]>p[j+1])
			{
			  c = p[j];
			  p[j] =p[j+1];
			  p[j+1]=c;
			}
		}
	}
}
 
 
 
int main()
{
 
	char str[52],c;int L,i,j;
	while(1)
	{
		scanf("%s",&str);
		if(str[0]=='#')break;
		L = strlen(str)-1;
        for(i=L;i>0;i--)
		{
			if(str[i]>str[i-1])			
				break;			
		}
		if(i==0)printf("No Successor\n");
                else if(i==L)
		{
			c = str[i];
			str[i] =  str[i-1];
			str[i-1] = c;
			printf("%s\n",str);
		}
                else 
		{
			for(j=L;j>=i;j--)
			{
				if(str[j]>str[i-1])
					break;
			}
			c = str[i-1];
			str[i-1] =  str[j];
			str[j] = c;
		    sort(str,i,L);
                    printf("%s\n",str);
		}
		
	}
 
	return 0;
}