/*

碱基

生物学家正在对n个物种进行研究。
其中第i个物种的DNA序列为s[i]，其中的第j个碱基为s[i][j],碱基一定是A、T、G、C之一。
生物学家想找到这些生物中一部分生物的一些共性，他们现在关注那些至少在m个生物中出现的长度为k的连续碱基序列。准确的说，科学家关心的序列用2m元组(i1,p1,i2,p2....im,pm)表示，
满足:
1<=i1<i2<....<im<=n;
且对于所有q(0<=q<k), s[i1][p1+q]=s[i2][p2+q]=....=s[im][pm+q]。

现在给定所有生物的DNA序列，请告诉科学家有多少的2m元组是需要关注的。如果两个2m元组有任何一个位置不同，则认为是不同的元组。

【输入格式】
输入的第一行包含三个整数n、m、k，两个整数之间用一个空格分隔，意义如题目所述。
接下来n行，每行一个字符串表示一种生物的DNA序列。
DNA序列从1至n编号，每个序列中的碱基从1开始依次编号，不同的生物的DNA序列长度可能不同。

【输出格式】
输出一个整数，表示关注的元组个数。
答案可能很大，你需要输出答案除以1000000007的余数。

【样例输入】
3 2 2
ATC
TCG
ACG

【样例输出】
2

再例如：
【样例输入】
4 3 3
AAA
AAAA
AAA
AAA

【样例输出】
7


【数据规模与约定】
对于20%的数据，k<=5,所有字符串总长L满足L <=100
对于30%的数据，L<=10000
对于60%的数据，L<=30000
对于100%的数据，n<=5,m<=5,1<=k<=L<=100000
保证所有DNA序列不为空且只会包含’A’ ’G’ ’C’ ’T’四种字母

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.HashMap;
import java.util.Scanner;

public class _6 {
    static final long MOD = 1000000007; // 答案取模
    static final long M1 = 1000000007; // 第一个哈希模数
    static final long M2 = 1000000009; // 第二个哈希模数
    static final long B = 131; // 哈希基数

    /**
     * 双哈希键：同时储存两个 64 位哈希值，避免哈希碰撞。
     */
    static class Pair {
        long h1, h2;

        Pair(long h1, long h2) {
            this.h1 = h1;
            this.h2 = h2;
        }

        @Override
        public int hashCode() {
            return (int) (h1 * 31 + h2);
        }

        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Pair))
                return false;
            Pair p = (Pair) o;
            return h1 == p.h1 && h2 == p.h2;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        String[] dna = new String[n];
        for (int i = 0; i < n; i++)
            dna[i] = sc.next();
        sc.close();

        // counts: 对于每种 k-子串模式（双哈希），记录其在每个物种中出现次数
        HashMap<Pair, int[]> map = new HashMap<>();

        for (int idx = 0; idx < n; idx++) {
            String s = dna[idx];
            int len = s.length();
            if (len < k)
                continue; // 该物种长度不足 k，跳过

            // 为当前物种计算前缀哈希和幂
            long[] pow1 = new long[k + 1], pow2 = new long[k + 1];
            long[] pre1 = new long[len + 1], pre2 = new long[len + 1];
            pow1[0] = pow2[0] = 1;
            for (int i = 1; i <= k; i++) {
                pow1[i] = pow1[i - 1] * B % M1;
                pow2[i] = pow2[i - 1] * B % M2;
            }
            for (int i = 0; i < len; i++) {
                int val = mapChar(s.charAt(i));
                pre1[i + 1] = (pre1[i] * B + val) % M1;
                pre2[i + 1] = (pre2[i] * B + val) % M2;
            }

            // 枚举所有起始位置，计算子串双哈希
            for (int p = 0; p + k <= len; p++) {
                long h1 = ((pre1[p + k] - pre1[p] * pow1[k]) % M1 + M1) % M1;
                long h2 = ((pre2[p + k] - pre2[p] * pow2[k]) % M2 + M2) % M2;
                Pair key = new Pair(h1, h2);
                int[] cnt = map.get(key);
                if (cnt == null) {
                    cnt = new int[n];
                    map.put(key, cnt);
                }
                cnt[idx]++;
            }
        }

        long ans = 0;

        // 枚举所有独特的 k-子串模式，计算其对答案的贡献
        for (int[] cnt : map.values()) {
            ans = (ans + contribution(cnt, m, n)) % MOD;
        }

        System.out.println(ans);
    }

    /** 将碱基映射为数值 (A=1, C=2, G=3, T=4)，避免全零串哈希为零。 */
    static int mapChar(char c) {
        switch (c) {
            case 'A':
                return 1;
            case 'C':
                return 2;
            case 'G':
                return 3;
            case 'T':
                return 4;
        }
        return 0; // 不会执行
    }

    /**
     * 给定每种物种的出现次数 cnt[0..n-1]，计算从中选出 m 个不同物种，
     * 且各取一个出现位置的不同方案数（模 MOD）。
     * 即 sum_{0≤j1<...<jm<n} cnt[j1] * cnt[j2] * ... * cnt[jm]。
     */
    static long contribution(int[] cnt, int m, int n) {
        return dfs(cnt, 0, m, n, 1L);
    }

    /** 递归枚举所有 m-组合，累积乘积。 */
    static long dfs(int[] cnt, int start, int left, int n, long prod) {
        if (left == 0)
            return prod % MOD;
        long sum = 0;
        for (int i = start; i <= n - left; i++) {
            if (cnt[i] == 0)
                continue; // 该物种无此模式，跳过
            sum = (sum + dfs(cnt, i + 1, left - 1, n, prod * cnt[i] % MOD)) % MOD;
        }
        return sum;
    }
}
