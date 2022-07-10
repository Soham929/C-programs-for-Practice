#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct stack1
{
	int data;
	struct stack1 *next;
};
struct stack1 *top1 = NULL;
struct stack1 *push1(struct stack1 *,int);
struct stack1 *display1(struct stack1 *);
struct stack1 *pop1(struct stack1 *);

int stack[100], top = -1;
void push(int stack[], int val);
int pop(int stack[]);
void display(int stack[]);

int main()
{
	int val,choice,option;
	printf("Enter 1 to perform stack operations using arrays and 2 for using linked lists.");
	scanf("%d",&option);
	if(option==1)
	{
	do
	{
		printf("\n    MAIN MENU    ");
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Display");
		printf("\n 4. Exit.");
		printf("\nEnter your choice.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\n Enter the number to be pushed on the stack.");
					scanf("%d",&val);
					push(stack,val);
					break;
			case 2:
					val = pop(stack);
					if(val!=-1)
					printf("The value deleted from the stack is: %d",val);
					break;
			case 3:
					display(stack);
					break;
		}
	}
	while(choice<4);
	return 0;
}
	else	
	{
	   do
	{
		printf("\n    MAIN MENU    ");
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Display");
		printf("\n 4. Exit.");
		printf("\nEnter your choice.");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\n Enter the number to be pushed on the stack.");
					scanf("%d",&val);
					top1 = push1(top1,val);
					break;
			case 2:
					top1 = pop1(top1);
					break;
			case 3:
					display1(top1);
					break;
		}
	}
	while(choice<4);
	return 0;
	}
}
struct stack1 *push1(struct stack1 *top1, int val)
{
	struct stack1 *ptr;
	ptr = (struct stack1*)malloc(sizeof(struct stack1));
	ptr->data = val;
	if(top1 == NULL)
	{
		ptr->next = NULL;
		top1 = ptr;
	}
	else
	{
		ptr->next = top1;
		top1 = ptr;
	}
	return top1;
}
struct stack1 *display1(struct stack1 *top1)
{
	struct stack1 *ptr;
	ptr = top1;
	if(top1 == NULL)
	printf("\nStack is empty.");
	else
	{
		while(ptr != NULL)
		{
			printf("\n %d",ptr->data);
			ptr = ptr->next;
		}
	}
	return top1;
}
struct stack1 *pop1(struct stack1 *top1)
{
	struct stack1 *ptr;
	ptr = top1;
	if(top1 == NULL)
	{
		printf("\n Stack underflow.");
	}
	else
	{
		top1 = top1->next;
		printf("\nThe value being deleted is:%d ",ptr->data);
		free(ptr);
	}
	return top1;
	}
void push(int stack[],int val)
{
	if(top == 100-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		top++;
		stack[top]=val;
	}
}
int pop(int stack[])
{
	int val;
	if(top == -1)
	{
		printf("\nSTACK UNDERFLOW.");
		return -1;
	}
	else
	{
		val = stack[top];
		top--;
		return val;
	}
}
void display(int stack[])
{
	int i;
	if(top==-1)
	printf("\nThe stack is empty.");
	else
	{
		for(i=top;i>=0;i--)
		printf("\n %d",stack[i]);
		printf("\n");
	}
}
