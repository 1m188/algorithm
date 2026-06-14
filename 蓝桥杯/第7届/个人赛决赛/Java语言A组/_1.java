/*
 * 
 * 阶乘位数
 * 
 * 9的阶乘等于：362880
 * 它的二进制表示为：1011000100110000000
 * 这个数字共有19位。
 * 
 * 请你计算，9999 的阶乘的二进制表示一共有多少位？
 * 
 * 注意：需要提交的是一个整数，不要填写任何无关内容（比如说明解释等）
 * 
 */

public class _1 {
    public static void main(String[] args) {
        // 二进制位数 = floor(log2(N!)) + 1 = floor(sum_{i=1}^{N} log2(i)) + 1
        double sum = 0.0;
        for (int i = 1; i <= 9999; i++) {
            sum += Math.log(i) / Math.log(2.0);
        }
        // 对于正数，(int)截断等价于 floor，因此 floor(sum) + 1 = (int)sum + 1
        System.out.println((int) sum + 1);
    }
}
