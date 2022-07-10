#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	struct node *next;
	int data;
	struct node *prev;
};
struct node *start = NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
int main()
{
	int choice;
	while(choice<9)
		{
               
                printf("\n                MENU                             \n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Delete a node from the beginning.      \n");
                printf("\n 4.Delete a node from the end.        \n");
                printf("\n 5.Delete before a given node.     \n");
                printf("\n 6.Delete after a given node.     \n");
                printf("\n 7.Delete the entire list.     \n");
				printf("\n 8.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        start=create(start);
                                        printf("\n Doubly Linked List Created.");
                                        break;
                        case 2:
                                        start=display(start);
                                        break;
                        case 3:
                        				start=delete_beg(start);
                        				break;
                        case 4:
                                        start=delete_end(start);
                                        break;
                        case 5:
                                        start=delete_before(start);
                        	            break;
                        case 6:
                        	 			start=delete_after(start);
                        	 			break;
                        case 7:
                        				start=delete_list(start);
                        				break;
                        case 8:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
struct node *create(struct node *start)
{
   struct node *new_node, *ptr;
   int num;
   char c;
   printf("\nEnter -1 to end.");
   printf("\nEnter the data:");
   scanf("%d",&num);
   while(num!=-1)
   { 
       if(start == NULL)
	   {
	   	 new_node = (struct node*)malloc(sizeof(struct node));
	   	 new_node->prev = NULL;
	   	 new_node->data = num;
	   	 new_node->next = NULL;
	   	 start = new_node;
	   }
	   else
	   {
	   	 ptr = start;
		 new_node = (struct node*)malloc(sizeof(struct node));
		 new_node->data = num;
		 while(ptr->next!=NULL)
		 ptr=ptr->next;
		 ptr->next=new_node;
		 new_node->prev=ptr;
		 new_node->next=NULL;	 
	   } 
	   printf("\nEnter the data:");
	   scanf("%d",&num);  
   }
   return start;
}
struct node *display(struct node*start)
{
	struct node *ptr;
	if(start == NULL)
	printf("\nList is empty.");
	else
	{
	ptr = start;
	while(ptr!=NULL)
	{
		printf("\t%d  <->",ptr->data);
		ptr = ptr->next;
	}
   }
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start = start->next;
	start->prev = NULL;
	free(ptr);
	return start;
}
struct node *delete_end(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->prev->next = NULL;
	free(ptr);
	return start;
}
struct node *delete_after(struct node *start)
{
	struct node *temp, *ptr;
   int val;
   printf("\nEnter the value after which the data has to be deleted.");
   scanf("%d",&val);
   ptr = start;
	while(ptr->data!=val)
	{
	ptr=ptr->next;
	if(ptr->data!=val && ptr->next==NULL)
	printf("\nValue not found.");
    }
	temp = ptr->next;
	ptr->next = temp->next;
	temp->next->prev = ptr;
	free(temp);
	return start;
}
struct node *delete_before(struct node *start)
{
	struct node *temp, *ptr;
   int val;
   printf("\nEnter the value before which the data has to be deleted.");
   scanf("%d",&val);
   ptr = start;
	while(ptr->data!=val)
	{
	ptr=ptr->next;
	if(ptr->data!=val && ptr->next==NULL)
	printf("\nValue not found.");
    }
	temp = ptr->prev;
	if(temp == start)
		start = delete_beg(start);
	else
	{
		ptr->prev = temp->prev;
		temp->prev->next = ptr;
	}
	free(temp);
	return start;
}
struct node *delete_list(struct node *start)
{
	while(start!=NULL)
	{
	start = delete_beg(start);
    }
	return start;
}
