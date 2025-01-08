#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

struct node *insert(struct node *root,int item)
{
	struct node *newnode;
	struct node *ptr=root;
	struct node *ptr1=NULL;
	int flag=0;


	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if(root==NULL)
		root=newnode;
	 else if(item < ptr->data)
	{
		ptr->left = insert(ptr->left,item);
		return ptr;	
	}
		else if(item > ptr->data)
	{
		ptr->right=insert(ptr->right,item);
		return ptr;
	}
	else
	{
		flag=1;
		printf("ITEM already exist\n");
		return ptr;
	}
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
	}
}

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->data);
	}
}

int main()
{
	int a,item;
	printf("BINARY SEARCH TREE\n");
	printf("1.Insert  2.Inorder  3.Preorder  4.Postorder  5.Exit\n");
	while(1)
	{
		printf("Enter the choice:");
		scanf("%d",&a);
		switch(a)
		{
			case 1: printf("\tEnter the item:");
					scanf("%d",&item);
					root=insert(root,item);
					break;
			case 2: printf("\tInorder:");
					inorder(root);
					printf("\n");
					break;
			case 3: printf("\tPreorder:");
					preorder(root);
					printf("\n");
					break;
			case 4: printf("\tPostorder:");
					postorder(root);
					printf("\n");
					break;
			case 5: exit(0);
					break;
			default:printf("\tWrong Choice!!");
		}
	}
}









