/*扩充String类*/
#include<iostream>
#include<cstring>

class String{
    private:
        int len;
        char *str;
    public:
        String(int len=0,char *str=NULL)
        {
            this->len=len;
            strcpy(this->str,str);
        }

        void Replace_char(char *str,char ch,int i)      //更换某个位置上的字符
        {
            int j;
            char *p=str;
            for(j=0;j<i;j++)
                p++;
            *p=ch;                                      //p即停留在更换字符位置上
        }

        void Replace_string(char *str,char *V,char *T)       //V为主串中的子串 T为替换串
        {
            int len1=strlen(V),len2=strlen(T);
            char *string;
            char *p=str,*q=str;
            while(*p!='\0')
            {
                if(strncmp(p,V,len1)==0)                     //找到了一组模式匹配串 完成一趟替换
                {
                    while(q!=p)
                    {
                        *string=*q;
                        q++;
                    }
                    strcat(string,T);
                    q=q+len1;
                    strcat(string,q);
                    str=string;
                    string=NULL;
                }
                p++;
            }
            
        }

        void Delete_char(char *str,char ch,int i)
        {
            int j;
            char *p=str;
            for(j=0;j<i;j++)
            {
                p++;
            }
            for(j=i;j<len;j++)
            {
                *(str+j)=*(str+j+1);                            //全部向前挪一位
            }
        }

        void Delete_string(char *str,char *V)        
        {
            int len1=strlen(V);
            char *p=str,*q=str;
            char *string;
            while(*p!='\0')
            {
                if(strncmp(p,V,len1)==0)
                {
                    while(q!=p)
                    {
                        *string=*q;
                        q++;
                    }
                    strcat(string,p+len1);
                    str=string;
                    string=NULL;
                }
                p++;
            }
        }
};

int main()
{
    int len;
    char *str;

    
    return 0;
}