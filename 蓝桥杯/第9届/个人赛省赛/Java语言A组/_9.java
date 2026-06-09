/*

标题：倍数问题

【题目描述】
众所周知，小葱同学擅长计算，尤其擅长计算一个数是否是另外一个数的倍数。但小葱只擅长两个数的情况，当有很多个数之后就会比较苦恼。现在小葱给了你 n 个数，希望你从这 n 个数中找到三个数，使得这三个数的和是 K 的倍数，且这个和最大。数据保证一定有解。

【输入格式】
从标准输入读入数据。
第一行包括 2 个正整数 n, K。
第二行 n 个正整数，代表给定的 n 个数。

【输出格式】
输出到标准输出。
输出一行一个整数代表所求的和。

【样例输入】
4 3
1 2 3 4

【样例输出】
9

【样例解释】
选择2、3、4。

【数据约定】
对于 30% 的数据，n <= 100。
对于 60% 的数据，n <= 1000。
对于另外 20% 的数据，K <= 10。
对于 100% 的数据，1 <= n <= 10^5, 1 <= K <= 10^3，给定的 n 个数均不超过 10^8。


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。


*/

public class _9 {

    /**
     * 每个余数分组中最多保留3个数即可（因为我们最多从同一余数组中取3个数）。
     * 保留每个余数组中最大的3个数，以便在枚举组合时直接取用。
     */
    static final int MAX_PER_GROUP = 3;

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int K = scanner.nextInt();

        /*
         * groups[r]: 存储余数为r的数中最大的若干个数
         * 使用优先队列（小顶堆）维护，当堆中元素超过MAX_PER_GROUP时弹出最小的，
         * 从而始终保留该余数组中最大的MAX_PER_GROUP个数
         */
        java.util.PriorityQueue<Integer>[] groups = (java.util.PriorityQueue<Integer>[]) new java.util.PriorityQueue[K];
        for (int r = 0; r < K; r++) {
            groups[r] = new java.util.PriorityQueue<>();
        }

        /*
         * 读取n个数，根据每个数对K的余数进行分组，
         * 并在每组中只保留最大的MAX_PER_GROUP个数
         */
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            int remainder = num % K;
            groups[remainder].offer(num);
            if (groups[remainder].size() > MAX_PER_GROUP) {
                groups[remainder].poll();
            }
        }

        /*
         * 将每个余数分组中的数从大到小排序，方便后续按索引取用
         * sorted[r][0] 为余数r组中最大的数，sorted[r][1] 为第二大，以此类推
         */
        int[][] sorted = new int[K][MAX_PER_GROUP];
        int[] groupSize = new int[K];
        for (int r = 0; r < K; r++) {
            groupSize[r] = groups[r].size();
            if (groupSize[r] == 0)
                continue;
            /*
             * 小顶堆弹出的顺序是从小到大，逆序存储即可得到从大到小的排列
             */
            int[] temp = new int[groupSize[r]];
            for (int j = groupSize[r] - 1; j >= 0; j--) {
                temp[j] = groups[r].poll();
            }
            for (int j = 0; j < groupSize[r]; j++) {
                sorted[r][j] = temp[j];
            }
        }

        /*
         * 枚举所有满足 a + b + c ≡ 0 (mod K) 的余数组合 (a, b, c)，其中 a ≤ b ≤ c
         * 对于每种有效组合，根据三个余数是否相同来决定从各分组中取多少个数：
         * - a == b == c: 从余数a分组取3个数（需要该组至少有3个数）
         * - a == b < c: 从余数a分组取2个数，余数c分组取1个数
         * - a < b == c: 从余数a分组取1个数，余数b分组取2个数
         * - a < b < c: 从各分组各取1个数
         * 记录所有可行组合中的最大和
         */
        int maxSum = 0;

        for (int a = 0; a < K; a++) {
            if (groupSize[a] == 0)
                continue;
            for (int b = a; b < K; b++) {
                if (groupSize[b] == 0)
                    continue;
                for (int c = b; c < K; c++) {
                    if (groupSize[c] == 0)
                        continue;

                    /* 判断余数之和是否为K的倍数 */
                    if ((a + b + c) % K != 0)
                        continue;

                    int sum = 0;

                    if (a == b && b == c) {
                        /*
                         * 三个余数完全相同，需要从同一分组取3个不同的数，
                         * 因此该分组必须至少有3个数
                         */
                        if (groupSize[a] < 3)
                            continue;
                        sum = sorted[a][0] + sorted[a][1] + sorted[a][2];
                    } else if (a == b) {
                        /*
                         * 前两个余数相同，第三个不同，
                         * 从余数a分组取2个数，余数c分组取1个数
                         */
                        if (groupSize[a] < 2)
                            continue;
                        sum = sorted[a][0] + sorted[a][1] + sorted[c][0];
                    } else if (b == c) {
                        /*
                         * 后两个余数相同，第一个不同，
                         * 从余数a分组取1个数，余数b分组取2个数
                         */
                        if (groupSize[b] < 2)
                            continue;
                        sum = sorted[a][0] + sorted[b][0] + sorted[b][1];
                    } else {
                        /*
                         * 三个余数各不相同，从各分组各取1个数
                         */
                        sum = sorted[a][0] + sorted[b][0] + sorted[c][0];
                    }

                    if (sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }
        }

        System.out.println(maxSum);
    }
}
