/*
标题：Excel地址

Excel单元格的地址表示很有趣，它使用字母来表示列号。
比如，
A表示第1列，
B表示第2列，
Z表示第26列，
AA表示第27列，
AB表示第28列，
BA表示第53列，
....

当然Excel的最大列号是有限度的，所以转换起来不难。
如果我们想把这种表示法一般化，可以把很大的数字转换为很长的字母序列呢？

本题目既是要求对输入的数字, 输出其对应的Excel地址表示方式。

例如，
输入：26 → 输出：Z
输入：2054 → 输出：BZZ

我们约定，输入的整数范围[1,2147483647]

资源约定：峰值内存消耗 < 256M，CPU消耗 < 1000ms
主类的名字必须是：Main


解题思路：
1-indexed 26 进制转换（没有 0，1→A, 26→Z, 27→AA）。
循环：n-- 转为 0-indexed，加上 'A'，n /= 26，最后反转。
*/
import java.util.Scanner;

public class _7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            n--; // 转为 0-indexed
            sb.append((char) ('A' + n % 26));
            n /= 26;
        }
        System.out.println(sb.reverse().toString());
    }
}
