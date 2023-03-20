#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	puts("enter the row and column number for the two matrix");
	int row1,column1,row2,column2;
	scanf("%d%d%d%d",&row1,&column1,&row2,&column2);
	
	double mat1[row1][column1],mat2[row2][column2]; 
	
	puts("enter the first matrix"); 
	for(int i=0;i<row1;i++) 
	{
		for(int j=0;j<column1;j++) 
		{
			scanf("%lf",&mat1[i][j]); 
		} 
	} 
	
	puts("enter the second matrix"); 
	for(int i=0;i<row2;i++) 
	{
		for(int j=0;j<column2;j++) 
		{
			scanf("%lf",&mat2[i][j]); 
		} 
	} 
	
	int it=1; 
	double t=0.0;
	while(1){
	
	double resMat[row1][column2];
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
	
	double max=0.0; 
	for(int i=0;i<row1;i++) 
	{
		for(int j=0;j<column2;j++) 
		{
			max=fmax(max,resMat[i][j]);
		} 
	} 
	
	
	for(int i=0;i<row1;i++) 
	{
		for(int j=0;j<column2;j++) 
		{
			mat2[i][j]=resMat[i][j]/max;
		} 
	} 	
	
	printf("%d  %9.6lf%9.6lf%9.6lf%9.6lf\n",it,mat2[0][0],mat2[1][0],mat2[2][0], max); 
	
	if(fabs(max-t)<0.000001) break; 
	t=max;
	it++;
	}
}		
