#include<iostream>
#include<cmath>
using namespace std;

class Point
{
    private:
        double A,B,C,D;
	public:
		Point(double a=0,double b=0,double c=0,double d=0)
		{
			A=a,B=b,C=c,D=d;
		 } 
		
		void Set_func(double a,double b,double c,double d)
		{
			A=a,B=b,C=c,D=d;
		}
		
		double Distance(double a,double b,double c,double d)
		{
			double x,y;
			x=(a-b)*(a-b);
			y=(c-d)*(c-d);
			
			return sqrt(x+y);
		}
		
};

int main()
{
	int x1,x2,y1,y2;
	Point local;
	
	cout<<"请输入两点坐标:"<<endl;
	cin>>x1>>y1>>x2>>y2;
	
	local.Set_func(x1,x2,y1,y2);
	cout<<"距离为:"<<local.Distance(x1,x2,y1,y2);
	
	return 0;
}