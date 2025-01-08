#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//function -> find the in-degree of each vertex
void calculateIndegree(int graph[MAX][MAX],int vertices, int indegree[])
{
	for(int i=0;i<vertices;i++)
	{
		indegree[i]=0;
		for(int j=0;j<vertices;j++)
		{
			if(graph[j][i]==1)
			{
				indegree[i]++;
			}
		}
	}
}

//function -> perform topological sorting(in-degree method)
void topologicalSort(int graph[MAX][MAX],int vertices)
{
	int indegree[MAX];
	calculateIndegree(graph,vertices,indegree);

	int queue[MAX],front=0,rear=0;
	int topoOrder[MAX],topoIndex=0;

	//enqueue all vertices with indegree 0
	for(int i=0;i<vertices;i++)
	{
		if(indegree[i]==0)
		{
			queue[rear++]=i;
		}
	}
	
	//process the queue
	while(front<rear)
	{
		int current=queue[front++];
		topoOrder[topoIndex++]=current;
		
		//remove outpoing edges from the current vertex
		for(int i=0;i<vertices;i++)
		{
			if(graph[current][i]==1)
			{
				graph[current][i]=0;//remove edge
				indegree[i]--;	//decrease indegree

				//if indegree becomes 0, enqueue the vertex
				if(indegree[i]==0)
				{
					queue[rear++]=i;
				}
			}
		}
	}
	//check for cycles(if all vertices are ot in topoOrder)
	if(topoIndex != vertices)
	{
		printf("The graph contains a cycle. Topological sorting is not possible.\n");
		return;
	}
	//print topological order
	printf("Topological Order:");
	for(int i=0;i<topoIndex;i++)
	{
		printf("%d ",topoOrder[i]);
	}
	printf("\n");
}

int main()
{
	int vertices, edges, src, dest;
	int graph[MAX][MAX]={0};
	printf("Enter the number of vertices:");
	scanf("%d",&vertices);
	printf("Enter the number of edges:");
	scanf("%d",&edges);
	printf("Enter the edges(sourse destination):\n");
	for(int i=0;i<edges;i++)
	{
		scanf("%d %d", &src, &dest);
		graph[src][dest]=1;
	}
	topologicalSort(graph,vertices);
	return 0;
}
















