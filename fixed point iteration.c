#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Max 200
#define F(x) ((x*x*x) + (4*x*x)-10)
#define G(x) sqrt((10-(x*x*x))/4)
int main()
{
    double x0,x1,gx0,fx1,fx0,tol=10.0e-5;
    x0=1.25;
    fx0=F(x0);

    for(int i=0;i<Max;i++)
    {
        printf("\n%d   %lf   %lf   %lf   %lf\n",i+1,x0,x1,gx0,fx1);
        gx0= G(x0);
        x1=gx0;

        fx1=F(x1);


        if(fabs(fx1)<=tol)
        {
            printf("Absolute root = %lf, Itr = %d\n",x1,i+1);
            break;
        }
        else
        {
            x0=x1;
            fx0=fx1;
            gx0=x0+fx0;
        }
    }
}




