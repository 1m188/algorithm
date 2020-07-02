/*

Huffman树能够作为编码树,对获取的正确编码进行解码,并且能够根据不同信息出现的频率不同做更有效率的查找,高频率信息查找快,低频率信息相对查找路径长度更长

*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"
#include "stdbool.h"
#include "memory.h"

// Huffman树的节点
typedef struct Node
{
    int freq;
    int num;
    struct Node *left, *right;
} Node;

// 构建Huffman树
Node *build_huffman(Node **node_vec, int len);

// 先序遍历
void preorder(Node *head);

// 中序遍历
void inorder(Node *head);

// 后序遍历
void postorder(Node *head);

// 释放树空间
void free_huffman(Node *head);

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    int n = rand() % 6 + 5;                                // 5-10
    Node **node_vec = (Node **)malloc(sizeof(Node *) * n); // 每个节点

    for (int i = 0; i < n; i++)
    {
        node_vec[i] = (Node *)malloc(sizeof(Node));
        node_vec[i]->left = node_vec[i]->right = NULL;
        node_vec[i]->num = rand() % 101;     // 0-100
        node_vec[i]->freq = rand() % 30 + 1; // 1-30
    }

    printf("original order:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", node_vec[i]->num);
    }
    printf("\n");

    printf("and it's rate:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", node_vec[i]->freq);
    }
    printf("\n");

    Node *head = build_huffman(node_vec, n);

    printf("pre order:");
    preorder(head);
    printf("\n");

    printf("in order:");
    inorder(head);
    printf("\n");

    printf("post order:");
    postorder(head);
    printf("\n");

    free_huffman(head);
    free(node_vec);

    return 0;
}

Node *build_huffman(Node **node_vec, int len)
{
    // 节点列表为空返回空头
    if (!node_vec[0])
    {
        return NULL;
    }

    Node *head = node_vec[0]; // 如果只有一个节点,则其为头
    int remain_len = len;
    while (remain_len > 1)
    {
        Node *min1 = NULL, *min2 = NULL;
        int index1 = -1, index2 = -1;

        // 找到两个最小的节点,并将原来的地方置为空
        for (int i = 0; i < len; i++)
        {
            if (node_vec[i] && (index1 < 0 || node_vec[i]->freq < node_vec[index1]->freq))
            {
                index1 = i;
            }
        }
        min1 = node_vec[index1];
        node_vec[index1] = NULL;

        for (int i = 0; i < len; i++)
        {
            if (node_vec[i] && (index2 < 0 || node_vec[i]->freq < node_vec[index2]->freq))
            {
                index2 = i;
            }
        }
        min2 = node_vec[index2];
        node_vec[index2] = NULL;

        // 这里是Huffman树的生成方式,找两个最小的节点作为子节点,之后生成一个父节点值为子节点之和的树,这棵树放入森林之中
        // 重复进行上述过程,直到森林里最终只有一棵树

        // 生成新的父节点,将找到的两个最小的节点置为其子节点,新的节点的频率为两个子节点频率之和
        // 将新的父节点重新放入节点数组中
        Node *min = (Node *)malloc(sizeof(Node));
        min->left = min1;
        min->right = min2;
        min->freq = min1->freq + min2->freq;
        min->num = -1;
        node_vec[index1] = min;
        head = min;   // 最后一次的时候,这个父节点就是最终的头节点
        remain_len--; // 待入树节点-1
    }
    return head;
}

void preorder(Node *head)
{
    if (head)
    {
        printf(" %d", head->num);
        preorder(head->left);
        preorder(head->right);
    }
}

void inorder(Node *head)
{
    if (head)
    {
        inorder(head->left);
        printf(" %d", head->num);
        inorder(head->right);
    }
}

void postorder(Node *head)
{
    if (head)
    {
        postorder(head->left);
        postorder(head->right);
        printf(" %d", head->num);
    }
}

void free_huffman(Node *head)
{
    // 后序遍历释放树空间
    if (head)
    {
        free_huffman(head->left);
        free_huffman(head->right);
        free(head);
    }
}