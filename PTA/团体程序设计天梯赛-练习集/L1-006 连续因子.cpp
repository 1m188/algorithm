/**
 * @file L1-006 连续因子.cpp
 * @date 2022-05-17
 */

/*
一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，
其中 5、6、7 就是 3 个连续的数字。给定任一正整数 N，要求编写程序求出最长连续因子的个数，
并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数 N（1<N<2^31）。

输出格式：
首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1*因子2*……*因子k 
的格式输出最小的连续因子序列，其中因子按递增顺序输出，1 不算在内。

输入样例：
630

输出样例：
3
5*6*7

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 这个故事告诉我们，不要自作聪明的优化，至少在把问题想清楚前，不要擅自优化，会变得不幸。 */

/* 用的双循环，第一重循环找每个连续因子的开头，第二个循环确定连续因子最长的数目，及所有
连续因子的内容，需要注意的一点是，对于某个数n而言，当它有一个2的因子并且之后有一个3的因子，
但是之后发现没有4的因子了，此时下一次开始不能直接从4开始，而是还得从3开始，因为n除了2和3
之后不一定还有4的因子，但是除了3之后说不定就会有4的因子了，注意。不过或许可以把所有除了
之后的内容记录下来做优化查询，不过这里没用 */

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N;           // 数
vector<int> ans; // 最终结果

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
}

/**
 * @brief 计算最长的连续因子
 */
void calc() {

    // 第一重循环，找起点
    for (int i = 2; i <= sqrt(N); i++) {

        // 如果能够整除则确定一个起点
        if (N % i != 0)
            continue;

        vector<int> tmp(1, i);
        int num = N / i;
        while (num % (tmp.back() + 1) == 0) { // 第二重循环找连续因子的内容
            num /= tmp.back() + 1;
            tmp.push_back(tmp.back() + 1);
        }

        // 判断最长
        // 因为这里的因子是从小往大走的，所以只有严格大于的时候才会更新
        if (tmp.size() > ans.size())
            ans = tmp;
    }
}

/**
 * @brief 输出
 */
void print() {
    if (!ans.size()) // 这里要注意，虽然1不算在内，但是N本身是被算在内的，找不到因子的时候就输出N，至少有一个
        ans.push_back(N);

    cout << ans.size() << '\n';

    cout << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << '*' << ans[i];
}

int main() {
    input();
    calc();
    print();
    return 0;
}