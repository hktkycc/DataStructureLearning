#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
using namespace std;


typedef char VertexType;
typedef int EdgeType;
#define MAX 100
#define INFINITY 65535

typedef int ShortPathTable[MAX];
typedef int Patharc[MAX];

bool visited[MAX];


typedef struct Edge
{
	int begin;
	int end;
	int weight;
};//边集数组edge定义

typedef struct
{
	VertexType vexs[MAX];
	EdgeType arc[MAX][MAX];
	Edge medges[MAX];
	int numVertexs, numEdges;
}MGraph;
void medge_sort(MGraph &G)
{
	int h = 1;
	int n = 2;
	while (h < MAX / n)
	{
		h = n * h + 1;
	}
	while (h >= 1) {
		for (int i = h; i < G.numEdges; i++)
		{
			for (int j = i; j >= h && G.medges[j].weight < G.medges[j - h].weight && i <= G.numVertexs && j <= G.numVertexs; j -= h)
			{
				swap(G.medges[j], G.medges[j - h]);
			}
		}
		h = h / n;
	}
}

void EdgesConvert(MGraph* G)
{
	int m = 0;
	for (int i = 0; i < G->numVertexs; i++)
	{
		for (int j = i; j < G->numVertexs; j++)
		{
			if (G->arc[i][j] != INFINITY)
			{
				G->medges[m].begin = i;
				G->medges[m].end = j;
				G->medges[m].weight = G->arc[i][j];
				m++;
			}
		}
	}
	medge_sort(*G);
}

void graphinit(MGraph* G)
{
	G->vexs[0] = 'a';
	G->vexs[1] = 'b';
	G->vexs[2] = 'c';
	G->vexs[3] = 'd';
	G->vexs[4] = 'e';

	G->numVertexs = 5;
	G->numEdges = 7;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			G->arc[i][j] = INFINITY;
		G->arc[0][1] = 1;
		G->arc[1][0] = G->arc[0][1];

		G->arc[0][2] = 4;
		G->arc[2][0] = G->arc[0][2];

		G->arc[1][2] = 3;
		G->arc[2][1] = G->arc[1][2];

		G->arc[1][3] = 5;
		G->arc[3][1] = G->arc[1][3];

		G->arc[1][4] = 2;
		G->arc[4][1] = G->arc[1][4];

		G->arc[2][4] = 6;
		G->arc[4][2] = G->arc[2][4];

		G->arc[3][4] = 1;
		G->arc[4][3] = G->arc[3][4];
}

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

	cout << "输入所有的节点名称，以空格分隔:";
	for (int i = 0; i < G->numVertexs; i++)
		cout << G->vexs[i];
	cout << endl;
}

void DFS(MGraph G, int i)
{
	int j;
	visited[i] = true;
	cout << G.vexs[i];
	for (j = 0; j < G.numVertexs; j++)
		if (G.arc[i][j] != INFINITY && !visited[j])
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
					if (G.arc[i][j] != INFINITY && !visited[j])
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

void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAX];
	int lowcost[MAX];
	lowcost[0] = 0;
	adjvex[0] = 0;
	for (i = 1; i < G.numVertexs; i++)
	{
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	for (int i = 1; i < G.numVertexs; i++)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		while (j < G.numVertexs)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		cout << adjvex[k] << "," << k << " ";
		lowcost[k] = 0;
		for (j = 1; j < G.numVertexs; j++)
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}//Prim算法最小生成树


int Find(int* parent, int f)
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	int parent[MAX];
	for (int i = 0; i < G.numVertexs; i++)
		parent[i] = 0;
	for (i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, G.medges[i].begin);
		m = Find(parent, G.medges[i].end);
		if (n != m)
		{
			parent[n] = m;
			cout << G.medges[i].begin << " " << G.medges[i].end << " " << G.medges[i].weight << ", ";
		}
	}
}

void Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D)
{
	int v, w, k, min;
	int final[MAX];
	for (v = 0; v < G.numVertexs; v++)
	{
		final[v] = 0;
		(*D)[v] = G.arc[v0][v];
		(*P)[v] = 0;
	}
	(*D)[v0] = 0;
	final[v0] = 1;

	for (v = 1; v < G.numVertexs; v++)
	{
		min = INFINITY;
		for (w = 0; w < G.numVertexs; w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for (w = 0; w < G.numVertexs; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}

int main()
{
	MGraph* G;
	Patharc* P;
	ShortPathTable* D;
	G = (MGraph*)malloc(sizeof(MGraph));
	P = (Patharc*)malloc(sizeof(Patharc));
	D = (ShortPathTable*)malloc(sizeof(ShortPathTable));
	graphinit(G);
	for (int i = 0; i < G->numVertexs; i++)
	{
		for (int j = 0; j < G->numVertexs; j++)
			cout << G->arc[i][j] << " ";
		cout << endl;
	}

	EdgesConvert(G);
	for (int i = 0; i < G->numEdges; i++)
		cout << G->medges[i].begin << " " << G->medges[i].end << " " << G->medges[i].weight << ", ";

	cout << endl;
	cout << "DFS:";
	DFSTraverse(*G);
	cout << endl;


	cout << "BFS:";
	BFSTraverse(*G);
	cout << endl;

	cout << "Prim:";
	MiniSpanTree_Prim(*G);
	cout << endl;

	cout << "Kruskal:";
	MiniSpanTree_Kruskal(*G);
	cout << endl;

	cout << "Dijkstra:";
	Dijkstra(*G,1,P,D);
	for (int i = 0; i < G->numVertexs; i++)
		cout << *P[i] << " ";
	cout << endl;

	system("pause");
}
