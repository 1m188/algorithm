#include "stdio.h"
#include "stdlib.h"

//示例数据类型
typedef int ElementType;
//队列中每个元素节点
struct Node
{
    //当前节点储存数据
    ElementType Data;
    //下一个节点
    struct Node *Next;
};
//表头，队列，存储队列相关信息
struct QNode
{
    //指向队尾节点
    struct Node *rear;
    //指向队头节点
    struct Node *front;
    //队列存储最大元素个数
    int MaxSize;
    //队列当前元素个数
    int ElementNum;
};
typedef struct QNode *Queue;

//生成长度为MaxSize的空队列
Queue CreateQueue(int MaxSize);
//判断队列Q是否已满
int IsFullQ(Queue Q);
//将数据元素item插入到队列Q中
void AddQ(Queue Q, ElementType item);
//判断队列Q是否为空
int IsEmptyQ(Queue Q);
//将队列头元素从队列中删除并返回
ElementType DeleteQ(Queue Q);

Queue CreateQueue(int MaxSize)
{
    Queue q = (Queue)malloc(sizeof(struct QNode));
    q->rear = q->front = NULL;
    q->MaxSize = MaxSize;
    q->ElementNum = 0;
    return q;
}

int IsFullQ(Queue Q)
{
    return Q->ElementNum == Q->MaxSize;
}

void AddQ(Queue Q, ElementType item)
{
    if (IsFullQ(Q))
    {
        printf("Queue Full!\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->Data = item;
        n->Next = NULL;
        if (!IsEmptyQ(Q))
        {
            Q->rear->Next = n;
        }
        else
        {
            Q->front = n;
        }
        Q->rear = n;
        Q->ElementNum++;
    }
}

int IsEmptyQ(Queue Q)
{
    return Q->ElementNum == 0;
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmptyQ(Q))
    {
        printf("Queue Empty!\n");
        return -1;
    }
    else
    {
        struct Node *t = Q->front;
        ElementType tt = t->Data;
        Q->front = Q->front->Next;
        free(t);
        Q->ElementNum--;
        if (Q->ElementNum == 0)
        {
            Q->rear = NULL;
        }
        return tt;
    }
}

//测试
int main()
{
    Queue q = CreateQueue(10);
    printf("%d %d\n", IsFullQ(q), IsEmptyQ(q));

    for (int i = 0; i < 11; i++)
    {
        AddQ(q, i);
    }
    printf("%d %d\n", IsFullQ(q), IsEmptyQ(q));

    printf("%d\n", DeleteQ(q));
    printf("%d %d\n", IsFullQ(q), IsEmptyQ(q));

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", DeleteQ(q));
    }
    printf("%d %d\n", IsFullQ(q), IsEmptyQ(q));

    return 0;
}