/*
标题：k倍区间

给定一个长度为N的数列，A1, A2, ... AN，如果其中一段连续的子序列Ai, Ai+1, ... Aj(i <= j)之和是K的倍数，我们就称这个区间[i, j]是K倍区间。  

你能求出数列中总共有多少个K倍区间吗？  

输入
第一行包含两个整数N和K。(1 <= N, K <= 100000)  
以下N行每行包含一个整数Ai。(1 <= Ai <= 100000)  

输出
输出一个整数，代表K倍区间的数目。  

例如，
输入：
5 2
1  
2  
3  
4  
5  

程序应该输出：
6

资源约定：峰值内存消耗 < 256M，CPU消耗 < 2000ms
主类的名字必须是：Main


解题思路：
前缀和 + 同余计数。
pref[i] = (A1 + ... + Ai) % K。
区间 [l, r] 的和 % K = (pref[r] - pref[l-1]) % K = 0
⇔ pref[r] ≡ pref[l-1] (mod K)

统计各余数出现次数 cnt[r]，答案 = Σ C(cnt[r], 2)。
特别地 cnt[0] 中的每个前缀自身也构成 k 倍区间，
所以先 cnt[0]++ 或将公式调整为 cnt[r]×(cnt[r]-1)/2。
*/
import java.util.Scanner;

public class _10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        long[] cnt = new long[k];
        cnt[0] = 1; // 空前缀和 ≡ 0
        long pref = 0;
        for (int i = 0; i < n; i++) {
            pref = (pref + sc.nextInt()) % k;
            cnt[(int) pref]++;
        }
        sc.close();

        long ans = 0;
        for (int r = 0; r < k; r++)
            ans += cnt[r] * (cnt[r] - 1) / 2;
        System.out.println(ans);
    }
}
