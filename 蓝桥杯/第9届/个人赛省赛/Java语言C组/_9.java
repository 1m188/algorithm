/*

标题：小朋友崇拜圈

班里N个小朋友，每个人都有自己最崇拜的一个小朋友（也可以是自己）。
在一个游戏中，需要小朋友坐一个圈，
每个小朋友都有自己最崇拜的小朋友在他的右手边。
求满足条件的圈最大多少人？

小朋友编号为1,2,3,...N
输入第一行，一个整数N（3<N<100000）
接下来一行N个整数，由空格分开。

要求输出一个整数，表示满足条件的最大圈的人数。

例如：
输入：
9
3 4 2 5 3 8 4 6 9

则程序应该输出：
4

解释：
如图p1.png所示，崇拜关系用箭头表示，红色表示不在圈中。
显然，最大圈是[2 4 5 3] 构成的圈


再例如：
输入：
30
22 28 16 6 27 21 30 1 29 10 9 14 24 11 7 2 8 5 26 4 12 3 25 18 20 19 23 17 13 15

程序应该输出：
16

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。


*/

import java.util.*;

public class _9 {

    /**
     * 小朋友崇拜圈
     *
     * 有 N 个小朋友，每个小朋友都有一个崇拜对象（可能为自己）。
     * 构成一个每个节点出度为 1 的有向图（Functional Graph）。
     * 求最大的环（圈）的长度。
     *
     * 核心思路：
     * Functional Graph 的每个连通分量恰好包含一个环，
     * 以及若干指向该环的树形结构。
     * 使用全局时间戳法检测环：
     * 1. 对未访问节点，沿崇拜链前进并记录到达时间。
     * 2. 若遇到在同一轮访问中已标记的节点，则发现环，
     * 环长 = 当前时间 - 该节点首次被访问的时间 + 1。
     * 3. 若遇到之前轮次已访问的节点，无新环。
     *
     * 时间复杂度：O(N)，每个节点最多被访问一次。
     * 空间复杂度：O(N)，存储崇拜数组和时间戳。
     */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        /*
         * admire[i] 表示小朋友 i 崇拜的对象（1-based 索引）。
         */
        int[] admire = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            admire[i] = sc.nextInt();
        }
        sc.close();

        /*
         * time[i] 记录节点 i 在全局时间轴上的到达时刻。
         * time[i] == 0 表示尚未访问。
         */
        int[] time = new int[N + 1];

        int maxCycle = 0; // 记录最大环长
        int clock = 0; // 全局时钟，单调递增，永不复位

        for (int i = 1; i <= N; i++) {
            if (time[i] != 0) {
                continue; // 已访问过，跳过
            }

            int cur = i;
            int startClock = clock + 1; // 本轮遍历开始的时钟值

            /* 沿崇拜链前进，标记到达时间 */
            while (time[cur] == 0) {
                clock++;
                time[cur] = clock;
                cur = admire[cur];
            }

            /*
             * 离开循环时，cur 指向一个已访问过的节点。
             * 若该节点的时间戳 ≥ startClock，说明是在本轮中首次访问的，
             * 即发现了一个新的环。
             * 环长 = 当前时钟 - 该节点时间戳 + 1
             */
            if (time[cur] >= startClock) {
                int cycleLen = clock - time[cur] + 1;
                if (cycleLen > maxCycle) {
                    maxCycle = cycleLen;
                }
            }
            /*
             * 若 time[cur] < startClock，则 cur 属于之前轮次的链，
             * 当前追踪的只是一条汇入已处理组件的树边，无新环。
             */
        }

        System.out.println(maxCycle);
    }
}
