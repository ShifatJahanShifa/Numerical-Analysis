#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#define MAXN 200

double bisection(double *root,double a,double b,double (*func)(double));

double sine(double x)
{
	double rad=3.14/180;
	return sin(rad*x);
}


int main()
{
	double a, b;
    printf("Enter the interval a and b: ");
    scanf("%lf %lf", &a, &b);
    
    double root1; 
    bisection(&root1,a, b, sine);
    printf("The root of func1 is: %lf\n", root1);

    //double root2 = bisection(a, b, func2);
   // printf("The root of func2 is: %lf\n", root2);

    return 0;
}

double bisection(double *root,double a, double b, double (*func)(double))
{
    double c;
    
    double fa,fb,fc,tol=10.e-6;
    fa=(*func)(a);
    fb=(*func)(b);
    
    if(fa*fb>=0) 
    {
    	puts("no roots");
    	return EXIT_FAILURE;
    } 
    
    int n=200,i=0;
    while (i<=n)
    {
        *root = a+(b-a)/2;
        fc=(*func)(*root);
        
        printf("%9.6lf   %9.6lf   %9.6lf   %9.6lf   %9.6lf   %9.6lf   %d\n",a,b,*root,fa,fb,fc,i);
        if (fabs(fc) <=tol)
            return c;
        else if (fc*fa < 0)
        {
        	   b=*root;
      	          fb=fc;
        } 
        else
        {
 	     	a = *root;
            	fa=fc;
       }
           i++;
    }
    //return c;
}

