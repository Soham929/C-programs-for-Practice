#include<stdio.h>
int sum(int n,int a,int b,int c)
{ 
   if(n==1)
   return a;
   if(n==2)
   return b;
   if(n==3)
   return c;
   else
   return sum(n-1,a,b,c)+sum(n-2,a,b,c)+sum(n-3,a,b,c);
}
int main()
{
	int n,a,b,c,ans;
	printf("Enter the number of terms you want to enter:");
	scanf("%d",&n);
	printf("Enter the first three terms of the series:");
	scanf("%d %d %d",&a,&b,&c);
	ans = sum(n,a,b,c);
	printf("The value of the n-th term of this series where the sum of each term is the sum of the previous three terms is:%d",ans);
	return 0;
}
