#include<stdio.h>
#include<stdlib.h>
//circular linked list

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *first=NULL;
struct node *last=NULL;
int length=0;
void create(int);
void empty();
void insertbeg(int);
void insertend(int);
void insertpos(int);
void deletebeg();
void deleteend();
void deletepos();
void search(int);
void update(int);
void displaybeg();
void displayrev();
int main()
{
	int ch,val;
	printf("press 1.Create a node\n");
	printf("2. Insert at beg\n");
	printf("3. Insert at end\n");
	printf("4. Insert at pos\n");
	printf("5. update\n");
	printf("6. Delete at beg\n");
	printf("7. Delete at end\n");
	printf("8. Delete at pos\n");
	printf("9. search\n");
	printf("10. display from beg\n");
	printf("11. display reverse\n");
	printf("12. Exit\n");
	while (1)
    {
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 :
        	printf("Enter the element to create a node:");
        	scanf("%d",&val);
            create(val);
            break;
        case 2 :
        	printf("Enter the element to insert at beg:");
        	scanf("%d",&val);
            insertbeg(val);
            break;
        case 3 :
        	printf("Enter the element to insert at end:");
        	scanf("%d",&val);
            insertend(val);
            break;
        case 4 :
        	printf("Enter the element to insert at pos:");
        	scanf("%d",&val);
            insertpos(val);
            break;
        case 5 :
        	printf("Enter the element to update:");
        	scanf("%d",&val);
            update(val);
            break;
        case 6 :
            deletebeg();
            break;
        case 7:
            deleteend();
            break;
        case 8:
            deletepos();
            break;
        case 9:
        	printf("Enter the element to search:");
        	scanf("%d",&val);
            search(val);
            break;
        case 10:
            displaybeg();
            break;
        case 11:
        	displayrev();
        	break;
        case 12:
        	printf("Thank you");
        	exit(1);
        default:
            printf("Invalid choice");                
        }
    }
    return 0;
}

//creating a anode
void create(int val)
{
	struct node *newNode=malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=NULL;
	newNode->prev=NULL;
	first=newNode;
	last=newNode;
	length++;
	printf("Node is created\n");
}
//checking whethwe the node is empty or not
void empty()
{
	if(first==NULL && last==NULL)
	{
		printf("List is empty!!!\n");
		return;
	}
}
void insertbeg(int val)
{
	struct node *newNode=malloc(sizeof(struct node));
	newNode->data=val;
	empty();
	newNode->next=first;
	first->prev=newNode;
	first=newNode;
	newNode->prev=last;
	last->next=first;
	length++;
	printf("Node inserted at begining\n");
}
void insertend(int val)
{
	struct node *newNode=malloc(sizeof(struct node));
	empty();
	newNode->data=val;
	newNode->prev=last;
	last->next=newNode;
	last=newNode;
	newNode->next=first;
	first->prev=last;
	length++;
	printf("Node inserted at end\n");
}
void insertpos(int val)
{
	struct node *newNode=malloc(sizeof(struct node));
	struct node *prevnode=first;
	int pos,i;
	newNode->data=val;
	empty();
	printf("Enter the position to be inserted: ");
	scanf("%d",&pos);
	if(length<pos)
	{
		printf("Cant insert as length is less\n");
	}
	else
	{
		i=1;
		while(i<pos-1)
		{
			prevnode=prevnode->next;
			i++;
		}
		newNode->next=prevnode->next;
		newNode->prev=prevnode;
		prevnode->next=newNode;
		newNode->next->prev=newNode;
		printf("Node inserted at position %d\n",pos);
		length++;
	}
}
void deletebeg()
{
	struct node *temp=first;
	first=temp->next;
	last->next=first;
	first->prev=last;
	free(temp);
	printf("First Node deleted\n");
	length--;
}
void deleteend()
{
	struct node *temp=last;
	last=temp->prev;
	last->next=first;
	first->prev=last;
	free(temp);
	printf("Last Node deleted\n");
	length--;
}
void deletepos()
{
	struct node *prevnode=first;
	struct node *ptr=NULL;
	int pos,i;
	empty();
	printf("Enter the position to be deleted: ");
	scanf("%d",&pos);
	if(length<pos)
	{
		printf("Cant delete as pos exceded length\n");
	}
	else
	{
		for (ptr = first, i = 1;i <= length; i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
            }
		prevnode->next = ptr->next;
        ptr->next->prev = prevnode;
        free(ptr);
		printf("Node deleted\n");
		length--;
	}
}
void search(int val)
{
	struct node *temp=first;
	int i=1;
	empty();
	while(i<length)
	{
		if(val==temp->data)
		{
			printf("Search value found at position %d\n",i);
			return;
		}
		i++;
		temp=temp->next;
	}
	printf("Value not found\n");
}
void update(int val)
{
	struct node *temp=first;
	int i=1,newval;
	empty();
	while(i<length)
	{
		if(val==temp->data)
		{
			printf("Enter the new value: ");
			scanf("%d",&newval);
			temp->data=newval;
			printf("Value updated\n");
			return;
		}
		i++;
		temp=temp->next;
	}
	printf("Value not found\n");
}
void displaybeg()
{
	struct node *ptr=NULL;
	empty();
	int i=1;
	for (ptr = first, i = 0;i < length;i++,ptr = ptr->next)
    printf("%d ", ptr->data);
    printf("\n");
}
void displayrev()
{
    struct node *ptr=NULL;
	empty();
	int i=1;
	for (ptr = last, i = 0;i < length;i++,ptr = ptr->prev)
    printf("%d ", ptr->data);
    printf("\n");
}

