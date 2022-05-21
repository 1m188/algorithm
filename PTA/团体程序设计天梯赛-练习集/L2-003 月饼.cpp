/**
 * @file L2-003 月饼.cpp
 * @date 2022-05-21
 */

/*
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：
每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。

输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50
代码长度限制
16 KB
时间限制
150 ms
内存限制
64 MB
*/

/* 从单位售价最高的开始卖，往后递推。

注意，题目里说库存和总售价都是“正数”，不是正整数，而是正数，所以得用double，
注意细节 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * @brief 月饼
 */
struct Mooncake {
    double inventory = 0;   // 总库存
    double total_price = 0; // 总售价
    double price_per = 0;   // 单位售价
};

int main() {

    int n = 0, d = 0;
    scanf("%d %d", &n, &d);

    vector<Mooncake> vec(n);

    for (int i = 0; i < n; i++) {
        scanf("%lf", &vec[i].inventory);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vec[i].total_price);
        vec[i].price_per = vec[i].total_price / vec[i].inventory;
    }

    // 按照单位售价从大往小排
    sort(vec.begin(), vec.end(), [](const Mooncake &e1, const Mooncake &e2) {
        return e1.price_per > e2.price_per;
    });

    double ans = 0;

    for (const Mooncake &e : vec) { // 从大往小挨个卖
        if (e.inventory < d) {
            ans += e.total_price;
            d -= e.inventory;
        } else {
            ans += e.price_per * d;
            break;
        }
    }

    printf("%.2lf", ans);

    return 0;
}