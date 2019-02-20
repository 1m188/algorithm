/*
6-10 阶乘计算升级版 （20 分）
本题要求实现一个打印非负整数阶乘的函数。

函数接口定义：

void Print_Factorial ( const int N );
其中N是用户传入的参数，其值不超过1000。如果N是非负整数，则该函数必须在一行中打印出N!的值，否则打印“Invalid input”。

裁判测试程序样例：

#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

你的代码将被嵌在这里

输入样例：

15
输出样例：

1307674368000
*/

#include <stdio.h>

void Print_Factorial(const int N);

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

//字符串模拟大数相乘
void Print_Factorial(const int N)
{
    if (N < 0)
    {
        printf("Invalid input");
    }
    else if (N == 0)
    {
        printf("1");
    }
    else
    {
        const int length = 100000;
        int arr[length];
        for (int i = 0; i < length; i++)
        {
            arr[i] = -1;
        }
        int n = N;
        for (int i = length - 1; n; i--)
        {
            arr[i] = n % 10;
            n /= 10;
        }

        for (int i = N - 1; i >= 1; i--)
        {
            int t[length];
            for (int j = 0; j < length; j++)
            {
                t[j] = -1;
            }
            int carry = 0;
            int index = 0;
            for (index = length - 1; arr[index] != -1; index--)
            {
                int num = arr[index] * i + carry;
                t[index] = num % 10;
                num /= 10;
                carry = num;
            }
            while (carry)
            {
                t[index] = carry % 10;
                carry /= 10;
                index--;
            }

            for (int j = 0; j < length; j++)
            {
                arr[j] = t[j];
            }
        }

        for (int i = 0; i < length; i++)
        {
            if (arr[i] != -1)
            {
                for (int j = i; j < length; j++)
                {
                    printf("%d", arr[j]);
                }
                break;
            }
        }
    }
}