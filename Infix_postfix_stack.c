#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//to include isdigit() isalpha();
#define size 100

char stack[size];
int top=-1;
void push(char item)
{
	if(top>=size-1)
	printf("Stack overflow\n");
	else
	{
		top++;
		stack[top]=item;
	}
}
char pop()
{
	char c;
	if(top<0)
	printf("Stack underflow\n");
	else
	{
		c=stack[top];
		top--;
		return c;
	}
}
int precedence(char item)
{
	if(item=='^')
	return 3;
	if(item=='*' || item=='/')
	return 2;
	else if(item=='+' || item=='-')
	return 1;
	else
	return 0;
}
int is_operator(char symbol)
{
if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;
	push('(');                               /* push '(' onto stack */
	strcat(infix_exp,")");                  /* add ')' to infix expression */
 
	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/
	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(is_operator(item) == 1)        		
		{
		    x=pop();
	        while(is_operator(x) == 1 && precedence(x)>= precedence(item))
	        {
				postfix_exp[j] = x;            
				j++;
				x = pop();                       
			}
			 
			push(x);
			push(item);                 
		}
		else if(item == ')')         
		{
			x = pop();                   
			while(x != '(')                
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        
			exit(1);
		}
		i++;
		item = infix_exp[i]; 
	    postfix_exp[j] = '\0'; 
 
}
}
int main()
{
	char infix[size];
	char postfix[size];
	printf("Enter Infix Expression: ");
	gets(infix);
	InfixToPostfix(infix,postfix);
	printf("PostFix expression: ");
	puts(postfix);
}

