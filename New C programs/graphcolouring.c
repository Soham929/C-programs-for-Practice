#include<stdio.h>
int c=0;
int colour(int arr[100][100],int k,int i,int sol[100]) //checks if kth vertex can be ith coloured
{
	int j;
	for(j=1;j<=k;j++)
	{
		if(arr[k][j]==1 && sol[j]==i)
		{
			return 0;
		}
	}
	return 1;
}
void graphColouring(int arr[100][100],int k,int n,int m,int sol[100])
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		if(colour(arr,k,i,sol))
		{
			sol[k]=i;
			if(k==n)
			{
				for(j=1;j<=n;j++)
				printf("%d ",sol[j]);
				c++;
				printf("\n");
			}
			else
				graphColouring(arr,k+1,n,m,sol);
		}
	}
}
int main()
{
	int i,j,n,m,arr[100][100],sol[100];
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the number of colours: ");
	scanf("%d",&m);
	printf("\nEnter the adjacency matrix: ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&arr[i][j]);		
		}
	}
	printf("\n\nThe solution sets are: \n");
	graphColouring(arr,1,n,m,sol);
	printf("\nTotal number of solutions are: %d",c);
	return 0;
}
