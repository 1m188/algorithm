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

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

*/

import java.io.*;
import java.util.*;

public class _5 {
    // Ai 的取值范围上限
    static final int MAX_A = 100000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        // 统计每个积分值的用户数量
        int[] cnt = new int[MAX_A + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int score = Integer.parseInt(st.nextToken());
            cnt[score]++;
        }

        int answer = 0;

        if (K == 0) {
            // K=0 时，同分用户构成完全图，每组最多选 1 人
            // 答案为不同积分的数量
            for (int i = 0; i <= MAX_A; i++) {
                if (cnt[i] > 0)
                    answer++;
            }
        } else {
            // K>0 时，积分值按模 K 余数分成组，每组内形成线性链
            // 链上相邻积分（相差 K）的用户冲突，用 DP 求最大独立集
            for (int r = 0; r < K; r++) {
                // 对当前余数 r 的链做 DP
                // dp0: 不选当前积分的最优值
                // dp1: 选择当前积分的最优值
                int dp0 = 0, dp1 = 0;
                for (int s = r; s <= MAX_A; s += K) {
                    if (cnt[s] == 0) {
                        // 出现断点：结算当前段，重置 DP
                        answer += Math.max(dp0, dp1);
                        dp0 = 0;
                        dp1 = 0;
                    } else {
                        // 标准线性 DP 转移
                        int newDp0 = Math.max(dp0, dp1); // 不选 s
                        int newDp1 = dp0 + cnt[s]; // 选 s（所有同分用户）
                        dp0 = newDp0;
                        dp1 = newDp1;
                    }
                }
                // 结算链末端的 DP 段
                answer += Math.max(dp0, dp1);
            }
        }

        System.out.println(answer);
    }
}
