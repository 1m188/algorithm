/*
02-线性结构2 一元多项式的乘法与加法运算 （20 分)
设计函数分别求两个一元多项式的乘积与和。

输入格式:

输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:

输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:

4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:

15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/

//用C语言写的一个版本

#include "stdio.h"
#include "stdlib.h"

//多项式每一项的结构体
struct PolyNode
{
    //系数
    int coef;
    //指数
    int expon;
    //指向下一个节点的指针
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;

//读入多项式
Polynomial ReadPoly();
//多项式相加
Polynomial Add(Polynomial P1, Polynomial P2);
//多项式相乘
Polynomial Mult(Polynomial P1, Polynomial P2);
//将某一项按照指数从大到小的顺序插入到一个多项式链表中，如果有相同的指数就相加合并
Polynomial Insert(Polynomial p, int coef, int expon);
//创造多项式的某项
Polynomial CreatePoly(int coef, int expon, Polynomial link);
//输出多项式
void PrintPoly(Polynomial p);
//释放多项式所占内存
void DeletePoly(Polynomial p);

Polynomial ReadPoly()
{
    int num = 0;
    scanf("%d", &num);
    Polynomial p = NULL;
    //按顺序读入，指数从大到小
    if (num > 0)
    {
        int c = 0, e = 0;
        scanf("%d %d", &c, &e);
        p = CreatePoly(c, e, NULL);
        Polynomial t = p;
        for (int i = 0; i < num - 1; i++)
        {
            c = 0, e = 0;
            scanf("%d %d", &c, &e);
            t->link = CreatePoly(c, e, NULL);
            t = t->link;
        }
    }
    return p;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
    //整个多项式链表的最头部辅助节点
    Polynomial P = CreatePoly(0, 0, NULL);
    Polynomial head = P;

    //当P1和P2都不为空的时候，每次取大的指数的项作为下一项，之后指针后移
    //如果有指数相等的情况则直接合并
    while (P1 && P2)
    {
        Polynomial p = CreatePoly(0, 0, NULL);
        if (P1->expon != P2->expon)
        {
            Polynomial *MaxP = P1->expon > P2->expon ? &P1 : &P2;
            p->coef = (*MaxP)->coef;
            p->expon = (*MaxP)->expon;
            *MaxP = (*MaxP)->link;
            P->link = p;
            P = P->link;
        }
        else
        {
            p->coef = P1->coef + P2->coef;
            if (p->coef != 0)
            {
                p->expon = P1->expon;
                P->link = p;
                P = P->link;
            }
            else
            {
                free(p);
            }
            P1 = P1->link;
            P2 = P2->link;
        }
    }

    //出来之后将两个指针中不为空的那个全部加到最后面
    while (P1)
    {
        Polynomial p = CreatePoly(0, 0, NULL);
        p->coef = P1->coef;
        p->expon = P1->expon;
        P1 = P1->link;
        P->link = p;
        P = P->link;
    }
    while (P2)
    {
        Polynomial p = CreatePoly(0, 0, NULL);
        p->coef = P2->coef;
        p->expon = P2->expon;
        P2 = P2->link;
        P->link = p;
        P = P->link;
    }

    //删除辅助头节点
    P = head;
    head = head->link;
    free(P);

    return head;

    //整个加法过程做的是深度拷贝
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
    Polynomial p = NULL;
    //对某个多项式上的每一项都要乘以另外一项
    while (P1)
    {
        Polynomial P2t = P2;
        while (P2t)
        {
            p = Insert(p, P1->coef * P2t->coef, P1->expon + P2t->expon);
            P2t = P2t->link;
        }
        P1 = P1->link;
    }

    //删除系数为0的节点
    //这里使用新的辅助头节点，从之后的第二个节点，也就是原来的头节点开始判断，如果有0多项式则直接删除
    //最后释放辅助头节点，返回原来（新）的头
    Polynomial t = CreatePoly(0, 0, p);
    Polynomial c = t;
    while (c->link)
    {
        if (c->link->coef == 0)
        {
            Polynomial tc = c->link;
            c->link = tc->link;
            free(tc);
        }
        c = c->link;
    }
    p = t->link;
    free(t);

    return p;
}

Polynomial Insert(Polynomial p, int coef, int expon)
{
    //待插入的新节点
    Polynomial n = CreatePoly(coef, expon, NULL);
    if (p)
    {
        //和头节点比较
        if (n->expon > p->expon)
        {
            n->link = p;
            p = n;
        }
        else if (n->expon == p->expon)
        {
            p->coef += n->coef;
            free(n);
        }
        //和头节点之后的节点比较
        else
        {
            Polynomial t = p;
            int flag = 0;
            while (t->link)
            {
                if (n->expon > t->link->expon)
                {
                    Polynomial tt = t->link;
                    t->link = n;
                    n->link = tt;
                    flag = 1;
                    break;
                }
                else if (n->expon == t->link->expon)
                {
                    t->link->coef += n->coef;
                    free(n);
                    flag = 1;
                    break;
                }
                t = t->link;
            }
            //如果到最后还没有插入，说明指数最小，应当插入到最后一个
            if (!flag)
            {
                t->link = n;
            }
        }
    }
    else
    {
        p = n;
    }
    return p;
}

Polynomial CreatePoly(int coef, int expon, Polynomial link)
{
    //按照给定的参数创建一个新的结构体节点指针返回
    Polynomial p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->coef = coef;
    p->expon = expon;
    p->link = link;
    return p;
}

void PrintPoly(Polynomial p)
{
    if (p)
    {
        printf("%d %d", p->coef, p->expon);
        p = p->link;
        while (p)
        {
            printf(" %d %d", p->coef, p->expon);
            p = p->link;
        }
        printf("\n");
    }
    else
    {
        printf("0 0\n");
    }
}

void DeletePoly(Polynomial p)
{
    //迭代释放
    while (p)
    {
        Polynomial t = p;
        p = p->link;
        free(t);
    }
}

int main()
{
    //输入
    Polynomial p1 = ReadPoly();
    Polynomial p2 = ReadPoly();

    //计算并输出
    Polynomial pm = Mult(p1, p2);
    PrintPoly(pm);
    Polynomial pa = Add(p1, p2);
    PrintPoly(pa);

    //释放内存
    DeletePoly(p1);
    DeletePoly(p2);
    DeletePoly(pm);
    DeletePoly(pa);

    return 0;
}