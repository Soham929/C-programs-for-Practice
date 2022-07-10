#include<stdio.h>
int main()  
{  
    //Initialize array   
    int arr,n;   
	int length,query;
    scanf("%d",&length);
    scanf("%d",&n);
    scanf("%d",&query);
    //Rotate the given array by n times toward right  
    for( i = 0; i < n; i++){  
        int j, last;  
        
        last = arr[length-1];  
      
        for(j=(length-1);j>0;j--)
		{
			arr[j] = arr[j-1];
		  }  
        arr[0] = last;  
    }  
    for(i=0;i<query;i++)
    {
    	printf("%d",arr[i]);
	}
    return 0;  
}  
