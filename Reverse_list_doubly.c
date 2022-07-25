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
struct node* reverse(struct node*,struct node*);
int main()
{
	int t,n,i,j;
	int num;
	struct node *head=NULL;
	struct node *revhead=NULL;
	scanf("%d %d",&t,&n);
	for(i=0;i<t;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&num);
			head=linkedlist(head,num);
		}
		revhead=reverse(head,revhead);
		display(revhead);
	}
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
	struct node *temp=head;
	if(head==NULL)
	{
		printf("Linked list is empty!!!\n");
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

struct node* reverse(struct node* head,struct node *revhead)
{
	struct node *ptr1=head;
	struct node *ptr2=ptr1->next;
	ptr1->prev=ptr2;
	ptr1->next=NULL;
	while(ptr2!=NULL)
	{
		ptr2->prev=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr2->prev;
	}
	revhead=ptr1;
	return revhead;
}
