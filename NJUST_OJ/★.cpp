/*
Description
任意输入两个数，按大小顺序输出这两个数（使用指针，注意空格和换行，不要多空格，也不要少了换行）

Input
第一行输入一个t（t<1000），接下来每一行输入一个a和一个b（不大于1000）

Output
先输出最大值，再输入最小值

Sample Input
2
1 2
5 3

Sample Output
2 1
5 3
*/

#include "cstdio"
int main() //PE。老问题，不知道出在何处...
{
    int t = 0;
    scanf("%d", &t);
    int **a = new int *[t] { nullptr };
    for (int i = 0; i < t; i++)
    {
        a[i] = new int[2]{0};
        scanf("%d%d", &a[i][0], &a[i][1]);
    }

    for (int i = 0; i < t; i++)
    {
        printf("%d %d\n", a[i][0] > a[i][1] ? a[i][0] : a[i][1], a[i][0] <= a[i][1] ? a[i][0] : a[i][1]);
    }

    for (int i = 0; i < t; i++)
    {
        delete[] a[i];
    }

    return 0;
}