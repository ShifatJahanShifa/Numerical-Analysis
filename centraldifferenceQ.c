#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define F(X) (X*X)+1

int main()
{
	double a,b,h;
	a=0.0,b=2.0;
	int n;
	n=10;
	double x[n+1],fx[n+1],dfx[n-1];
	h=(b-a)/n;
	
	// setting points(x)
	x[0]=a,x[n]=b;
	for(int i=1;i<n;i++)
	{
		x[i]=x[i-1]+h;
	}
	
	// setting f(x)
	for(int i=0;i<=n;i++) 
	{
		fx[i]=F(x[i]);
	}
	
	// dfx calculating 
	for(int i=1;i<n;i++) 
	{
		dfx[i-1]=(fx[i+1]-fx[i-1])/(2*h); 
	}
	
	// printing 
	puts("x        f(x)         df(x)");
	printf("%9.6lf%9.6lf   %s\n",x[0],fx[0],"...."); 
	for(int i=1;i<n;i++)
	{
		printf("%9.6lf%9.6lf%9.6lf\n",x[i],fx[i],dfx[i-1]); 
	}
	printf("%9.6lf%9.6lf   %s\n",x[n],fx[n],"...."); 
}
