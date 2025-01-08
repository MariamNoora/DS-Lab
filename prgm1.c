#include<stdio.h>
#include<stdlib.h>

void merge(int arr1[],int arr2[],int s1, int s2, int mer[])
{
	int i=0,j=0,k=0;	
	while(i<s1&&j<s2)
	{
		if(arr1[i]<arr2[j])
		{
			mer[k++]=arr1[i++];
			
		}
		else
		{
			mer[k++]=arr2[j++];
		
		}
	}
	while(i<s1)
	{
		mer[k++]=arr1[i++];
		
	}
	while(j<s2)
	{
		mer[k++]=arr2[j++];
		
	}

}

int main()
{
	int s1,s2,i,j,k;

	printf("\nEnter number of elements in first array:\t");
	scanf("%d",&s1);
	int *arr1=(int *)malloc(s1*sizeof(int));
	printf("\nEnter elements in ascending order for the first sorted array:\n");
	for(i=0;i<s1;i++)
	{
		scanf("%d",&arr1[i]);
	}

	printf("\nEnter number of elements in second array:\t");
	scanf("%d",&s2);
	int *arr2=(int *)malloc(s2*sizeof(int));
	printf("\nEnter elements in ascending order for the second sorted array:\n");
	for(j=0;j<s2;j++)
	{
		scanf("%d",&arr2[j]);
	}

	int *mer=(int *)malloc((s1+s2)*sizeof(int));
	merge(arr1,arr2,s1,s2,mer);

	printf("The merged array:\n");
	for(i=0;i<s1+s2;i++)
	{
		printf("\t%d",mer[i]);
	}
	printf("\n");

	free(arr1);
	free(arr2);
	free(mer);
	return 0;		
}


