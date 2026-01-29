/*

排序——天勤2021数据结构

*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "memory.h"
#include "stdbool.h"
#include "math.h"

// 生成一个随机数组(0-100)
void genrandvec(int vec[], int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
        vec[i] = rand() % 101;
}

// 输出一个数组
void printvec(int vec[], int n, char *prefix)
{
    printf("%s", prefix);
    for (int i = 0; i < n; i++)
        printf(" %d", vec[i]);
    printf("\n");
}

// 交换两个int变量的值
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/***********************************************  插入类排序  ******************************************************/

// 直接插入排序
void InsertSort(int r[], int n)
{
    // 时间复杂度最好的情况下为O(n)，最坏的情况下为O(n^2)，平均O(n^2)
    // 空间复杂度为O(1)，其所使用的辅助空间不随问题规模而增长
    // 是一个稳定的排序

    for (int i = 1; i < n; i++)
    {
        int tmp = r[i];
        int in = i - 1;
        while (in >= 0 && r[in] > tmp)
        {
            r[in + 1] = r[in];
            in--;
        }
        r[in + 1] = tmp;
    }
}

// 在顺序序列中获取折半查找索引（左闭右闭区间）
int bindex(int vec[], int target, int left, int right)
{
    int mid = (left + right) / 2;
    while (left < right)
    {
        if (vec[mid] == target)
            return mid + 1;
        else if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
        mid = (left + right) / 2;
    }
    return vec[mid] <= target ? mid + 1 : mid;
}

// 折半插入排序
void bInsertSort(int r[], int n)
{
    // 相较于直接插入排序，折半插入排序查找次数更少，但是对关键字移动次数是相同的
    // 时间复杂度最好情况为O(nlog2n)，最坏情况为O(n^2)和直接插入排序一样，平均情况为O(n^2)
    // 空间复杂度和直接插入排序一样，都没有使用随问题规模增加的空间，为O(1)

    for (int i = 1; i < n; i++)
    {
        int tmp = r[i];
        int in = bindex(r, r[i], 0, i - 1);
        for (int j = i - 1; j >= in; j--)
            r[j + 1] = r[j];
        r[in] = tmp;
    }
}

// 希尔排序
// k为初始增量
// 按照每次/2的增量选取
void shellSort(int r[], int n, int k)
{
    // 希尔排序的时间复杂度和增量选取有关，/2增量的时间复杂度为O(n^2)
    // 空间复杂度为O(1)

    while (k >= 1)
    {
        for (int i = 0; i < k; i++)            // 将整个数组分为k个序列
            for (int j = i + k; j < n; j += k) // 对每个序列单独进行直接插入排序
            {
                int tmp = r[j];
                int in = j - k;
                while (in >= i && tmp < r[in])
                {
                    r[in + k] = r[in];
                    in -= k;
                }
                r[in + k] = tmp;
            }
        k /= 2;
    }
}

/******************************************************************************************************************/

/***********************************************  交换类排序  ******************************************************/

// 冒泡排序
void BubbleSort(int r[], int n)
{
    // 时间复杂度最好为O(n)，最坏为O(n^2)
    // 空间复杂度，未用到随规模变化的额外辅助空间，为O(1)

    for (int i = n - 1; i >= 1; i--)
    {
        bool flag = false; // 判定在这一趟排序中有没有发生关键字交换，若没有，则表明排序结束
        for (int j = 1; j <= i; j++)
            if (r[j] < r[j - 1])
            {
                swap(&r[j], &r[j - 1]);
                flag = true;
            }
        if (!flag)
            return;
    }
}

// 快速排序
// left和right为左右封闭的区间端点索引
void QuickSort(int r[], int left, int right)
{
    // 时间复杂度最好的情况为O(nlog2n)，最坏的情况为O(n^2)
    // 待排序序列越有序，效率越低；越无序效率越高
    // 基本操作执行次数的多项式时间在同级别算法中最好
    // 空间复杂度为O(log2n)，递归进行使用了栈

    if (left >= right)
        return;

    int low = left, high = right;
    int tmp = r[low];

    // 这个循环完成了一趟排序，将数组中小于tmp的关键字放到左边，大于的放到右边
    while (low < high)
    {
        while (low < high && r[high] >= tmp) // 从右往左扫描，找到第一个小于tmp的关键字
            high--;
        if (low < high) // 如果此时符合左右要求的话，将其放在tmp的左边，即low的位置上，并将low右移一位
            r[low++] = r[high];

        while (low < high && r[low] <= tmp) // 做类似的操作，把左边大的放到右边
            low++;
        if (low < high)
            r[high--] = r[low];
    }

    // 以tmp关键字左右分别小于和大于它，对左右再做同样的排序，直到数组有序
    r[low] = tmp;
    QuickSort(r, left, low - 1);
    QuickSort(r, low + 1, right);
}

/******************************************************************************************************************/

