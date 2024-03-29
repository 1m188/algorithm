/**
 * @file L1-077 大笨钟的心情.cpp
 * @date 2022-05-21
 */

/*
心情.jpg
有网友问：未来还会有更多大笨钟题吗？笨钟回复说：看心情……

本题就请你替大笨钟写一个程序，根据心情自动输出回答。

输入格式：
输入在一行中给出 24 个 [0, 100] 区间内的整数，依次代表大笨钟在一天 24 小时中，每个小时的心情指数。

随后若干行，每行给出一个 [0, 23] 之间的整数，代表网友询问笨钟这个问题的时间点。当出现非法的时间点时，表示输入结束，这个非法输入不要处理。题目保证至少有 1 次询问。

输出格式：
对每一次提问，如果当时笨钟的心情指数大于 50，就在一行中输出 心情指数 Yes，否则输出 心情指数 No。

输入样例：
80 75 60 50 20 20 20 20 55 62 66 51 42 33 47 58 67 52 41 20 35 49 50 63
17
7
3
15
-1
输出样例：
52 Yes
20 No
50 No
58 Yes
代码长度限制
16 KB
Java (javac)
时间限制
600 ms
内存限制
64 MB
其他编译器
时间限制
400 ms
内存限制
64 MB
*/

#include <cstdio>
#include <vector>
using namespace std;

vector<int> xinqing(24);

int main() {

    for (int i = 0; i < 24; i++)
        scanf("%d", &xinqing[i]);

    for (int t; scanf("%d", &t);) {
        if (t < 0 || t > 23)
            break;

        printf("%d %s\n", xinqing[t], xinqing[t] > 50 ? "Yes" : "No");
    }

    return 0;
}