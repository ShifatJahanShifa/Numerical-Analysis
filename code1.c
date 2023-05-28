#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r,c;
	scanf("%d%d",&r,&c);
	
	double matrix[r][c],ab[r][c+1];
	double b[3];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf("%lf",&matrix[i][j]);
		}
	}
	
	for(int i=0;i<3;i++)
	{
		scanf("%lf",&b[i]);
		//matrix[i][3]=b[i];
	}
	int j;
	for(int i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			ab[i][j]=matrix[i][j];
		}
		ab[i][j]=b[i];
	}
	
	puts("1:");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<=c;j++)
		{
			printf("%9.3lf ",ab[i][j]);
		}
		puts("");
	}
	
	// r2 and r3
	puts("");
	double k,l;
	for(int i=0;i<r-1;i++)
	{
		for(int j=i+1;j<r;j++)
		{
			k=ab[i][i];
			l=ab[j][i];
			for(int a=0;a<=c;a++)
			{
				ab[j][a]=k*ab[j][a]-l*ab[i][a];
				ab[i][a]=l*ab[i][a];
				//ab[2][i]*=x;
			} 
		} 
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<=c;j++)
		{
			printf("%9.3lf   ",ab[i][j]);
		}
		puts(""); 
	}
	
	puts("");
	
	for(int i=0;i<r;i++)
	{
		l=ab[i][i];
		for(int j=0;j<=c;j++)
		{
			ab[i][j]/=l;
		}
	}
	
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<=c;j++)
		{
			printf("%9.3lf   ",ab[i][j]);
		}
		puts(""); 
	}
	
	puts("");
	
	
	// back substitution 
	for(int i=0;i
	
}
	
	

