/*
立方变自身

观察下面的现象,某个数字的立方，按位累加仍然等于自身。
1^3 = 1 
8^3  = 512    5+1+2=8
17^3 = 4913   4+9+1+3=17
...

请你计算包括1,8,17在内，符合这个性质的正整数一共有多少个？

请填写该数字，不要填写任何多余的内容或说明性的文字。
*/

/*
 * 解题思路：
 * 对于正整数 n，计算 n^3 的各位数字之和，判断是否等于 n。
 * n 的上界：设 n^3 有 k 位，则各位和 ≤ 9k = 9*ceil(3*log10(n))。
 * 要使 n ≤ 9*(3*log10(n)+1)，n ≈ 100 时右边 ≈ 63。n ≈ 60 时 ≈ 54。
 * 所以 n 最大不超过两位数（实际验证 n<100）。
 * 逐位求和枚举即可。
 */

public class _2 {
    public static void main(String[] args) {
        int count = 0;
        for (int n = 1; n < 100; n++) {
            long cube = (long) n * n * n;
            // 求各位数字之和
            int sum = 0;
            long tmp = cube;
            while (tmp > 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
            if (sum == n)
                count++;
        }
        System.out.println(count);
    }
}
