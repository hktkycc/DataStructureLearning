#include <iostream>
using namespace std;

typedef char  ElemType;
#define END  '#'
typedef enum{LINK = 0,THREAD = 1} PointerTag;
typedef struct BiThrNode
{
	BiThrNode *leftchild;
	BiThrNode *rightchild;
	PointerTag Ltag,Rtag;
	ElemType data;
}BiThrNode,*BinaryThreadTree;

BiThrNode * Buynode()
{
	BiThrNode *s = (BiThrNode*)malloc(sizeof(BiThrNode));
	if(NULL == s) exit(1);
	memset(s,0,sizeof(BiThrNode)); // new;
	return s;
}

void Freenode(BiThrNode *p)
{
	free(p);
}

BiThrNode * CreateTree(ElemType *&str)  //创建树  //还未线索化
{
	BiThrNode *s = NULL;
	if(str != NULL  && *str != END)
	{
		s = Buynode();
		s->data = *str;
		s->Ltag = s->Rtag = LINK;
		s->leftchild = CreateTree(++str);
		s->rightchild = CreateTree(++str);
	}
	return s;
}

void InOrder(BiThrNode *p)  //中序遍历
{
	if(p != NULL)
	{
		InOrder(p->leftchild);
		cout<<p->data<<" ";
		InOrder(p->rightchild);
	}
}

void MakeThread(BiThrNode *p,BiThrNode *&ptr)  //进行线索化
{
	if(p != NULL)
	{
		MakeThread(p->leftchild,ptr);

		if(p->leftchild == NULL)                   //ptr是p的跟屁虫 //可以作为p回退的点
		{
			p->leftchild = ptr;
			p->Ltag = THREAD;
		}
		if(ptr != NULL && ptr->rightchild == NULL)
		{
			ptr->rightchild = p;
			ptr->Rtag = THREAD;
		}
		ptr = p;

		MakeThread(p->rightchild,ptr);
	}
}
void MakeThreadTree(BiThrNode *p)      //线索化
{
	BiThrNode *ptr = NULL;
	MakeThread(p,ptr);
	ptr->Rtag = THREAD;
}

BiThrNode * First(BiThrNode *ptr)   //线索化前驱
{
	while(ptr != NULL && ptr->Ltag != THREAD)
	{
		ptr = ptr->leftchild;
	}
	return ptr;
}
BiThrNode *Next(BiThrNode *ptr)    //线索化后继
{
	if(ptr == NULL) return NULL;
	if(ptr->Rtag == THREAD)
	{
		return ptr->rightchild;
	}
	else
	{
		return First(ptr->rightchild);
	}
}
BiThrNode *Last(BiThrNode *ptr)   //逆向线索化  //后继
{
	while(ptr != NULL && ptr->Rtag != THREAD)
	{
		ptr = ptr->rightchild;
	}
	return ptr;
}
BiThrNode * Prev(BiThrNode *ptr)   //逆向线索化  //前驱
{
	if(NULL == ptr) return NULL;
	if(ptr->Ltag == THREAD)
	{
		return ptr->leftchild;
	}
	else
	{
		return Last(ptr->leftchild);
	}
}
void NiceInOrder(BiThrNode *ptr)   //线索化  //中序遍历输出函数
{
	for(BiThrNode *p = First(ptr); p != NULL; p = Next(p))
	{
		cout<<p->data<<" ";
	}
	cout<<endl;
}
void ResNiceInOrder(BiThrNode *ptr)   //逆向线索化  //中序遍历输出函数
{
	for(BiThrNode *p = Last(ptr); p != NULL; p = Prev(p))
	{
		cout<<p->data<<" ";
	}
	cout<<endl;
}
int main()
{
	char *str = "ABC##DE##F##G#H##";
	BinaryThreadTree root = CreateTree(str);
	InOrder(root);
	cout<<endl;
	MakeThreadTree(root);
	NiceInOrder(root);
	ResNiceInOrder(root);
	return 0;
}
