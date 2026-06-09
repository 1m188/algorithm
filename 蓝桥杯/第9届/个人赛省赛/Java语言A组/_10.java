/*

标题：付账问题

【题目描述】
几个人一起出去吃饭是常有的事。但在结帐的时候，常常会出现一些争执。

现在有 n 个人出去吃饭，他们总共消费了 S 元。其中第 i 个人带了 ai 元。幸运的是，所有人带的钱的总数是足够付账的，但现在问题来了：每个人分别要出多少钱呢？

为了公平起见，我们希望在总付钱量恰好为 S 的前提下，最后每个人付的钱的标准差最小。这里我们约定，每个人支付的钱数可以是任意非负实数，即可以不是1分钱的整数倍。你需要输出最小的标准差是多少。

标准差的介绍：标准差是多个数与它们平均数差值的平方平均数，一般用于刻画这些数之间的“偏差有多大”。形式化地说，设第 i 个人付的钱为 bi 元，那么标准差为 : [参见p1.png]

【输入格式】
从标准输入读入数据。
第一行包含两个整数 n、S；
第二行包含 n 个非负整数 a1, ..., an。

【输出格式】
输出到标准输出。
输出最小的标准差，四舍五入保留 4 位小数。
保证正确答案在加上或减去 10^−9 后不会导致四舍五入的结果发生变化。

【样例输入】
5 2333
666 666 666 666 666

【样例输出】
0.0000

【样例解释】
每个人都出 2333/5 元，标准差为 0。

再比如：
【样例输入】
10 30
2 1 4 7 4 8 3 6 4 7

【样例输出】
0.7928

【数据约定】
对于 10% 的数据，所有 ai 相等；
对于 30% 的数据，所有非 0 的 ai 相等；
对于 60% 的数据，n ≤ 1000；
对于 80% 的数据，n ≤ 10^5；
对于所有数据，n ≤ 5 × 10^5, 0 ≤ ai ≤ 10^9。


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。

*/

public class _10 {

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        long S = scanner.nextLong();

        /*
         * 读取每个人带的钱数，并按升序排序。
         * 排序的原因：钱少的人更容易无法支付平均份额，
         * 需要优先处理他们，让他们付出全部携带的钱，
         * 剩余费用由钱多的人平均分摊，从而使标准差最小。
         */
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }
        java.util.Arrays.sort(a);

        /*
         * 核心贪心策略：最小化标准差等价于最小化 Σbi²，
         * 要让每个人支付的钱尽可能接近平均值。
         *
         * 逐个处理钱最少的人：
         * - 若 a[i] < 当前平均份额 avg：此人只能付 a[i]（全部家当），
         * 剩余费用减少 a[i]，剩余人数减少1，重新计算平均份额。
         * - 若 a[i] >= avg：此人（及后续所有人）都能支付 avg，
         * 所有人付 avg 即可使方差最小，处理结束。
         *
         * remainingCost: 剩余需要支付的总费用
         * remainingPeople: 剩余需要分配费用的人数
         * totalSquaredDiff: 累计的 Σ(bi - S/n)² 值，用于最终计算标准差
         */
        double remainingCost = S;
        int remainingPeople = n;
        double avg = (double) S / n;
        double totalSquaredDiff = 0.0;

        for (int i = 0; i < n; i++) {
            /*
             * avg 是当前剩余人群中每人应付的平均份额。
             * 如果第i个人带的钱不足以支付这个平均份额，
             * 他只能付出自己全部的钱 a[i]，对平均值的偏差被计入 totalSquaredDiff。
             */
            avg = remainingCost / remainingPeople;

            if (a[i] < avg) {
                /*
                 * 此人付 a[i]，偏差 = a[i] - S/n，
                 * 偏差平方累加到 totalSquaredDiff 中。
                 */
                double diff = a[i] - (double) S / n;
                totalSquaredDiff += diff * diff;
                remainingCost -= a[i];
                remainingPeople--;
            } else {
                /*
                 * 从此人开始，所有人都能支付当前的 avg，
                 * 他们每人付 avg，偏差 = avg - S/n = (remainingCost/remainingPeople) - S/n。
                 * 共有 remainingPeople 个人支付这个金额，
                 * 方差贡献为 remainingPeople × (avg - S/n)²。
                 * 计入后即可结束循环，后续所有人的支付方式相同。
                 */
                double diff = avg - (double) S / n;
                totalSquaredDiff += remainingPeople * diff * diff;
                break;
            }
        }

        /*
         * 标准差 = sqrt( (1/n) × Σ(bi - S/n)² )
         * 其中 S/n 是整体的平均支付金额。
         *
         * 题目保证正确答案在 ±10^-9 范围内不会影响四舍五入结果，
         * 因此 double 精度足够，直接使用 printf 格式化输出即可。
         */
        double stdDev = Math.sqrt(totalSquaredDiff / n);
        System.out.printf("%.4f%n", stdDev);
    }
}
