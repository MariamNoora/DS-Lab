#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define M 4		//order of btree(max num of children

//structure of btree node
typedef struct BTreeNode
{
	int keys[M-1];	//max M-1 keys in a btree node
	struct BTreeNode *child[M];		//child pointers
	int n;		//current num of keys
	int leaf;	//boolean to check if the node is a node
}BTreeNode;

//function => create new node
BTreeNode *createNode(int leaf)
{
	BTreeNode *node=(BTreeNode *)malloc(sizeof(BTreeNode));
	node->leaf=leaf;
	node->n=0;
	for(int i=0;i<M;i++)
	{
		node->child[i]=NULL;
	}
	return node;
}

//function => traverse
void traverse(BTreeNode *root)
{
	if(root)
	{
		for(int i=0;i<root->n;i++)
		{
			//visit left child
			if(!root->leaf)
			{
				traverse(root->child[i]);
			}
			printf("%d ",root->keys[i]);
		}
		//visit rightmost child
		if(!root->leaf)
		{
			traverse(root->child[root->n]);
		}
	}
}

//function => search a key
BTreeNode *search(BTreeNode *root, int key)
{
	int i=0;
	while(i<root->n && key>root->keys[i])
	{
		i++;
	}

	//if key is found
	if(i<root->n && key==root->keys[i])
	{
		return root;
	}

	//if key not found & node is leaf
	if(root->leaf)
	{
		return NULL;
	}

	//recur to the appropriate child??????
	return search(root->child[i], key);
}

//function => split a full child node
void splitChild(BTreeNode *parent, int i, BTreeNode *child)
{
	BTreeNode *newChild = createNode(child->leaf);
	int mid=M/2;	//middle index for splitting
	newChild->n=mid-1;

	//copy 2nd half of keys into a new child
	for(int j=0;j<mid-1;j++)
	{
		newChild->keys[j]=child->keys[j+mid];
	}

	//copy the 2nd half of children to new child
	if(!child->leaf)
	{
		for(int j=0;j<mid;j++)
		{
			newChild->child[j]=child->child[j+mid];
		}
	}

	child->n=mid-1;		//reduce the num of keys in the old child

	//shift parent children to make room for new child
	for(int j=parent->n; j>=i+1; j--)
	{
		parent->child[j+1]=parent->child[j];
	}
	parent->child[i+1]=newChild;

	//shift parent keys and add the middle key from the old child
	for(int j=parent->n-1; j>=i; j--)
	{
		parent->keys[j+1]=parent->keys[j];
	}
	parent->keys[i]=child->keys[mid-1];
	parent->n++;
}

//function => insert key to a non-full node
void insertNonFull(BTreeNode *node, int key)
{
	int i=node->n-1;
	if(node->leaf)
	{
		//find postion to insert
		while(i>=0 && key<node->keys[i])
		{
			node->keys[i+1]=node->keys[i];
			i--;
		}
		node->keys[i+1]=key;
		node->n++;
	}
	else
	{
		//find child that will have the new key
		while(i>=0 && key<node->keys[i])
		{
			i--;
		}
		i++;
		
		//if child full, split it
		if(node->child[i]->n == M-1)
		{
			splitChild(node, i, node->child[i]);

			//after split, middle key move up; decide which child to go
			if(key>node->keys[i])
			{
				i++;
			}
		}	
		insertNonFull(node->child[i],key);
	}
}

//function => insert a key
BTreeNode *insert(BTreeNode *root, int key)
{
	if(root->n == M-1)
	{
		//if root full, create new root
		BTreeNode *newRoot=createNode(0);
		newRoot->child[0]=root;
		splitChild(newRoot,0,root);
		insertNonFull(newRoot,key);
		return newRoot;
	}
	else
	{
		insertNonFull(root,key);
		return root;
	}
}

int main()
{
	BTreeNode *root=createNode(1);		//create empty tree
	int choice, key;
	
	printf("B-TREE OPERATIONS (ORDER %d)\n",M);
	while(1)
	{
		printf("\n1.Insert  2.Traverse  3.Search  4.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter key to insert: ");
					scanf("%d",&key);
					root=insert(root,key);
					break;
			case 2:	printf("B-Tree: ");
					traverse(root);
					printf("\n");
					break;
			case 3:	printf("Enter key to search: ");
					scanf("%d",&key);
					if(search(root,key))
						printf("Key %d found in the B-Tree\n",key);
					else
						printf("Key %d not found in the B-Tree\n",key);
					break;
			case 4:	exit(0);
			default:printf("Invalid choice. Try again\n");
		}
	}
	return 0;
}





















