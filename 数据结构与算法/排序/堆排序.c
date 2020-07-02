/*

堆是一种重要的排序结构,通过构建完全二叉树来进行排序,属于选择排序的一种

对于大顶堆,每个节点的值都不小于其子节点的值,此时树根为最大值
对于小顶堆,每个节点的值都不大于其子节点的值,此时树根为最小值

堆身为完全二叉树,放在数组中有 父节点的索引*2+1=左子节点索引,父节点索引*2+2=右子节点索引 的性质

排序过程为:
1. 对获取的乱序数组进行建堆,升序用大顶堆,降序用小顶堆.首先从最后一个不为叶子的节点,从下至上,从右至左进行调整.
2. 之后将头部元素和最后元素交换,并对剩下的元素重新调整,直到最终堆的长度为0
3. 调整的操作中:
    (1) 首先将头部节点保存在临时变量中
    (2) 开始循环,索引从头部开始,每次循环指向当前节点的左子节点
    (3) 循环中,获取两个子节点中相应的符合大小顶堆性质的节点(如果右子节点存在的话)(大顶堆找最大的,小顶堆找最小的)
    (4) 将其和临时变量的值比较,如果符合堆性质,不用变,直接跳出去;否则移动节点的值向上,将下面的节点作为父节点,继续重复上述循环,直到最终找到一个位置可以给
    临时变量的值放置,也就是之前换上来的头节点
    (5) 将临时变量的值赋给这个节点

建堆时间复杂度为 O(n)
排序时间复杂度为 O(nlogn)

*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"
#include "memory.h"

// 大顶堆排序(升序)
void maxheap_sort(int *vec, int len);

// 调整大顶堆
void adjust_maxheap(int *vec, int len, int index);

// 小顶堆排序(降序)
void minheap_sort(int *vec, int len);

// 调整小顶堆
void adjust_minheap(int *vec, int len, int index);

// 交换
void swap(int *a, int *b);

int main(int argc, char *argv[])
{
    // 生成若干个一定范围内的随机数,由于生成随机,所以初始的顺序也是随机的
    srand((unsigned int)time(NULL));
    int n = rand() % 11 + 5; // 5-15
    int *vec = (int *)malloc(sizeof(int) * n);

    printf("before sort:");
    for (int i = 0; i < n; i++)
    {
        vec[i] = rand() % 101; // 0-100
        printf(" %d", vec[i]);
    }
    printf("\n");

    int *vec2 = (int *)malloc(sizeof(int) * n);
    memcpy(vec2, vec, sizeof(int) * n);

    maxheap_sort(vec, n);
    minheap_sort(vec2, n);

    printf("after maxheap sort:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", vec[i]);
    }
    printf("\n");

    printf("after minheap sort:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", vec2[i]);
    }
    printf("\n");

    free(vec);
    free(vec2);

    return 0;
}

void maxheap_sort(int *vec, int len)
{
    // 对已经存在的数组进行调整,使其成为大顶堆
    for (int i = len / 2 - 1; i >= 0; i--) // 从最后一个非叶子节点从下至上,从右至左进行调整
    {
        adjust_maxheap(vec, len, i);
    }

    // 交换堆顶和堆尾的元素,逐渐将所有大的元素往后排
    // 并在每次交换之后,重新调整堆,使其继续符合大顶堆定义
    for (int i = len - 1; i >= 0; i--)
    {
        swap(&vec[0], &vec[i]);
        adjust_maxheap(vec, i, 0);
    }
}

void adjust_maxheap(int *vec, int len, int index)
{
    int temp = vec[index];
    for (int i = index * 2 + 1; i < len; i = i * 2 + 1)
    {
        // 拿到两个子节点中(如果存在的话)值最大的那个
        if (i + 1 < len && vec[i] < vec[i + 1])
        {
            i++;
        }

        if (vec[i] > temp)
        {
            vec[index] = vec[i];
            index = i;
        }
        else
        {
            break;
        }
    }
    vec[index] = temp;
}

void minheap_sort(int *vec, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        adjust_minheap(vec, len, i);
    }

    for (int i = len - 1; i >= 0; i--)
    {
        swap(&vec[0], &vec[i]);
        adjust_minheap(vec, i, 0);
    }
}

void adjust_minheap(int *vec, int len, int index)
{
    int temp = vec[index];
    for (int i = index * 2 + 1; i < len; i = i * 2 + 1)
    {
        if (i + 1 < len && vec[i] > vec[i + 1])
        {
            i++;
        }

        if (vec[i] < temp)
        {
            vec[index] = vec[i];
            index = i;
        }
        else
        {
            break;
        }
    }
    vec[index] = temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}