/*

数组、矩阵与广义表——天勤2021数据结构

*/

#include "stdio.h"
#include "stdbool.h"
#include <stdlib.h>

/**********************************************  数组  ***********************************************************/

// 多维数组，行列优先

/****************************************************************************************************************/

/**********************************************  矩阵  ***********************************************************/

// 二维数组，矩阵定义
#define M 4
#define N 3
int A[M][N];

// 二维数组最大尺寸
#define MAX_SIZE 100

// 矩阵转置
void trsmat(int A[][MAX_SIZE], int B[][MAX_SIZE], int m, int n) // maxsize用来控制数组最大值，m和n用来指示矩阵实际大小
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            B[j][i] = A[i][j];
}

// 矩阵相加
void addmat(int C[][MAX_SIZE], int A[][MAX_SIZE], int B[][MAX_SIZE], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// 矩阵相乘
// A矩阵为m*n，B矩阵为n*k
void mutmat(int C[][MAX_SIZE], int A[][MAX_SIZE], int B[][MAX_SIZE], int m, int n, int k)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j] = 0;
            for (int h = 0; h < n; h++)
                C[i][j] += A[i][h] * B[h][j];
        }
}

// 对称矩阵、三角阵和对角矩阵等特殊矩阵的存储，注意特殊元素的下标索引

// 稀疏矩阵，三元组表示法（顺序表示法）
/*
typdef struct
{
    int val; // 元素的值
    int i, j; // 元素所在矩阵内部的位置
}Trimat;
Trimat trimat[maxterms + 1]; // 一个含有maxterms个非零元素的稀疏矩阵

// 简便起见
int trimat[maxterms + 1][3]; // 第一个位置放元素，第二个位置和第三个位置放位置索引，整个数组的第一个地方放整个矩阵的信息，包括行列数和非零元素个数等
*/

// 给定一个稀疏矩阵A（float型），其尺寸为m*n，建立其对应的三元组存储，并通过三元组打印输出矩阵A

// 建立三元组
void createtrimat(float A[][MAX_SIZE], int m, int n, float B[][3])
{
    int k = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j])
            {
                B[k][0] = A[i][j];
                B[k][1] = i;
                B[k][2] = j;
                k++;
            }
    B[0][0] = k - 1; // 非零元素个数
    B[0][1] = m;     // 行数
    B[0][2] = n;     // 列数
}

// 通过三元组打印矩阵
void print(float B[][3])
{
    int k = 1;
    for (int i = 0; i < B[0][1]; i++)
    {
        for (int j = 0; j < B[0][2]; j++)
        {
            if (i == (int)B[k][1] && j == (int)B[k][2])
            {
                printf("%f ", B[k][0]);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// 稀疏矩阵，伪地址表示法。A[i][j]伪地址计算方法：n(i-1)+j

// 稀疏矩阵链式表示法，邻接表表示法，十字链表表示法

// 十字链表表示

// 普通节点结构定义
typedef struct OLNode
{
    int row, col;                // 行号和列号
    struct OLNode *right, *down; // 指向右边节点和下方节点的指针
    float val;
} OLNode;

// 头节点结构定义
typedef struct
{
    OLNode *rhead, *chead; // 指向两头节点数组的指针
    int m, n, k;           // 矩阵行数、列数和非零节点数
} CrossList;

// 给定一个稀疏矩阵A，其尺寸为m*n，非零元素个数为k，建立其对应的十字链表存储结构
bool createcrossListmat(float A[][MAX_SIZE], int m, int n, int k, CrossList *cm)
{
    if (cm->rhead)
    {
        free(cm->rhead);
        cm->rhead = NULL;
    }
    if (cm->chead)
    {
        free(cm->chead);
        cm->chead = NULL;
    }

    cm->m = m;
    cm->n = n;
    cm->k = k;

    // 申请头节点数组空间
    if (!(cm->chead = (OLNode *)malloc(sizeof(OLNode) * m)))
        return false;
    if (!(cm->rhead = (OLNode *)malloc(sizeof(OLNode) * n)))
        return false;

    // 头节点数组right和down指针都置空
    for (int i = 0; i < m; i++)
    {
        cm->chead[i].right = NULL;
        cm->chead[i].down = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        cm->rhead[i].right = NULL;
        cm->rhead[i].down = NULL;
    }

    OLNode *temps[MAX_SIZE]; // 建立列链表的辅助指针数组
    for (int i = 0; i < n; i++)
        temps[i] = &(cm->rhead[i]);

    for (int i = 0; i < m; i++)
    {
        OLNode *r = &(cm->chead[i]);
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                OLNode *p = (OLNode *)malloc(sizeof(OLNode));
                p->row = i;
                p->col = j;
                p->val = A[i][j];
                p->down = NULL;
                p->right = NULL;

                r->right = p;
                r = p;
                temps[j]->down = p;
                temps[j] = p;
            }
        }
    }
    return true;
}

/****************************************************************************************************************/

/**********************************************  广义表  ***********************************************************/

// 广义表的长度：为表中最上层元素个数
// 广义表的深度：为表中括号的最大层数

/****************************************************************************************************************/

int main(int argc, char *argv[])
{
    return 0;
}