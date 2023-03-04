#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

int main()
{
	puts("enter the row and column number of the matrix");
	int row,column;
	scanf("%d%d",&row,&column); 
	
	int mat[row][column+1];
	puts("enter the coefficient matrix"); 
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++) 
		{ 
			scanf("%d",&mat[i][j]); 
		} 
	}
	
	puts("enter the input vector");
	for(int i=0;i<row;i++)
	{
		scanf("%d",&mat[i][column]); 
	}
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<=column;j++) 
		{
			printf("%d ",mat[i][j]); 
		} 
		puts(""); 
	}
	
	/** upper triangular matrix **/
	for(int j=0;j<column;j++)
	{
		for(int i=j+1;i<row;i++) 
		{
			int m=mat[j][j];
			int n=mat[i][j]; 
			
			for(int k=0;k<=column;k++) 
			{
				mat[i][k]=(m*mat[i][k])-(n*mat[j][k]);
			} 
		} 
	}
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<=column;j++) 
		{
			printf("%d ",mat[i][j]); 
		} 
		puts(""); 
	}
	
	/** back substitution **/ 
	int ans[row];
	ans[row-1]=(mat[row-1][column]/mat[row-1][column-1]);
	
	printf("%d\n",ans[row-1]);
	for(int j=row-2;j>-1;j--)
	{
		int sum=0;
		for(int i=j+1;i<column;i++) 
		{
			sum+=(mat[j][i]*ans[i]); 
		} 
		
		ans[j]=(mat[j][column]-sum)/(mat[j][j]);
	}
	
	/** answer **/
	for(int i=0;i<row;i++) 
	{
		printf("%d\n",ans[i]);
	}
} 

