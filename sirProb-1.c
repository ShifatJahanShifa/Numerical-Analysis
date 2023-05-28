#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define F(X) (X*X)
#define MAXN 200

int main()
{
	double a,b,tol;
	a=0.5,b=2,tol=10.e-6;
	
	// bisection task
	double m, fm,fa,fb;
	fa=sqrt(a)-F(a);
	fb=sqrt(b)-F(b);
	
	if(fa*fb>=0) 
	{
		puts("no root is here");
	 	exit(1);
	}
	
	puts("a      b       m       fa       fb        fm");
	for(int i=1;i<=MAXN;i++)
	{
		m=a+(b-a)/2;
		fm=sqrt(m)-F(m);
		
		printf("%19.6lf%19.6lf%19.6lf%19.6lf%19.6lf%19.6lf\n",a,b,m,fa,fb,fm);
		
		if(fabs(fm)<=tol)
		{
			printf("found root. root is = %.6lf\n",m);
			printf("iteration number = %d\n",i);
			return EXIT_SUCCESS;
		}
		
		if(fm*fa<0) 
		{
			b=m;
			fb=fm;
		}
		else 
		{
			a=m;
			fa=fm;
		}	
	}
	
	puts("iteration overflow");
}
