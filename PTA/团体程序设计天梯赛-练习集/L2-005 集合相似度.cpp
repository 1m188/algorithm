/**
 * @file L2-005 集合相似度.cpp
 * @date 2022-05-22
 */

/*
给定两个整数集合，它们的相似度定义为：N 
c
​
 /N 
t
​
 ×100%。其中N 
c
​
 是两个集合都有的不相等整数的个数，N 
t
​
 是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。

输入格式：
输入第一行给出一个正整数N（≤50），是集合的个数。随后N行，每行对应一个集合。每个集合首先给出一个正整数M（≤10 
4
 ），是集合中元素的个数；然后跟M个[0,10 
9
 ]区间内的整数。

之后一行给出一个正整数K（≤2000），随后K行，每行对应一对需要计算相似度的集合的编号（集合从1到N编号）。数字间以空格分隔。

输出格式：
对每一对需要计算的集合，在一行中输出它们的相似度，为保留小数点后2位的百分比数字。

输入样例：
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
输出样例：
50.00%
33.33%
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 注意细节，用set做集合，之后手动求交集和并集 */

#include <cstdio>
#include <set>
#include <vector>
using namespace std;

vector<set<int>> vec; // 集合数组

/**
 * @brief 求取两个集合的相似度
 * @param x 集合1编号
 * @param y 集合2编号
 * @return double 一个比率（非百分数）
 */
double rate(int x, int y) {
    double nc = 0, nt = 0;

    auto it1 = vec[x].begin(), it2 = vec[y].begin();
    while (it1 != vec[x].end() && it2 != vec[y].end()) { // 交集
        if (*it1 == *it2)
            nc++, it1++, it2++;
        else if (*it1 > *it2)
            it2++;
        else
            it1++;
    }

    it1 = vec[x].begin(), it2 = vec[y].begin();
    while (it1 != vec[x].end() && it2 != vec[y].end()) { // 并集
        nt++;
        if (*it1 == *it2)
            it1++, it2++;
        else if (*it1 > *it2)
            it2++;
        else
            it1++;
    }
    while (it1 != vec[x].end())
        nt++, it1++;
    while (it2 != vec[y].end())
        nt++, it2++;

    return nc / nt;
}

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d", &n);

    vec.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int m = 0;
        scanf("%d", &m);
        while (m--) {
            int x = 0;
            scanf("%d", &x);
            vec[i].insert(x);
        }
    }

    int k = 0;
    scanf("%d", &k);
    while (k--) {
        int x = 0, y = 0;
        scanf("%d %d", &x, &y);
        double a = rate(x, y);
        printf("%.2lf%%\n", a * 100);
    }
}

int main() {
    input();
    return 0;
}