/*
Description
给定一个大小为n的数组，请使用冒泡排序方法对数组从小到大进行排序。（要求使用数组的指针和函数）
PS：函数格式：
void BubbleSort(int *a,int n){
       
}

Input
第一行输入一个t（t<1000），接下来先输入一个n，然后再输入n个数（均不大于1000）

Output
输出数组

Sample Input
2
3
1 3 2
4
4 3 2 1

Sample Output
1 2 3
1 2 3 4
*/

#include "cstdio"

void BubbleSort(int *a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() //PE...简单的题目总是挂在格式上面...
{
    int t = 0;
    scanf("%d", &t);
    int **a = new int *[t] {};
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        scanf("%d", &n);
        a[i] = new int[n + 1]{n}; //用数组的第一个元素储存数组的大小，之后n的大小用来储存数组元素
        for (int j = 1; j < n + 1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < t; i++)
    {
        BubbleSort(a[i] + 1, a[i][0]);
        for (int j = 1; j < a[i][0]; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][a[i][0]]);
        if (i != t - 1)
        {
            printf("\n");
        }
        delete[] a[i]; //注意内存的释放
    }
    delete[] a;

    return 0;
}