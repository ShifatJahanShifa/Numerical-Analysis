#include<stdio.h>
#include<stdlib.h>

int main()
{
    double a,b;
    int n;
    scanf("%lf%lf",&a,&b);
    scanf("%d",&n);
    double x[11]={0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
    double fx[11]={1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0};
    double h=(b-a)/n;

    double sumX=fx[0]+fx[10];
    double sumI=0.0;
    for(int i=1;i<10;i++) sumI+=fx[i];

    double integration=(h*(sumX+(2*sumI)))/2;
    printf("the value is = %9.6lf\n",integration);
}
