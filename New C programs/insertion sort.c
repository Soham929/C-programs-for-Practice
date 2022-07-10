#include<stdio.h>
int main()
{
	int n,arr[100],i,j,k,temp;
	printf("/nEnter the number of elements in the array: ");
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		printf("Enter the %d th element: ",(k+1));
		scanf("%d",&arr[k]);
	}
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	printf("\nThe sorted array is: \n");
	for(k=0;k<n;k++)
	{
		printf(" %d ",arr[k]);
	}
	return 0;
}

	
