#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;

void push()
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(newnode==NULL)
	{
		printf("Insufficient Data!!!");
	}
	else if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}

void pop()
{
	struct node *ptr;
	if(top==NULL)
	{
		printf("Stack is Empty!!!");
	}
	else
	{
		ptr=top;
		top=top->next;
		printf("Deleted Item : %d\n",ptr->data);
		free(ptr);
	}
}

void display()
{
	struct node *ptr;
	if(top==NULL)
	{
		printf("Stack is Empty!!!");
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("\nOPERATIONS:  1.Push  2.Pop  3.Display  4.Exit\n");
		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	push();
					break;
			case 2:	pop();
					break;
			case 3:	display();
					break;
			case 4:	exit(0);
					break;
			default:printf("Wrong Entry!!!\n");
		}
	}
}




















