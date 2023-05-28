#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

#define F(X) C0+(C1*X)+(C2*X*X)+(C3*X*X*X)

#define MAX 11

int main()
{
	double b[MAX][1];
	double x[]={0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
	double fx[]={1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0};
	
	for(int i=0;i<MAX;i++) 
	{
		b[i][0]=fx[i];
	}
	
	double a[MAX][4];
	
	for(int i=0;i<MAX;i++) 
	{
		a[i][0]=1; 
		a[i][1]=x[i];
		a[i][2]=x[i]*x[i];
		a[i][3]=x[i]*x[i]*x[i]; 
	} 
	
	for(int i=0;i<MAX;i++) 
	{
		for(int j=0;j<4;j++) 
		{
			printf("%9.6lf ",a[i][j]); 
		} 
		puts(""); 
	}  
	
	double at[4][MAX]; 
	
	for(int i=0;i<MAX;i++) 
	{
		for(int j=0;j<4;j++) 
		{
			at[0][i]=a[i][0];
			at[1][i]=a[i][1];
			at[2][i]=a[i][2];
			at[3][i]=a[i][3]; 
		} 
	}  
	
	puts(""); 
	puts("transpose"); 	
	
	for(int i=0;i<4;i++) 
	{
		for(int j=0;j<MAX;j++) 
		{
			printf("%9.6lf ",at[i][j]); 
		} 
		puts(""); 
	}  
	
	
	// multiplication 
	
	double multi[4][4]; 
	
	for(int i=0;i<4;i++) 
	{
		for(int j=0;j<4;j++) 
		{
			multi[i][j]=0; 
		} 
	}
	
	for(int i=0;i<4;i++) 
	{
		for(int j=0;j<MAX;j++) 
		{
			for(int k=0;k<4;k++) 
			{ 
				multi[i][k]=; 
			} 
		} 
	} 
}

