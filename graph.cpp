#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
using namespace std;

typedef char VertexType;
typedef int EdgeType;
#define MAX 100
#define INFINITY 65535

bool visited[MAX];

typedef struct
{
	VertexType vexs[MAX];
	EdgeType arc[MAX][MAX];
	int numVertexs, numEdges;
}MGraph;


typedef struct Queue
{
	int q[MAX];
	int front = 0, rear = 0;
}Queue;
bool QueueEmpty(Queue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
void EnQueue(Queue *Q, int i)
{
	Q->q[Q->rear] = i;
	Q->rear++;
}
void DeQueue(Queue* Q, int* j)
{
	if (!QueueEmpty(*Q))
	{
		*j = Q->q[Q->front];
		Q->front++;
	}
}

void CreateMGraph(MGraph* G)
{
	int i, j, k, w;
	cout << "输入顶点数与边数";
	cin >> G->numVertexs >> G->numEdges;
	for (i = 0; i < G->numVertexs; i++)
		cin >> G->vexs[i];
	for (i = 0; i < G->numVertexs; i++)
		for (j = 0; j < G->numVertexs; j++)
			G->arc[i][j] = INFINITY;
	for (k = 0; k < G->numEdges; k++)
	{
		cout << "输入边（vi，vj）上的下标i，下标j和权w";
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}

void DFS(MGraph G, int i)
{
	int j;
	visited[i] = true;
	cout << G.vexs[i];
	for (j = 0; j < G.numVertexs; j++)
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G, j);
}
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexs; i++)
		visited[i] = false;
	for (i = 0; i < G.numVertexs; i++)
		if (!visited[i])
			DFS(G, i);
}

void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexs; i++)
		visited[i] = false;
	for (i = 0; i < G.numVertexs; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			cout << G.vexs[i];
			EnQueue(&Q, i);
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				for (j = 0; j < G.numVertexs; j++)
				{
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = true;
						cout << G.vexs[j];
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}

int main()
{
	MGraph *G;
	G = (MGraph*)malloc(sizeof(MGraph));
	CreateMGraph(G);
	for (int i = 0; i < G->numVertexs; i++)
	{
		for (int j = 0; j < G->numEdges; j++)
			cout << G->arc[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < G->numVertexs; i++)
		cout << G->vexs[i];
	cout << endl;

	cout << "DFS:";
	DFSTraverse(*G);
	cout << endl;


	cout << "BFS:";
	BFSTraverse(*G);
	cout << endl;

	system("pause");
}
