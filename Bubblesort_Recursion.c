#include<stdio.h>
//sorting using recursion
void sort(int arr[10],int n)
{
	int i,temp;
	if(n>0)
	{
		for(i=0;i<n;i++)
	    {
		    if(arr[i]>=arr[i+1])
		    {
		        temp=arr[i];
			    arr[i]=arr[i+1];
			    arr[i+1]=temp;
		    }
	    }
	    sort(arr,n-1);
	}
	else
	printf(" ");
}

int main()
{
	int n,i;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the values of an array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	printf("Array elements after sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
