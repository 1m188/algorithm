/*
6-7 统计某类完全平方数 （20 分）
本题要求实现一个函数，判断任一给定整数N是否满足条件：它是完全平方数，又至少有两位数字相同，如144、676等。

函数接口定义：

int IsTheNumber ( const int N );
其中N是用户传入的参数。如果N满足条件，则该函数必须返回1，否则返回0。

裁判测试程序样例：

#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

你的代码将被嵌在这里

输入样例：

105 500
输出样例：

cnt = 6
*/

#include <stdio.h>
#include <math.h>

int IsTheNumber(const int N);

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for (i = n1; i <= n2; i++)
    {
        if (IsTheNumber(i))
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber(const int N)
{
    int n = sqrt(N);
    if (n * n != N)
    {
        return 0;
    }

    char num[20] = {'\0'};
    n = N;
    for (int i = 0; n; i++)
    {
        num[i] = n % 10 + '0'; //注意这里要加字符0，为了使其中的数字元素不和后面的'\0'搞混
        n /= 10;
    }
    for (int i = 0; num[i] != '\0'; i++)
    {
        for (int j = i + 1; num[j] != '\0'; j++)
        {
            if (num[i] == num[j])
            {
                return 1;
            }
        }
    }
    return 0;
}