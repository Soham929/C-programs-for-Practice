#include <stdio.h>
#include<limits.h>
#define INFY 999999999
long int m[20][20];
int s[20][20];
int p[20],i,j,n;

void parenthesis(int i,int j)
{
if (i == j)
printf(" A%d ",i);
else
   {
      printf("( ");
      parenthesis(i, s[i][j]);
      parenthesis(s[i][j] + 1, j);
      printf(" )");
   }
}

void matmultiply(void)
{
	long int q;
	int k,l;
	for(i=1;i<=n;i++)
	{
		m[i][i] = 0;
	}
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j = i+l-1;
			m[i][j] = 999;
	    }
    }
	for(i=n;i>0;i--)
 	{
   		for(j=i;j<=n;j++)
    	{
     		if(i==j)
       			m[i][j]=0;
     		else
       		{
        		for(k=i;k<j;k++)
        		{
         			q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
         			if(q<m[i][j])
          			{
            			m[i][j]=q;
            			s[i][j]=k;
          			}
         		}
        	}
       }
 	}
}

void main()
{
	int k;
	printf("Enter the no. of matrices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
 			s[i][j]=0;
		}
	}
	printf("\nEnter the dimensions: \n");
	for(k=0;k<=n;k++)
	{
 		printf("P%d: ",k);
 		scanf("%d",&p[k]);
	}
	matmultiply();
	printf("\nCost Matrix M:\n");
	for(i=1;i<=n;i++)
 	{
 		for(j=1;j<=n;j++)
  		{		
	  		printf(" %ld ",m[i][j]);
		}
		printf("\n");
 	}

	i=1,j=n;
	printf("\nMultiplication Sequence : ");
	parenthesis(i,j);
	printf("\nMinimum number of multiplications is : %d ",m[1][n]);
}