/***********************************************  选择类排序  ******************************************************/

// 简单选择排序
void SelectSort(int r[], int n)
{
    // 时间复杂度为O(n^2)
    // 空间复杂度为O(1)

    for (int i = 0; i < n; i++)
    {
        int in = i;
        for (int j = i + 1; j < n; j++) // 从无序序列中挑一个最小的关键字
            if (r[j] < r[in])
                in = j;

        // 交换最小关键字和序列第一个关键字，使得前部分交换过的序列为有序
        swap(&r[in], &r[i]);
    }
}

// 对于大顶堆，在r数组的[left,right]范围内进行调整
void Sift(int r[], int left, int right)
{
    if (left >= right)
        return;

    int tmp = r[left];    // 根节点值
    int m = left * 2 + 1; // 左子节点索引
    while (m <= right)    // 从根节点开始进行调整
    {
        if (m + 1 <= right && r[m] < r[m + 1]) // 取左右子节点的最大值
            m++;

        if (tmp < r[m]) // 如果这个地方不能够满足的话，下面的节点上移，往下面继续讨论
        {
            r[left] = r[m];
            left = m;
            m = left * 2 + 1;
        }
        else
            break;
    }
    r[left] = tmp;
}

// 大顶堆 堆排序
void heapSort(int r[], int n)
{
    // 时间复杂度为O(nlog2n)
    // 空间复杂度为O(1)
    // 堆排序最好最坏情况下的时间复杂度一样，这是其相对于快速排序的最大优点，其空间复杂度在所有的相同时间复杂度的算法中是最好的
    // 适合关键字很多的场景

    // 从最后一个非叶子节点开始调整
    for (int i = (n - 2) / 2; i >= 0; i--)
        Sift(r, i, n - 1);

    // 将每个堆顶元素（最大值）放到序列最后，并对头部元素进行调整
    for (int i = n - 1; i >= 1; i--)
    {
        swap(&r[0], &r[i]);
        Sift(r, 0, i - 1);
    }
}

/******************************************************************************************************************/

/***********************************************  二路归并排序  ******************************************************/

// 将数组中两个索引闭区间已排好序的内容进行归并
// left和right为区间左右边界，mid为中间索引，[left,mid],[mid+1,right]
void merge(int r[], int left, int mid, int right)
{
    // 待转存序列数组长度
    const int vll = mid - left + 1, vrl = right - mid;

    // 转存两个顺序序列
    int vl[vll], vr[vrl];
    memcpy(vl, r + left, sizeof(int) * (vll));
    memcpy(vr, r + mid + 1, sizeof(int) * (vrl));

    int vli = 0, vri = 0;          // 转存序列数组索引
    while (vli < vll && vri < vrl) // 将两个数组中小的部分从前往后往r里填
    {
        if (vl[vli] <= vr[vri])
            r[left++] = vl[vli++];
        else
            r[left++] = vr[vri++];
    }

    // 将最后还没有归并进入的数组部分进行归并
    while (vli < vll)
        r[left++] = vl[vli++];
    while (vri < vrl)
        r[left++] = vr[vri++];
}

// 二路归并排序
void mergeSort(int r[], int left, int right)
{
    // 时间复杂度最好最坏情况下均为O(nlog2n)
    // 空间复杂度由于需要转存整个待排序列，为O(n)

    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(r, left, mid);
        mergeSort(r, mid + 1, right);
        merge(r, left, mid, right);
    }
}

/******************************************************************************************************************/

/***********************************************  基数排序  ******************************************************/

// 对关键字每一位进行排序
// b为关键字的某一位，1为个位，2为十位，以此类推
void sortperbit(int r[], int n, int b)
{
    // 定义存放每个关键字的“桶”，即队列，10是因为个位数只有十个
    int bkt[10][n];
    memset(bkt, 0, sizeof(int) * 10 * n);

    // 定义队列指针
    int front[10], rear[10];
    for (int i = 0; i < 10; i++)
        front[i] = rear[i] = -1; // 空队两个指针相等为-1，队列不用循环，每个队列都能够装下所有元素

    int bb = pow(10, b - 1); // 定义获取某一位上数字的待除数

    for (int i = 0; i < n; i++) // 根据关键字某一位的大小将其放入不同的“桶”
    {
        int in = r[i] / bb % 10;
        bkt[in][++rear[in]] = r[i];
    }

    int index = 0;
    for (int i = 0; i < 10; i++) // 将桶里的数按照入队顺序拿出
        while (front[i] != rear[i])
            r[index++] = bkt[i][++front[i]];
}

