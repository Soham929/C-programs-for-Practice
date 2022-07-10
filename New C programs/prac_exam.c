#include<stdio.h>

void parenthesis(int s[100][100],int i,int j)
{
	if(i == j)
		printf(" A%d ",i);
	else
	{
		printf("( ");
		parenthesis(s,i,s[i][j]);
		parenthesis(s,s[i][j]+1,j);
		printf(" )");
	}
}
void matrixchainorder(int p[100],int n)
{
	int i,j,k,l,q;
	int mat[100][100],s[100][100];
	for(i=0;i<n;i++)
	{
		mat[i][i] = 0;
	}
	
	for(l=1;l<n;l++)
	{
		for(i=0;i<n-l;i++)
		{
			j=i+l;
			mat[i][j] = 999;
			for(k=i;k<j;k++)
			{
				q = mat[i][k]+mat[k+1][j]+(p[i]*p[k+1]*p[j+1]);
				if(q<mat[i][j])
				{
					mat[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	printf("\nThe cost matrix M is: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\nThe S matrix is: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d ",s[i][j]);
		}
		printf("\n");
	}
	printf("\nOptimal Parenthesis is: ");
	parenthesis(s,0,n-1);
	printf("\nMinimum number of scalar multiplications is: %d",mat[0][n-1]);
}
int main()
{
	int i,j,k,n,p[100];
	printf("Enter the total number of matrices: ");
	scanf("%d",&n);
	printf("\nEnter the dimension vector: ");
	for(i=0;i<n+1;i++)
	{
		scanf("%d",&p[i]);
	}
	matrixchainorder(p,n);
	return 0;
}
