#include<stdio.h>
void sort(int array[],int n)
{
	static int i=0;
	int j,temp;
	if(n>=0)
	{
		i++;
		temp=array[i];
	    for(j=i-1;j>=0;j--)
	    {
		if(array[j]>=temp)
		{
			array[j+1]=array[j];
			array[j]=temp;
		}
	    }
	    sort(array,n-1);
	}
	else
	printf("");

}
int main()
{
	int i,n;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	int array[n];
	printf("Enter the values for an array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	sort(array,n);
	printf("Sorted values are:\n");
	for(i=0;i<n;i++)
	printf("%d\n",array[i]);
	return 0;
}
