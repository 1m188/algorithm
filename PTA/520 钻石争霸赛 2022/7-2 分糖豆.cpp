/**
 * @file 7-2 分糖豆.cpp
 * @date 2022-05-20
 */

/*
mm.png
N 个宝宝分 M 颗 m&m 糖豆，如果每人分 K 个，够不够分呀？

输入格式：
输入在一行中给出 3 个正整数，分别是 N（不超过 100），是宝宝们的总人数；M（不超过 1000），是糖豆的总颗数；K（不超过 10），是要分给每个宝宝的糖豆数。

输出格式：
如果每人 K 个正好能够分完，输出 zheng hao mei ren K!；如果分完了还剩 X 颗糖豆，则输出 hai sheng X!；如果不够分的，还差 X 颗糖豆，则输出 hai cha X!。

输入样例 1：
10 50 5
输出样例 1：
zheng hao mei ren 5!
输入样例 2：
12 30 2
输出样例 2：
hai sheng 6!
输入样例 3：
15 40 3
输出样例 3：
hai cha 5!
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include <cstdio>
using namespace std;

int main() {

    int n = 0, m = 0, k = 0;
    scanf("%d %d %d", &n, &m, &k);

    if (n * k == m)
        printf("zheng hao mei ren %d!", k);
    else if (n * k < m)
        printf("hai sheng %d!", m - n * k);
    else
        printf("hai cha %d!", n * k - m);

    return 0;
}