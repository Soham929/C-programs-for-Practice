#include<stdio.h>
int main()
{
	int arr[100],n,i,temp[100];
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		temp[i]=arr[n-i-1];
		printf("%d ",temp[i]);
	}
	return 0;
}
