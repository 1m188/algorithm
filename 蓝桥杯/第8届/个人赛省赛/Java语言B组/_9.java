/*
标题：分巧克力

    儿童节那天有K位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。
    小明一共有N块巧克力，其中第i块是Hi x Wi的方格组成的长方形。

    为了公平起见，小明需要从这 N 块巧克力中切出K块巧克力分给小朋友们。切出的巧克力需要满足：

    1. 形状是正方形，边长是整数  
    2. 大小相同  

例如一块6x5的巧克力可以切出6块2x2的巧克力或者2块3x3的巧克力。

当然小朋友们都希望得到的巧克力尽可能大，你能帮小Hi计算出最大的边长是多少么？

输入
第一行包含两个整数N和K。(1 <= N, K <= 100000)  
以下N行每行包含两个整数Hi和Wi。(1 <= Hi, Wi <= 100000) 
输入保证每位小朋友至少能获得一块1x1的巧克力。   

输出
输出切出的正方形巧克力最大可能的边长。

样例输入：
2 10  
6 5  
5 6  

样例输出：
2

资源约定：峰值内存消耗 < 256M，CPU消耗 < 1000ms
主类的名字必须是：Main


解题思路：
二分边长 L，检查 Σ floor(Hi/L) × floor(Wi/L) ≥ K。
*/
import java.util.Scanner;

public class _9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int[] h = new int[n], w = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
            w[i] = sc.nextInt();
            max = Math.max(max, Math.max(h[i], w[i]));
        }
        sc.close();

        int lo = 1, hi = max, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >>> 1;
            if (check(h, w, mid, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        System.out.println(ans);
    }

    static boolean check(int[] h, int[] w, int side, int k) {
        long cnt = 0;
        for (int i = 0; i < h.length; i++) {
            cnt += (long) (h[i] / side) * (w[i] / side);
            if (cnt >= k) return true;
        }
        return false;
    }
}
