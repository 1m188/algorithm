#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"

// 大顶堆排序
void maxheap_sort(int *vec, int len);

// 调整大顶堆
void adjust_maxheap(int *vec, int len, int index);

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

    maxheap_sort(vec, n);

    printf("after sort:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", vec[i]);
    }
    printf("\n");

    free(vec);

    return 0;
}

void maxheap_sort(int *vec, int len)
{
    // 对已经存在的数组进行调整,使其成为大顶堆
    for (int i = len / 2 - 1; i >= 0; i--) // 从第一个非叶子节点从下至上,从右至左进行调整
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}