/**
 * @file 7-40 奥运排行榜.cpp
 * @date 2022-05-14
 */

/*
每年奥运会各大媒体都会公布一个排行榜，但是细心的读者发现，不同国家的排行榜略有不同。
比如中国金牌总数列第一的时候，中国媒体就公布“金牌榜”；
而美国的奖牌总数第一，于是美国媒体就公布“奖牌榜”。
如果人口少的国家公布一个“国民人均奖牌榜”，说不定非洲的国家会成为榜魁…… 
现在就请你写一个程序，对每个前来咨询的国家按照对其最有利的方式计算它的排名。

输入格式:
输入的第一行给出两个正整数N和M（≤224，因为世界上共有224个国家和地区），
分别是参与排名的国家和地区的总个数、以及前来咨询的国家的个数。
为简单起见，我们把国家从0 ~ N−1编号。
之后有N行输入，第i行给出编号为i−1的国家的金牌数、奖牌数、国民人口数（单位为百万），
数字均为[0,1000]区间内的整数，用空格分隔。最后面一行给出M个前来咨询的国家的编号，用空格分隔。

输出格式:
在一行里顺序输出前来咨询的国家的排名:计算方式编号。其排名按照对该国家最有利的方式计算；
计算方式编号为：金牌榜=1，奖牌榜=2，国民人均金牌榜=3，国民人均奖牌榜=4。
输出间以空格分隔，输出结尾不能有多余空格。

若某国在不同排名方式下有相同名次，则输出编号最小的计算方式。

输入样例:
4 4
51 100 1000
36 110 300
6 14 32
5 18 40
0 1 2 3

输出样例:
1:1 1:2 1:3 1:4

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 不是很难的题目，但却让人容易出错。

最开始用的是同意vector来做，连带着将金牌和奖牌数这种本来应该是int的
东西也变成了double进行比较，本以为应该没有问题的，在本机上有限的
测试也没发现问题，但在oj上就是过不了，后来参考了网上的简易解法，
把int和double的部分都分开了，然后过了，但这种写法看上去很笨。

顺便一提，这一题里面double的比较不需要fabs，直接比较即可 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> rank1,    // 第一种计算方式排名
    rank2;                       // 第二种排名
vector<pair<int, double>> rank3, // 第三种排名
    rank4;                       // 第四种排名

vector<int> country;        // 待咨询的国家
vector<pair<int, int>> ans; // 最终结果

/**
 * @brief 输入初始化
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        double c = 0;
        cin >> a >> b >> c;
        rank1.push_back({i, a});
        rank2.push_back({i, b});
        rank3.push_back({i, a / c});
        rank4.push_back({i, b / c});
    }
    sort(rank1.begin(), rank1.end(), [](const auto &e1, const auto &e2) { return e1.second > e2.second; });
    sort(rank2.begin(), rank2.end(), [](const auto &e1, const auto &e2) { return e1.second > e2.second; });
    sort(rank3.begin(), rank3.end(), [](const auto &e1, const auto &e2) { return e1.second > e2.second; });
    sort(rank4.begin(), rank4.end(), [](const auto &e1, const auto &e2) { return e1.second > e2.second; });

    country.resize(m);
    for (int i = 0; i < m; i++)
        cin >> country[i];
}

/**
 * @brief 计算找出排名
 */
void calc() {

    for (const int &ctry : country) {
        int rk = 225, way = 0;

        int trk = 0;

        while (rank1[trk].first != ctry)
            trk++;
        while (trk > 0 && rank1[trk - 1].second <= rank1[trk].second) // 相同值应为相同排名
            trk--;
        trk++; // 排名为索引+1
        if (trk < rk) {
            rk = trk;
            way = 1;
        }

        trk = 0;
        while (rank2[trk].first != ctry)
            trk++;
        while (trk > 0 && rank2[trk - 1].second <= rank2[trk].second)
            trk--;
        trk++;
        if (trk < rk) {
            rk = trk;
            way = 2;
        }

        trk = 0;
        while (rank3[trk].first != ctry)
            trk++;
        while (trk > 0 && rank3[trk - 1].second <= rank3[trk].second)
            trk--;
        trk++;
        if (trk < rk) {
            rk = trk;
            way = 3;
        }

        trk = 0;
        while (rank4[trk].first != ctry)
            trk++;
        while (trk > 0 && rank4[trk - 1].second <= rank4[trk].second)
            trk--;
        trk++;
        if (trk < rk) {
            rk = trk;
            way = 4;
        }

        ans.push_back({rk, way});
    }
}

/**
 * @brief 格式化输出
 */
void print() {
    cout << ans[0].first << ':' << ans[0].second;
    for (int i = 1; i < ans.size(); i++)
        cout << ' ' << ans[i].first << ':' << ans[i].second;
}

int main() {
    input();
    calc();
    print();
    return 0;
}