/*

标题：堆的计数

我们知道包含N个元素的堆可以看成是一棵包含N个节点的完全二叉树。  
每个节点有一个权值。对于小根堆来说，父节点的权值一定小于其子节点的权值。  

假设N个节点的权值分别是1~N，你能求出一共有多少种不同的小根堆吗？  

例如对于N=4有如下3种：

    1
   / \
  2   3
 /
4

    1
   / \
  3   2
 /
4

    1
   / \
  2   4
 /
3

由于数量可能超过整型范围，你只需要输出结果除以1000000009的余数。  


【输入格式】
一个整数N。  
对于40%的数据，1 <= N <= 1000  
对于70%的数据，1 <= N <= 10000  
对于100%的数据，1 <= N <= 100000

【输出格式】
一个整数表示答案。  

【输入样例】
4  

【输出样例】
3


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.*;

public class _10 {

    /**
     * 模数，取 1000000009（10⁹+9，质数），用于费马小定理求逆元。
     */
    static final int MOD = 1000000009;

    /**
     * 堆的计数
     *
     * 核心思路：
     * 1. 包含 N 个元素的完全二叉树的结构是确定的。小根堆要求根为最小值，
     * 因此根节点必为 1。
     * 2. 设左子树包含 L 个节点，则右子树包含 R = N - 1 - L 个节点。
     * 从剩余的 N-1 个权值中选出 L 个放入左子树，其余放入右子树。
     * f(N) = C(N-1, L) × f(L) × f(R)
     * 3. 利用动态规划自底向上计算 f(1) 到 f(N)。
     * 4. 组合数通过预处理阶乘与阶乘逆元在 O(1) 时间内计算。
     *
     * 完全二叉树左子树节点数 L 的计算：
     * - 设树高 h = ⌊log₂(N)⌋（根在第 0 层）。
     * - 第 0 至 h-1 层为满层，共 2^h - 1 个节点。
     * - 第 h 层（最后一层）有 last = N - (2^h - 1) 个节点。
     * - 左子树中满层节点数为 2^(h-1) - 1。
     * - 左子树在第 h 层最多可以容纳 2^(h-1) 个节点。
     * - 因此 L = 2^(h-1) - 1 + min(2^(h-1), last)
     *
     * 时间复杂度：O(N)，预计算阶乘与 DP 均为线性扫描。
     * 空间复杂度：O(N)，存储阶乘、逆元和 DP 结果。
     */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();

        /*
         * fact[i] 存储 i! mod MOD
         * invFact[i] 存储 (i!)⁻¹ mod MOD
         * f[i] 存储当节点数为 i 时的不同小根堆数量（模 MOD）
         */
        long[] fact = new long[N + 1];
        long[] invFact = new long[N + 1];
        long[] f = new long[N + 1];

        /* 预计算阶乘 */
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        /*
         * 计算阶乘的逆元。
         * 由于 MOD = 1000000009 是质数，由费马小定理：a^(MOD-2) ≡ a⁻¹ (mod MOD)
         * invFact[N] = (N!)⁻¹ mod MOD，然后倒推出其余逆元。
         */
        invFact[N] = powMod(fact[N], MOD - 2);
        for (int i = N - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        /* 边界条件 */
        f[0] = 1; // 空树只有一种（不存在的）情况
        f[1] = 1; // 仅根节点，权值必为 1，只有一种

        /* 动态规划递推 */
        for (int i = 2; i <= N; i++) {
            int L = leftSubtreeSize(i); // 左子树节点数
            int R = i - 1 - L; // 右子树节点数

            /*
             * f(i) = C(i-1, L) × f(L) × f(R) mod MOD
             * 其中 C(n, k) = n! / (k! × (n-k)!) mod MOD
             */
            long comb = fact[i - 1] * invFact[L] % MOD * invFact[i - 1 - L] % MOD;
            f[i] = comb * f[L] % MOD * f[R] % MOD;
        }

        System.out.println(f[N]);
    }

    /**
     * 快速幂取模：计算 (base^exp) % MOD
     *
     * @param base 底数
     * @param exp  指数，非负整数
     * @return base^exp mod MOD
     */
    static long powMod(long base, long exp) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * base % MOD;
            }
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }

    /**
     * 计算包含 n 个节点的完全二叉树的左子树节点数。
     *
     * 完全二叉树：除最后一层外其余层全满，最后一层从左到右填充。
     * 设总高度 h = ⌊log₂(n)⌋，则：
     * - 第 0 至 h-1 层为满二叉树，共 2^h - 1 个节点。
     * - 第 h 层有 last = n - (2^h - 1) 个节点。
     * - 左子树满层节点：2^(h-1) - 1。
     * - 左子树在第 h 层最多 2^(h-1) 个节点，实际取 min(2^(h-1), last)。
     *
     * @param n 总节点数
     * @return 左子树的节点数
     */
    static int leftSubtreeSize(int n) {
        if (n <= 1) {
            return 0;
        }

        /* 计算 h = ⌊log₂(n)⌋（通过右移统计位数） */
        int h = 0;
        int temp = n;
        while (temp > 1) {
            temp >>= 1;
            h++;
        }

        /* 第 0 至 h-1 层（满层）共 2^h - 1 个节点 */
        int fullLayers = (1 << h) - 1;
        /* 第 h 层（最后一层）的节点数 */
        int lastLayer = n - fullLayers;
        /* 左子树在第 h 层的最大容量 */
        int maxLeftLast = 1 << (h - 1);
        /* 左子树实际获得的第 h 层节点数 */
        int leftLast = lastLayer < maxLeftLast ? lastLayer : maxLeftLast;

        /* 左子树满层节点数 + 最后一层节点数 */
        return (1 << (h - 1)) - 1 + leftLast;
    }
}
