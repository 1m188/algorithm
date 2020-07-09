/*

栈和队列——天勤2021数据结构

*/

#include "stdio.h"
#include "memory.h"
#include "stdbool.h"
#include "malloc.h"

typedef int ElementType;
#define MAX_SIZE 100

/*************************************  顺序栈  ************************************************/

typedef struct
{
    ElementType data[MAX_SIZE];
    int top;
} SqStack;

// 初始化栈
void initStack(SqStack *s)
{
    s->top = -1; // 栈顶指针置为-1，指向第一个元素位置前一个
    memset(s->data, (ElementType)0, sizeof(ElementType) * MAX_SIZE);
}

// 判断栈为空
bool isEmpty(SqStack *s)
{
    return s->top == -1;
}

// 进栈
bool push(SqStack *s, ElementType x)
{
    if (s->top == MAX_SIZE - 1) // 栈满
        return false;
    s->data[++s->top] = x;
    return true;
}

// 出栈
bool pop(SqStack *s, ElementType *x)
{
    if (s->top == -1) // 栈空
        return false;
    *x = s->data[s->top--];
    return true;
}

/***********************************************************************************************/

/*************************************  链栈  ************************************************/

typedef struct LNode
{
    ElementType data;
    struct LNode *next;
} LNode;

// 初始化链栈
void initLStack(LNode **l)
{
    (*l) = (LNode *)malloc(sizeof(LNode)); // 制造一个头节点
    (*l)->data = 0;
    (*l)->next = NULL;
}

// 判断链栈为空
bool isLSEmpty(LNode *l)
{
    return !l->next;
}

// 链栈进栈
void pushLS(LNode *l, ElementType x)
{
    // 制造一个待插入节点
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = x;
    p->next = NULL;

    // 以下为头插法
    p->next = l->next;
    l->next = p;
}

// 链栈出栈
bool popLS(LNode *l, ElementType *x)
{
    // 栈空
    if (!l->next)
        return false;

    LNode *p = l->next;
    l->next = p->next;
    *x = p->data;
    free(p);
    return true;
}

/***********************************************************************************************/

/*************************************  栈的应用  ************************************************/

// C语言里算术表达式中的括号只有小括号，编写算法，判断一个表达式中的括号是否正确匹配，表达式已经存入字符数组exp[]中，表达式中的字符个数为n

// 将表达式中的内容入栈，如果碰见右括号则出栈，倘若此时栈空，则不匹配，倘若到最后栈中还有左括号，不匹配
bool match(char exp[], int n)
{
    // 定义栈
    char stack[MAX_SIZE];
    memset(stack, '\0', sizeof(char) * MAX_SIZE);
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(') // 左括号入栈
            stack[++top] = '(';
        else // 右括号则匹配栈中的一个左括号出栈，若此时栈空，则不匹配
        {
            if (top == -1)
                return false;
            else
                top--;
        }
    }

    // 如果栈空，匹配，如果栈中还有剩余的左括号，不匹配
    return top == -1;
}

// 编写一个函数，求后缀式的数值，其中后缀式存于一个字符数组exp中，exp中最后一个字符为'\0'，作为结束符，并且假设后缀式中的数字都只有一位，本题中
// 所出现的除法均为整数除法

// 用栈入栈数字，碰到了操作符则出栈两个进行操作
// 注意两个个位数字进行运算有可能为两位数，注意除法的0问题

// 两个数进行操作
int op(int a, char o, int b)
{
    if (o == '+')
        return a + b;
    else if (o == '-')
        return a - b;
    else if (o == '*')
        return a * b;
    else if (b == 0) // 除数为0，小心陷阱
    {
        printf("ERROR\n");
        return 0;
    }
    else
        return a / b;
}

// 进行主要的入栈出栈及运算操作
int com(char exp[])
{
    // 定义栈，要用int，因为9+9=18
    int stack[MAX_SIZE];
    memset(stack, 0, sizeof(int) * MAX_SIZE);
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
            stack[++top] = exp[i] - '0'; // 这里注意字符和数字的转换
        else
        {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = op(a, exp[i], b);
        }
    }
    return stack[top];
}

// 用不带头节点的单链表存储链栈，设计初始化栈、判断栈是否为空、进栈和出栈等相应的算法。

// 初始化栈
void initStackl(LNode **l)
{
    // 无表头的栈注意初始化应该是什么都没有，第一个节点就是栈中的第一个元素
    (*l) = NULL;
}

// 判断栈是否为空
bool isEmptyl(LNode *l)
{
    return l == NULL;
}

// 进栈
void pushl(LNode **l, ElementType x)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->next = NULL;
    p->data = x;

    // 插入
    p->next = (*l);
    *l = p;
}

