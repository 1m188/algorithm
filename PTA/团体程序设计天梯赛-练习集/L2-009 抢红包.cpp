/**
 * @file L2-009 抢红包.cpp
 * @date 2022-05-24
 */

/*
没有人没抢过红包吧…… 这里给出N个人之间互相发红包、抢红包的记录，请你统计一下他们抢红包的收获。

输入格式：
输入第一行给出一个正整数N（≤10 
4
 ），即参与发红包和抢红包的总人数，则这些人从1到N编号。随后N行，第i行给出编号为i的人发红包的记录，格式如下：

KN 
1
​
 P 
1
​
 ⋯N 
K
​
 P 
K
​
 

其中K（0≤K≤20）是发出去的红包个数，N 
i
​
 是抢到红包的人的编号，P 
i
​
 （>0）是其抢到的红包金额（以分为单位）。注意：对于同一个人发出的红包，每人最多只能抢1次，不能重复抢。

输出格式：
按照收入金额从高到低的递减顺序输出每个人的编号和收入金额（以元为单位，输出小数点后2位）。每个人的信息占一行，两数字间有1个空格。如果收入金额有并列，则按抢到红包的个数递减输出；如果还有并列，则按个人编号递增输出。

输入样例：
10
3 2 22 10 58 8 125
5 1 345 3 211 5 233 7 13 8 101
1 7 8800
2 1 1000 2 1000
2 4 250 10 320
6 5 11 9 22 8 33 7 44 10 55 4 2
1 3 8800
2 1 23 2 123
1 8 250
4 2 121 4 516 7 112 9 10
输出样例：
1 11.63
2 3.63
8 3.63
3 2.11
7 1.69
6 -1.67
9 -2.18
10 -3.26
5 -3.26
4 -12.32
代码长度限制
16 KB
时间限制
300 ms
内存限制
64 MB
*/

/* 模拟题，利用hash存储编号和其红包个数和金额数的映射，注意细节 */

#include <algorithm>
#include <cstdio>
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

/**
 * @brief 红包
 */
struct Rede {
    int num = 0;   // 总红包个数
    int money = 0; // 总金额
};

map<int, Rede> mp; // 用来存储  编号-红包  映射

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d", &n);

    // 用来标识这个人是否已经收过这个红包
    unordered_set<int> uset;

    for (int i = 1; i <= n; i++) {

        int k = 0;
        scanf("%d", &k);

        int submoney = 0; // 当前编号的人总共要发出去的金额
        while (k--) {
            int a = 0, b = 0;
            scanf("%d %d", &a, &b);
            if (uset.find(a) != uset.end()) // 如果这个人已经受过i编号人发过的红包了
                continue;
            uset.insert(a);
            mp[a].money += b;
            mp[a].num++;
            submoney += b;
        }

        mp[i].money -= submoney; // 发出去金额
        uset.clear();            // 下一次循环新的i，重新开始
    }
}

/**
 * @brief 计算并输出
 */
void calc() {
    vector<pair<int, Rede>> vec(mp.begin(), mp.end());

    // 按要求排序便于输出
    sort(vec.begin(), vec.end(), [](const pair<int, Rede> &e1, const pair<int, Rede> &e2) {
        if (e1.second.money != e2.second.money)
            return e1.second.money > e2.second.money;
        else if (e1.second.num != e2.second.num)
            return e1.second.num > e2.second.num;
        else
            return e1.first < e2.first;
    });

    // 按要求输出，注意输入的时候钱是分为单位，但是输出的时候是元，要/100
    for (const auto &e : vec) {
        printf("%d %.2lf\n", e.first, double(e.second.money) / 100);
    }
}

int main() {
    input();
    calc();
    return 0;
}