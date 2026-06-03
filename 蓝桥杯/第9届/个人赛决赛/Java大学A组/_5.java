/*

标题：自描述序列

小明在研究一个序列，叫Golomb自描述序列，不妨将其记作{G(n)}。这个序列有2个很有趣的性质:

1. 对于任意正整数n，n在整个序列中恰好出现G(n)次。
2. 这个序列是不下降的。

以下是{G(n)}的前几项：

n	1	2	3	4	5	6	7	8	9	10	11	12	13
G(n)	1	2	2	3	3	4	4	4	5	5	5	6	6

给定一个整数n，你能帮小明算出G(n)的值吗？

输入
----
一个整数n。  

对于30%的数据，1 <= n <= 1000000  
对于70%的数据，1 <= n <= 1000000000  
对于100%的数据，1 <= n <= 2000000000000000  

输出
----
一个整数G(n)


【样例输入】
13

【样例输出】
6

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。



*/

import java.io.*;

public class _5 {
    public static void main(String[] args) throws IOException {
        long n = Long.parseLong(new BufferedReader(new InputStreamReader(System.in)).readLine());

        // 预生成 G(1..M)，使得 M >= G(G(n))，即能覆盖所有 w 值
        int M = 5_000_000;
        if (n <= M) {
            System.out.println(precompute((int) n)[(int) n]);
            return;
        }

        int[] g = precompute(M);

        long pos = 1; // f[v]：值 v 首次出现的位置
        long v = 1; // 当前值

        for (int w = 1;; w++) {
            long cnt = g[w]; // 值 w 在 G 序列中出现的次数 = G(w)
            long advance = cnt * w; // 该 w-块跨越的位置数
            if (pos + advance > n) {
                // n 落在当前 w-块内部
                System.out.println(v + (n - pos) / w);
                return;
            }
            pos += advance;
            v += cnt;
        }
    }

    // 预生成 G(1..limit)
    static int[] precompute(int limit) {
        int[] g = new int[limit + 1];
        g[1] = 1;
        if (limit >= 2)
            g[2] = 2;
        if (limit >= 3)
            g[3] = 2;

        int pos = 4; // 下一个待填充位置
        int val = 3; // 当前要写入的值
        int idx = 3; // G(idx) 决定 val 写入多少次

        while (pos <= limit) {
            int times = g[idx];
            int end = Math.min(pos + times, limit + 1);
            while (pos < end) {
                g[pos++] = val;
            }
            val++;
            idx++;
        }
        return g;
    }
}
