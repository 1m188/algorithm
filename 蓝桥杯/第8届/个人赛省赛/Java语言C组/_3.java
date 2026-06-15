/*
标题：纸牌三角形

A,2,3,4,5,6,7,8,9 共9张纸牌排成一个正三角形（A按1计算）。要求每个边的和相等。
下图就是一种排法（如有对齐问题，参看p1.png）。

      A
     9 6
    4   8
   3 7 5 2

这样的排法可能会有很多。

如果考虑旋转、镜像后相同的算同一种，一共有多少种不同的排法呢？

请你计算并提交该数字。

注意：需要提交的是一个整数，不要提交任何多余内容。


解题思路：
9 个位置：   0
           1 2
          3   4
         5 6 7 8
三边: 左[0,1,3,5]  右[0,2,4,8]  底[5,6,7,8]
枚举 1~9 全排列，检查三边和相等。
用 D3 群（6 种对称）去重得到不同排法数。
答案：144
*/
public class _3 {
    static int[] invR120 = {8, 4, 7, 2, 6, 0, 1, 3, 5};
    static int[] invR240 = {5, 6, 3, 7, 1, 8, 4, 2, 0};
    static int[] invM0   = {0, 2, 1, 4, 3, 8, 7, 6, 5};

    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        java.util.Set<String> set = new java.util.HashSet<>();
        do {
            if (a[0]+a[1]+a[3]+a[5] == a[0]+a[2]+a[4]+a[8]
             && a[0]+a[2]+a[4]+a[8] == a[5]+a[6]+a[7]+a[8])
                set.add(canonical(a));
        } while (nextPerm(a));
        System.out.println(set.size());
    }

    static String canonical(int[] a) {
        int[] best = a.clone();
        int[][] invs = {invR120, invR240, invM0};
        // identity, rotate, reflect
        for (int[] inv : invs) {
            int[] t = apply(a, inv);
            if (less(t, best)) best = t;
        }
        // compose R120+R120 = R240 already covered
        // compose R120+M0 and R240+M0
        int[] r1 = apply(a, invR120);
        int[] r1m = apply(r1, invM0);
        if (less(r1m, best)) best = r1m;
        int[] r2 = apply(a, invR240);
        int[] r2m = apply(r2, invM0);
        if (less(r2m, best)) best = r2m;
        StringBuilder sb = new StringBuilder();
        for (int v : best) sb.append((char)('0'+v));
        return sb.toString();
    }

    static int[] apply(int[] a, int[] inv) {
        int[] b = new int[9];
        for (int i = 0; i < 9; i++) b[i] = a[inv[i]];
        return b;
    }

    static boolean less(int[] a, int[] b) {
        for (int i = 0; i < 9; i++) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
        }
        return false;
    }

    static boolean nextPerm(int[] a) {
        int i = a.length - 2;
        while (i >= 0 && a[i] >= a[i + 1]) i--;
        if (i < 0) return false;
        int j = a.length - 1;
        while (a[j] <= a[i]) j--;
        swap(a, i, j);
        reverse(a, i + 1, a.length - 1);
        return true;
    }

    static void swap(int[] a, int i, int j) { int t = a[i]; a[i] = a[j]; a[j] = t; }
    static void reverse(int[] a, int l, int r) { while (l < r) swap(a, l++, r--); }
}
