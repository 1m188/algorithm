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

#include <cstdio>
#include <cstring>

const long long MOD = 1000000007LL;

// 骰子对面映射：opp[i] = 与i对面的数字
const int OPP[7] = {0, 4, 5, 6, 1, 2, 3};

// 6×6 矩阵乘法：C = A × B (mod MOD)
void mat_mul(const long long A[6][6], const long long B[6][6], long long C[6][6]) {
    long long tmp[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < 6; k++) {
                tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            C[i][j] = tmp[i][j];
}

// 6×6 矩阵快速幂：result = base^exp
void mat_pow(long long base[6][6], long long exp, long long result[6][6]) {
    // result 初始化为单位矩阵
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            result[i][j] = (i == j);

    long long tmp[6][6];
    while (exp > 0) {
        if (exp & 1) {
            mat_mul(result, base, tmp);
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    result[i][j] = tmp[i][j];
        }
        mat_mul(base, base, tmp);
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                base[i][j] = tmp[i][j];
        exp >>= 1;
    }
}

// 快速幂取模：base^exp % MOD
long long pow_mod(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    long long n;
    int m;
    scanf("%lld %d", &n, &m);

    // 构建6×6状态转移矩阵
    // T[i][j]=1 表示下面骰子顶面为i+1时，上面骰子顶面可以为j+1
    // 初始全1，再根据互斥对清零
    long long T[6][6];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            T[i][j] = 1;

    for (int k = 0; k < m; k++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // a与b不能紧贴，即下面顶面=a时上面底面不能=b
        // 上面底面=b意味着上面顶面=opp[b]
        T[a - 1][OPP[b] - 1] = 0;
        T[b - 1][OPP[a] - 1] = 0;
    }

    // 计算 T^(n-1)
    long long T_pow[6][6];
    if (n == 1) {
        // n=1时T^0=I，无需计算
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                T_pow[i][j] = (i == j);
    } else {
        long long T_copy[6][6];
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                T_copy[i][j] = T[i][j];
        mat_pow(T_copy, n - 1, T_pow);
    }

    // 初始向量 v = [1,1,1,1,1,1]^T，即第一个骰子顶面可以任意选择
    long long vec[6] = {1, 1, 1, 1, 1, 1};
    long long res_vec[6];
    for (int i = 0; i < 6; i++) {
        res_vec[i] = 0;
        for (int j = 0; j < 6; j++) {
            res_vec[i] = (res_vec[i] + T_pow[i][j] * vec[j]) % MOD;
        }
    }

    // 总面方案数 = sum(res_vec)
    long long face_ways = 0;
    for (int i = 0; i < 6; i++)
        face_ways = (face_ways + res_vec[i]) % MOD;

    // 每颗骰子有4种旋转方式，n颗即4^n
    long long rot_ways = pow_mod(4, n);

    long long ans = face_ways * rot_ways % MOD;
    printf("%lld\n", ans);

    return 0;
}
