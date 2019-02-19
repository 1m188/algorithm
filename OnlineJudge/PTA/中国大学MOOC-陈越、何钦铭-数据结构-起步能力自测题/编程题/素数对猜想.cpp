/*
自测-2 素数对猜想 （20 分）
让我们定义d
​n
​​ 为：d
​n
​​ =p
​n+1
​​ −p
​n
​​ ，其中p
​i
​​ 是第i个素数。显然有d
​1
​​ =1，且对于n>1有d
​n
​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10
​5
​​ )，请计算不超过N的满足猜想的素数对的个数。

输入格式:

输入在一行给出正整数N。

输出格式:

在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:

20
输出样例:

4
*/

#include "iostream"
#include "cmath"

#define MAX 100000

//标记是否是素数，这样可以避免重复计算，因为i和i+2
bool table[MAX]{false};

bool isPrime(int num)
{
    //这里如果不能被2整除那么所有的偶数都不必判断了
    if (num % 2 == 0)
    {
        return false;
    }
    else
    {
        //注意这里的部分，求余数的被除数只需要到根号下的数字即可，后面的数字就都是反过来的了，比如2*3=6和3*2=6
        int aim = sqrt(num);
        for (int i = 3; i <= aim; i += 2)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    table[2] = true;
    table[3] = true;

    int N = 0;
    std::cin >> N;

    int num = 0;
    for (int i = 5; i <= N; i++)
    {
        if (isPrime(i))
        {
            table[i] = true;
        }
        if (table[i - 2] && table[i])
        {
            num++;
        }
    }

    std::cout << num;

    return 0;
}