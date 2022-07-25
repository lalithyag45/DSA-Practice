#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
int rollnumber;
char name[100];
char phone[100];
float percentage;
struct Student *next;
} *head;

//insert a node at beginning
void insert_beg(int rollnumber, char* name, char* phone, float percentage)
{
struct Student * student = (struct Student *) malloc(sizeof(struct Student));
student->rollnumber = rollnumber;
strcpy(student->name, name);
strcpy(student->phone, phone);
student->percentage = percentage;
student->next = NULL;
if(head==NULL)
{
head = student;
}
else
{
student->next = head;
head = student;
}
printf("Element is inserted successfully at the beg\n");
}
//insert a node at end
void insert_end(int rollnumber, char* name, char* phone, float percentage)
{
struct Student *student = (struct Student *) malloc(sizeof(struct Student));
struct Student *ptr=NULL;
student->rollnumber = rollnumber;
strcpy(student->name, name);
strcpy(student->phone, phone);
student->percentage = percentage;
student->next = NULL;
if(head==NULL)
{
	head=student;
}
else
{
	struct Student *temp=head;
	ptr=head->next;
	while(ptr!=NULL)
	{
		temp=temp->next;
		ptr=ptr->next;
	}
	temp->next=student;
}
printf("Element is inserted successfully at the end\n");	
}
//insertion at particular position
void insert_pos(int rollnumber, char* name, char* phone, float percentage,int pos)
{
struct Student *student = (struct Student *) malloc(sizeof(struct Student));
struct Student *ptr=NULL;
student->rollnumber = rollnumber;
strcpy(student->name, name);
strcpy(student->phone, phone);
student->percentage = percentage;
student->next = NULL;
if(head==NULL)
{
	head=student;
}
else
{
	int i=1;
	ptr=head;
	while(i<pos-1)
	{
		ptr=ptr->next;
		i++;
	}
	student->next=ptr->next;
	ptr->next=student;
}
printf("Element is inserted successfully at position %d\n",pos);	
}
//search a node using roll number
void search(int rollnumber)
{
struct Student * temp = head;
while(temp!=NULL)
{
if(temp->rollnumber==rollnumber)
{
printf("Student with roll number %d is found !!!\n", rollnumber);
printf("Roll Number: %d\t", temp->rollnumber);
printf("Name: %s\t", temp->name);
printf("Phone Number: %s\t", temp->phone);
printf("Percentage: %f\t", temp->percentage);
return;
}
temp = temp->next;
}
printf("Student with roll number %d is not found !!!\n", rollnumber);
}

//update a node
void update(int rollnumber)
{
struct Student * temp = head;
while(temp!=NULL)
{
if(temp->rollnumber==rollnumber)
{
printf("Record with roll number %d Found !!!\n", rollnumber);
printf("Enter new name: ");
scanf("%s", &temp->name);
printf("Enter new phone number: ");
scanf("%s", &temp->phone);
printf("Enter new percentage: ");
scanf("%f",&temp->percentage);
printf("Updation successfull\n");
return;
}
temp = temp->next;
}
printf("Student with roll number %d is not found !!!\n", rollnumber);
}
//delete a node at beg
void Delete_beg()
{
struct Student * temp = head;
if(head==NULL)
{
printf("Link is empty\n");
}
else
{
head = head->next;
free(temp);
temp=NULL;
printf("Record Successfully Deleted !!!\n");
}
}
//delete node at end
void Delete_end()
{
struct Student * temp1 = head;
struct Student * temp2 = head;
if(head==NULL)
{
printf("Link is empty\n");
}
else
{
	while(temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
    temp2->next=NULL;
    free(temp1);
    temp1=NULL;
    printf("Record Successfully Deleted !!!\n");
}
}
//delete a node at particular pos
void Delete_pos(int pos)
{
struct Student * temp1 = head;
struct Student * temp2 = head;
int i=1;
if(head==NULL)
{
printf("Link is empty\n");
}
else
{
	while(i<pos)
	{
		temp2=temp1;
		temp1=temp1->next;
		i++;
	}
    temp2->next=temp1->next;
    free(temp1);
    temp1=NULL;
    printf("Record Successfully Deleted !!!\n");
}
}
//count the no. of nodes
void count()
{
	int count=0;
	struct Student *ptr=NULL;
	ptr=head;
	if(ptr==NULL)
	printf("List is empty\n");
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	printf("The no.of nodes are %d\n",count);
}
//display the node
void display()
{
struct Student *temp = NULL;
temp=head;
while(temp!=NULL)
{
printf("Roll Number: %d\n" ,temp->rollnumber);
printf("Name: %s\n", temp->name);
printf("Phone Number: %s\n" ,temp->phone);
printf("Percentage: %f\n\n" ,temp->percentage);
temp = temp->next;
}
}

int main()
{
head = NULL;
int choice,pos;
char name[100];
char phone[100];
int rollnumber;
float percentage;

printf("PRESS\n1 to INSERT_BEG\n2 to INSERT_END\n3 to INSERT_POS\n4 to SEARCH\n5 to DELETE_BEG\n");
printf("6 to DELETE_POS\n7 to DELETE_END\n8 to UPDATE\n9 to COUNT\n10 to DISPLAY\n0 to EXIT");
do
{
printf("\nEnter Choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
    printf("Enter roll number: ");
    scanf("%d",&rollnumber);
    printf("Enter Name: ");
    scanf("%s",&name);
    printf("Enter Phone Number: ");
    scanf("%s",&phone);
    printf("Enter percentage: ");
    scanf("%f",&percentage);
    insert_beg(rollnumber, name, phone, percentage);
    break;
case 2:
    printf("Enter roll number: ");
    scanf("%d",&rollnumber);
    printf("Enter Name: ");
    scanf("%s",&name);
    printf("Enter Phone Number: ");
    scanf("%s",&phone);
    printf("Enter percentage: ");
    scanf("%f",&percentage);
    insert_end(rollnumber, name, phone, percentage);
    break;
case 3:
    printf("Enter roll number: ");
    scanf("%d",&rollnumber);
    printf("Enter Name: ");
    scanf("%s",&name);
    printf("Enter Phone Number: ");
    scanf("%s",&phone);
    printf("Enter percentage: ");
    scanf("%f",&percentage);
    printf("Enter the position: ");
    scanf("%d",&pos);
    insert_pos(rollnumber, name, phone, percentage,pos);
    break;
case 4:
    printf("Enter roll number to search: ");
    scanf("%d", &rollnumber);
    search(rollnumber);
    break;
case 5:
    Delete_beg();
    break;
case 6:
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    Delete_pos(pos);
    break;
case 7:
    Delete_end();
    break;
case 8:
    printf("Enter roll number to update: ");
    scanf("%d",&rollnumber);
    update(rollnumber);
    break;
case 9:
    count();
    break;
case 10:
    display();
    break;
default:
    printf("Thank you");
}
} 
while (choice != 0);
return 0;
}
