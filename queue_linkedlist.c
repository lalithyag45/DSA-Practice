#include<stdio.h>
#include<stdlib.h>
#define size 3
//queue implementation
struct Node
{
   int data;
   struct Node *next;
};
struct Node *front = NULL,*rear = NULL;

void EnQueue(int);
void DeQueue();
void display();
void Front();
int QueueSize();
void retrive();
void empty();
int full();

int main()
{
    int choice, value;
    printf("*** Queue Implementation using Linked List ***\n");
    printf("\n****** MENU ******\n");
        printf("1. Insert in Queue\n");
        printf("2. Delete From Queue\n");
        printf("3. Display Queue\n");
        printf("4. Front of the Queue\n");
        printf("5. Size of Queue\n");
        printf("6. Retrive data\n");
        printf("7. Exit\n");
    while(choice!=7)
    {
    	printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
                printf("Insert the value you want to enter: ");
                scanf("%d", &value);
                EnQueue(value);
                break;
         case 2:
                DeQueue();
                break;
         case 3:
                display();
                break;
         case 4:
                Front();
                break;
         case 5:
                printf("Size of the queue is %d \n",QueueSize());
                break;
         case 6:
         	    retrive();
         	    break;
         case 7:
         	    printf("Thank you");
                exit(0);
         default:
                printf("\nInvalid Selection!!..Select valid number please!!\n");
        };
    }
   return 0;
}

void EnQueue(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(front == NULL)
    {
    	front = rear = newNode;
    	printf("Data inserted in Queue!!!\n");
	}
    else if(full()==1)
    printf("Queue is full!!!\n");
    else
    {
        rear -> next = newNode;
        rear = newNode;
        printf("Data inserted in Queue!!!\n");
    }
}
void DeQueue()
{
        empty();
        struct Node *temp = front;
        front = front -> next;
        printf("Deleted element is: %d\n", temp->data);
        free(temp);
}

void display()
{
        empty();
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            printf("%d --> ",temp->data);
            temp = temp -> next;
        }
        printf("%d \n", temp->data);
}

void Front()
{
    printf("Data at front of the queue is %d \n",front->data);
}
int QueueSize()
{
        empty();
        int count=0;
        struct Node *temp = front;
        while(temp!= NULL)
        {
            count++;
            temp = temp -> next;
        }
        return count;
}
void retrive()
{
	struct Node *temp=rear;
	empty();
	printf("Data retrived from rear node is %d\n",temp->data);
}
void empty()
{
	if(front==NULL)
	printf("Queue is Empty!!!\n");
}
int full()
{
	int count;
	count=QueueSize();
	if(count>size-1)
	{
		return 1;
	}
	return 0;
}
