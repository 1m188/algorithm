/*

压缩变换

小明最近在研究压缩算法。
他知道，压缩的时候如果能够使得数值很小，就能通过熵编码得到较高的压缩比。
然而，要使数值很小是一个挑战。

最近，小明需要压缩一些正整数的序列，这些序列的特点是，后面出现的数字很大可能是刚出现过不久的数字。对于这种特殊的序列，小明准备对序列做一个变换来减小数字的值。

变换的过程如下：
从左到右枚举序列，每枚举到一个数字，如果这个数字没有出现过，刚将数字变换成它的相反数，如果数字出现过，则看它在原序列中最后的一次出现后面（且在当前数前面）出现了几种数字，用这个种类数替换原来的数字。

比如，序列(a1, a2, a3, a4, a5)=(1, 2, 2, 1, 2)在变换过程为：
a1: 1未出现过，所以a1变为-1；
a2: 2未出现过，所以a2变为-2；
a3: 2出现过，最后一次为原序列的a2，在a2后、a3前有0种数字，所以a3变为0；
a4: 1出现过，最后一次为原序列的a1，在a1后、a4前有1种数字，所以a4变为1；
a5: 2出现过，最后一次为原序列的a3，在a3后、a5前有1种数字，所以a5变为1。
现在，给出原序列，请问，按这种变换规则变换后的序列是什么。

输入格式：
输入第一行包含一个整数n，表示序列的长度。
第二行包含n个正整数，表示输入序列。

输出格式：
输出一行，包含n个数，表示变换后的序列。

例如，输入：
5
1 2 2 1 2

程序应该输出：
-1 -2 0 1 1

再例如，输入：
12
1 1 2 3 2 3 1 2 2 2 3 1

程序应该输出：
-1 0 -2 -3 1 1 2 2 0 0 2 2

数据规模与约定
对于30%的数据，n<=1000；
对于50%的数据，n<=30000；
对于100%的数据，1 <=n<=100000，1<=ai<=10^9


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。


*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.StringTokenizer;

public class _10 {

    /**
     * 树状数组（Fenwick Tree）
     * 用于维护每个数值"当前最后出现位置"的标记，支持单点更新和区间求和
     */
    static class Fenwick {
        int[] tree;
        int n;

        Fenwick(int n) {
            this.n = n;
            tree = new int[n + 1];
        }

        /** 在 1-indexed 位置 idx 上增加 delta */
        void add(int idx, int delta) {
            while (idx <= n) {
                tree[idx] += delta;
                idx += idx & -idx;
            }
        }

        /** 查询 1-indexed 前缀和 [1, idx] */
        int sum(int idx) {
            int s = 0;
            while (idx > 0) {
                s += tree[idx];
                idx -= idx & -idx;
            }
            return s;
        }

        /** 查询 1-indexed 区间和 [l, r] */
        int rangeSum(int l, int r) {
            if (l > r) {
                return 0;
            }
            return sum(r) - sum(l - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int[] ans = new int[n];
        // 记录每个数值在原序列中最后一次出现的位置（0-indexed）
        HashMap<Integer, Integer> lastPos = new HashMap<Integer, Integer>();
        // 树状数组：标记每个数值"当前最后出现"的位置
        Fenwick bit = new Fenwick(n);

        for (int i = 0; i < n; i++) {
            int val = a[i];
            Integer prev = lastPos.get(val);
            if (prev == null) {
                // 首次出现：变换为相反数
                ans[i] = -val;
            } else {
                // 出现过：查询 [prev+1, i-1]（0-indexed）内不同数字的种类数
                // 转为 1-indexed：[prev+2, i]
                int l = prev + 2;
                int r = i;
                ans[i] = bit.rangeSum(l, r);
                // 移除旧的"最后出现位置"标记
                bit.add(prev + 1, -1);
            }
            // 在当前位置打上标记
            bit.add(i + 1, 1);
            // 更新最后出现位置
            lastPos.put(val, i);
        }

        // 输出结果
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                sb.append(' ');
            }
            sb.append(ans[i]);
        }
        System.out.println(sb.toString());
    }
}
