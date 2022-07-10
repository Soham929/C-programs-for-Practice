#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{ 
   int data;
   struct node *next;
};
struct node *start = NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_list(struct node *);

int main()     
{
        int choice;
        while(choice<9)
		{
               
                printf("\n                MENU                             \n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Add a node at the beginning      \n");
                printf("\n 4.Add a node at the end        \n");
                printf("\n 5.Delete from the beginning     \n");
                printf("\n 6.Delete from the end     \n");
                printf("\n 7.Delete from the entire list     \n");
				printf("\n 8.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        start=create(start);
                                        printf("\n Circular Linked List Created.");
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
                                        start=delete_beg(start);
                                        break;
                        case 6:
                                        start=delete_end(start);
                                        break;
                        case 7:
                        	            start=delete_list(start);
                        	            printf("\n Circular Linked List Deleted.");
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
   printf("\nEnter -1 to end.");
   printf("\nEnter the data:");
   scanf("%d",&num);
   while(num!=-1)
   { 
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->data = num;
      if(start == NULL)
      { 
         new_node->next = new_node;
         start = new_node;
	  }
	  else
	  { 
	     ptr = start;
	     while(ptr->next != start)
	     {
		    ptr = ptr->next;
	     }  
		 ptr->next = new_node;
	     new_node->next = start;
	  }
	  printf("\nEnter the data:");
	  scanf("%d",&num);
   }
   return start;
}


struct node *display(struct node *start)
{ 
  struct node *ptr;
  ptr = start;
  if(start==NULL)
  { 
    printf("\nThe list is empty.");
  }
  while(ptr->next != start)
	     {
	     	printf("\t %d", ptr->data);
		    ptr = ptr->next;
	     }
	     printf("\t %d", ptr->data);
	     return start;
}

struct node *insert_beg(struct node *start)
{ 
   struct node *new_node, *ptr;
   int num;
   printf("\nEnter the data:");
   scanf("%d", &num); 
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = num;
   ptr = start;
   while(ptr->next != start)
   {
		    ptr = ptr->next;
    }  
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
	return start;   
}

struct node *insert_end(struct node *start)
{ 
   struct node *new_node, *ptr;
   int num;
   printf("\nEnter the data:");
   scanf("%d", &num); 
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = num;
   ptr = start;
   while(ptr->next != start)
   {
		    ptr = ptr->next;
    }  
    ptr->next = new_node;
    new_node->next = start;
	return start;   
}

struct node *delete_beg(struct node *start)
{ 
   struct node *ptr;
   ptr = start;
   while(ptr->next != start)
   { 
     ptr = ptr->next;
   }
   ptr->next = start->next;
   free(start);
   start = ptr->next;
   return start;
}

struct node *delete_end(struct node *start)
{ 
   struct node *ptr, *preptr;
   ptr = start;
   while(ptr->next != start)
   { 
      preptr = ptr;
      ptr = ptr->next;
   }
   preptr->next = ptr->next;
   free(ptr);
   return start;
}


struct node *delete_list(struct node *start)
{ 
   struct node *ptr;
   ptr = start;
   while(ptr->next != start)
      start = delete_end(start);
   free(start);
   
   return start;
}















