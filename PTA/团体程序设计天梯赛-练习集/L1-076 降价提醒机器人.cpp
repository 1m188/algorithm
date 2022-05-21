/**
 * @file L1-076 降价提醒机器人.cpp
 * @date 2022-05-21
 */

/*
小 T 想买一个玩具很久了，但价格有些高，他打算等便宜些再买。但天天盯着购物网站很麻烦，请你帮小 T 写一个降价提醒机器人，当玩具的当前价格比他设定的价格便宜时发出提醒。

输入格式：
输入第一行是两个正整数 N 和 M (1≤N≤100,0≤M≤1000)，表示有 N 条价格记录，小 T 设置的价格为 M。

接下来 N 行，每行有一个实数 P 
i
​
 （−1000.0<P 
i
​
 <1000.0），表示一条价格记录。

输出格式：
对每一条比设定价格 M 便宜的价格记录 P，在一行中输出 On Sale! P，其中 P 输出到小数点后 1 位。

输入样例：
4 99
98.0
97.0
100.2
98.9
输出样例：
On Sale! 98.0
On Sale! 97.0
On Sale! 98.9
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
using namespace std;

int main() {

    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    while (n--) {
        double p = 0;
        scanf("%lf", &p);

        if (p < m)
            printf("On Sale! %.1lf\n", p);
    }

    return 0;
}