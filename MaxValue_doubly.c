#include<stdio.h>
#include<stdlib.h>
//doubly linkedlist
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node* linkedlist(struct node*,int);
void display(struct node*);
void max(struct node*);
int main()
{
	int n,j;
	int num;
	struct node *head=NULL;
	printf("Input the no. of nodes: ");
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
			printf("Input data for node %d: ",j+1);
			scanf("%d",&num);
			head=linkedlist(head,num);
		}
		printf("Data entered in list are: \n");
		display(head);
		max(head);
	return 0;
}
struct node* linkedlist(struct node*head,int val)
{
	struct node *temp=head;
	struct node *ptr=malloc(sizeof(struct node));
	ptr->data=val;
	ptr->prev=NULL;
	ptr->next=NULL;
	if(head==NULL)
	{
	    head=ptr;
	    return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->prev=temp;
	return head;
}
void display(struct node *head)
{
	int i=1;
	struct node *temp=head;
	if(head==NULL)
	{
		printf("Linked list is empty!!!\n");
	}
	while(temp!=NULL)
	{
		printf("Node %d: %d\n",i,temp->data);
		temp=temp->next;
		i++;
	}
}
void max(struct node *head)
{
	int max=0;
	struct node *ptr=head;
	while(ptr!=NULL)
	{
		if(max<=ptr->data)
		max=ptr->data;
		ptr=ptr->next;
	}
	printf("The Maximum value in the Linked list is %d",max);
}


