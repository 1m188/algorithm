/*

2021王道数据结构 线性表 练习

*/

#include "limits.h"
#include "malloc.h"
#include "memory.h"
#include "stdbool.h"
#include "stdio.h"

#define MAX_SIZE 100

// 顺序表
typedef struct
{
    int data[MAX_SIZE];
    int length;
} SqList;

// 打印顺序表
void printVec(const SqList *s, const char *prefix)
{
    printf("%s:", prefix);
    for (int i = 0; i < s->length; i++)
        printf(" %d", s->data[i]);
    printf("\n");
}

// 交换
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 交换（通用版）
// n为实际数据所占字节数
void swapg(void *a, void *b, int n)
{
    void *p = malloc(n);
    memcpy(p, a, n);
    memcpy(a, b, n);
    memcpy(b, p, n);
    free(p);
}

// 单链表节点定义
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 双链表节点定义
typedef struct DNode
{
    int data;
    struct DNode *next;
    struct DNode *prior;
} DNode;

// 生成单链表
Node *genList(const int vec[], const int n, bool hasHead)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = hasHead ? INT_MAX : vec[0];
    node->next = NULL;
    Node *cur = node;
    for (int i = hasHead ? 0 : 1; i < n; i++)
    {
        cur->next = (Node *)malloc(sizeof(Node));
        cur = cur->next;
        cur->data = vec[i];
        cur->next = NULL;
    }
    return node;
}

// 释放链表
void delList(Node *node)
{
    while (node)
    {
        Node *tmp = node->next;
        free(node);
        node = tmp;
    }
}

