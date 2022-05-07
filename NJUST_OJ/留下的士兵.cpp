/*
Description
有N个士兵站成一行，从右到左，从1到N依次编号，他们还得到一个整数M。然后这些士兵从右手边的士兵开始报数。
报的数为M的倍数的士兵留在队列里，其他的士兵需要离开队列。他们重复进行这项操作直到队列中的人数小于M。
举例来说，如果有10个士兵，并且M=3。第一次操作后，编号为3，6，9的士兵留在队列中。第二次操作后，编号为9的士兵留在队列中。
由于队列中的士兵的数量小于M，那么编号为9的士兵就是最终留在队列里面的士兵。
现在我们想知道哪些士兵将会最终留在队列中，你能告诉我们吗?

Input
输入包含几个测试数据。每个测试数据只占单独的一行，包含两个整数n和m(3 <= n <= 10^9, 2 <= m <= n)。
当n=0 并且m=0的时候标志输入结束。

Output
对于每组测试数据，输出两行。第一行包含一个整数X，表示最终留下的士兵的数量。
第二行包含X个整数，表示最终留下的士兵的编号。你应该把他们按照升序输出。

Sample Input
10 3
8 3
0 0

Sample Output
1
9
2
3 6
*/

//这道题的特点在于不像约瑟夫环一样是一个环，而是一条直线，每次从头开始报数到末尾结束，要注意这一点
#include "cstdio"
#include "vector"
int main() //超时了
{
    int n = 0, m = 0;
    std::vector<std::pair<int, int>> data{};
    while (scanf("%d%d", &n, &m) && n && m)
    {
        data.push_back(std::pair<int, int>(n, m));
    }

    for (std::vector<std::pair<int, int>>::iterator it = data.begin(); it != data.end(); it++)
    {
        int n = (*it).first, m = (*it).second, leaveNum = 1;
        while (n >= m) //直到n中的数小于m，即剩下来的士兵数目小于m
        {
            int comparen = n;
            for (int i = 1; i <= comparen; i++)
            {
                if (i % m) //对每个数把所有非m的倍数的数去掉
                {
                    n--;
                }
            }
            leaveNum *= m; //每去掉一轮数，剩下来的编号就从乘以m的这个数开始
        }
        printf("%d\n", n);
        for (int i = 1; i <= n; i++)
        {
            printf("%d", i * leaveNum);
            if (i != n)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}