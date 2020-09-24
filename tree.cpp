#include <iostream>
using namespace std;


typedef struct BiTNode//二叉树定义
{
	char data;
	struct BiTNode* left, * right;
}BitNode, * BiTree;

void create(BiTNode *&T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T)
			exit(OVERFLOW);
		(T)->data = ch;
		create(T->left);
		create(T->right);
	}
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

int main()
{
	BiTNode* test;
	test = (BiTNode*)malloc(sizeof(BiTNode));
	create(test);
	cout << "PreOrder:  ";
	Preorder(test);
	cout << endl;
	cout << "InOrder:   ";
	Inorder(test);
	cout << endl;
	cout << "BackOrder: ";
	Bacorder(test);
}
