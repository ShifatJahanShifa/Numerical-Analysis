#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define F1(y,z) ( 85-3*y+ 2*(z))/15
#define F2(x,z) ( 51-2*x- z)/10
#define F3(x,y) ( 5-x+ 2*(y))/8

int main()
{
	int i=0,j,k;
	double x10,x20,x30,x1,x2,x3;
	double tol=10.e-6;
	
	// approaximate part
	x10=x20=x30=0;
	
	while(1)
	{
		x1=F1(x20,x30);
		x2=F2(x1,x30);
		x3=F3(x1,x2);
		i++;
		if((fabs((x1-x10))< tol) && (fabs((x2-x20))< tol) && (fabs((x3-x30))< tol))
		{
			printf("x1=%9lf , x2=%9lf , x3=%9lf\n", x1,x2,x3);
			printf("no of iteration %d",i);
			break; 
		}
		
		x10=x1;
		x20=x2;
		x30=x3;
	} 
}
		
		
/*#include<stdio.h>
#include<math.h>
#define X 2
main()
{
    float x[X][X+1],a[X], ae, max,t,s,e;
    int i,j,r,mxit;
    for(i=0;i<X;i++) a[i]=0;
    puts(" Eneter the elemrnts of augmented matrix rowwise\n");
    for(i=0;i<X;i++)
    {
    for(j=0;j<X+1;j++)
    {
    scanf("%f",&x[i][j]);
    }
    }
    printf(" Eneter the allowed error and maximum number of iteration: ");
    scanf("%f%d",&ae,&mxit);
    printf("Iteration\tx[1]\tx[2]\n");
    for(r=1;r<=mxit;r++)
    {
        max=0;
        for(i=0;i<X;i++)
        {
            s=0;
            for(j=0;j<X;j++)
            if(j!=i) s+=x[i][j]*a[j];
            t=(x[i][X]-s)/x[i][i];
            e=fabs(a[i]-t);
            a[i]=t;
        }
        printf(" %5d\t",r);
        for(i=0;i<X;i++)
        printf(" %9.4f\t",a[i]);
        printf("\n");
        if(max<ae)
        {
            printf(" Converses in %3d iteration\n", r);
            for(i=0;i<X;i++)
            printf("a[%3d]=%7.4f\n", i+1,a[i]);
            return 0;
        }

        }
    }*/
