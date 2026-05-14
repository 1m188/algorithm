/*

标题：对局匹配


小明喜欢在一个围棋网站上找别人在线对弈。这个网站上所有注册用户都有一个积分，代表他的围棋水平。

小明发现网站的自动对局系统在匹配对手时，只会将积分差恰好是K的两名用户匹配在一起。如果两人分差小于或大于K，系统都不会将他们匹配。

现在小明知道这个网站总共有N名用户，以及他们的积分分别是A1, A2, ... AN。

小明想了解最多可能有多少名用户同时在线寻找对手，但是系统却一场对局都匹配不起来(任意两名用户积分差不等于K)？

输入
----
第一行包含两个个整数N和K。
第二行包含N个整数A1, A2, ... AN。

对于30%的数据，1 <= N <= 10
对于100%的数据，1 <= N <= 100000, 0 <= Ai <= 100000, 0 <= K <= 100000

输出
----
一个整数，代表答案。

样例输入：
10 0
1 4 2 8 5 7 1 4 2 8

样例输出：
6

再比如，
样例输入：
10 1
2 1 1 1 1 4 4 3 4 4

样例输出：
8

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXA = 100001;
int cnt[MAXA];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }

    int ans = 0;

    if (k == 0) {
        // K=0时，相同积分的用户会被匹配，每个积分值只能保留一个人
        for (int i = 0; i < MAXA; i++) {
            if (cnt[i] > 0) ans++;
        }
    } else {
        // K>0时，按积分模K的余数分组
        // 同一组内的积分形如 r, r+K, r+2K, ...
        // 相邻的两个积分差恰好为K，不能同时选
        // 对每组做DP：dp[i] = max(dp[i-1], dp[i-2] + cnt[r+i*K])
        for (int r = 0; r < k; r++) {
            int prev2 = 0; // dp[i-2]
            int prev1 = 0; // dp[i-1]
            for (int v = r; v < MAXA; v += k) {
                int cur = max(prev1, prev2 + cnt[v]);
                prev2 = prev1;
                prev1 = cur;
            }
            ans += prev1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
