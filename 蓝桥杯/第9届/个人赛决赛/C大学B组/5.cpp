/*

标题：搭积木

小明对搭积木非常感兴趣。他的积木都是同样大小的正立方体。
在搭积木时，小明选取 m 块积木作为地基，将他们在桌子上一字排开，中间不留空隙，并称其为第0层。
随后，小明可以在上面摆放第1层，第2层，……，最多摆放至第n层。摆放积木必须遵循三条规则：

规则1：每块积木必须紧挨着放置在某一块积木的正上方，与其下一层的积木对齐；
规则2：同一层中的积木必须连续摆放，中间不能留有空隙；
规则3：小明不喜欢的位置不能放置积木。

其中，小明不喜欢的位置都被标在了图纸上。图纸共有n行，从下至上的每一行分别对应积木的第1层至第n层。每一行都有m个字符，字符可能是‘.’或‘X’，其中‘X’表示这个位置是小明不喜欢的。
现在，小明想要知道，共有多少种放置积木的方案。他找到了参加蓝桥杯的你来帮他计算这个答案。
由于这个答案可能很大，你只需要回答这个答案对1000000007(十亿零七)取模后的结果。
注意：地基上什么都不放，也算作是方案之一种。

【输入格式】
输入数据的第一行有两个正整数n和m，表示图纸的大小。
随后n行，每行有m个字符，用来描述图纸 。每个字符只可能是‘.’或‘X’。

【输出格式】
输出一个整数，表示答案对1000000007取模后的结果。

【样例输入1】
2 3
..X
.X.

【样例输出1】
4

【样例说明1】
成功的摆放有（其中O表示放置积木）：
(1)
..X
.X.
(2)
..X
OX.
(3)
O.X
OX.
(4)
..X
.XO

【样例输入2】
3 3
..X
.X.
...

【样例输出2】
16

【数据规模约定】
对于10%的数据，n=1，m<=30；
对于40%的数据，n<=10，m<=30；
对于100%的数据，n<=100，m<=100。


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。



*/

#include <cstring>
#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int MAXM = 105;

int n, m;
int dp[MAXM][MAXM];  // dp[l][r]
int pre[MAXM][MAXM]; // 二维前缀和
char row[MAXM];      // 当前行的字符串

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> (row + 1); // 1-indexed

        // 计算二维前缀和 pre[l][r] = sum_{l'<=l, r'<=r} dp[l'][r']
        for (int l = 1; l <= m; ++l) {
            for (int r = 1; r <= m; ++r) {
                long long v = (long long)dp[l][r] + pre[l - 1][r] +
                              pre[l][r - 1] - pre[l - 1][r - 1];
                pre[l][r] = (v % MOD + MOD) % MOD;
            }
        }

        int new_dp[MAXM][MAXM] = {};

        for (int l = 1; l <= m; ++l) {
            if (row[l] == 'X') continue;
            for (int r = l; r <= m; ++r) {
                if (row[r] == 'X') break; // 包含 'X'，不能继续扩展
                // sum_{[l',r'] ⊆ [l,r]} dp[l'][r'] = pre[r][r] - pre[l-1][r]
                long long sub = (long long)pre[r][r] - pre[l - 1][r];
                sub = (sub % MOD + MOD) % MOD;
                // +1: 从本层首次放置积木（前面所有层全空）
                new_dp[l][r] = (int)((1 + sub) % MOD);
            }
        }

        memcpy(dp, new_dp, sizeof(dp));
    }

    // 统计答案：全空 + 所有以第 n 层为非空层结尾的链
    long long ans = 1;
    for (int l = 1; l <= m; ++l)
        for (int r = l; r <= m; ++r)
            ans = (ans + dp[l][r]) % MOD;

    cout << ans << endl;
    return 0;
}
