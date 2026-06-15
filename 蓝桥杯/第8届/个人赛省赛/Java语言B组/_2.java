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


解题思路：
9 个位置排列成三角形：
   0
  1 2
 3   4
5 6 7 8
三条边（各 4 个位置）：
  左: [0,1,3,5]  右: [0,2,4,8]  底: [5,6,7,8]
要求三边和相等。

枚举 1~9 的全排列填入 9 个位置，检查边和。
考虑旋转和镜像（D3 群，共 6 种对称）去重：
  旋转 R120: [5,6,3,7,1,8,4,2,0]（位置映射表）
  旋转 R240: R120 两次复合
  镜像 M0（关于顶点 0 的中垂线）: [0,2,1,4,3,8,7,6,5]
总去重后数 ÷ 6 → 答案。
*/
public class _2 {
    // 三条边的位置索引
    static int[][] sides = {
        {0, 1, 3, 5}, // 左边
        {0, 2, 4, 8}, // 右边
        {5, 6, 7, 8}, // 底边
    };

    // R120 旋转的逆置换：rotArr[j] = origArr[invR120[j]]
    static int[] invR120 = {8, 4, 7, 2, 6, 0, 1, 3, 5};
    // R240 = R120∘R120 的逆置换
    static int[] invR240 = {5, 6, 3, 7, 1, 8, 4, 2, 0};
    // M0 镜像的逆置换（关于顶点0的中垂线自逆）
    static int[] invM0   = {0, 2, 1, 4, 3, 8, 7, 6, 5};

    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        java.util.Set<String> set = new java.util.HashSet<>();
        do {
            if (!check(a))
                continue;
            set.add(canonical(a));
        } while (nextPerm(a));
        System.out.println(set.size());
    }

    static boolean check(int[] a) {
        int s0 = a[0] + a[1] + a[3] + a[5];
        int s1 = a[0] + a[2] + a[4] + a[8];
        int s2 = a[5] + a[6] + a[7] + a[8];
        return s0 == s1 && s1 == s2;
    }

    // 对 6 种对称取最小排列
    static String canonical(int[] a) {
        int[] best = a.clone();
        // R120
        int[] r1 = apply(a, invR120);
        if (less(r1, best)) best = r1;
        // R240
        int[] r2 = apply(a, invR240);
        if (less(r2, best)) best = r2;
        // M0
        int[] m0 = apply(a, invM0);
        if (less(m0, best)) best = m0;
        // R120+M0: 先 R120 再 M0
        int[] r1m = apply(apply(a, invR120), invM0);
        if (less(r1m, best)) best = r1m;
        // R240+M0: 先 R240 再 M0
        int[] r2m = apply(apply(a, invR240), invM0);
        if (less(r2m, best)) best = r2m;
        return toString(best);
    }

    static int[] apply(int[] a, int[] inv) {
        int[] b = new int[9];
        for (int i = 0; i < 9; i++)
            b[i] = a[inv[i]];
        return b;
    }

    static boolean less(int[] a, int[] b) {
        for (int i = 0; i < 9; i++) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
        }
        return false;
    }

    static String toString(int[] a) {
        StringBuilder sb = new StringBuilder(9);
        for (int v : a) sb.append((char)('0' + v));
        return sb.toString();
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
