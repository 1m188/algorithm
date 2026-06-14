/*
立方尾不变

有些数字的立方的末尾正好是该数字本身。
比如：1,4,5,6,9,24,25,....

请你计算一下，在10000以内的数字中（指该数字，并非它立方后的数值），符合这个特征的正整数一共有多少个。

请提交该整数，不要填写任何多余的内容。
*/

/*
 * 解题思路：
 * 对于每个 n < 10000，计算 n^3，检查 n^3 的末尾是否 = n。
 * n^3 % (10^len(n)) == n。
 */

public class _2 {
    public static void main(String[] args) {
        int count = 0;
        for (long n = 1; n < 10000; n++) {
            // 计算 n 的位数对应的 10^len
            long mod = 1;
            for (long tmp = n; tmp > 0; tmp /= 10)
                mod *= 10;
            if ((n * n * n) % mod == n)
                count++;
        }
        System.out.println(count);
    }
}
