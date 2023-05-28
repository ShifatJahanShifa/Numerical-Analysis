#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 200
#define F(X) ((X*X*X) + (4*X*X)-10)

int main()
{
	double a,b,p,tol,fa,fb,fp;
	a=1.25,b=1.50,tol=10e-6;
	int i=0;
	fa=F(a),fb=F(b); 
	
	if(fa*fb>=0) 
	{
		puts("no root");
		return EXIT_FAILURE; 
	}
	
	puts("a	      b        c         f(a)         f(b)          f(c)");	

	while(i<MAXN)
	{
		i++;
		p=a+(b-a)/2;
		fp=F(p);
		printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",a,b,p,fa,fb,fp);
		if(fabs(fp)<=tol) 
		{
			printf("the approaximate solution is = %lf\n",p); 
			printf("iteration number =%d\n",i);
			return EXIT_SUCCESS;
		}  
		else 
		{
			if(fp*fa<0) 
			{
				b=p;
				fb=fp; 
			} 
			else 
			{
				a=p;
				fa=fp; 
			}
		} 
		 
	}
	printf("iteration overflow . . . "); 
}
