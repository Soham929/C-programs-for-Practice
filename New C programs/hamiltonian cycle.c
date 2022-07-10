#include<stdio.h>
#define NODE 4

int graph[NODE][NODE];
int path[NODE];

void displayCycle() {    //Function to display the cycle obtained
   printf("The Hamilton Cycle : \n");
	int i;
   for (i = 0; i < NODE; i++)
      printf(" %d ",path[i]);
   printf(" %d \n",path[0]);      //print the first vertex again
}

int isValid(int v, int k) {
   int i;
   if (graph [path[k-1]][v] == 0)   //if there is no edge
      return 0;
	
   for (i = 0; i < k; i++)   //if vertex is already taken, skip that
      if (path[i] == v)
         return 0;
   return 1;
}

int cycleFound(int k) {
   if (k == NODE) {             //when all vertices are in the path
      if (graph[path[k-1]][ path[0] ] == 1 )
         return 1;
      else
         return 0;
   }
	int v;
   for (v = 1; v < NODE; v++) {       //for all vertices except starting point
      if (isValid(v,k)) {                //if possible to add v in the path
         path[k] = v;
         if (cycleFound (k+1) == 1)
            return 1;
         path[k] = -1;               //when k vertex will not in the solution
      }
   }
   return 0;
}

int hamiltonianCycle() {
	int i;
   for (i = 0; i < NODE; i++)
      path[i] = -1;
   path[0] = 0;     //first vertex as 0

   if ( cycleFound(1) == 0 ) {
      printf("Solution does not exist\n");
      return 0;
   }

   displayCycle();
   return 1;
}

int main() {
	int i,j;
	printf("Enter the Graph : \n");
	for (i=0;i<NODE;i++){
		for (j=0;j<NODE;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	printf("\n");
	printf("\nThe graph is: \n");
	for (i=0;i<NODE;i++){
		for (j=0;j<NODE;j++){
			printf(" %d ",graph [i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
   	hamiltonianCycle();
   	return 0;
  }
