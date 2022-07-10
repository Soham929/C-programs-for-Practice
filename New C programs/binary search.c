#include<stdio.h>
void binarysearch(int arr[100],int n);
void main()
{
	int n,arr[100],i,pos,num;
	printf("/nEnter the number of elements in the array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d th element: ",(i+1));
		scanf("%d",&arr[i]);
	}
	binarysearch(arr,n);
}
void binarysearch(int arr[100],int n)
{
	int beg=0,mid,end=(n-1),num,found = 0;
	printf("/nEnter the value to be searched: ");
	scanf("%d",&num);
	while(beg<=end)
	{
		mid = (beg+end)/2;
		if(num==arr[mid])
		{
			found = 1;
			printf("value is found at position %d",(mid+1));
			break;
		}
		else if(num<arr[mid])
		{
			end = mid-1;
		}
		else
		{
			beg = mid+1;
		}
	}
	if(beg>0 && found == 0)
	printf("\nValue not found");
}
