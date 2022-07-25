#include<stdio.h>
//sorting in ascending order using insertion sort
int main()
{
	int i,j,n,temp;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	int array[n];
	i=0;
	printf("Enter the values for an array:\n");
	while(i<n)
	{
		scanf("%d",&array[i]);
		i++;
	}
	for(i=1;i<n;i++)
	{
		temp=array[i];
		for(j=i-1;j>=0;j--)
		{
			if(array[j]>=temp)
			{
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
	printf("Sorted elements are:\n");
	for(i=0;i<n;i++)
	printf("%d\n",array[i]);
}
