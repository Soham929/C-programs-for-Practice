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
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
int main()
{
	int choice;
	while(choice<8)
		{
               
                printf("\n                MENU                             \n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Add a node at the beginning.      \n");
                printf("\n 4.Add a node at the end.        \n");
                printf("\n 5.Insert before a given node.     \n");
                printf("\n 6.Insert after a given node.     \n");
				printf("\n 7.Exit       \n");
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
                        				start=insert_beg(start);
                        				break;
                        case 4:
                                        start=insert_end(start);
                                        break;
                        case 5:
                                        start=insert_before(start);
                        	            break;
                        case 6:
                        	 			start=insert_after(start);
                        	 			break;
                        case 7:
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
	ptr = start;
	while(ptr!=NULL)
	{
		printf("\t%d  <->",ptr->data);
		ptr = ptr->next;
	}
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
   int num;
   printf("\nEnter the data:");
   scanf("%d",&num);
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = num;
   start->prev = new_node;
   new_node->next = start;
   new_node->prev = NULL;
   start = new_node;
   return start;
}
struct node *insert_end(struct node *start)
{
   struct node *new_node, *ptr;
   int num;
   printf("\nEnter the data:");
   scanf("%d",&num);
   ptr = start;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
    new_node->next=NULL;	 
   return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node, *ptr;
   int num,val;
   printf("\nEnter the data:");
   scanf("%d",&num);
   printf("\nEnter the value before which the data has to be inserted.");
   scanf("%d",&val);
   ptr = start;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	while(ptr->data!=val)
	{
	ptr=ptr->next;
	if(ptr->data!=val && ptr->next==NULL)
	printf("\nValue not found.");
    }
   	new_node->next = ptr;
	new_node->prev = ptr->prev;
	ptr->prev->next = new_node;
	ptr->prev = new_node;
	return start;
}
struct node *insert_after(struct node *start)
{
	struct node *new_node, *ptr;
   int num,val;
   printf("\nEnter the data:");
   scanf("%d",&num);
   printf("\nEnter the value after which the data has to be inserted.");
   scanf("%d",&val);
   ptr = start;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	while(ptr->data!=val)
	{
	ptr=ptr->next;
	if(ptr->data!=val && ptr->next==NULL)
	printf("\nValue not found.");
    }
	new_node->prev = ptr;
	new_node->next = ptr->next;
	ptr->next->prev = new_node;
	ptr->next = new_node;
	return start;
}
