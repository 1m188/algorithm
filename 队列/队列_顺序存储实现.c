#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//示例数据类型
typedef int ElementType;
//队列结构体
struct QNode
{
    //实现顺序存储的数组
    ElementType *Data;
    //记录队列尾元素位置
    int rear;
    //记录队列头元素位置
    int front;
    //队列最大存储元素个数
    int MaxSize;
    //队列当前元素数目
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
    q->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
    memset(q->Data, 0, sizeof(ElementType) * MaxSize);
    q->front = q->rear = -1;
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
        Q->rear++;
        if (Q->rear == Q->MaxSize)
        {
            Q->rear = 0;
        }
        Q->Data[Q->rear] = item;
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
        Q->front++;
        if (Q->front == Q->MaxSize)
        {
            Q->front = 0;
        }
        Q->ElementNum--;
        return Q->Data[Q->front];
    }
}

//测试
int main()
{
    Queue q = CreateQueue(10);
    printf("%d %d\n", IsFullQ(q), IsEmptyQ(q));

    for (int i = 0; i < 12; i++)
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