// 最低位优先 基数排序
// b为关键字位数
void jishuSort(int r[], int n, int b)
{
    // 时间复杂度最好最坏情况下都是O(d*(n+rd))
    // n为元素个数，rd为关键字取值范围，即有几个“桶”，d为整个排序对分配和收集所进行的次数
    // 空间复杂度为O(rd)，因为需要开辟队列，每个桶都是一个队列，每个队列需要有头尾指针

    // 最高位优先类似于扑克排序，先将花色排序，然后再对数字排序，即对优先级高的关键字先排序，然后再对低级关键字排序
    // 低级关键字可以直接用插入排序或者快排等。有点像桶排序，或许这两者就是一个东西，高低优先级两种排序统称为基数排序

    // 基数排序适合关键字很多的场景，并且关键字取值范围较小

    for (int i = 1; i <= b; i++)
        sortperbit(r, n, i);
}

/******************************************************************************************************************/

/***********************************************  外部排序  ******************************************************/
/*

k路归并排序
    置换——选择排序（给出若干段初始归并段）
    最佳归并树（选择最佳的归并路径）
    败者树（在每次归并中减少比较次数）

1. m个初始归并段进行k路归并，时间复杂度为O(logkm)
2. 每一次归并，所有的记录都要进行2次IO操作
3. 置换——选择排序一步中，所有记录都要进行2次IO操作
4. 置换——选择排序一步中，时间复杂度由选取最值的算法决定
5. k路归并败者树的高度为log2k+1，利用败者树从k个记录里选出最值需要进行log2k次比较，即时间复杂度为O(log2k)
6. k路归并败者树的建树时间复杂度为O(klog2k)
7. k路归并败者树为一颗二叉树
8. 选择树的精髓在于：通过某较大的时间复杂度进行建树，将若干数据排列成某种结构，之后从中选取一个满足要求的关键字，并拿到新的数据
替换原来的关键字的位置，之后用较小的时间复杂度进行局部调整，循环往复
9. 空间复杂度为O(1)，所有步骤中额外空间均为常量

*/
/******************************************************************************************************************/

/***********************************************  计数排序  ******************************************************/

// 课后习题 综合应用题 基础题 (1)

// 计数排序
// a为待排序数组，n为数组元素个数，b为排序结果数组
void calcSort(int a[], int n, int b[])
{
    // 计数排序要求所有关键字没有重复

    int num = 0;
    for (int i = 0; i < n; i++) // 对数组中每个元素
    {
        for (int j = 0; j < n; j++) // 再次扫描整个数组，确定有多少更小的元素
            if (a[j] < a[i])
                num++;
        b[num] = a[i];
        num = 0;
    }
}

/******************************************************************************************************************/

/***********************************************  双向冒泡排序  ******************************************************/

// 课后习题 综合应用题 基础题 (3)

// 双向冒泡排序
void dBubbleSort(int r[], int n)
{
    bool flag = true;
    int left = 0, right = n - 1;
    while (flag)
    {
        flag = false;

        for (int i = left; i < right; i++)
            if (r[i] > r[i + 1])
            {
                swap(&r[i], &r[i + 1]);
                flag = true;
            }

        right--;

        for (int i = right; i > left; i--)
            if (r[i] < r[i - 1])
            {
                swap(&r[i], &r[i - 1]);
                flag = true;
            }
        left++;
    }
}

/******************************************************************************************************************/

int main(int argc, char *argv[])
{
    const int len = 10;
    int vec[len];
    memset(vec, 0, sizeof(int) * len);

    // 直接插入排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    InsertSort(vec, len);
    printvec(vec, len, "after insert sort:");

    printf("\n");

    // 折半插入排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    bInsertSort(vec, len);
    printvec(vec, len, "after binary insert sort:");

    printf("\n");

    // 希尔排序 /2增量
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    shellSort(vec, len, 3);
    printvec(vec, len, "after shell /2 sort:");

    printf("\n");

    // 冒泡排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    BubbleSort(vec, len);
    printvec(vec, len, "after bubble sort:");

    printf("\n");

    // 快速排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    QuickSort(vec, 0, len - 1);
    printvec(vec, len, "after quick sort:");

    printf("\n");

    // 简单选择排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    SelectSort(vec, len);
    printvec(vec, len, "after select sort:");

    printf("\n");

    // 大顶堆排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    heapSort(vec, len);
    printvec(vec, len, "after heap sort:");

    printf("\n");

    // 二路归并排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    mergeSort(vec, 0, len - 1);
    printvec(vec, len, "after merge sort:");

    printf("\n");

    // 基数排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    jishuSort(vec, len, 3);
    printvec(vec, len, "after jishu sort:");

    printf("\n");

    // 计数排序
    for (int i = 0; i < len; i++)
        vec[i] = len - i;
    printvec(vec, len, "original vec:");
    int b[len];
    memset(b, 0, sizeof(int) * len);
    calcSort(vec, len, b);
    printvec(b, len, "after calc sort:");

    printf("\n");

    // 双向冒泡排序
    genrandvec(vec, len);
    printvec(vec, len, "original vec:");
    dBubbleSort(vec, len);
    printvec(vec, len, "after double direction bubble sort:");

    printf("\n");

    return 0;
}