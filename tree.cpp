#include <iostream>
using namespace std;


typedef struct BiTNode//二叉树定义
{
	int data;
	struct BiTNode* left, * right;
}BitNode, * BiTree;


BiTNode* init()
{
	BiTNode* t;
	t = (BiTNode*)malloc(sizeof(BiTNode));
	t->data = 0;
	t->left = NULL;
	t->right = NULL;
	return t;
}

void add(BiTNode* t, int data, int dir)
{
	BitNode* p = t;
	BiTNode* m = init();
	m->data = data;
	if (dir % 2 == 0)
		p->left = m;
	else
		p->right = m;
}


void Preorder(BiTNode* t)
{
	BiTNode* p = t;
	cout << p->data << " ";
	if (p->left != NULL)
		Preorder(p->left);
	if (p->right != NULL)
		Preorder(p->right);
}


void Inorder(BiTNode* t)
{
	BiTNode* p = t;
	if(p->left!=NULL)
		Inorder(p->left);
	cout << p->data << " ";
	if(p->right!=NULL)
		Inorder(p->right);
}


void Bacorder(BiTNode* t)
{
	BiTNode* p = t;
	if (p->left != NULL)
		Bacorder(p->left);
	if (p->right != NULL)
		Bacorder(p->right);
	cout << p->data << " ";
}


void show(BiTNode* t)
{
	BiTNode* p = t;
	while(p!=NULL)
	{
		cout << p->data << " ";
		p = p->right;
	}
}

int main()
{
	BiTNode* tree;
	tree = (BiTNode*)malloc(sizeof(BiTNode));
	tree->data = 0;
	add(tree, 1, 0);
	add(tree, 2, 1);
	add(tree->left, 3, 2);
	add(tree->left, 4, 3);
	add(tree->right, 5, 4);
	add(tree->right, 6, 5);
	cout << "PreOrder:  ";
	Preorder(tree);
	cout << endl;
	cout << "InOrder:   ";
	Inorder(tree);
	cout << endl;
	cout << "BackOrder: ";
	Bacorder(tree);
}
