#include<stdio.h>
#include<stdlib.h>
#define MAXN 11

int main()
{
	double x[MAXN]={0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
	double b[MAXN][1]={1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0};
	double a[MAXN][4],at[4][MAXN],A[4][4],B[4][1],mat[4][5]; 
	for(int i=0;i<MAXN;i++)
	{
		a[i][0]=1;
		a[i][1]=x[i];
		a[i][2]=x[i]*x[i];
		a[i][3]=x[i]*x[i]*x[i];
	}
	
	
	/** making transpose matrix **/ 
	for(int i=0;i<4;i++) 
	{
		for(int j=0;j<=MAXN;j++) 
		{
			at[i][j]=a[j][i]; 
		} 
	} 
	
	
	/* multilication of transpose matrix X matrix */
	for(int i=0;i<4;i++) 
	{
		for(int j=0;j<4;j++) 
		{
			A[i][j]=0;
		} 
	} 
	
	for(int i=0;i<4;i++) 
	{
		for(int j=0;j<4;j++) 
		{
			for(int k=0;k<MAXN;k++)
			{
				A[i][j]+=(at[i][k]*a[k][j]); 
			}
		} 
	} 
	
	
	/* updating B */
	for(int i=0;i<4;i++) 
	{
		for(int j=0;j<1;j++) 
		{
			B[i][j]=0;
		} 
	} 
	
	for(int i=0;i<4;i++) 
	{
		for(int j=0;j<1;j++) 
		{
			for(int k=0;k<MAXN;k++)
			{
				B[i][j]+=(at[i][k]*b[k][j]); 
			}
		} 
	} 
	
	
	/** using gauss elimination process to find the least square fitted values **/
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++) 
		{
			mat[i][j]=A[i][j];
		} 
		mat[i][4]=B[i][0];
	}
	
	
	/** upper triangular matrix **/
	for(int j=0;j<4;j++)
	{
		for(int i=j+1;i<4;i++) 
		{
			double m=mat[j][j];
			double n=mat[i][j]; 
			
			for(int k=0;k<=4;k++) 
			{
				mat[i][k]=(m*mat[i][k])-(n*mat[j][k]);
			} 
		} 
	}
	
	
	/** back substitution **/ 
	double ans[4];
	ans[4-1]=(mat[4-1][4]/mat[4-1][4-1]);
	
	for(int j=4-2;j>-1;j--)
	{
		double sum=0;
		for(int i=j+1;i<4;i++) 
		{
			sum+=(mat[j][i]*ans[i]); 
		} 
		
		ans[j]=(mat[j][4]-sum)/(mat[j][j]);
	}
	
	/** answer **/
	printf("(c1 ,c2 ,c3 ,c4) = (");
	for(int i=0;i<4;i++) 
	{
		if(i!=3)
		printf("%5.3lf, ",ans[i]); 
		else 
		printf("%5.3lf)\n",ans[i]); 
	}
	
}
	
