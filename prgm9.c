#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int adj[MAX][MAX];	//adjacency matrix
int visited[MAX];	//array to track visited nodes
int queue[MAX];		//queue for BFS
int front=-1,rear=-1;	//queue pointers

//function -> add element to queue
void enqueue(int vertex)
{
	if(rear == MAX-1)
	{
		printf("Queue is full!!\n");
		return;
	}
	if(front==-1)
		front=0;
	queue[++rear]=vertex;
}

//function -> remove element
int dequeue()
{
	if(front==-1 || front>rear)
	{
		printf("Queue is empty!!\n");
		return -1;
	}
	return queue[front++];
}

void bfs(int startVertex,int n)
{
	enqueue(startVertex);
	visited[startVertex]=1;

	printf("BFS Traversal:");
	while(front<=rear)
	{
		int currentVertex=dequeue();
		printf("%d ",currentVertex);

		for(int i=0;i<n;i++)
		{
			if(adj[currentVertex][i]==1 && !visited[i])
			{
				enqueue(i);
				visited[i]=1;
			}
		}
	}
	printf("\n");
}

int main()
{
	int n,edges,u,v,startVertex;

	printf("Enter the number of vertices:");
	scanf("%d",&n);

	printf("Enter the number of edges:");
	scanf("%d",&edges);

	//initialise adjacency matrix and visited array
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			adj[i][j]=0;
		visited[i]=0;
	}

	//input edges
	printf("Enter the edges (u v):\n");
	for(int i=0;i<edges;i++)
	{
		scanf("%d %d",&u,&v);
		adj[u][v]=1;	//add edge u -> v
		adj[v][u]=1;	//for undirected graph, add edge v -> u
	}	
	printf("Enter the starting vertex:");
	scanf("%d",&startVertex);
	bfs(startVertex,n);

	return 0;
}











