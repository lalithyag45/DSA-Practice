#include<stdio.h>
#include<string.h>
//stack and queue

void enqueue(char);
void push(char);
char dequeue();
char pop();

int  top=-1,rear=-1,front=0,stack[20],queue[20],len;
int main()
{
	char s[20]="racecar";
    len=strlen(s);
	int i,j=0,count=0;
	for(i=0;i<len;i++)
	{
		push(s[i]);
		enqueue(s[i]);
	}
	while(j<len)
	{
	if(pop()==dequeue())
	{
		count++;
	}
	j++;
	}
	
	if(len==count)
	printf("The word %s is a palindrome",s);
	else
	printf("The word %s is not a palindrome",s);
	return 0;
}

void push(char c)
{
	if(top<len)
	{
	top++;
	stack[top]=c;
	}
	else
	printf("stack is overflow\n");
}
void enqueue(char c)
{
	if(rear<len)
	{
	rear++;
	queue[rear]=c;
	}
	else
	printf("queue is overflow\n");
}
char pop()
{
	if(top>-1)
	{
		top--;
		return stack[top+1];
	}
	else
	printf("Stack is underflow");
}
char dequeue()
{
	if(front<len)
	{
		front++;
		return queue[front-1];
	}
	
	else
	printf("queue is underflow");
}
