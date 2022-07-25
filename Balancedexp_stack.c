#include<stdio.h>
#include<string.h>
//checking balanced expression-stack
char sample[10];
int size,top=-1;
void push(char);
void pop(char);
int main()
{
	int i;
	char stack[10];
	printf("Enter the characters: ");
	gets(stack);
	size=strlen(stack);
	for(i=0;i<size;i++)
	{
		if(stack[i]=='{' || stack[i]=='[' || stack[i]=='(')
		push(stack[i]);
		else
		pop(stack[i]);
	}
	if(top==-1)
	printf("Balanced expression");
	else
	printf("Not a Balanced expression");

}
void push(char c)
{
	if(top>=size)
	printf("Stack overflow\n");
	else
	{
		top++;
		sample[top]=c;
	}
	
}
void pop(char c)
{
	if((c==')'&&sample[top]=='(') ||(c==']' && sample[top]=='[')||(c=='}' && sample[top]=='{'))
	top--;
}