// 出栈
bool popl(LNode **l, ElementType *x)
{
    // 栈空
    if (!*l)
        return false;

    LNode *p = *l;
    (*l) = (*l)->next;
    *x = p->data;
    free(p);
    return true;
}

/***********************************************************************************************/

/*************************************  顺序队列  ************************************************/

typedef struct
{
    ElementType data[MAX_SIZE];
    int front; // 队首指针
    int rear;  // 队尾指针

    // 这里数据从队尾进去，队首出来，并且队首指针所指位置总是为空，队尾指针所指位置有或无元素，可以看作从队首到队尾的左开右闭区间，同时也是
    // 为了区分队满和队空的两种状态

    // 为了利用内存空间，做循环队列
    // 队空条件：front==rear
    // 队满条件：(rear+1)%maxsize==front
    // 进队操作：rear=(rear+1)%maxsize;data[rear]=x;
    // 出队操作：front=(front+1)%maxsize;x=data[front];
    // 队列中元素个数：(rear-front+maxsize)%maxsize
} SqQueue;

// 初始化队列
void initQueue(SqQueue *q)
{
    memset(q->data, (ElementType)0, sizeof(ElementType) * MAX_SIZE);
    q->front = q->rear = 0;
}

// 判断队空
bool isQueueEmpty(SqQueue *q)
{
    return q->front == q->rear;
}

// 进队算法
bool enQueue(SqQueue *q, ElementType x)
{
    int index = (q->rear + 1) % MAX_SIZE;
    if (index == q->front) // 队满无法进队
        return false;

    q->rear = index;
    q->data[q->rear] = x;
    return true;
}

// 出队算法
bool deQueue(SqQueue *q, ElementType *x)
{
    if (q->front == q->rear) // 队空无法出队
        return false;

    q->front = (q->front + 1) % MAX_SIZE;
    *x = q->data[q->front];
    return true;
}

/***********************************************************************************************/

/*************************************  链队  ************************************************/

// 链队的操作类似单链表，但是头尾指针的处理要注意，尤其在入队出队的部分

// 队节点
typedef struct QNode
{
    ElementType data;   // 数据域
    struct QNode *next; // 指针域
} QNode;

// 队类型定义
// 保存队头和队尾的指针
typedef struct
{
    QNode *front; // 队头指针
    QNode *rear;  // 队尾指针
} LiQueue;

// 初始化链队
void initLQueue(LiQueue **q)
{
    (*q) = (LiQueue *)malloc(sizeof(LiQueue));
    (*q)->front = (*q)->rear = NULL;
}

// 判断链队为空
bool isLQueueEmpty(LiQueue *q)
{
    return q->front == NULL || q->rear == NULL; // 任一指针为空均可判空
}

// 链队入队
void enLQueue(LiQueue *q, ElementType x)
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->data = x;
    p->next = NULL;

    if (isLQueueEmpty(q)) // 考虑链队为空的情况
        q->front = q->rear = p;
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}

// 出队算法
bool deLQueue(LiQueue *q, ElementType *x)
{
    if (isLQueueEmpty(q)) // 队空无法出队
        return false;

    QNode *p = q->front;
    if (q->front == q->rear) // 考虑只有一个元素
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    *x = p->data;
    free(p);
    return true;
}

/***********************************************************************************************/

int main(int argc, char *argv[])
{
    // 括号匹配
    printf("bracket match\n");
    char exp[] = {'(', '(', ')', '(', ')', ')'};
    printf("The bracket order: ");
    for (int i = 0; i < 6; i++)
    {
        printf(" %c", exp[i]);
    }
    printf("  result is: %d\n", match(exp, 6));

    char exp1[] = {'(', ')', ')', '(', ')', ')'};
    printf("The bracket order: ");
    for (int i = 0; i < 6; i++)
    {
        printf(" %c", exp1[i]);
    }
    printf("  result is: %d\n", match(exp1, 6));

    printf("\n");

    // 计算后缀表达式
    printf("calc postfix\n");
    char *exp2 = "9312+*/2-";
    printf("The exp  %s  result is: %d\n", exp2, com(exp2));

    printf("\n");

    // 无头链栈
    printf("list stack without head\n");
    LNode *l = NULL;
    initStackl(&l);
    printf("is stack empty: %d\n", isEmptyl(l));
    pushl(&l, 2);
    printf("after push 2, is stack empty: %d\n", isEmptyl(l));
    ElementType e = 0;
    popl(&l, &e);
    printf("pop: %d\n", e);
    printf("and now is stack empty: %d\n", isEmptyl(l));

    printf("\n");

    return 0;
}