// 打印单链表
void printList(const Node *node, const char *prefix, bool hasHead)
{
    if (hasHead)
        node = node->next;

    printf("%s:", prefix);
    while (node)
    {
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}

/****************************************************************************************************/

// 顺序表 综合应用题

// 1
// 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
// 空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行
int delMin(SqList *s)
{
    if (s->length == 0)
    {
        printf("delMin ERROR!\n");
        return 0;
    }

    int mi = 0;
    for (int i = 1; i < s->length; i++)
        if (s->data[i] < s->data[mi])
            mi = i;
    int res = s->data[mi];
    s->data[mi] = s->data[s->length - 1];
    return res;
}

void delMin_test()
{
    printf("No.1\n");
    SqList s;
    s.length = 10;
    for (int i = 0; i < s.length; i++)
        s.data[i] = i;
    printVec(&s, "before");
    printf("res: %d\n", delMin(&s));
    printVec(&s, "after");
    s.length = 0;
    printf("faild: %d\n", delMin(&s));
    printf("\n");
}

// 2
// 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
void reverse(SqList *l)
{
    int left = 0, right = l->length - 1;
    while (left < right)
        swap(&l->data[left++], &l->data[right--]);
}

void reverse_test()
{
    printf("No.2\n");
    SqList s;
    s.length = 10;
    for (int i = 0; i < s.length; i++)
        s.data[i] = i;
    printVec(&s, "before");
    reverse(&s);
    printVec(&s, "after");
    printf("\n");
}

// 3
// 对长度为n的顺序表L，变暗写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素
void delX(SqList *s, int x)
{
    int num = 0;
    for (int i = 0; i < s->length; i++)
        if (s->data[i] == x)
            num++;
        else
            s->data[i - num] = s->data[i];
    s->length -= num;
}

void delX_test()
{
    printf("No.3\n");
    SqList s;
    s.length = 10;
    for (int i = 0; i < s.length; i++)
        s.data[i] = i;
    s.data[0] = s.data[5] = s.data[9] = 1;
    printVec(&s, "before");
    delX(&s, 1);
    printVec(&s, "after");
    printf("\n");
}

// 4
// 从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并
// 退出运行
void delRange(SqList *l, int s, int t)
{
    if (!l->length || s >= t)
    {
        printf("delRange ERROR!\n");
        return;
    }

    int num = 0;
    int idx = 0;
    for (; idx < l->length; idx++)
    {
        if (l->data[idx] >= t)
            break;
        else if (l->data[idx] > s)
            num++;
    }
    for (; idx < l->length; idx++)
        l->data[idx - num] = l->data[idx];
    l->length -= num;
}

void delRange_test()
{
    printf("No.4\n");
    SqList s;
    s.length = 10;
    for (int i = 0; i < s.length; i++)
        s.data[i] = i;
    printVec(&s, "before");
    delRange(&s, 3, 7);
    printVec(&s, "after");
    printf("\n");
}

// 5
// 从顺序表中删除其值在给定值s和t之间（包含s和t，要求s<t）的所有元素，如果s或t不合理或顺序表为空则显示
// 出错信息并退出运行
// 解：
// 和上个问题差不多，循环判断条件一改就可以了

// 6
// 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
void delSame(SqList *s)
{
    for (int i = 1; i < s->length;)
        if (s->data[i] == s->data[i - 1])
        {
            for (int j = i + 1; j < s->length; j++)
                s->data[j - 1] = s->data[j];
            s->length--;
        }
        else
            i++;
}

void delSame_test()
{
    printf("No.6\n");
    SqList s;
    s.length = 10;
    for (int i = 0; i < s.length; i += 2)
        s.data[i] = s.data[i + 1] = i;
    printVec(&s, "before");
    delSame(&s);
    printVec(&s, "after");
    printf("\n");
}

// 7
// 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
SqList merge(SqList *l, SqList *s)
{
    SqList res;
    res.length = l->length + s->length;
    int idx = 0, li = 0, si = 0;
    while (li < l->length && si < s->length)
        if (l->data[li] <= s->data[si])
            res.data[idx++] = l->data[li++];
        else
            res.data[idx++] = s->data[si++];
    if (si < s->length)
        l = s, li = si;
    while (li < l->length)
        res.data[idx++] = l->data[li++];
    return res;
}

void merge_test()
{
    printf("No.7\n");
    SqList s1, s2;
    s1.length = s2.length = 5;
    for (int i = 1; i <= 2 * s1.length; i += 2)
    {
        s1.data[(i - 1) / 2] = i;
        s2.data[(i - 1) / 2] = i + 1;
    }
    printVec(&s1, "before");
    printVec(&s2, "before");
    SqList s = merge(&s1, &s2);
    printVec(&s, "after");
    printf("\n");
}

// 8
// 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn)。试编写一个函数，
// 将数组中两个顺序表的位置互换，即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面

void revRan(int vec[], int left, int right)
{
    while (left < right)
        swap(&vec[left++], &vec[right--]);
}

void swapVec(int vec[], int m, int n)
{
    revRan(vec, 0, m - 1);
    revRan(vec, m, m + n - 1);
    revRan(vec, 0, m + n - 1);
}

void swapVec_test()
{
    printf("No.8\n");
    SqList s;
    s.length = 10;
    for (int i = 0; i < s.length; i++)
        s.data[i] = i;
    printVec(&s, "before");
    swapVec(s.data, 5, 5);
    printVec(&s, "after");
    printf("\n");
}

// 9
// 线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。要求设计一算法，完成用最少的时间在表中查找
// 数值为x的元素，若找到则将其于后继元素位置交换，若找不到则将其插入表中并使表中顺序仍递增有序

// 二分查找
int bsearch(SqList *s, int x)
{
    int left = 0, right = s->length - 1;
    int mid = (left + right) / 2;
    while (left < right)
    {
        if (s->data[mid] == x)
            return mid;
        else if (s->data[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
        mid = (left + right) / 2;
    }
    return s->data[mid] == x ? mid : (s->data[mid] < x ? mid + 1 : mid);
}

void search(SqList *s, int x)
{
    int idx = bsearch(s, x);

    if (s->data[idx] == x)
    {
        if (idx + 1 < s->length)
            swap(&s->data[idx], &s->data[idx + 1]);
    }
    else
    {
        for (int i = s->length - 1; i >= idx; i--)
            s->data[i + 1] = s->data[i];
        s->data[idx] = x;
        s->length++;
    }
}

void search_test()
{
    printf("No.9\n");
    SqList s;
    s.length = 10;
    for (int i = 0; i < s.length; i++)
        s.data[i] = i * 2;
    printVec(&s, "before");
    search(&s, 10);
    printVec(&s, "after");
    printVec(&s, "before");
    search(&s, 3);
    printVec(&s, "after");
    printf("\n");
}

// 10
// 设将n（n>1）个整数存放到一维数组R中，设计一个在时间和空间两方面都尽可能高效的算法。将R中保存的序列循环左移
// p（0<p<n）个位置，即将R中的数据由(x0,x1,x2,...,xn-1)变换成(xp,xp+1,...,xn-1,x0,x1,...,xp-1)。

// 时间复杂度为O(n)
// 空间复杂度为O(1)

void clefts(int r[], int n, int p)
{
    revRan(r, 0, p - 1);
    revRan(r, p, n - 1);
    revRan(r, 0, n - 1);
}

void clefts_test()
{
    printf("No.10\n");
    SqList s;
    s.length = 10;
    for (int i = 0; i < s.length; i++)
        s.data[i] = i;
    printVec(&s, "before");
    clefts(s.data, s.length, 4);
    printVec(&s, "after");
    printf("\n");
}

// 11
// 一个长度为L（L>=1）的升序序列S，处在第[L/2]个位置的数称为S的中位数。例如，若序列S1=（11，13，15，17，19），
// 则S1的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2=（2，4，6，8，20），则S1和
// S2的中位数是11。现在有两个等长的升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A
// 和B的中位数。

// 时间复杂度O(n)
// 空间复杂度O(1)

int midNum(int a[], int b[], int n)
{
    int ai = 0, bi = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[ai] < b[bi])
            ai++;
        else
            bi++;
    return a[ai] < b[bi] ? a[ai] : b[bi];
}

void midNum_test()
{
    printf("No.11\n");
    SqList s1, s2;
    s1.length = s2.length = 5;
    for (int i = 0; i < s1.length; i++)
    {
        s1.data[i] = i * 2 + 11;
        s2.data[i] = (i + 1) * 2;
    }
    s2.data[s2.length - 1] = 20;
    printVec(&s1, "A");
    printVec(&s2, "B");
    int res = midNum(s1.data, s2.data, s1.length);
    printf("res: %d\n", res);
    printf("\n");
}

// 12
// 已知一个整数序列A=（a0,a1,...,an-1），其中0<=ai<n(0<=i<n)。若存在ap1=ap2=...=apm=x且m>n/2(0<=pk<n,1<=k<m)
// 则称x为A的主元素。例如A=(0,5,5,3,5,7,5,5)，则5为主元素，又如A=(0,5,5,3,5,1,5,7)，则A中没有主元素。假设A中
// 的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素，若存在主元素，则输出该元素，否则输出-1

// 时间复杂度O(n)
// 空间复杂度O(1)

int mainElement(int vec[], int n)
{
    int num = vec[0];
    int count = 1;
    for (int i = 1; i < n; i++)
        if (vec[i] != num)
        {
            if (!--count)
                count = 1, num = vec[i];
        }
        else
            count++;

    if (!count)
        return -1;

    count = 0;
    for (int i = 0; i < n; i++)
        if (vec[i] == num)
            count++;
    return count > n / 2 ? num : -1;
}

void mainElement_test()
{
    printf("No.12\n");
    SqList s;
    s.length = 8;
    s.data[1] = s.data[2] = s.data[4] = s.data[6] = s.data[7] = 5;
    s.data[0] = 0, s.data[3] = 3, s.data[5] = 7;
    printVec(&s, "vec");
    int res = mainElement(s.data, s.length);
    printf("main element: %d\n", res);

    s.data[5] = 1, s.data[7] = 7;
    printVec(&s, "vec");
    res = mainElement(s.data, s.length);
    printf("main element: %d\n", res);
    printf("\n");
}

// 13
// 给定一个含n(n>=1)个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。例如，数组
// {-5,3,2,3}中为出现的最小正整数为；数组{1,2,3}中未出现的最小正整数为4。

// 时间复杂度O(n)
// 空间复杂度O(n)

int dispmi(int vec[], int n)
{
    bool fvec[n];
    memset(fvec, 0, n * sizeof(bool));

    for (int i = 0; i < n; i++)
        if (vec[i] > 0)
            fvec[vec[i] - 1] = true;

    int res = n + 1;
    for (int i = 0; i < n; i++)
        if (!fvec[i])
        {
            res = i + 1;
            break;
        }
    return res;
}

void dispmi_test()
{
    printf("No.13\n");
    SqList s;
    s.length = 4;
    s.data[0] = -5, s.data[1] = 3, s.data[2] = 2, s.data[3] = 3;
    printVec(&s, "vec");
    int res = dispmi(s.data, s.length);
    printf("res: %d\n", res);

    s.length = 3;
    s.data[0] = 1, s.data[1] = 2, s.data[2] = 3;
    printVec(&s, "vec");
    res = dispmi(s.data, s.length);
    printf("res: %d\n", res);
    printf("\n");
}

/****************************************************************************************************/

// 链表 综合应用题

// 1
// 设计一个递归算法，删除不带头节点的单链表L中所有值为x的节点
void delLnkX(Node **node, int x)
{
    for (Node *cur = *node; cur->next;)
        if (cur->next->data == x)
        {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
        else
            cur = cur->next;

    if ((*node)->data == x)
    {
        Node *tmp = *node;
        *node = tmp->next;
        free(tmp);
    }
}

void delLnkX_test()
{
    printf("No.1\n");
    int vec[] = {0, 0, 0, 1, 1};
    Node *node = genList(vec, 5, false);
    printList(node, "before", false);
    delLnkX(&node, 0);
    printList(node, "after", false);
    delList(node);
    printf("\n");
}

// 2
// 在带头节点单链表的单链表L中，删除所有值为x的节点，并释放其空间，假设值为x的节点不唯一，试编写算法实现
// 上述操作
void delLnkXH(Node *head, int x)
{
    for (Node *cur = head; cur->next;)
        if (cur->next->data == x)
        {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
        else
            cur = cur->next;
}

void delLnkXH_test()
{
    printf("No.2\n");
    int vec[] = {0, 0, 0, 1, 1};
    Node *node = genList(vec, 5, true);
    printList(node, "before", true);
    delLnkXH(node, 0);
    printList(node, "after", true);
    delList(node);
    printf("\n");
}

// 3
// 设L为带头结点的单链表，编写算法实现从尾到头反向输出每个节点的值
void revPrint(const Node *head)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = 0, n->next = NULL;

    for (Node *cur = head->next; cur; cur = cur->next)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = cur->data;
        node->next = n->next;
        n->next = node;
    }

    printList(n, "rev", true);
    delList(n);
}

void revPrint_test()
{
    printf("No.3\n");
    int vec[] = {0, 1, 2, 3, 4};
    Node *node = genList(vec, 5, true);
    printList(node, "orignal", true);
    revPrint(node);
    delList(node);
    printf("\n");
}

// 4
// 试编写在带头节点的单链表L中删除一个最小值节点的高效算法（假设最小值节点是唯一的）
void delSMin(Node *head)
{
    Node *minnp = head;
    for (Node *cur = head; cur->next; cur = cur->next)
        if (cur->next->data < minnp->next->data)
            minnp = cur;

    Node *tmp = minnp->next;
    minnp->next = tmp->next;
    free(tmp);
}

void delSMin_test()
{
    printf("No.4\n");
    int vec[] = {2, 1, 0, 3, 4};
    Node *node = genList(vec, 5, true);
    printList(node, "before", true);
    delSMin(node);
    printList(node, "after", true);
    delList(node);
    printf("\n");
}

// 5
// 试编写算法将带头结点的单链表就地逆置，所谓“就地”指的是辅助空间复杂度为O(1)
void revSitu(Node *head)
{
    Node *cur = head->next;
    head->next = NULL;
    while (cur)
    {
        Node *tmp = cur;
        cur = cur->next;
        tmp->next = head->next;
        head->next = tmp;
    }
}

void revSitu_test()
{
    printf("No.5\n");
    int vec[] = {0, 1, 2, 3, 4};
    Node *node = genList(vec, 5, true);
    printList(node, "before", true);
    revSitu(node);
    printList(node, "after", true);
    delList(node);
    printf("\n");
}

// 6
// 有一个带头节点的单链表L，设计一个算法使其元素递增有序

// 快速排序
void quickSort(int vec[], int left, int right)
{
    if (left >= right)
        return;

    int low = left, high = right;
    int tmp = vec[low];
    while (low < high)
    {
        while (low < high && vec[high] >= tmp)
            high--;
        if (low < high)
            vec[low++] = vec[high];
        while (low < high && vec[low] <= tmp)
            low++;
        if (low < high)
            vec[high--] = vec[low];
    }
    vec[low] = tmp;
    quickSort(vec, left, low - 1);
    quickSort(vec, low + 1, right);
}

void sort(Node *head)
{
    int len = 0;
    for (Node *cur = head->next; cur; cur = cur->next)
        len++;
    int vec[len];
    int idx = 0;
    for (Node *cur = head->next; cur; cur = cur->next)
        vec[idx++] = cur->data;
    quickSort(vec, 0, len - 1);
    idx = 0;
    for (Node *cur = head->next; cur; cur = cur->next)
        cur->data = vec[idx++];
}

void sort_test()
{
    printf("No.6\n");
    int vec[] = {4, 3, 2, 1, 0};
    Node *node = genList(vec, 5, true);
    printList(node, "before", true);
    sort(node);
    printList(node, "after", true);
    delList(node);
    printf("\n");
}

// 7
// 设在一个带表头节点的单链表中所有元素节点的数据值无序，试编写一个函数，删除表中所有介于给定两个值（作为函数参数给出）
// 之间元素的元素（若存在）
void delRanE(Node *head, int x, int y)
{
    for (Node *cur = head; cur->next;)
        if (cur->next->data > x && cur->next->data < y)
        {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
        else
            cur = cur->next;
}

void delRanE_test()
{
    printf("No.7\n");
    int vec[] = {4, 3, 2, 1, 0};
    Node *node = genList(vec, 5, true);
    printList(node, "before", true);
    delRanE(node, 0, 3);
    printList(node, "after", true);
    delList(node);
    printf("\n");
}

// 8
// 给定两个单链表，编写算法找出两个链表的公共节点
const Node *pubNode(const Node *heada, const Node *headb)
{
    // 先获取两个链表的长度
    // 让长的链表先走表长之差
    // 两个链表同时走，直到汇合或null

    int lena = 0, lenb = 0;
    const Node *cura = heada->next, *curb = headb->next;
    while (cura)
    {
        lena++;
        cura = cura->next;
    }
    while (curb)
    {
        lenb++;
        curb = curb->next;
    }
    cura = heada, curb = headb;

    if (lenb > lena)
    {
        swap(&lena, &lenb);
        cura = heada, curb = headb;
    }

    for (int i = 0; i < lena - lenb; i++)
        cura = cura->next;
    while (cura && curb && cura != curb)
    {
        cura = cura->next;
        curb = curb->next;
    }
    return cura;
}

void pubNode_test()
{
    printf("No.8\n");
    int vec[] = {4, 3, 2, 1, 0};
    Node *nodea = genList(vec, 5, true);
    Node *nodeb = (Node *)malloc(sizeof(Node));
    nodeb->next = nodea->next->next->next;
    printList(nodea, "before", true);
    printList(nodeb, "before", true);
    const Node *res = pubNode(nodea, nodeb);
    printList(res, "res", false);
    delList(nodea);
    free(nodeb);
    printf("\n");
}

// 9
// 给定一个带表头结点的单链表，设head为头指针，节点结构为(next,data)，data为整型元素，next为指针，试写出
// 算法：按递增次序输出单链表中各节点的数据元素，并释放节点所占的存储空间（要求：不允许使用数组作为辅助空间）
void printSort(Node *head)
{
    printf("res:");
    while (head->next)
    {
        Node *mincur = head;
        for (Node *cur = head; cur->next; cur = cur->next)
            if (cur->next->data < mincur->next->data)
                mincur = cur;
        printf(" %d", mincur->next->data);
        Node *tmp = mincur->next;
        mincur->next = tmp->next;
        free(tmp);
    }
    printf("\n");
}

void printSort_test()
{
    printf("No.9\n");
    int vec[] = {4, 3, 2, 1, 0};
    Node *node = genList(vec, 5, true);
    printList(node, "before", true);
    printSort(node);
    delList(node);
    printf("\n");
}

// 10
// 将一个带头节点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表中序号为奇数的元素，而B表中含有原表
// 中序号为偶数的元素，且保持相对顺序不变
void detach(Node *head, Node **heada, Node **headb)
{
    Node *a = (Node *)malloc(sizeof(Node)), *b = (Node *)malloc(sizeof(Node));
    a->next = b->next = NULL, a->data = b->data = 0;
    Node *cura = a, *curb = b;
    while (head->next)
    {
        Node *tmp = head->next;
        head->next = tmp->next;
        tmp->next = NULL;
        cura->next = tmp;
        cura = cura->next;

        if (head->next)
        {
            tmp = head->next;
            head->next = tmp->next;
            tmp->next = NULL;
            curb->next = tmp;
            curb = curb->next;
        }
    }
    *heada = a, *headb = b;
}

void detach_test()
{
    printf("No.10\n");
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *node = genList(vec, 10, true);
    Node *a = NULL, *b = NULL;
    printList(node, "original", true);
    detach(node, &a, &b);
    printList(a, "a", true);
    printList(b, "b", true);
    delList(node);
    delList(a);
    delList(b);
    printf("\n");
}

// 11
// 设C={a1,b1,a2,b2,...,an,bn}为线性表，采用带头节点的hc单链表存放，设计一个就地算法，将其拆分为两个线性表，
// 使得A={a1,a2,...,an},B={bn,...,b2,b1}
void detachhc(Node *head, Node **heada, Node **headb)
{
    Node *a = (Node *)malloc(sizeof(Node)), *b = (Node *)malloc(sizeof(Node));
    a->next = b->next = NULL, a->data = b->data = 0;
    Node *cura = a;
    while (head->next)
    {
        Node *tmp = head->next;
        head->next = tmp->next;
        tmp->next = NULL;
        cura->next = tmp;
        cura = cura->next;

        if (head->next) // 头插法
        {
            tmp = head->next;
            head->next = tmp->next;
            tmp->next = NULL;
            tmp->next = b->next;
            b->next = tmp;
        }
    }
    *heada = a, *headb = b;
}

void detachhc_test()
{
    printf("No.11\n");
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *node = genList(vec, 10, true);
    Node *a = NULL, *b = NULL;
    printList(node, "original", true);
    detachhc(node, &a, &b);
    printList(a, "a", true);
    printList(b, "b", true);
    delList(node);
    delList(a);
    delList(b);
    printf("\n");
}

// 12
// 在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，设计算法去掉数值相同的元素，使表中不再有
// 重复的元素，例如(7,10,10,21,30,42,42,42,51,70)将变为(7,10,21,30,42,51,70)
void delSameSort(Node *head)
{
    if (!head->next)
        return;

    for (Node *cur = head->next; cur->next;)
        if (cur->next->data == cur->data)
        {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
        else
            cur = cur->next;
}

void delSameSort_test()
{
    printf("No.12\n");
    int vec[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    Node *node = genList(vec, 10, true);
    printList(node, "before", true);
    delSameSort(node);
    printList(node, "after", true);
    delList(node);
    printf("\n");
}

// 13
// 假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。请编写算法将这两个单链表归并为一个按元素值递减次序
// 排列的单链表，并要求利用原来两个单链表的节点存放归并后的单链表
void mergeRed(Node *heada, Node *headb)
{
    Node *r = (Node *)malloc(sizeof(Node));
    r->next = NULL, r->data = 0;
    Node *cura = heada->next, *curb = headb->next;
    heada->next = headb->next = NULL;

    while (cura && curb)
    {
        Node *t = NULL;
        if (cura->data <= curb->data)
        {
            t = cura;
            cura = cura->next;
        }
        else
        {
            t = curb;
            curb = curb->next;
        }
        t->next = r->next;
        r->next = t;
    }

    if (curb)
        cura = curb;
    while (cura)
    {
        Node *t = cura;
        cura = cura->next;
        t->next = r->next;
        r->next = t;
    }

    heada->next = r->next;
    free(r);
}

void mergeRed_test()
{
    printf("No.13\n");
    int veca[] = {1, 3, 5, 7, 9}, vecb[] = {2, 4, 6, 8, 10};
    Node *nodea = genList(veca, 5, true), *nodeb = genList(vecb, 5, true);
    printList(nodea, "before", true);
    printList(nodeb, "before", true);
    mergeRed(nodea, nodeb);
    printList(nodea, "after", true);
    delList(nodea);
    delList(nodeb);
    printf("\n");
}

// 14
// 设A和B是两个单链表（带头结点），其中元素递增有序。设计一个算法从A和B中的公共元素产生单链表C，要求不破坏
// A、B的节点
Node *genFPub(Node *heada, Node *headb)
{
    Node *c = (Node *)malloc(sizeof(Node));
    c->data = 0, c->next = NULL;
    Node *curc = c;
    for (const Node *cura = heada->next; cura; cura = cura->next)
        for (const Node *curb = headb->next; curb; curb = curb->next)
            if (cura->data == curb->data)
            {
                curc->next = (Node *)malloc(sizeof(Node));
                curc = curc->next;
                curc->data = cura->data;
                curc->next = NULL;
                break;
            }
    return c;
}

void genFPub_test()
{
    printf("No.14\n");
    int veca[] = {1, 2, 5, 7, 9}, vecb[] = {2, 4, 6, 7, 9};
    Node *nodea = genList(veca, 5, true), *nodeb = genList(vecb, 5, true);
    printList(nodea, "before", true);
    printList(nodeb, "before", true);
    Node *res = genFPub(nodea, nodeb);
    printList(res, "res", true);
    delList(nodea);
    delList(nodeb);
    delList(res);
    printf("\n");
}

// 15
// 已知两个链表A和B分别表示两个集合，其元素递增排列。编制函数，求A和B的交集，并存放于A链表中
void intxn(Node *heada, Node *headb)
{
    if (!heada || !headb)
        return;

    Node *curb = headb, *cura = heada;
    while (cura->next && curb->next)
    {
        if (cura->next->data > curb->next->data)
            curb = curb->next;
        else if (cura->next->data < curb->next->data)
        {
            Node *tmp = cura->next;
            cura->next = tmp->next;
            free(tmp);
        }
        else
            cura = cura->next, curb = curb->next;
    }
}

void intxn_test()
{
    printf("No.15\n");
    int veca[] = {1, 2, 5, 7, 9}, vecb[] = {2, 4, 6, 7, 9};
    Node *nodea = genList(veca, 5, true), *nodeb = genList(vecb, 5, true);
    printList(nodea, "before", true);
    printList(nodeb, "before", true);
    intxn(nodea, nodeb);
    printList(nodea, "res", true);
    delList(nodea);
    delList(nodeb);
    printf("\n");
}

// 16
// 两个整数序列A=a1,a2,a3,...,m和B=b1,b2,b3,...,bn已经存入两个单链表中，设计一个算法，判断序列B是否是序列
// A的连续子序列

// 获取kmp next数组
void get_next(int vec[], int next[], int n)
{
    next[0] = -1;
    for (int i = 1; i < n; i++)
    {
        int idx = next[i - 1];
        while (idx >= 0 && vec[idx] != vec[i - 1])
            idx = next[idx];
        next[i] = idx + 1;
    }
}

bool jusub(Node *ha, int m, Node *hb, int n)
{
    int va[m], vb[n];
    int ia = 0, ib = 0;
    for (const Node *cur = ha->next; ia < m; ia++, cur = cur->next)
        va[ia] = cur->data;
    for (const Node *cur = hb->next; ib < n; ib++, cur = cur->next)
        vb[ib] = cur->data;

    int next[n];
    get_next(vb, next, n);

    ia = 0, ib = 0;
    while (ia < m && ib < n)
        if (va[ia] == vb[ib] || (ib = next[ib]) == -1)
            ia++, ib++;

    return ib >= n;
}

void jusub_test()
{
    printf("No.16\n");
    int veca[] = {1, 2, 5, 7, 8, 2}, vecb[] = {1, 2, 5};
    Node *nodea = genList(veca, 6, true), *nodeb = genList(vecb, 3, true);
    printList(nodea, "before", true);
    printList(nodeb, "before", true);
    bool res = jusub(nodea, 6, nodeb, 3);
    printf("res: %d\n", res);
    delList(nodea);
    delList(nodeb);
    printf("\n");
}

// 17
// 设计一个算法用于判断带头结点的循环双链表是否对称
bool jsym(const DNode *hn)
{
    for (const DNode *h = hn->next, *t = hn->prior; h != t && t->next != h; h = h->next, t = t->prior)
        if (h->data != t->data)
            return false;
    return true;
}

void jsym_test()
{
    printf("No.17\n");

    DNode *node = (DNode *)malloc(sizeof(DNode));
    node->data = 0, node->next = node->prior = NULL;
    DNode *cur = node;
    for (int i = 0; i < 5; i++, cur = cur->next)
        for (int j = 0; j < 2; j++)
        {
            DNode *n = (DNode *)malloc(sizeof(DNode));
            n->data = i;
            n->next = cur->next;
            if (n->next)
                n->next->prior = n;
            n->prior = cur;
            cur->next = n;
        }
    while (cur->next)
        cur = cur->next;
    cur->next = node, node->prior = cur;

    printf("dclink: ");
    for (cur = node->next; cur != node; cur = cur->next)
        printf(" %d", cur->data);
    printf("\n");

    bool res = jsym(node);
    printf("res: %d\n", res);

    for (cur = node->next; cur != node;)
    {
        DNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(node);

    printf("\n");
}

// 18
// 有两个循环单链表，链表头指针分别为h1和h2，编写一个函数将链表h2链接到链表h1之后，要求链接后的链表仍保持
// 循环链表形式
void clnkcat(Node *h1, Node *h2)
{
    Node *c1 = h1, *c2 = h2;
    while (c1->next != h1)
        c1 = c1->next;
    while (c2->next != h2)
        c2 = c2->next;

    c1->next = h2->next;
    free(h2);
    c2->next = h1;
}

void clnkcat_test()
{
    printf("No.18\n");
    int veca[] = {1, 2, 5, 7, 8, 2}, vecb[] = {1, 2, 5};
    Node *nodea = genList(veca, 6, true), *nodeb = genList(vecb, 3, true);
    printList(nodea, "before", true);
    printList(nodeb, "before", true);

    Node *cur = nodea;
    while (cur->next)
        cur = cur->next;
    cur->next = nodea;
    cur = nodeb;
    while (cur->next)
        cur = cur->next;
    cur->next = nodeb;

    clnkcat(nodea, nodeb);

    printf("after:");
    for (cur = nodea->next; cur != nodea;)
    {
        printf(" %d", cur->data);
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    printf("\n");
    free(nodea);

    printf("\n");
}

// 19
// 设计一个带有头节点的循环单链表，其节点值均为正整数。设计一个算法，反复找出单链表中节点值最小的节点并输出，
// 然后将该节点从中删除，直到链表空为止，再删除表头结点
void pdmin(Node *head)
{
    printf("min:");
    while (head->next != head)
    {
        Node *cur = head;
        for (Node *c = head; c->next != head; c = c->next)
            if (c->next->data < cur->next->data)
                cur = c;
        Node *tmp = cur->next;
        printf(" %d", tmp->data);
        cur->next = tmp->next;
        free(tmp);
    }
    printf("\n");
}

void pdmin_test()
{
    printf("No.19\n");
    int vec[] = {5, 2, 1, 7, 4, 2};
    Node *node = genList(vec, 6, true);
    printList(node, "before", true);

    Node *cur = node;
    while (cur->next)
        cur = cur->next;
    cur->next = node;

    pdmin(node);

    for (cur = node->next; cur != node;)
    {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(node);

    printf("\n");
}

// 20
// 设头指针为L的带有表头结点的非循环双向链表，其每个节点中除有pred（前驱指针），data（数据）和next（后继指针）
// 外，还有一个访问频度域freq。在链表被启用前，其值均初始化为0。每当在链表中进行一次Locate(L,x)运算时，令
// 元素值为x的节点中freq域的值增加1，并使此链表中节点保持按访问频度非增（递减）的顺序排列，同时最近访问的节点
// 排在频度相同的节点前面，以便使频繁访问的节点总是靠近表头。试编写符合上述要求的Locate(L,x)运算的算法，该运算
// 为函数过程，返回找到节点的地址，类型为指针型。

// 非循环双向链表节点定义
typedef struct FNode
{
    int data;
    struct FNode *pred;
    struct FNode *next;
    int freq;
} FNode;

FNode *Locate(FNode *L, int x)
{
    FNode *cur = L->next;
    while (cur && cur->data != x)
        cur = cur->next;
    if (!cur) // 没有找到目标值
        return NULL;
    cur->freq++;

    if (cur->pred == L || cur->pred->freq > cur->freq) // 某些不需要移动节点的情况
        return cur;

    // 这里要注意在移动节点之前要将节点从原来的位置上摘出来
    cur->pred->next = cur->next;
    cur->next->pred = cur->pred;

    FNode *ic = cur->pred;
    while (ic != L && ic->freq <= cur->freq) // 找到待插入点前的节点
        ic = ic->pred;
    cur->next = ic->next; // 执行插入操作
    cur->next->pred = cur;
    ic->next = cur;
    cur->pred = ic;

    return cur;
}

FNode *get_FNode(int data)
{
    FNode *nd = (FNode *)malloc(sizeof(FNode));
    nd->data = data;
    nd->next = nd->pred = NULL;
    nd->freq = 0;
    return nd;
}

void del_FNLst(FNode *nd)
{
    while (nd)
    {
        FNode *tmp = nd;
        nd = nd->next;
        free(tmp);
    }
}

void print_FNLstWH(const FNode *hd)
{
    for (hd = hd->next; hd; hd = hd->next)
        printf(" %d", hd->data);
}

void Locate_test()
{
    printf("No.20\n");

    FNode *hd = get_FNode(0);
    FNode *cur = hd;
    for (int i = 0; i < 10; i++, cur = cur->next)
        cur->next = get_FNode(i), cur->next->pred = cur;

    for (int i = 0; i < 5; i++)
    {
        cur = Locate(hd, i);
        printf("the locate with %d:", i);
        print_FNLstWH(hd);
        printf("     retval - %d\n", cur->data);
    }
    cur = Locate(hd, 2);
    printf("the locate with %d:", 2);
    print_FNLstWH(hd);
    printf("     retval - %d\n", cur->data);

    del_FNLst(hd);

    printf("\n");
}

// 21
// 已知一个带有表头结点的单链表，节点结构为 data，link，假设该链表只给出了头指针list。在不改变链表的前提下，
// 设计一个尽可能高效的算法，查找链表中倒数第k个位置上的节点（k为正整数）。若查找成功，算法输出该节点的data
// 域的值，并返回1，否则，只返回0
bool flk(const Node *list, const int k)
{
    const Node *cur = list;
    for (int i = 0; i < k && cur; i++)
        cur = cur->next;
    if (!cur)
        return false;

    const Node *c = list;
    while (cur)
        cur = cur->next, c = c->next;
    printf("locat %d: %d\n", k, c->data);
    return true;
}

void flk_test()
{
    printf("No.21\n");
    int vec[] = {1, 2, 5, 7, 8, 2};
    Node *node = genList(vec, 6, true);
    printList(node, "list", true);
    printf("list at l3\n");
    bool res = flk(node, 3);
    printf("res: %d\n", res);
    printf("list at l7\n");
    res = flk(node, 7);
    printf("res: %d\n", res);
    delList(node);
    printf("\n");
}

// 22
// 假定采用带头节点的单链表保存单词，当两个单词有相同的后缀时，可共享相同的后缀存储空间，例如，"loading"和
// "being"的存储映像如下图所示（没有图。。。）。设str1和str2分别指向两个单词所在单词链表的头节点，链表节点的
// 结构为data，next，请设计一个时间上尽可能高效的算法，找出由str1和str2所指向两个链表共同后缀的起始位置。
const Node *fsp(const Node *str1, const Node *str2)
{
    int len1 = 0, len2 = 0;
    for (const Node *cur = str1->next; cur; cur = cur->next)
        len1++;
    for (const Node *cur = str2->next; cur; cur = cur->next)
        len2++;

    if (len2 > len1)
        swapg(&len1, &len2, sizeof(int)), swapg(&str1, &str2, sizeof(const Node *));

    for (int i = 0; i < len1 - len2; i++)
        str1 = str1->next;
    while (str1 && str2 && str1->data != str2->data)
        str1 = str1->next, str2 = str2->next;
    return str1;
}

void fsp_test()
{
    printf("No.22\n");
    int veca[] = {1, 2, 5, 7, 8, 2}, vecb[] = {4, 7, 8, 2};
    Node *nodea = genList(veca, 6, true), *nodeb = genList(vecb, 4, true);
    printList(nodea, "list", true);
    printList(nodeb, "list", true);
    const Node *n = fsp(nodeb, nodea);
    printf("res data: %d\n", n->data);
    delList(nodea);
    delList(nodeb);
    printf("\n");
}

// 23
// 用单链表保存m个整数，节点的结构为[data,link]，且|data|<=n（n为正整数）。现要求设计一个时间复杂度尽可能高效的
// 算法，对于链表中data的绝对值相等的节点，仅保留第一次出现的节点而删除其余绝对值相等的节点。例如，若给定的单链表
// head如下：
// head -> 21 -> -15 -> -15 -> -7 -> 15
// 则删除后的head为：
// head -> 21 -> -15 -> -7
void delabs(Node *head)
{
    for (Node *cur = head->next; cur; cur = cur->next)
        for (Node *c = cur; c->next;)
            if (c->next->data == cur->data || c->next->data == -cur->data)
            {
                Node *tmp = c->next;
                c->next = tmp->next;
                free(tmp);
            }
            else
                c = c->next;
}

void delabs_test()
{
    printf("No.23\n");
    int vec[] = {21, -15, -15, -7, 15};
    Node *node = genList(vec, 5, true);
    printList(node, "before", true);
    delabs(node);
    printList(node, "after", true);
    delList(node);
    printf("\n");
}

// 24
// 设计一个算法完成以下功能：判断一个链表是否有环，如果有，找出环的入口点并返回，否则返回NULL
const Node *fce(const Node *head)
{
    const Node *c1 = head, *c2 = head;
    do
    {
        c1 = c1->next;
        c2 = c2->next;
        if (c2)
            c2 = c2->next;
    } while (c2 && c1 != c2);
    if (!c2)
        return NULL;

    c1 = head;
    while (c1 != c2)
        c1 = c1->next, c2 = c2->next;
    return c1;
}

void fce_test()
{
    printf("No.24\n");
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *node = genList(vec, 10, true);

    printList(node, "entry 6", true);

    Node *m = NULL, *cur = node;
    for (; cur->next; cur = cur->next)
        if (cur->next->data == 6)
            m = cur->next;
    cur->next = m;

    const Node *res = fce(node);
    printf("entry res: %d\n", res->data);

    cur = node;
    while (cur != m)
    {
        Node *t = cur;
        cur = cur->next;
        free(t);
    }
    while (cur->next != m)
        cur = cur->next;
    cur->next = NULL;
    delList(m);

    printf("\n");
}

// 25
// 设线性表L=(a1,a2,a3,...,an-2,an-1,an)采用带头结点的单链表保存，链表中的节点结构定义为[data,next]，请设计一个
// 空间复杂度为O(1)且时间上尽可能高效的算法，重新排列L中的各节点，得到线性表L'=(a1,an,a2,an-1,a3,an-2,...)
void reang(Node *head)
{
    Node *c = head, *ce = head;
    do
    {
        c = c->next;
        ce = ce->next;
        if (ce)
            ce = ce->next;
    } while (ce);

    ce = c->next;
    c->next = NULL;
    while (ce)
    {
        Node *t = ce;
        ce = ce->next;
        t->next = c->next;
        c->next = t;
    }

    ce = c->next;
    c->next = NULL;
    c = head->next;
    while (ce)
    {
        Node *t = ce;
        ce = ce->next;
        t->next = c->next;
        c->next = t;
        c = t->next;
    }
}

void reang_test()
{
    printf("No.25\n");
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *node = genList(vec, 9, true);
    printList(node, "before", true);
    reang(node);
    printList(node, "after", true);
    delList(node);
    printf("\n");
}

/****************************************************************************************************/

int main(int argc, char *argv[])
{
    // 顺序表
    printf("Sequential List\n\n");

    // 1
    delMin_test();

    // 2
    reverse_test();

    // 3
    delX_test();

    // 4
    delRange_test();

    // 6
    delSame_test();

    // 7
    merge_test();

    // 8
    swapVec_test();

    // 9
    search_test();

    // 10
    clefts_test();

    // 11
    midNum_test();

    // 12
    mainElement_test();

    // 13
    dispmi_test();

    printf("\n");

    // 链表
    printf("Linked List\n\n");

    // 1
    delLnkX_test();

    // 2
    delLnkXH_test();

    // 3
    revPrint_test();

    // 4
    delSMin_test();

    // 5
    revSitu_test();

    // 6
    sort_test();

    // 7
    delRanE_test();

    // 8
    pubNode_test();

    // 9
    printSort_test();

    // 10
    detach_test();

    // 11
    detachhc_test();

    // 12
    delSameSort_test();

    // 13
    mergeRed_test();

    // 14
    genFPub_test();

    // 15
    intxn_test();

    // 16
    jusub_test();

    // 17
    jsym_test();

    // 18
    clnkcat_test();

    // 19
    pdmin_test();

    // 20
    Locate_test();

    // 21
    flk_test();

    // 22
    fsp_test();

    // 23
    delabs_test();

    // 24
    fce_test();

    // 25
    reang_test();

    return 0;
}