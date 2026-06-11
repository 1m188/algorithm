/*

标题：区间移位

数轴上有n个闭区间：D1,...,Dn。
其中区间Di用一对整数[ai, bi]来描述，满足ai < bi。
已知这些区间的长度之和至少有10000。
所以，通过适当的移动这些区间，你总可以使得他们的“并”覆盖[0, 10000]——也就是说[0, 10000]这个区间内的每一个点都落于至少一个区间内。
你希望找一个移动方法，使得位移差最大的那个区间的位移量最小。

具体来说，假设你将Di移动到[ai+ci, bi+ci]这个位置。你希望使得maxi{|ci|} 最小。

【输入格式】
输入的第一行包含一个整数n，表示区间的数量。
接下来有n行，每行2个整数ai, bi，以一个空格分开，表示区间[ai, bi]。
保证区间的长度之和至少是10000。

【输出格式】
输出一个数字，表示答案。如果答案是整数，只输出整数部分。如果答案不是整数，输出时四舍五入保留一位小数。

【样例输入】
2
10 5010
4980 9980

【样例输出】
20

【样例说明】
第一个区间往左移动10；第二个区间往右移动20。

【样例输入】
4
0 4000
3000 5000
5001 8000
7000 10000
【样例输出】
0.5
【样例说明】
第2个区间往右移0.5；第3个区间往左移0.5即可。

【数据规模与约定】
对于30%的评测用例，1 <= n <= 10；
对于100%的评测用例，1 <= n <= 10000，0 <= ai < bi <= 10000。

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。


*/

import java.io.*;
import java.util.*;

public class _6 {
    static final double TARGET = 10000.0;
    static final double EPS = 1e-7;

    static class Interval {
        double a, b, len;

        Interval(double a, double b) {
            this.a = a;
            this.b = b;
            this.len = b - a;
        }
    }

    /**
     * 检查最大位移 d 是否足以覆盖 [0, 10000]
     * 贪心策略：按 a 排序，用最小堆按 a+d（最远可开始位置）选取区间
     */
    static boolean feasible(List<Interval> list, double d) {
        int n = list.size();

        // 按原始左端点 a 排序
        Interval[] arr = list.toArray(new Interval[0]);
        Arrays.sort(arr, new Comparator<Interval>() {
            public int compare(Interval x, Interval y) {
                return Double.compare(x.a, y.a);
            }
        });

        // 最小堆：按 a+d 排序（越早过期的越优先）
        PriorityQueue<Interval> pq = new PriorityQueue<Interval>(
                new Comparator<Interval>() {
                    public int compare(Interval x, Interval y) {
                        return Double.compare(x.a + d, y.a + d);
                    }
                });

        int idx = 0;
        double R = 0;

        while (R + EPS < TARGET) {
            // 将所有 a-d <= R 的区间入堆
            while (idx < n && arr[idx].a - d <= R + EPS) {
                pq.offer(arr[idx]);
                idx++;
            }

            if (pq.isEmpty())
                return false;

            // 弹出 a+d 最小的区间
            boolean extended = false;
            while (!pq.isEmpty()) {
                Interval it = pq.poll();
                // 该区间最远也只能延伸到 b+d，若仍不超 R 则无用
                if (it.b + d <= R + EPS)
                    continue;

                if (it.a + d >= R - EPS) {
                    R = R + it.len; // 可从 R 处开始，延伸 len
                } else {
                    R = it.b + d; // 不能从 R 开始，但可重叠延伸
                }
                extended = true;
                break;
            }
            if (!extended)
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Interval> list = new ArrayList<Interval>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double a = Double.parseDouble(st.nextToken());
            double b = Double.parseDouble(st.nextToken());
            list.add(new Interval(a, b));
        }

        // 二分查找最小可行位移 d
        double lo = 0, hi = 10000;
        for (int iter = 0; iter < 60; iter++) {
            double mid = (lo + hi) / 2;
            if (feasible(list, mid))
                hi = mid;
            else
                lo = mid;
        }

        // 按四舍五入保留一位小数输出
        // 若为整数则输出整数部分
        double ans = hi;
        long rounded = Math.round(ans * 10);
        if (rounded % 10 == 0)
            System.out.println(rounded / 10);
        else
            System.out.printf("%.1f%n", ans);
    }
}
