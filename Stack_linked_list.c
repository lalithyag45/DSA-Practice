#include<stdio.h>
#include<stdlib.h>
//stack iplementation using linked list

struct node
{
	int info;
	struct node *ptr;
}*top,*top1,*temp;

int count=0;
//create a stack
void create()
{
top = NULL;
}
//no. of elements in stack
void stack_count()
{
printf("No. of elements in stack : %d\n", count);
}
//push an element into a stack
void push(int data)
{
if (top == NULL)
{
top =(struct node *)malloc(sizeof(struct node));
top->ptr = NULL;
top->info = data;
}
else
{
temp =(struct node *)malloc(sizeof(struct node));
temp->ptr = top;
temp->info = data;
top = temp;
}
count++;
printf("Element pushed successfully!!!\n");
}
//display stack
void display()
{
top1 = top;
if (top1 == NULL)
{
printf("Stack is empty\n");
return;
}
while (top1 != NULL)
{
printf("%d ",top1->info);
top1 = top1->ptr;
}
}
//pop element from stack
void pop()
{
top1 = top;
if (top1 == NULL)
{
printf("Error : Trying to pop from empty stack\n");
return;
}
else
top1 = top1->ptr;
printf("Popped value : %d\n", top->info);
free(top);
top = top1;
count--;
}
//return top element in a stack
int topelement()
{
return(top->info);
}
//check whether stack is empty or not
void empty()
{
if (top == NULL)
printf("Stack is empty\n");
else
printf("Stack is not empty with %d elements\n", count);
}
//destroy the stack
void destroy()
{
top1 = top;
if(top==NULL)
printf("Stack is already empty\n");
while (top1 != NULL)
{
top1 = top->ptr;
free(top);
top = top1;
top1 = top1->ptr;
}
free(top1);
top = NULL;
printf("All stack elements destroyed\n");
count = 0;
}

int main()
{
	int choice,num,top_ele;
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Top\n");
        printf("4 - Empty\n");
        printf("5 - Exit\n");
        printf("6 - Dipslay\n");
        printf("7 - Stack Count\n");
        printf("8 - Destroy stack\n");
        create();
	do
	{
		printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {case 1:
         printf("Enter data : ");
         scanf("%d",&num);
         push(num);
         break;
         case 2:
         pop();
         break;
         case 3:
         if (top == NULL)
         printf("No elements in stack\n");
         else
         {
         top_ele = topelement();
         printf("Top element : %d\n", top_ele);
         }
         break;
         case 4:
         empty();
         break;
         case 5:
         printf("Thank you");
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
         printf("Wrong choice, Please enter correct choice\n");
         break;
}
}
while(choice!=0);
return 0;
}

