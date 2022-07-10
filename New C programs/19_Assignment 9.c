#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 25
#include<stdlib.h>
char st[MAX];
void push(char st[],char);
char pop(char st[]);
void reverse(char str[]);
int top = -1;
void InfixtoPostfix(char source[], char target[]);
int priority(char);
char infix[100],postfix[100],temp[100];
int main()
{	
	printf("\nEnter any infix expression: ");
	gets(infix);
	reverse(infix);
    InfixtoPostfix(temp, postfix);
	reverse(postfix);
	printf("\nThe prefix expression is: ");
	puts(temp);
	getch();
	return 0;	
}
void push(char st[],char val)
{
	if(top==MAX-1)
	{
		printf("\nOverflow");
	}
	else
	{
		top++;
		st[top]=val;
	}
}
char pop(char st[])
{
	char val=' ';
	if(top==-1)
	{
		printf("\n Underflow");
	}
	else
	{
		val=st[top];
		top--;
	}
	return val;
}
int priority(char op)
{
	if(op == '/' || op == '*' || op == '%')
	return 1;
	else if(op == '+' || op == '-')
	return 0;
}
void InfixtoPostfix(char source[],char target[])
{
	int i=0,j=0;
	char temp;
	while(source[i]!='\0')
	{
		if(source[i]=='(')
		{
			push(st,source[i]);
			i++;
		}
		else if(source[i]==')')
		{
			while((top!=-1)&& (st[top]!='('))
			{
				target[j]=pop(st);
				j++;
			}
			temp=pop(st);
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i]))
		{
			target[j]=source[i];
			j++;
			i++;
		}
		else if(source[i]=='/'||source[i]=='*'||source[i]=='%'||source[i]=='+'||source[i]=='-')
		{
			while((top!=-1)&&(st[top]!='(')&&(priority(st[top])>priority(source[i])))
			{
				target[j]=pop(st);
				j++;
			}
			push(st,source[i]);
			i++;
		}
	}
	while((top!=-1)&&(st[top]!='('))
	{
		target[j] = pop(st);
		j++;
	}
	target[j]='\0';
}
void reverse(char str[])
{
	int len, i=0, j=0;
	len = strlen(str);
	j = len - 1;
	while(j>=0)
	{
		if(str[j] == '(')
		temp[i] = ')';
		else if(str[j] == ')')
		temp[i] = '(';
		else
		temp[i] = str[j];
		i++ , j--;
	}
	temp[i] = '\0';
}

