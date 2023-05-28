#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define F(X) (X*X)

int main()
{
	double a,b,h;
	int n;
	a=0,b=2,n=10;
	h=(b-a)/n;
	double x[n+1],fx[n+1],gx[n+1],hx[n+1];
	double p=(1.0/3.0);
	
	// setting x
	x[0]=a,x[n]=b;
	for(int i=1;i<n;i++) 
	{
		x[i]=x[i-1]+h;
	}
	
	// calculating fx and gx
	for(int i=0;i<=n;i++) 
	{
		fx[i]=F(x[i]);
		gx[i]=sqrt(x[i]); 
		hx[i]=gx[i]-fx[i];
	} 
	
	// output 
	//puts("\"x[i]\"      \"fx[i]\"      \"gx[i]\"");
	for(int i=0;i<=n;i++) 
	{
		printf("%9.3lf,%9.3lf,%9.3lf,%9.3lf\n",x[i],fx[i],gx[i],hx[i]);
	} 
}
