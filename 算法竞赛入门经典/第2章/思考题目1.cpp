#include "stdio.h"
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("%d\n", i);
    return 0;
}

// 对程序改动，输出2，4，6，8，...，2n

// 任务1：修改第七行，不修改第六行
// printf("%d\n", 2 * i);

// 任务2：修改第六行，不修改第七行
// for (int i = 2; i <= 2 * n; i += 2)
