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
	
	/** identity matrix **/
	for(int j=0;j<row;j++)
	{
		for(int i=0;i<row;i++) 
		{
			if(j!=i)
			{
				int m=mat[j][j];
				int n=mat[i][j]; 
			
				for(int k=0;k<=column;k++) 
				{
					mat[i][k]=(m*mat[i][k])-(n*mat[j][k]);
				}
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
	
	/** getting solution **/ 
	int ans[row];
	
	for(int j=0;j<row;j++)
	{	
		ans[j]=(mat[j][column])/(mat[j][j]);
	}
	
	/** answer **/
	for(int i=0;i<row;i++) 
	{
		printf("%d\n",ans[i]);
	}
} 

