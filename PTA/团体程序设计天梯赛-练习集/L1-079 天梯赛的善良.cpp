/**
 * @file L1-079 天梯赛的善良.cpp
 * @date 2022-05-21
 */

/*
天梯赛是个善良的比赛。善良的命题组希望将题目难度控制在一个范围内，使得每个参赛的学生都有能做出来的题目，并且最厉害的学生也要非常努力才有可能得到高分。

于是命题组首先将编程能力划分成了 10 
6
  个等级（太疯狂了，这是假的），然后调查了每个参赛学生的编程能力。现在请你写个程序找出所有参赛学生的最小和最大能力值，给命题组作为出题的参考。

输入格式：
输入在第一行中给出一个正整数 N（≤2×10 
4
 ），即参赛学生的总数。随后一行给出 N 个不超过 10 
6
  的正整数，是参赛学生的能力值。

输出格式：
第一行输出所有参赛学生的最小能力值，以及具有这个能力值的学生人数。第二行输出所有参赛学生的最大能力值，以及具有这个能力值的学生人数。同行数字间以 1 个空格分隔，行首尾不得有多余空格。

输入样例：
10
86 75 233 888 666 75 886 888 75 666
输出样例：
75 3
888 2
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB
*/

#include <cstdio>
using namespace std;

int main() {

    int n = 0;
    scanf("%d", &n);

    int minval = 1e6 + 1, minnum = 0, maxval = 0, maxnum = 0;
    while (n--) {
        int a = 0;
        scanf("%d", &a);

        if (a < minval) {
            minval = a;
            minnum = 1;
        } else if (a == minval)
            minnum++;

        if (a > maxval) {
            maxval = a;
            maxnum = 1;
        } else if (a == maxval)
            maxnum++;
    }

    printf("%d %d\n%d %d", minval, minnum, maxval, maxnum);

    return 0;
}