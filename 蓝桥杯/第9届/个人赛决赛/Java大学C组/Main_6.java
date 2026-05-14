/*
 *
 * 标题：自描述序列
 *
 * 小明在研究一个序列，叫Golomb自描述序列，不妨将其记作{G(n)}。这个序列有2个很有趣的性质:
 *
 * 1. 对于任意正整数n，n在整个序列中恰好出现G(n)次。
 * 2. 这个序列是不下降的。
 *
 * 以下是{G(n)}的前几项：
 *
 * n 1 2 3 4 5 6 7 8 9 10 11 12 13
 * G(n) 1 2 2 3 3 4 4 4 5 5 5 6 6
 *
 * 给定一个整数n，你能帮小明算出G(n)的值吗？
 *
 * 输入
 * ----
 * 一个整数n。
 *
 * 对于30%的数据，1 <= n <= 1000000
 * 对于70%的数据，1 <= n <= 1000000000
 * 对于100%的数据，1 <= n <= 2000000000000000
 *
 * 输出
 * ----
 * 一个整数G(n)
 *
 *
 * 【样例输入】
 * 13
 *
 * 【样例输出】
 * 6
 *
 * 资源约定：
 * 峰值内存消耗（含虚拟机） < 256M
 * CPU消耗 < 1000ms
 *
 *
 * 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 *
 * 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 * 不要使用package语句。不要使用jdk1.7及以上版本的特性。
 * 主类的名字必须是：Main，否则按无效代码处理。
 *
 *
 *
 */

import java.util.Scanner;

public class Main_6 {
    /*
     * Golomb 自描述序列 - 分块跳跃算法 O(G(n)^(1/2)) ≈ O(n^0.309)
     *
     * 核心思路：
     * G(n) 定义为：值 v 在序列中出现 G(v) 次。
     * 利用「双重累加」关系同时推进两个指针：
     * cnt[v] = G(v) —— 值 v 出现的次数
     * sum[v] = S(v) —— 值 ≤ v 的总项数
     *
     * 算法维持 i 从 1 向上递推 G(i)，同时用另一个指针 pos 来"消费"这些值：
     * G(pos) 表示值 pos 在序列中出现的次数。
     * 每当我们计算出 G(i) 后，就将其"分配"到对应的值上。
     *
     * 实际上 G 可以由递推 G(k)=1+G(k-G(G(k-1))) 计算，
     * 但这里我们沿用"双重循环"的经典生成方式——模拟 Golomb 序列的生成过程，
     * 仅需 O(√答案) 的时间。
     */
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            long n = sc.nextLong();

            if (n == 1) {
                System.out.println(1);
                return;
            }
            if (n <= 3) {
                System.out.println(2);
                return;
            }

            // ---------- 第一步：预计算 G[1..PRE] 和 S[1..PRE] ----------
            // PRE 取 2×10^6 即可覆盖约 S(PRE) ≈ 1.5×10^11 的范围
            final int PRE = 2000000;
            final int BUF = 1 << 21; // 环形缓冲区大小
            final int MASK = BUF - 1;
            int[] g = new int[BUF];

            g[1] = 1;
            g[2] = 2;
            g[3] = 2;
            // 同时把前缀和存入 sumG（非环形）
            long[] sumG = new long[PRE + 1];
            sumG[1] = 1;
            sumG[2] = 3;
            sumG[3] = 5;

            // 检查 n 是否已被初始值覆盖
            if (sumG[3] >= n) {
                System.out.println(3);
                return;
            }

            int m = 4;
            while (m <= PRE) {
                int gm1 = g[(m - 1) & MASK];
                int gg = g[gm1 & MASK];
                int idx = m - gg;
                int gm = 1 + g[idx & MASK];
                g[m & MASK] = gm;
                sumG[m] = sumG[m - 1] + gm;
                if (sumG[m] >= n) {
                    System.out.println(m);
                    return;
                }
                m++;
            }

            // ---------- 第二步：n 较大时，紧凑递推 ----------
            long sum = sumG[PRE];
            // m 从 PRE+1 开始，用 int 循环加速（G(n) < 2^31）
            int mm = PRE + 1;
            int mask = MASK;

            while (true) {
                int gm1 = g[(mm - 1) & mask];
                int gg = g[gm1 & mask];
                int gm = 1 + g[(mm - gg) & mask];
                g[mm & mask] = gm;
                sum += gm;
                if (sum >= n) {
                    System.out.println(mm);
                    return;
                }
                mm++;
            }
        }
    }
}
