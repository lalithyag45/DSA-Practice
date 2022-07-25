#include<stdio.h>
#include<string.h>
//reversing a string-stack
char stack[20],rev[20];
int size,top=-1;
void push();
void pop();
int main()
{
	int i;
	printf("Enter the string to be reversed: ");
	gets(stack);
	size=strlen(stack);
	for(i=0;i<size;i++)
	{
		push();
		//inserting elements to rev using push();
	}
	for(i=0;i<size;i++)
	{
		pop();
		//to pop elements from rev and display;
    }
}
void push()
{
	if(top>=size)
	printf("Stack overflow\n");
	else
	{
		top++;
		rev[top]=stack[top];
	}
	
}
void pop()
{
	char c;
	if(top<=-1)
	printf("Stack underflow\n");
	else
	{
		c=rev[top];
		top--;
		printf("%c",c);
	}
	
}
