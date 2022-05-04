/*
Description
　　小明对数的研究比较热爱，一谈到数，脑子里就涌现出好多数的问题，今天，小明想考考你对素数的认识。
　　问题是这样的：一个十进制数，如果是素数，而且它的各位数字和也是素数，则称之为“美素数”，如29，本身是素数，而且2+9 = 11也是素数，所以它是美素数。
　　给定一个区间，你能计算出这个区间内有多少个美素数吗？

Input
第一行输入一个正整数T，表示总共有T组数据(T <= 10000)。
接下来共T行，每行输入两个整数L，R(1<= L <= R <= size)，表示区间的左值和右值。

Output
对于每组数据，先输出Case数，然后输出区间内美素数的个数（包括端点值L,R）。
每组数据占一行，具体输出格式参见样例。

Sample Input
3
1 100
2 2
3 19

Sample Output
Case #1: 14
Case #2: 1
Case #3: 4
*/

#include "iostream"
#include "vector"

int Sum(int num) //求各位数字之和
{
    int n = 0;
    while (num)
    {
        n += num % 10;
        num /= 10;
    }
    return n;
}

int main() //AC!模拟+打表...
{
    const int size = 1000001;

    std::vector<int> prime(size, 1); //通过区间筛选的方法给出题目范围内所有素数
    prime[0] = prime[1] = 0;
    for (int i = 2; i < size; i++)
    {
        if (prime[i]) //如果这个数是素数才行动，不然这是一个已经标记过的合数，不必再浪费时间
        {
            for (int j = 2 * i; j < size; j += i) //所有素数的倍数都是合数，因此找到一个素数之后把所有相关的合数标记上
            {
                prime[j] = 0; //标记为合数
            }
        }
    }

    std::vector<int> beautifulPrimeNum(size, 0); //任意区间内美素数的个数
    for (int i = 2; i < size; i++)
    {
        if (prime[i] && prime[Sum(i)]) //如果这个数是美素数
        {
            beautifulPrimeNum[i] = beautifulPrimeNum[i - 1] + 1; //那么这个数对应的数组位置里的数要比前一个多一
        }
        else
        {
            beautifulPrimeNum[i] = beautifulPrimeNum[i - 1]; //不然相同
        }
    }

    int T = 0;
    std::cin >> T;
    std::vector<std::pair<int, int>> data(T, std::pair<int, int>{});
    for (int i = 0; i < T; i++)
    {
        std::cin >> data[i].first >> data[i].second; //处理输入
    }

    for (int i = 0; i < T; i++) //这里关键在于输出数量，由于前面给出了每个数字相对于1的区间内美素数个数，因此只要对应区间相减即可得到区间内的美素数个数
    {
        std::cout << "Case #" << i + 1 << ": " << beautifulPrimeNum[data[i].second] - beautifulPrimeNum[data[i].first - 1] << std::endl;
    }

    return 0;
}