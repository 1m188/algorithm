/*
奇妙的数字

小明发现了一个奇妙的数字。它的平方和立方正好把0~9的10个数字每个用且只用了一次。
你能猜出这个数字是多少吗？

请填写该数字，不要填写任何多余的内容。
*/

/*
 * 解题思路：
 * 设该数字为 n。n² 和 n³ 的各位数字合在一起恰好包含 0~9 各一次。
 * n² 与 n³ 合并后总位数必为 10。
 * n < 100（n=100 时 n²=10000 已有 5 位，n³=1000000 有 7 位，总 12 位 > 10）。
 * 枚举 1~99，检查 n² + n³ 的字符串是否包含 0~9 各一次。
 * 答案：n=69（69²=4761, 69³=328509 → 4761328509 包含 0~9 各一次）。
 */

public class _6 {
    public static void main(String[] args) {
        for (int n = 1; n < 100; n++) {
            String s = String.valueOf(n * n) + String.valueOf(n * n * n);
            if (s.length() != 10)
                continue;
            int[] cnt = new int[10];
            for (int i = 0; i < s.length(); i++)
                cnt[s.charAt(i) - '0']++;
            boolean ok = true;
            for (int i = 0; i < 10; i++)
                if (cnt[i] != 1) { ok = false; break; }
            if (ok) {
                System.out.println(n);
                return;
            }
        }
    }
}
