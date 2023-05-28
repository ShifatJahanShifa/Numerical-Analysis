#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 200
#define F(X) ((X*X*X) + (4*X*X)-10)


int main()
{
	double a,b,p,tol,fa,fp,fb;
	a=1.5,b=2,tol=10.e-6;
	int i=0;
	fa=F(a),fb=F(b); 
	
	puts("a	      b        p       f(a)         f(b)         p        f(p)");	

	while(i<MAXN)
	{
		i++;
		p=(a*fb-b*fa)/(fb-fa);
		fp=F(p);
		printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",a,b,p,fa,fb,p,fp);
		if(fabs(fp)<=tol) 
		{
			printf("the approaximate solution is = %lf\n",p); 
			printf("iteration number =%d\n",i);
			return EXIT_SUCCESS;
		}  
		a=b;
		b=p;
		fa=fb;
		fb=fp;
	}
	printf("iteration overflow . . . "); 
}
