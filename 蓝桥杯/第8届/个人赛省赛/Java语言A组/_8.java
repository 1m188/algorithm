/*
标题：包子凑数

小明几乎每天早晨都会在一家包子铺吃早餐。他发现这家包子铺有N种蒸笼，其中第i种蒸笼恰好能放Ai个包子。每种蒸笼都有非常多笼，可以认为是无限笼。

每当有顾客想买X个包子，卖包子的大叔就会迅速选出若干笼包子来，使得这若干笼中恰好一共有X个包子。比如一共有3种蒸笼，分别能放3、4和5个包子。当顾客想买11个包子时，大叔就会选2笼3个的再加1笼5个的（也可能选出1笼3个的再加2笼4个的）。

当然有时包子大叔无论如何也凑不出顾客想买的数量。比如一共有3种蒸笼，分别能放4、5和6个包子。而顾客想买7个包子时，大叔就凑不出来了。

小明想知道一共有多少种数目是包子大叔凑不出来的。

输入
第一行包含一个整数N。(1 <= N <= 100)
以下N行每行包含一个整数Ai。(1 <= Ai <= 100)  

输出
一个整数代表答案。如果凑不出的数目有无限多个，输出INF。

例如，
输入：
2  
4  
5   

程序应该输出：
6  

再例如，
输入：
2  
4  
6    

程序应该输出：
INF

样例解释：
对于样例1，凑不出的数目包括：1, 2, 3, 6, 7, 11。  
对于样例2，所有奇数都凑不出来，所以有无限多个。  

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


解题思路：
本质上是有无解整数线性组合问题。
如果所有 Ai 的最大公约数 gcd ≠ 1，则有无穷多数凑不出 → INF。
否则，用完全背包 DP 统计不可达的数。
根据扩展欧几里得，当 gcd=1 时，最大不可凑数 < Ai_max²（经验上界 100×100=10000）。
对 1~10000 做布尔 DP，统计 dp[i]=false 的个数。
*/
import java.util.Scanner;

public class _8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int g = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            g = gcd(g, a[i]);
        }
        sc.close();

        if (g != 1) {
            System.out.println("INF");
            return;
        }

        // 上界取 Ai 最大值附近的合理值
        int maxA = 0;
        for (int v : a)
            if (v > maxA)
                maxA = v;
        int bound = maxA * maxA; // 不超过 10000
        boolean[] dp = new boolean[bound + 1];
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = a[i]; j <= bound; j++) {
                if (dp[j - a[i]])
                    dp[j] = true;
            }
        }

        int ans = 0;
        for (int j = 1; j <= bound; j++) {
            if (!dp[j])
                ans++;
        }
        System.out.println(ans);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
