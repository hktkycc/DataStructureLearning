#include <iostream>
using namespace std;
#define maxsize 100

typedef struct
{
    int data[maxsize];
    int front;
    int rear;
}SqQueue;

SqQueue* init()
{
    SqQueue *Q;
    Q = (SqQueue*)malloc(sizeof(SqQueue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

int QueueLength(SqQueue *Q)
{
    return Q->rear-Q->front;
}

int EnQueue(SqQueue* Q, int e)
{
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % maxsize;
    return 0;
}

int DeQueue(SqQueue* Q)
{
    int m = Q->data[Q->front];
    Q->front = (Q->front + 1) % maxsize;
    return m;
}

void ShowQueue(SqQueue* Q)
{
    int i = Q->front;;
    while (i != Q->rear)
    {
        cout << Q->data[i];
        i++;
    }
}

int main()
{
    SqQueue* testqueue = init();
    for(int i=0;i<10;i++)
      EnQueue(testqueue, i);
    int head = DeQueue(testqueue);
    head = DeQueue(testqueue);
    cout<<head<<" ";
    ShowQueue(testqueue);
    cout<<"\n"<<"Length:"<<QueueLength(testqueue)<<endl;
    return 0;
}
