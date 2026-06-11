/*

标题：平方十位数

由0~9这10个数字不重复、不遗漏，可以组成很多10位数字。
这其中也有很多恰好是平方数（是某个数的平方）。

比如：1026753849，就是其中最小的一个平方数。

请你找出其中最大的一个平方数是多少？

注意：你需要提交的是一个10位数字，不要填写任何多余内容。

*/

public class _1 {
    public static void main(String[] args) {
        // 最小已知解为 1026753849，其平方根约为 32043
        // 最大可能 10 位数为 9876543210，平方根约为 99380
        long low = (long) Math.sqrt(1026753849L);
        long high = (long) Math.sqrt(9876543210L);

        // 从大到小遍历，第一个符合条件的即为最大平方数
        for (long i = high; i >= low; i--) {
            long sq = i * i;

            // 检查是否包含 0~9 各恰好一次
            int[] cnt = new int[10];
            long t = sq;
            for (int d = 0; d < 10; d++) {
                cnt[(int) (t % 10)]++;
                t /= 10;
            }

            boolean ok = true;
            for (int d = 0; d < 10; d++) {
                if (cnt[d] != 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                System.out.println(sq);
                break;
            }
        }
    }
}
