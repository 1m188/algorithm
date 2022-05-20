/**
 * @file 7-8 521序列.cpp
 * @date 2022-05-20
 */

/*
521.jpg
所谓“521 序列”是指将一个原始整数序列 S 中的每个数字分别乘以 5、2、1 后形成的序列，
例如 S= { 5, 2, 1 } 时，其对应的 521 序列就是 { 25, 10, 5, 10, 4, 2, 5, 2, 1 } —— 
这里我们不要求这个序列一定具有某种顺序，即 521 序列中元素的顺序是可以打乱的。给定 S 后，
计算其对应的 521 序列是很简单的。但给定一个 521 序列，恢复其对应的原始序列 S 就略微复杂一点了。
本题就请你恢复任意给定的 521 序列的原始序列。

输入格式：
输入第一行给出正整数 N（<10^5），为 521 序列的长度。随后一行给出 N 个整数，即给定的 521 序列。
所有数字的绝对值不超过 10^5，以空格分隔。

输出格式：
在一行中按照非递增序输出 521 序列对应的原始序列。数字间以 1 个空格分隔，行首尾不得有多余空格。

题目保证原始序列是存在的。

输入样例：
12
1 -5 10 -1 2 4 5 -2 5 25 10 2
输出样例：
5 2 1 -1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 虽然未来得及验证，但还是写了一下，说一下思路：

对于目标集合，由每个数乘以5 2 1 组成，求能被1整除的数、
能被2整除的数和能被5整除的数的交集

因题目集关闭未验证 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {

    int n = 0;
    scanf("%d", &n);

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());

    vector<int> set2;
    for (const int &i : vec)
        if (i % 2 == 0)
            set2.push_back(i / 2);

    vector<int> set3;
    for (const int &i : vec)
        if (i % 5 == 0)
            set3.push_back(i / 5);

    vec.resize(set2.size() + set3.size());
    auto it = set_intersection(set2.begin(), set2.end(), set3.begin(), set3.end(), vec.begin());
    vec.erase(it, vec.end());
    it = unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());

    printf("%d", vec.back());
    for (int i = vec.size() - 2; i >= 0; i--)
        printf(" %d", vec[i]);

    return 0;
}