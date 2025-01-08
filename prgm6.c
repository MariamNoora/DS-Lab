#include<stdio.h>
#define MAX 8

void display(int set)
{
	printf("{");
	for(int i=0;i<MAX;i++)
	{
		if(set & (1<<i))
		{
			printf("%d",i);
		}
	}
	printf("} - Bitstring: ");
	for(int i=MAX-1;i>=0;i--)
	{
		printf("%d",(set>>i) & 1);
	}
	printf("\n");
}

int create(int n)
{
	int set=0, element;
	printf("Enter %d elements: ",n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&element);
		if(element>=0 && element<MAX)
		{
			set |= (1<<element);
		}
		else
		{
			printf("Element %d out of range! Please enter elements between 0 and %d.\n",element,MAX-1);
			i--;
		}
	}
	return set;
}

int unionSet(int setA, int setB)
{
	return setA | setB;
}

int intersection(int setA, int setB)
{
	return setA & setB;
}

int difference(int setA, int setB)
{
	return setA & ~setB;
}

int main()
{
	int nA,nB;
	printf("Enter the number of elements in set A:");
	scanf("%d",&nA);
	int setA=create(nA);
	printf("Enter the number of elements in set B:");
	scanf("%d",&nB);
	int setB=create(nB);

	printf("Set A:");
	display(setA);
	printf("Set B:");
	display(setB);

	int unionRes = unionSet(setA,setB);
	printf("Union of A and B:");
	display(unionRes);

	int intersectionRes = intersection(setA,setB);
	printf("Intersection of A and B:");
	display(intersectionRes);

	int differenceRes = difference(setA,setB);
	printf("Difference between A and B:");
	display(differenceRes);

	return 0;
}






