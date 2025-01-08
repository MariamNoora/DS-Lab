#include<stdio.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

int full()
{
	return (rear+1)%MAX == front;
}

int empty()
{
	return front == -1;
}

void enqueue(int data)
{
	if(full())
	{
		printf("Queue overflow\n");
		return;
	}

	if(front == -1)
	{
		front = 0;
	}
	
	rear = (rear+1)%MAX;
	queue[rear]=data;
	printf("Element %d inserted.\n",data);
}

void dequeue()
{
	if(empty())
	{
		printf("Queue underflow.\n");
		return;
	}

	int data=queue[front];

	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front=(front+1)%MAX;
	}

	printf("Dequeued element: %d\n",data);
}

void display()
{
	if(empty())
	{
		printf("Queue is empty\n");
		return;
	}

	printf("Queue elements: ");
	for(int i=front ; i!=rear ; i=(i+1)%MAX)
	{
		printf("%d\t",queue[i]);
	}

	printf("%d\n",queue[rear]);
}

void peek()
{
	if(empty())
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		printf("The first element is %d\n",queue[front]);
	}
}

int main()
{
	int x,a;
	while(1)
	{
		printf("\n-------CIRCULAR QUEUE-------");
		printf("\n1. Insert a value\n2. Delete a value\n3. Display the queue\n4. View first element\n5. Exit\n");
		printf("Select an operation by entering the respective number:\t");
		scanf("%d",&x);
		switch(x)
		{
			case 1:	printf("Enter a value to insert into the queue:");
			   		scanf("%d",&a);
			   		enqueue(a);
			   		break;
			case 2:	dequeue();
			   		break;
			case 3:	display();
			   		break;
			case 4:	peek();
			   		break;
			case 5:	return 0;
			default:printf("Invalid input.\n");
		}
	}

	return 0;	
}









