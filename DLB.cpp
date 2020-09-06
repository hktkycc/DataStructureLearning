#include <iostream>
using namespace std;

#define MAX 100

struct DLBNode {
    int data = 0;
    DLBNode* next;
};//单链表

DLBNode* DLBinit()
{
    DLBNode* list;
    list = (DLBNode*)malloc(sizeof(DLBNode));
    list->next = NULL;
    return list;
}

int DLBGet(DLBNode* l, int n)
{
    DLBNode* p = l;
    int j = 0;
    int data = 0;
    while (p->next != NULL && j <= n)
    {
        data = p->data;
        p = p->next;
        ++j;
    }
    return data;
}

void DLBInsert(DLBNode* l, int n, int data)
{
    DLBNode* p = l, *s = DLBinit();
    s->data = data;
    int j = 0;
    for (j; j < n; j++)
    {
        p = p->next;
    }
    s->next = p->next;
    p->next = s;
}

void DLBChange(DLBNode* l, int n, int data)
{
    DLBNode* p = l;
    int j = 0;
    for (j; j < n; j++)
        p = p->next;
    p->data = data;
}

void DLBDelete(DLBNode* l, int n)
{
    DLBNode* p = l, * s = l;
    int j = 0;
    for (j; j < n-1; j++)
    {
        p = p->next;
        s = s->next;
    }
    p = p->next;
    s->next = p->next;
    free(p);
}

void DLBShow(DLBNode* l)
{
    DLBNode* p = l;
    while (p->next != NULL)
    {
        cout << p << " " << p->data << " " << p->next << "\n";
        p = p->next;
    }
    cout << p << " " << p->data << " " << p->next << "\n";
}

void DLBSwap(DLBNode* l, int n)
{
    DLBNode* p = l, * s = l;
    int data = 0;
    if (s->next != NULL)
    {
        for (int j = 0; j < n; j++)
        {
            p = p->next;
            s = s->next;
        }
        if(s->next != NULL)
            s = s->next;
        data = s->data;
        s->data = p->data;
        p->data = data;
    }
}

void DLBSort(DLBNode* l)
{
    DLBNode* p = l, * q = l;
    for (p = l; p->next != 0; p = p->next)
    {
        for (q = l; q->next != 0; q = q->next)
        {
            if (q->data < q->next->data)
            {
                swap(q->data, q->next->data);
            }
        }
    }
}

void DLBClear(DLBNode* l)
{
    DLBNode* p = l, * s = l;
    while (p->next != NULL)
    {
        s = p->next;
        free(p);
        p = s;
        if (s->next != NULL)
            s = s->next;
    }
    l->next = NULL;
}

void DLBCircle(DLBNode* l)
{
    DLBNode* p = l;
    while (p->next != NULL)
        p = p->next;
    p->next = l;
}

int GETLength(DLBNode* l)
{
    DLBNode* p = l;
    int n = 1;
    while (p->next != NULL)
    {
        n = n++;
        p = p->next;
    }
    return n;
}
//这里使用函数重载定义获取表长度的函数


int main()
{
    DLBNode* list = DLBinit();
    for (int i = 0; i < 10; i++)
        DLBInsert(list, i, i);
    DLBChange(list, 0, 9);
    DLBDelete(list, 10);
    DLBSwap(list, 4);
    DLBShow(list);
    cout << DLBGet(list, 3);
    cout << "\n";
    DLBSort(list);
    cout << "\n";
    DLBShow(list);
    int n = GETLength(list);
    cout << "\n链表长度" << n;
    DLBClear(list); //单链表功能测试代码

    return 0;
}