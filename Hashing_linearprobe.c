#include<stdio.h>
//Hashing- modulo division and linear probe
void insert();
void display();
void search();
int arr[10];
int n;
int main()
{
	printf("Enter the size of array: ");
	scanf("%d",&n);
	insert();
	display();
	search();
}

void insert()
{
	int i,index,element;
	printf("Enter the keys:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&element);
		index=element%10;
		while(arr[index]!=0)
		{
			index=(index+1)%10;
		}
		arr[index]=element;
	}
}
void display()
{
	int i;
	printf("The elements in hash table are:\n");
	for(i=0;i<10;i++)
	{
		printf("%d\n",arr[i]);
	}
}
void search()
{
	int search,index,found=0,probe=0;
	printf("Enter the element to be searched: ");
	scanf("%d",&search);
	index=search%10;
	while(arr[index]!=0)
	{
		probe++;
		if(arr[index]==search)
		{
			printf("Element found with probe %d",probe);
			found=1;
			break;
		}
		index=(index+1)%10;
	}
	if(found!=1)
	printf("Element not found");
	
}
