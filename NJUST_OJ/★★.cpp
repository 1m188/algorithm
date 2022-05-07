/*
Description
任意输入三个数，按照大小顺序输出这三个数（使用指针变量作为函数参数，注意空格和换行，不要多空格，也不要少了换行）

Input
第一行输入一个t（t<1000），接下来每一行输入一个a和一个b，一个c（不大于1000）

Output
按照降序的顺序排列

Sample Input
2
1 2 3
3 1 2

Sample Output
3 2 1
3 2 1
*/

#include "cstdio"
int main() //PE。Why??? 很简单的排序输出题，数据也很好处理
{
    int t = 0;
    scanf("%d", &t);
    int **a = new int *[t] { nullptr }; //这里的指针数组要注意一下
    for (int i = 0; i < t; i++)
    {
        a[i] = new int[3]{0};
        scanf("%d%d%d", a[i], a[i] + 1, a[i] + 2); //处理输入
    }

    for (int i = 0; i < t; i++) //对每组数据进行排序
    {
        for (int j = 0; j < 2; j++) //并非严格的冒泡
        {
            if (a[i][j] < a[i][j + 1])
            {
                int temp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = temp;
            }
        }
        if (a[i][0] < a[i][1])
        {
            int temp = a[i][0];
            a[i][0] = a[i][1];
            a[i][1] = temp;
        }
    }

    for (int i = 0; i < t; i++)
    {
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]); //顺序输出，注意格式
    }

    for (int i = 0; i < t; i++) //最后要释放内存，防止内存泄漏
    {
        delete[] a[i];
    }

    return 0;
}