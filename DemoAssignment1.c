#include<stdio.h>
#include<stdlib.h>

int main()
{
	double x[4]={0,1,2,3},b[4][1]={1,0,1,2};
	double a[4][3],at[3][4],A[3][3],B[3][1],mat[3][4]; 
	
	for(int i=0;i<4;i++)
	{
		a[i][0]=1;
		a[i][1]=x[i];
		a[i][2]=x[i]*x[i];
		//a[i][3]=x[i]*x[i]*x[i];
	}
	
	
	/** making transpose matrix **/ 
	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<4;j++) 
		{
			at[i][j]=a[j][i]; 
		} 
	} 
	
	
	/* multilication of transpose matrix X matrix */
	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<4;j++) 
		{
			A[i][j]=0;
		} 
	} 
	
	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<3;j++) 
		{
			for(int k=0;k<4;k++)
			{
				A[i][j]+=(at[i][k]*a[k][j]); 
			}
		} 
	} 
	
	
	/* updating B */
	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<1;j++) 
		{
			B[i][j]=0;
		} 
	} 
	
	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<1;j++) 
		{
			for(int k=0;k<4;k++)
			{
				B[i][j]+=(at[i][k]*b[k][j]); 
			}
		} 
	} 
	
	
	/** using gauss elimination process to find the least square fitted values **/
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++) 
		{
			mat[i][j]=A[i][j];
		} 
		mat[i][3]=B[i][0];
	}
	
	
	/** upper triangular matrix **/
	for(int j=0;j<3;j++)
	{
		for(int i=j+1;i<3;i++) 
		{
			int m=mat[j][j];
			int n=mat[i][j]; 
			
			for(int k=0;k<=3;k++) 
			{
				mat[i][k]=(m*mat[i][k])-(n*mat[j][k]);
			} 
		} 
	}
	
	
	/** back substitution **/ 
	double ans[3];
	ans[3-1]=(mat[3-1][3]/mat[3-1][3-1]);
	
	for(int j=3-2;j>-1;j--)
	{
		double sum=0;
		for(int i=j+1;i<3;i++) 
		{
			sum+=(mat[j][i]*ans[i]); 
			//printf("sum %9.3lf\n",sum);
		} 
		
		ans[j]=(mat[j][3]-sum)/(mat[j][j]);
	}
	
	
	/** answer **/
	for(int i=0;i<3;i++) 
	{
		printf("c%d = %9.3lf\n",i+1,ans[i]);
	}
}
	
