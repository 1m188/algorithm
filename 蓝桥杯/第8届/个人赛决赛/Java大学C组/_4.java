/*

标题： 小数第n位

我们知道，整数做除法时，有时得到有


本题的任务是：在上面的约定下，求整数除法小数点后的第n位开始的3位数。

输入：
 一行三个整数：a b n，用空格分开。a是被除数，b是除数，n是所求的小数后位置（0<a,b,n<1000000000）
输出：
一行3位数字，表示：a除以b，小数后第n位开始的3位数字。

比如：
输入：
1 8 1

程序应该输出：
125

再比如：
输入：
1 8 3

程序应该输出：
500

再比如：
输入：
282866 999000 6

程序应该输出：
914

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

----------------------------------------
笨笨有话说：
    这个除法小学就会算啊，模拟手算除法的过程就可以了吧。
	只是数有点大啊....
	管它呢，能算多远算多远....
	
歪歪有话说：
    如果我能确定循环节从哪里开始到哪里结束，再大的数不过就是与它取模的余数等价啊
	
*/

import java.io.*;
import java.util.*;

public class _4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long n = Long.parseLong(st.nextToken());

        // 只需考虑 a mod b 的小数部分
        a %= b;

        // 计算 r = a * 10^(n-1) mod b
        // 小数后第 n 位相当于将 a 乘以 10^(n-1) 后除以 b 的小数首位
        long pow = fastPow(10, n - 1, b);
        long r = (a * pow) % b;

        // r / b 的小数前三位即为 r * 1000 / b 的整数部分
        long ans = r * 1000 / b;

        // 输出 3 位数字（含前导零）
        System.out.printf("%03d%n", ans);
    }

    /** 快速幂：计算 base^exp mod m */
    static long fastPow(long base, long exp, long mod) {
        long result = 1 % mod;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
}
