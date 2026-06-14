/*

垒骰子

赌圣atm晚年迷恋上了垒骰子，就是把骰子一个垒在另一个上边，不能歪歪扭扭，要垒成方柱体。
经过长期观察，atm 发现了稳定骰子的奥秘：有些数字的面贴着会互相排斥！
我们先来规范一下骰子：1 的对面是 4，2 的对面是 5，3 的对面是 6。
假设有 m 组互斥现象，每组中的那两个数字的面紧贴在一起，骰子就不能稳定的垒起来。
atm想计算一下有多少种不同的可能的垒骰子方式。
两种垒骰子方式相同，当且仅当这两种方式中对应高度的骰子的对应数字的朝向都相同。
由于方案数可能过多，请输出模 10^9 + 7 的结果。

不要小看了 atm 的骰子数量哦～

「输入格式」
第一行两个整数 n m
n表示骰子数目
接下来 m 行，每行两个整数 a b ，表示 a 和 b 数字不能紧贴在一起。

「输出格式」
一行一个数，表示答案模 10^9 + 7 的结果。

「样例输入」
2 1
1 2

「样例输出」
544

「数据范围」
对于 30% 的数据：n <= 5
对于 60% 的数据：n <= 100
对于 100% 的数据：0 < n <= 10^9, m <= 36


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/

/*
 * 解题思路：
 * 骰子对面关系：1↔4, 2↔5, 3↔6。
 * 每枚骰子有 6 种朝上的面，每种对应 4 种旋转。
 * 记 dp[i][f] = 前 i 枚骰子、最上一枚朝上面为 f 的方案数。
 * 初始：dp[1][f] = 4（首枚可任意旋转）。
 * 转移：若上一枚顶面 f 与当前骰子的底面 opp[g] 不冲突，
 *       则 dp[i+1][g] += dp[i][f] * 4。
 *
 * 构造 6×6 转移矩阵 M：M[g][f] = 4（不冲突）或 0（冲突）。
 * dp[n] = M^(n-1) × dp[1]，用矩阵快速幂 O(6³ log n)。
 */
#include <cstring>
#include <iostream>

const int MOD = 1000000007;
typedef long long ll;

struct Matrix {
    ll a[6][6];
    Matrix() { std::memset(a, 0, sizeof(a)); }

    Matrix operator*(const Matrix &o) const {
        Matrix res;
        for (int i = 0; i < 6; i++)
            for (int k = 0; k < 6; k++)
                if (a[i][k])
                    for (int j = 0; j < 6; j++)
                        res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
        return res;
    }
};

// 矩阵快速幂
Matrix matPow(Matrix base, int exp) {
    Matrix res;
    for (int i = 0; i < 6; i++)
        res.a[i][i] = 1;
    while (exp) {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    // 对面关系
    int opp[7] = {0, 4, 5, 6, 1, 2, 3};

    // 初始化转移矩阵：所有转移默认允许（权重 4）
    Matrix trans;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            trans.a[j - 1][i - 1] = 4;

    // 标记冲突：上一枚顶面 i 与当前骰子底面 opp[j] 冲突 → 禁止转移
    for (int k = 0; k < m; k++) {
        int a, b;
        std::cin >> a >> b;
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                int bottom = opp[j]; // 当前骰子的底面（与上一枚顶面接触）
                if ((i == a && bottom == b) || (i == b && bottom == a))
                    trans.a[j - 1][i - 1] = 0;
            }
        }
    }

    // dp[n] = trans^(n-1) × dp[1]
    Matrix p = matPow(trans, n - 1);

    ll ans = 0;
    for (int g = 0; g < 6; g++)                // 枚举最上一枚的朝上面
        for (int f = 0; f < 6; f++)            // 枚举第一枚的朝上面
            ans = (ans + p.a[g][f] * 4) % MOD; // 首枚 4 种旋转

    std::cout << ans << std::endl;
    return 0;
}
