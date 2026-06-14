/*
居民集会

蓝桥村的居民都生活在一条公路的边上，公路的长度为L，每户家庭的位置都用这户家庭到公路的起点的距离来计算，第i户家庭距起点的距离为di。

每年，蓝桥村都要举行一次集会。今年，由于村里的人口太多，村委会决定要在4个地方举行集会，其中3个位于公路中间，1个位最公路的终点。

已知每户家庭都会向着远离公路起点的方向去参加集会，参加集会的路程开销为家庭内的人数ti与距离的乘积。

给定每户家庭的位置di和人数ti，请为村委会寻找最好的集会举办地：p1, p2, p3, p4 (p1<=p2<=p3<=p4=L),使得村内所有人的路程开销和最小。

【输入格式】
输入的第一行包含两个整数n, L，分别表示蓝桥村的家庭数和公路长度。
接下来n行，每行两个整数di, ti，分别表示第i户家庭距离公路起点的距离和家庭中的人数。

【输出格式】
输出一行，包含一个整数，表示村内所有人路程的开销和。
【样例输入】
6 10
1 3
2 2
4 5
5 20
6 5
8 7
【样例输出】
18
*/

import java.util.*;

public class _6 {
    static int n;
    static long L;
    static long[] d;            // 家庭位置
    static long[] t;            // 家庭人数
    static long[] prefT;        // 人数前缀和
    static long[] prefTD;       // 人数×距离 前缀和

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        L = sc.nextLong();
        d = new long[n + 1];
        t = new long[n + 1];
        prefT = new long[n + 1];
        prefTD = new long[n + 1];

        for (int i = 1; i <= n; i++) {
            d[i] = sc.nextLong();
            t[i] = sc.nextLong();
            prefT[i] = prefT[i - 1] + t[i];
            prefTD[i] = prefTD[i - 1] + t[i] * d[i];
        }
        sc.close();

        // dp1[i]: 前 i 个家庭由一个集会点（在 d[i]）覆盖的最小成本
        long[] dp1 = new long[n + 1];
        for (int i = 1; i <= n; i++)
            dp1[i] = d[i] * prefT[i] - prefTD[i];

        // dp2[i]: 前 i 个家庭，用 2 个集会点
        long[] dp2 = computeNext(dp1);

        // dp3[i]: 前 i 个家庭，用 3 个集会点
        long[] dp3 = computeNext(dp2);

        // 最后一段由 L 覆盖，枚举 dp3 的划分点
        long ans = Long.MAX_VALUE;
        for (int j = 0; j <= n; j++) {
            long cost = dp3[j] + L * (prefT[n] - prefT[j]) - (prefTD[n] - prefTD[j]);
            if (cost < ans)
                ans = cost;
        }
        System.out.println(ans);
    }

    /**
     * 从 dp_{k-1} 计算 dp_k。
     * dp_k[i] = di*prefT[i] - prefTD[i] - max_{j < i}(prefT[j]*di - dp_{k-1}[j] - prefTD[j])
     * 使用凸包技巧维护上凸壳（斜率单调递增、查询点单调非降）。
     */
    static long[] computeNext(long[] prev) {
        long[] dp = new long[n + 1];
        dp[0] = 0;
        CHT cht = new CHT();
        cht.add(0, 0);                // j=0 的初始线（prefT[0]=0, prev[0]=0, prefTD[0]=0）
        for (int i = 1; i <= n; i++) {
            long maxVal = cht.query(d[i]);
            dp[i] = d[i] * prefT[i] - prefTD[i] - maxVal;
            // 将当前 i 作为新的可能分割点加入凸包
            long m = prefT[i];
            long b = -(prev[i] + prefTD[i]);
            cht.add(m, b);
        }
        return dp;
    }

    /** 维护上凸壳（斜率递增），支持最大点查询 */
    static class CHT {
        ArrayList<Line> hull = new ArrayList<>();

        void add(long m, long b) {
            Line newLine = new Line(m, b);
            // 去除被新线覆盖的冗余线
            while (hull.size() >= 2) {
                Line l1 = hull.get(hull.size() - 2);
                Line l2 = hull.get(hull.size() - 1);
                // l2 无用的条件：(b1-b3)/(m3-m1) <= (b1-b2)/(m2-m1)
                if ((l1.b - newLine.b) * (l2.m - l1.m) <= (l1.b - l2.b) * (newLine.m - l1.m))
                    hull.remove(hull.size() - 1);
                else
                    break;
            }
            hull.add(newLine);
        }

        long query(long x) {
            while (hull.size() >= 2) {
                Line l1 = hull.get(0);
                Line l2 = hull.get(1);
                // 如果 l2 在当前 x 处优于 l1，则丢弃 l1
                if (l1.m * x + l1.b <= l2.m * x + l2.b)
                    hull.remove(0);
                else
                    break;
            }
            return hull.get(0).m * x + hull.get(0).b;
        }

        static class Line {
            long m, b;
            Line(long m, long b) { this.m = m; this.b = b; }
        }
    }
}
