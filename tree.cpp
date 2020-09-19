#include <iostream>
using namespace std;

#define MAX 100
typedef struct PTNode
{
	int data;
	int parent;
}PTNode;

typedef struct
{
	PTNode nodes[MAX];
	int r, n;
}PTree;

typedef struct BiTNode//二叉树定义
{
	int data;
	struct BiTNode* left, * right;
}BitNode,*BiTree;
