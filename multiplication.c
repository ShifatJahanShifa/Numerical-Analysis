#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	puts("enter the row and column number for the two matrix");
	int row1,column1,row2,column2;
	scanf("%d%d%d%d",&row1,&column1,&row2,&column2);
	
	int mat1[row1][column1],mat2[row2][column2]; 
	
	puts("enter the first matrix"); 
	for(int i=0;i<row1;i++) 
	{
		for(int j=0;j<column1;j++) 
		{
			scanf("%d",&mat1[i][j]); 
		} 
	} 
	
	puts("enter the second matrix"); 
	for(int i=0;i<row2;i++) 
	{
		for(int j=0;j<column2;j++) 
		{
			scanf("%d",&mat2[i][j]); 
		} 
	} 
	
	int resMat[row1][column2];
	for(int i=0;i<row1;i++) 
	{
		for(int j=0;j<column2;j++) 
		{
			resMat[i][j]=0;
		} 
	} 
	
	for(int i=0;i<row1;i++) 
	{
		for(int j=0;j<column2;j++) 
		{
			for(int k=0;k<column1;k++)
			{
				resMat[i][j]+=(mat1[i][k]*mat2[k][j]); 
			}
		} 
	} 
	
	for(int i=0;i<row1;i++) 
	{
		for(int j=0;j<column2;j++) 
		{
			printf("%d ",resMat[i][j]); 
		} 
		puts("");
	} 
}
	
	
