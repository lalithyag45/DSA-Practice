#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *ptr;
}; 
struct node *top,*top1,*temp;
int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
int count = 0;
int main()
{
int choice,num,top_ele; 
printf("\n1 - Push");
printf("\n2 - Pop");
printf("\n3 - Top");
printf("\n4 - Empty");
printf("\n5 - Exit");
printf("\n6 - Dipslay");
printf("\n7 - Stack Count");
printf("\n8 - Destroy stack");
create();
while (1)
{
printf("\nEnter choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("\nEnter data : ");
scanf("%d",&num);
push(num);
break;
case 2:
pop();
break;
case 3:
if (top == NULL)
printf("\nNo elements in stack");
else
{
top_ele = topelement();
printf("\nTop element : %d", top_ele);
}
break;
case 4:
empty();
break;
case 5:
exit(0);
case 6:
display();
break;
case 7:
stack_count();
break;
case 8:
destroy();
break;
default :
printf("Wrong choice, Please enter correct choice");
break;
}
}
}
/* Create empty stack */
void create()
{
top = NULL;
}

/* Count stack elements */

void stack_count()
{
printf("\nNo. of elements in stack : %d", count);
}
/* Push data into stack */
void push(int data)
{
if (top == NULL)
{
top =(struct node *)malloc(1*sizeof(struct node));
top->ptr = NULL;
top->info = data;
}
else
{
temp =(struct node *)malloc(1*sizeof(struct node));
temp->ptr = top;
temp->info = data;
top = temp;
}
count++;
}
/* Display stack elements */
void display()
{
top1 = top;
if (top1 == NULL)
{
printf("Stack is empty");
return;
}
while (top1 != NULL)
{
printf("%d ",top1->info);
top1 = top1->ptr;
}
}
/* Pop Operation on stack */
void pop()
{
top1 = top;
if (top1 == NULL)
{
printf("\nError : Trying to pop from empty stack");
return;
}
else
top1 = top1->ptr;
printf("\nPopped value : %d", top->info);
free(top);
top = top1;
count--;
}
/* Return top element */
int topelement()
{
return(top->info);
}
/* Check if stack is empty or not */
void empty()
{
if (top == NULL)
printf("\nStack is empty");
else
printf("\nStack is not empty with %d elements", count);
}
/* Destroy entire stack */
void destroy()
{
top1 = top;
while (top1 != NULL)
{
top1 = top->ptr;
free(top);
top = top1;
top1 = top1->ptr;
}
free(top1);
top = NULL;
printf("\nAll stack elements destroyed");
count = 0;
}
