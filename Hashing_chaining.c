#include<stdio.h>
#include<stdlib.h>
#define size 7

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size]={NULL};

void insert(int value)
{
    //create a newnode with value
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}
int search(int value)
{
    int key = value % size;
    struct node *temp = chain[key];
    while(temp)
    {
        if(temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int i,key,element;
    printf("Enter the keys:\n");
    for(i=0;i<size;i++)
    {
    	scanf("%d",&key);
    	insert(key);
	}
    print();
    printf("Enter the element to be searched: ");
    scanf("%d",&element);


    if(search(element))
        printf("Search Found\n");
    else
        printf("Search Not Found\n");

    return 0;
}

