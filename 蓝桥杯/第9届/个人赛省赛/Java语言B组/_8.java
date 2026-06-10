/*

标题：日志统计

小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有N行。其中每一行的格式是：

ts id  

表示在ts时刻编号id的帖子收到一个"赞"。  

现在小明想统计有哪些帖子曾经是"热帖"。如果一个帖子曾在任意一个长度为D的时间段内收到不少于K个赞，小明就认为这个帖子曾是"热帖"。  

具体来说，如果存在某个时刻T满足该帖在[T, T+D)这段时间内(注意是左闭右开区间)收到不少于K个赞，该帖就曾是"热帖"。  

给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。  

【输入格式】
第一行包含三个整数N、D和K。  
以下N行每行一条日志，包含两个整数ts和id。  

对于50%的数据，1 <= K <= N <= 1000  
对于100%的数据，1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000  

【输出格式】
按从小到大的顺序输出热帖id。每个id一行。  

【输入样例】
7 10 2  
0 1  
0 10    
10 10  
10 1  
9 1
100 3  
100 3  

【输出样例】
1  
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

public class _8 {

    /**
     * 日志统计
     *
     * 核心思路：
     * 1. 将日志按帖子 id 分组，收集每个帖子的所有点赞时间戳。
     * 2. 对每个帖子的时间戳列表排序。
     * 3. 使用"尺取法"（滑动窗口）判断该帖子是否为热帖：
     * 检查是否存在连续的 K 个时间戳，使得它们中最晚与最早的时间差 < D。
     * 若存在，则该帖子是热帖。
     * 4. 将所有热帖 id 升序输出。
     *
     * 正确性说明：
     * - 充分性：若第 i 个到第 i+K-1 个时间戳之差 < D，则令 T = 第 i 个时间戳，
     * 窗口 [T, T+D) 必包含这 K 个赞，帖子为热帖。
     * - 必要性：若存在某个窗口 [T, T+D) 包含至少 K 个赞，取其中最早的 K 个时间戳，
     * 它们的最晚与最早之差必然 < D，算法能检测到。
     *
     * 时间复杂度：O(N log N)，其中 N 为日志条数。
     * - 分组：O(N)
     * - 每个帖子的排序：总计 O(N log M) ≤ O(N log N)
     * - 尺取法扫描：O(N)
     * - 热帖排序：O(R log R)，R 为热帖数量，R ≤ N
     *
     * 空间复杂度：O(N)，存储所有日志的时间戳。
     */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        /* 读取输入：日志条数 N、时间窗口长度 D、热帖阈值 K */
        int N = sc.nextInt();
        int D = sc.nextInt();
        int K = sc.nextInt();

        /*
         * 将每条日志按帖子 id 分组，收集对应的时间戳列表。
         * 使用 HashMap 而非数组是考虑到 id 可能较大（≤100000），但 HashMap 更通用。
         */
        Map<Integer, List<Integer>> idToTimes = new HashMap<Integer, List<Integer>>();
        for (int i = 0; i < N; i++) {
            int ts = sc.nextInt();
            int id = sc.nextInt();

            List<Integer> times = idToTimes.get(id);
            if (times == null) {
                times = new ArrayList<Integer>();
                idToTimes.put(id, times);
            }
            times.add(ts);
        }
        sc.close();

        /* 存储所有热帖 id */
        List<Integer> hotPosts = new ArrayList<Integer>();

        /* 逐个帖子判断是否为热帖 */
        for (Map.Entry<Integer, List<Integer>> entry : idToTimes.entrySet()) {
            int id = entry.getKey();
            List<Integer> times = entry.getValue();

            /* 按时间升序排列该帖子的所有点赞时间戳 */
            Collections.sort(times);

            int size = times.size();
            if (size < K) {
                /* 点赞总数不足以达到 K，不可能成为热帖 */
                continue;
            }

            /*
             * 尺取法（滑动窗口）：
             * 检查是否存在连续的 K 个时间戳，满足 times[i+K-1] - times[i] < D。
             * 一旦找到即标记为热帖，无须继续检查该帖子的其余窗口。
             */
            for (int i = 0; i + K - 1 < size; i++) {
                if (times.get(i + K - 1) - times.get(i) < D) {
                    hotPosts.add(id);
                    break;
                }
            }
        }

        /* 按 id 升序排列热帖 */
        Collections.sort(hotPosts);

        /* 输出结果：每个热帖 id 占一行 */
        for (int id : hotPosts) {
            System.out.println(id);
        }
    }
}
