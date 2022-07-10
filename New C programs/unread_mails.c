#include<stdio.h>
int main()
{
	int n,i,flag,k,temp,renumbering = 0;
	printf("Enter the number of unread mails: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(k=2;k<i;k++)
		{
			if(i%k == 0)
			{
				printf("\n%d is not prime",i);
				temp++;
				break;
			}
		}	
	}
	renumbering++;
	printf("\n%d",temp);
	flag = temp;
	temp = 0;
	for(i=1;i<=flag;i++)
	{
		for(k=2;k<i;k++)
		{
			if(i%k == 0)
			{
				printf("\n%d is not prime",i);
				temp++;
				break;
			}
		}	
	}
	renumbering++;
	if(temp == 1)
	{
		renumbering++;
	}
	printf("\nThe number of renumberings is: %d",renumbering);
	return 0;
	
}
