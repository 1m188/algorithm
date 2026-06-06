/*

标题：快速排序。

以下代码可以从数组a[]中找出第k小的元素。


它使用了类似快速排序中的分治算法，期望时间复杂度是O(N)的。


请仔细阅读分析源码，填写划线部分缺失的内容。

#include <stdio.h>

int quick_select(int a[], int l, int r, int k) {
        int p = rand() % (r - l + 1) + l;
        int x = a[p];
        {int t = a[p]; a[p] = a[r]; a[r] = t;}
        int i = l, j = r;
        while(i < j) {
                while(i < j && a[i] < x) i++;
                if(i < j) {
                        a[j] = a[i];
                        j--;
                }
                while(i < j && a[j] > x) j--;
                if(i < j) {
                        a[i] = a[j];
                        i++;
                }
        }
        a[i] = x;
        p = i;
        if(i - l + 1 == k) return a[i];
        if(i - l + 1 < k) return quick_select( _____________________________ ); //填空
        else return quick_select(a, l, i - 1, k);
}

int main()
{
        int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};
        printf("%d\n", quick_select(a, 0, 14, 5));
        return 0;
}


注意：只填写划线部分缺少的代码，不要抄写已经存在的代码或符号。


*/

/*
 * 分析：
 *   quick_select 快速选择算法，类似快速排序的分治。
 *   第 35 行：当 pivot 在左子数组的排名 i-l+1 < k 时，
 *   说明第 k 小的元素在 pivot 右侧子数组 a[i+1..r] 中，
 *   且在该子数组中的排名变为 k - (i - l + 1)。
 *   因此填空为：a, i + 1, r, k - (i - l + 1)
 */

#include "cstdlib"
#include "ctime"
#include "iostream"

int quick_select(int a[], int l, int r, int k) {
    int p = rand() % (r - l + 1) + l;
    int x = a[p];
    {
        int t = a[p];
        a[p] = a[r];
        a[r] = t;
    }
    int i = l, j = r;
    while (i < j) {
        while (i < j && a[i] < x)
            i++;
        if (i < j) {
            a[j] = a[i];
            j--;
        }
        while (i < j && a[j] > x)
            j--;
        if (i < j) {
            a[i] = a[j];
            i++;
        }
    }
    a[i] = x;
    p = i;
    if (i - l + 1 == k)
        return a[i];
    if (i - l + 1 < k)
        return quick_select(a, i + 1, r, k - (i - l + 1)); // 填空
    else
        return quick_select(a, l, i - 1, k);
}

int main() {
    // 初始化随机种子
    srand(time(0));

    // 题目给定测试
    int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};
    std::cout << quick_select(a, 0, 14, 5) << std::endl;

    return 0;
}
