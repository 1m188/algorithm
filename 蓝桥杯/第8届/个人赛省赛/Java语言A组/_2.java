/*
标题：9数算式

观察如下的算式：

9213 x 85674 = 789314562

左边的乘数和被乘数正好用到了1~9的所有数字，每个1次。
而乘积恰好也是用到了1~9的所有数字，并且每个1次。

请你借助计算机的强大计算能力，找出满足如上要求的9数算式一共有多少个？

注意：
1. 总数目包含题目给出的那个示例。
2. 乘数和被乘数交换后作为同一方案来看待。


解题思路：
枚举 1~9 的全排列，分割成两部分 a（k 位）和 b（9-k 位）。
计算 c = a × b，检查 c 是否也使用了 1~9 各一次（共 9 位）。
乘数被乘数交换算同一方案，用 Set 去重。
*/
import java.util.*;

public class _2 {
    public static void main(String[] args) {
        int[] d = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        Set<Long> set = new HashSet<>();
        do {
            for (int k = 1; k <= 4; k++) { // 第一个数的位数
                long a = 0;
                for (int i = 0; i < k; i++)
                    a = a * 10 + d[i];
                long b = 0;
                for (int i = k; i < 9; i++)
                    b = b * 10 + d[i];
                long c = a * b;
                if (c < 123456789 || c > 987654321)
                    continue;
                if (check(c)) {
                    long key = Math.min(a, b) * 10000000000L + Math.max(a, b);
                    set.add(key);
                }
            }
        } while (nextPerm(d));
        System.out.println(set.size());
    }

    static boolean check(long n) {
        if (n < 100000000 || n > 999999999)
            return false;
        boolean[] has = new boolean[10];
        while (n > 0) {
            int d = (int) (n % 10);
            if (d == 0 || has[d])
                return false;
            has[d] = true;
            n /= 10;
        }
        return true;
    }

    static boolean nextPerm(int[] a) {
        int i = a.length - 2;
        while (i >= 0 && a[i] >= a[i + 1])
            i--;
        if (i < 0)
            return false;
        int j = a.length - 1;
        while (a[j] <= a[i])
            j--;
        swap(a, i, j);
        reverse(a, i + 1, a.length - 1);
        return true;
    }

    static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    static void reverse(int[] a, int l, int r) {
        while (l < r) {
            swap(a, l, r);
            l++;
            r--;
        }
    }
}
