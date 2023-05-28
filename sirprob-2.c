#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXN 200
/*double cos(double x)
{
	double rad=3.14/180;
	return cos(rad*x);
}*/

int main()
{
	double a,b,tol,h;
	a=100,b=500,tol=10.e-6;
	double fx;
	h=(b-a)/20;
	
	// bisection task
	double m, fm,fa,fb;
	double rad=3.14159/180;
	fa=cos(a*rad);
	fb=cos(b*rad);
	if(fa*fb>=0) 
	{
		puts("no root is here");
	}
	
	double x[21],f[21];
	x[0]=a, x[20]=b;
	for(int i=1;i<20;i++) 
	{
		x[i]=x[i-1]+h;
	}
	
	for(int i=0;i<=20;i++) 
	{
		f[i]=cos(x[i]*rad);
	}
	
	for(int i=0;i<=20;i++) 
	{
		printf("%13.6lf,%13.6lf\n",x[i],f[i]);
	}
	
	double A,B;
	A=a;
	B=A+h;
	int cnt=0;
	puts("");
	puts("a      b       m       fa       fb        fm");
	
	while(B<=b)
	{
		fa=cos(A*rad);
		fb=cos(B*rad);
		cnt++;
		double a1,b1;
		a1=A,b1=B;
		if(fa*fb<0) 
		{
			for(int i=1;i<=MAXN;i++)
			{
				m=a1+(b1-a1)/2;
				fm=cos(m*rad);
		
							printf("%11.6lf%11.6lf%11.6lf%11.6lf%11.6lf%11.6lf\n",a1,b1,m,fa,fb,fm);
		
				if(fabs(fm)<=tol)
				{
					printf("found root. root is = %.6lf\n",m);
					printf("iteration number = %d\n",i);
					break;
				}	
				if(fm*fa<0) 
				{
					b1=m;
					fb=fm;
				}
				else 
				{
					a1=m;
					fa=fm;
				}	
			}
			puts("");
		}
		
		A=B;
		B=A+h;
	}
}
