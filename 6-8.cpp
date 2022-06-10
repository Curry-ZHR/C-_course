/*����String��*/
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

        void Replace_char(char *str,char ch,int i)      //����ĳ��λ���ϵ��ַ�
        {
            int j;
            char *p=str;
            for(j=0;j<i;j++)
                p++;
            *p=ch;                                      //p��ͣ���ڸ����ַ�λ����
        }

        void Replace_string(char *str,char *V,char *T)       //VΪ�����е��Ӵ� TΪ�滻��
        {
            int len1=strlen(V),len2=strlen(T);
            char *string;
            char *p=str,*q=str;
            while(*p!='\0')
            {
                if(strncmp(p,V,len1)==0)                     //�ҵ���һ��ģʽƥ�䴮 ���һ���滻
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
                *(str+j)=*(str+j+1);                            //ȫ����ǰŲһλ
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