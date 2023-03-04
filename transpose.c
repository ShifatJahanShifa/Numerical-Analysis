#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	puts("enter the row and column number for the matrix");
	int row1,column1;
	scanf("%d%d",&row1,&column1);
	
	int mat1[row1][column1]; 
	
	puts("enter the matrix"); 
	for(int i=0;i<row1;i++) 
	{
		for(int j=0;j<column1;j++) 
		{
			scanf("%d",&mat1[i][j]); 
		} 
	} 
	
	int transpose[column1][row1];
	
	for(int i=0;i<column1;i++) 
	{
		for(int j=0;j<row1;j++) 
		{
			transpose[i][j]=mat1[j][i]; 
		} 
	} 
	
	puts("transpose matrix of the given matrix");
	for(int i=0;i<column1;i++) 
	{
		for(int j=0;j<row1;j++) 
		{
			printf("%d ",transpose[i][j]); 
		} 
		puts("");
	} 
	
	int resMat[column1][column1];
	for(int i=0;i<column1;i++) 
	{
		for(int j=0;j<column1;j++) 
		{
			resMat[i][j]=0;
		} 
	} 
	
	for(int i=0;i<column1;i++) 
	{
		for(int j=0;j<column1;j++) 
		{
			for(int k=0;k<row1;k++)
			{
				resMat[i][j]+=(transpose[i][k]*mat1[k][j]); 
			}
		} 
	} 
	
	for(int i=0;i<column1;i++) 
	{
		for(int j=0;j<column1;j++) 
		{
			printf("%d ",resMat[i][j]); 
		} 
		puts("");
	} 
}
