#include<stdio.h>
int main()
{
	int i,n,j,arr[100],temp,min=0,max=0;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[j+1]<arr[j])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=1;i<n;i++)
	{
		max+=arr[i];
	}
	
	for(i=0;i<(n-1);i++)
	{
		min+=arr[i];
	}
	printf("\n%d %d",min,max);
	return 0;
}
