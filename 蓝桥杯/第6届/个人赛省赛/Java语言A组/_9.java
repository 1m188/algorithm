/*
垒骰子

赌圣atm晚年迷恋上了垒骰子，就是把骰子一个垒在另一个上边，不能歪歪扭扭，要垒成方柱体。
经过长期观察，atm 发现了稳定骰子的奥秘：有些数字的面贴着会互相排斥！
我们先来规范一下骰子：1 的对面是 4，2 的对面是 5，3 的对面是 6。
假设有 m 组互斥现象，每组中的那两个数字的面紧贴在一起，骰子就不能稳定的垒起来。 atm想计算一下有多少种不同的可能的垒骰子方式。
两种垒骰子方式相同，当且仅当这两种方式中对应高度的骰子的对应数字的朝向都相同。
由于方案数可能过多，请输出模 10^9 + 7 的结果。

不要小看了 atm 的骰子数量哦～

「输入格式」
第一行两个整数 n m
n表示骰子数目
接下来 m 行，每行两个整数 a b ，表示 a 和 b 不能紧贴在一起。

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
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。
*/

/*
 * 解题思路：
 * 骰子对面关系：1↔4, 2↔5, 3↔6。
 * 每枚骰子有 6 种朝上的面，每种有 4 种旋转方向。
 * 记 dp[i][f] = 前 i 枚骰子、最上一枚朝上面为 f 的方案数。
 * 初始：dp[1][f] = 4（首枚可任意旋转）。
 * 转移：若上一枚顶面 f 与当前骰子的底面 opp[g] 不冲突，
 *       则 dp[i+1][g] += dp[i][f] * 4。
 *
 * 构造 6×6 转移矩阵 M：M[g][f] = 4（不冲突）或 0（冲突）。
 * dp[n] = M^(n-1) × dp[1]，用矩阵快速幂 O(6³ log n)。
 */
import java.util.Scanner;

public class _9 {
    static final int MOD = 1000000007;

    static long[][] matMul(long[][] a, long[][] b) {
        int n = a.length;
        long[][] res = new long[n][n];
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                if (a[i][k] != 0)
                    for (int j = 0; j < n; j++)
                        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
        return res;
    }

    static long[][] matPow(long[][] base, int exp) {
        int n = base.length;
        long[][] res = new long[n][n];
        for (int i = 0; i < n; i++)
            res[i][i] = 1;
        while (exp > 0) {
            if ((exp & 1) == 1)
                res = matMul(res, base);
            base = matMul(base, base);
            exp >>= 1;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] opp = {0, 4, 5, 6, 1, 2, 3};

        // 初始化转移矩阵：所有转移默认允许（权重 4）
        long[][] trans = new long[6][6];
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                trans[j - 1][i - 1] = 4;

        // 标记冲突
        for (int k = 0; k < m; k++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            for (int i = 1; i <= 6; i++) {
                for (int j = 1; j <= 6; j++) {
                    int bottom = opp[j];
                    if ((i == a && bottom == b) || (i == b && bottom == a))
                        trans[j - 1][i - 1] = 0;
                }
            }
        }
        sc.close();

        // dp[n] = trans^(n-1) × dp[1]
        long[][] p = matPow(trans, n - 1);

        long ans = 0;
        for (int g = 0; g < 6; g++)
            for (int f = 0; f < 6; f++)
                ans = (ans + p[g][f] * 4) % MOD;

        System.out.println(ans);
    }
}
