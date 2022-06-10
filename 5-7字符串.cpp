#include <iostream>
#include <cstring>
using namespace std;

class String{
	private:
		char *string;
	public:
		void inputString(char *string){
			this->string=new char(strlen(string)+1);
			strcpy(this->string,string);
			this->string[strlen(string)]='\0';				//???为什么要重新归0？
		}
		String(){
			string='\0'; 
		} 
		 
		
		bool IsSubstring(const char *str){
			int i=0,j=0,count=0;
			int flag=0;
			while(i<strlen(string)&&j<strlen(str)){
				if(string[i]==str[j]){
					i++;
					j++;
					if(j==strlen(str))  flag=1;
				}
				else {
					i=count;
					count++;
					j=0;
				}
			}
			if(flag==1)  return true;
			else return false;	
		}
		
		bool IsSubstring(const String &Str){
			char *pstr=Str.string;
			int length=strlen(string);
			int i,j;
			for(i=0;i<length;i++){
				int k=i;
				for(j=0;j<length;j++,k++)				//用来比较两个字符串长度相同？
				  if(pstr[j]!=string[i])  break;
				if(j==length)  return true;
			}
			return false;
			
		}
		
		void str2num(){
			int num[50];
			int i;
				cout<<"after the transform:  ";
			for(i=0;i<strlen(string);i++){
				num[i]=string[i]-48;
				cout<<num[i];			//数组？
			}
			
		}
		//把字符串转换成大写字母 
		void toUppercase(){ 
		  string[strlen(string)+1]='\0';
		   while(*string!='\0'){
		   	 if(*string>='a'&&*string<='z'){
		   	 	  *string-=32;
		   	 	  cout<<*string;
			string++;
			}
	}
		}
};

int main(){
	char strr[50],strrr[50];
	String A;
	bool flag1,flag2;
	cout<<"input the main number string:  ";
	cin>>strr;
	cout<<"input the second number string: ";
	cin>>strrr;
	A.inputString(strr);			//将字符串值存入对象中
	flag1=A.IsSubstring(strrr);
	if(flag1==true)  cout<<"the result of the first method is:Yes!"<<endl;
	else cout<<"the result of the first method is:No!"<<endl;
	flag2=A.IsSubstring("105");
	if(flag1==true)  cout<<"the result of the second method is:Yes!"<<endl;
	else cout<<"the result of the second method is:No!"<<endl;
	cout<<"input the main letter string:  ";
	cin>>strr;
	A.inputString(strr);
	A.toUppercase();
	
	
}
