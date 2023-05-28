#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 200
#define F(X) ((X*X)-(3*X)+2)
#define DF(X) ((2*X)-3)

int main()
{
	double a,p,tol,fa,fp,dfa;
	a=0,tol=10.e-6;
	int i=0;
	fa=F(a),dfa=DF(a); 
	
	puts("a	      p       f(a)         df(a)          f(p)");	

	while(i<MAXN)
	{
		i++;
		p=a-(fa/dfa);
		fp=F(p);
		printf("%lf\t%lf\t%lf\t%lf\t%lf\n",a,p,fa,dfa,fp);
		if(fabs(fp)<=tol) 
		{
			printf("the approaximate solution is = %lf\n",p); 
			printf("iteration number =%d\n",i);
			return EXIT_SUCCESS;
		}  
		a=p;
		fa=fp;
		dfa=DF(p);
	}
	printf("iteration overflow . . . "); 
}
