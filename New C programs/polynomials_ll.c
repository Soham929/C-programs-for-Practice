#include<stdio.h>
#include<malloc.h>
struct node
{
	int num;
	int coeff;
	struct node *next;
};
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;
struct node *last3 = NULL;

struct node *create_pol(struct node *start)
{
	struct node *newnode, *ptr;
	int n, c;
	printf("\n Enter the number:");
	scanf("%d",&n);
	printf("\t Enter the coefficient:");
	scanf("%d",&c);
	while(n!=-1)
	{
		if(start == NULL)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = n;
			newnode->coeff = c;
			newnode->next = NULL;
			start = newnode;
		}
		else
		{
			ptr = start;
			while(ptr->next != NULL)
				ptr = ptr->next;
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = n;
			newnode->coeff = c;
			newnode->next = NULL;
			ptr->next = newnode;
		}
		printf("\n Enter the number:");
		scanf("%d",&n);
		if(n==-1)
		break;
		printf("\t Enter its coefficient:");
		scanf("%d",&c);
}
return start;
}

