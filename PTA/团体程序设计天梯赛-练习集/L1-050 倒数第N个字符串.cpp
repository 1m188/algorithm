/**
 * @file L1-050 倒数第N个字符串.cpp
 * @date 2022-05-19
 */

/*
给定一个完全由小写英文字母组成的字符串等差递增序列，该序列中的每个字符串的长度固定为 L，
从 L 个 a 开始，以 1 为步长递增。例如当 L 为 3 时，序列为 
{ aaa, aab, aac, ..., aaz, aba, abb, ..., abz, ..., zzz }。
这个序列的倒数第27个字符串就是 zyz。对于任意给定的 L，本题要求你给出对应序列倒数第 N 个字符串。

输入格式：
输入在一行中给出两个正整数 L（2 ≤ L ≤ 6）和 N（≤10^5）。

输出格式：
在一行中输出对应序列倒数第 N 个字符串。题目保证这个字符串是存在的。

输入样例：
3 7417

输出样例：
pat

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 其实就是26进制从最后一个往回走就是了，每一位都走他能走的最大值，直到个位 */

#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

int main() {

    int l = 0, n = 0;
    scanf("%d %d", &l, &n);
    n--; // 不太清楚这里为什么要-1，但-1就对了，大概是从1开始和从0开始的区别

    string str(l, 'z');

    int p = str.size() - 1;
    for (char &c : str) { // 对每个字符都往回滚到它能滚回的最大字符数
        int x = pow(26, p);
        c -= n / x;
        n %= x;
        p--;
    }

    printf("%s", str.c_str());

    return 0;
}