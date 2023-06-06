#include <stdio.h>
#include <math.h>

void main()
{
    int row1,column1, i, j, p, q, flag;
    double a[10][10], d[10][10], s[10][10], s1[10][10], s1t[10][10];
    double temp[10][10], theta, zero=1e-5, max, pi=3.141592654;

    printf("Enter the row and column size of the matrix ");
    scanf("%d%d",&row1,&column1);

    int mat1[row1][column1];

    puts("enter the matrix");
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<column1; j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }

    int transpose[column1][row1];

    for(int i=0; i<column1; i++)
    {
        for(int j=0; j<row1; j++)
        {
            transpose[i][j]=mat1[j][i];
        }
    }

    int resMat[column1][column1];
    for(int i=0; i<column1; i++)
    {
        for(int j=0; j<column1; j++)
        {
            resMat[i][j]=0;
        }
    }

    for(int i=0; i<column1; i++)
    {
        for(int j=0; j<column1; j++)
        {
            for(int k=0; k<row1; k++)
            {
                resMat[i][j]+=(transpose[i][k]*mat1[k][j]);
            }
        }
    }

    int n=column1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            a[i][j]=resMat[i][j];
    }

    printf("The symmetric matrix is\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf ("%8.4f ", a[i][j]);
        printf ("\n");
    }
    printf ("\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            d[i][j]= a[i][j];
            if(i==j)
                s[i][j]= 1;
            else
                s[i][j]= 0;
        }
    }

    do
    {
        flag= 0;
        p=0;
        q=1;
        max= fabs(d[p][q]);

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=j)
                {
                    if (max < fabs(d[i][j]))
                    {
                        max= fabs(d[i][j]);
                        p= i;
                        q= j;
                    }
                }
            }
        }

        if(d[p][p]==d[q][q])
        {
            if (d[p][q] > 0)
                theta= pi/4;
            else
                theta= -pi/4;
        }
        else
        {
            theta=0.5*atan(2*d[p][q]/(d[p][p]-d[q][q]));
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j)
                {
                    s1[i][j]= 1;
                    s1t[i][j]= 1;
                }
                else
                {
                    s1[i][j]= 0;
                    s1t[i][j]= 0;
                }
            }
        }

        s1[p][p]= cos(theta);
        s1t[p][p]= s1[p][p];

        s1[q][q]= cos(theta);
        s1t[q][q]= s1[q][q];

        s1[p][q]= -sin(theta);
        s1[q][p]= sin(theta);

        s1t[p][q]= s1[q][p];
        s1t[q][p]= s1[p][q];

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                temp[i][j]= 0;
                for(p=0; p<n; p++)
                    temp[i][j]+= s1t[i][p]*d[p][j];
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                d[i][j]= 0;
                for(p=0; p<n; p++)
                    d[i][j]+= temp[i][p]*s1[p][j];
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                temp[i][j]= 0;
                for(p=0; p<n; p++)
                    temp[i][j]+= s[i][p]*s1[p][j];
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                s[i][j]= temp[i][j];
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=j)
                    if(fabs(d[i][j]) > zero)
                        flag= 1;
            }
        }
    }
    while(flag==1);

    double eigenValues[n];
    puts("eigen values are: ");
    for(i=0; i<n; i++)
    {
        printf("%8.4lf ",d[i][i]);
        eigenValues[i]=(d[i][i]);
    }

    puts("\ncorresponding eigen vectors are: ");
    for(j=0; j<n; j++)
    {
        printf("(");
        for(i=0; i<n-1; i++)
            printf("% 8.4lf,",s[i][j]);
        printf("%8.4lf )^T\n",s[n-1][j]);
    }

    double tem;
    double u[row1][column1];
    for(int i=1; i<n; i++)
    {
        for(int j=n-1; j>=i; j--)
        {
            if(eigenValues[j-1]<eigenValues[j])
            {
                tem=eigenValues[j-1];
                eigenValues[j-1]=eigenValues[j];
                eigenValues[j]=tem;

                for(int k=0; k<n; k++)
                {
                    tem=s[k][j-1];
                    s[k][j-1]=s[k][j];
                    s[k][j]=tem;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        eigenValues[i]=sqrt(eigenValues[i]);
    }

    int t=0;
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<column1; j++)
        {
            u[i][j]=0;
        }
    }
    while(t<column1)
    {
        double clone1[row1][column1];
        for(int i=0; i<row1; i++)
        {
            for(int j=0; j<column1; j++)
            {
                clone1[i][j]=mat1[i][j];
            }
        }

        double multi=1/eigenValues[t];

        for(int i=0; i<row1; i++)
        {
            for(int j=0; j<column1; j++)
            {
                clone1[i][j]=clone1[i][j]*multi;
            }
        }

        for(int i=0; i<row1; i++)
        {
            //for(int j=0; j<column1; j++)
            for(int k=0; k<column1; k++)
            {
                u[i][t]+=(clone1[i][k]*s[k][t]);
            }
        }
        t++;
    }


    printf("\nThe corresponding U is: \n");
    for(j=0; j<column1; j++)
    {
        printf("(");
        for(i=0; i<row1-1; i++)
            printf("% 8.4lf,",u[i][j]);
        printf("%8.4lf )^T\n",u[row1-1][j]);
    }

    printf("\nthe singular matrix: \n");
    for(int i=0;i<column1;i++)
    {
        for(int j=0;j<column1;j++)
        {
            if(i==j) printf("% 8.4lf ",eigenValues[i]);
            else printf("% 8.4lf ",0.0);
        }
        puts("");
    }

    printf("\nthe corresponding V^T is: \n");
    for(j=0; j<n; j++)
    {
        //printf("(");
        for(i=0; i<n-1; i++)
            printf("% 8.4lf ",s[i][j]);
        printf("%8.4lf \n",s[n-1][j]);
    }

}
