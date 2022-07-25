#include<stdio.h>
#include<stdlib.h>
//selection sort

int main()
{
	int last,min,i,j,temp;
	int arr[]={23,12,56,34,6};
	i=0;
	while(i<5)
	{
		
		min=arr[i];
		j=i++;
		while(j<5)
		{
			if(min>=arr[j])
			{
				temp=min;
				min=arr[j];
				arr[j]=temp;
			}
		    j++;
		}
		i++;
	}
	for(i=0;i<5;i++)
	printf("%d\n",arr[i]);
	return 0;
}
