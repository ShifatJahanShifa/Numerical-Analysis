#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 200
#define F(X) ((X*X*X) + (4*X*X)-10)
#define G(X) (10/(4+X))

int main()
{
	double x0,x1,tol,fx0,fx1,gx0;
	x0=1.5,tol=10.e-6;
	int i=0;
	//ga=G(a); 
	
	puts("a	      p       g(a)         f(p)");	

	while(i<MAXN)
	{
		i++;
		gx0=sqrt(G(x0));
		x1=gx0;
		fx1=F(x1);
		printf("%lf\t%lf\t%lf\t%lf\n",x0,x1,gx0,fx1);
		if(fabs(fx1)<=tol) 
		{
			printf("the approaximate solution is = %lf\n",x1); 
			printf("iteration number =%d\n",i);
			return EXIT_SUCCESS;
		}  
		x0=x1;
	}
	printf("iteration overflow . . . "); 
}
