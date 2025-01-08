#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int adj[MAX][MAX];	//adjacency matrix
int visited[MAX];	//array to track visited nodes

void dfs(int vertex,int n)
{
	printf("%d ",vertex);
	visited[vertex]=1;
	for(int i=0;i<n;i++)
	{
		if(adj[vertex][i]==1 && !visited[i])
		{
			dfs(i,n);	//recursively visit adjacent vertices
		}
	}
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

	//perform DFS
	printf("DFS Traversal:");
	dfs(startVertex,n);
	printf("\n");

	return 0;
}























