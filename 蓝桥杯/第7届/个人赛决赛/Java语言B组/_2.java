/*

反幻方

我国古籍很早就记载着

2 9 4
7 5 3
6 1 8

这是一个三阶幻方。每行每列以及对角线上的数字相加都相等。

下面考虑一个相反的问题。
可不可以用 1~9 的数字填入九宫格。
使得：每行每列每个对角线上的数字和都互不相等呢？


这应该能做到。
比如：
9 1 2
8 4 3
7 5 6

你的任务是搜索所有的三阶反幻方。并统计出一共有多少种。
旋转或镜像算同一种。

比如：
9 1 2
8 4 3
7 5 6

7 8 9
5 4 1
6 3 2

2 1 9
3 4 8
6 5 7

等都算作同一种情况。

请提交三阶反幻方一共多少种。这是一个整数，不要填写任何多余内容。


*/

import java.util.HashSet;

public class _2 {
    /**
     * 三重循环枚举加法器：将 [1..9] 的全排列逐一遍历，检查每种排列是否满足
     * “三行、三列、两条对角线的八个和全部互不相同”的条件。对满足条件的排列，
     * 计算其在正方形 D4 群（旋转 0°/90°/180°/270° 与镜像四种）作用下的
     * 字典序最小等价形式，加入 HashSet 去重。最终集合大小即为答案。
     */
    public static void main(String[] args) {
        int[] a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        HashSet<String> set = new HashSet<>(); // 存放规范形式（字典序最小者）

        do {
            // 计算三行和
            int r0 = a[0] + a[1] + a[2];
            int r1 = a[3] + a[4] + a[5];
            int r2 = a[6] + a[7] + a[8];
            // 计算三列和
            int c0 = a[0] + a[3] + a[6];
            int c1 = a[1] + a[4] + a[7];
            int c2 = a[2] + a[5] + a[8];
            // 计算两条对角线和
            int d0 = a[0] + a[4] + a[8];
            int d1 = a[2] + a[4] + a[6];

            // 八个和互不相等
            if (r0 == r1 || r0 == r2 || r0 == c0 || r0 == c1 || r0 == c2 ||
                    r0 == d0 || r0 == d1)
                continue;
            if (r1 == r2 || r1 == c0 || r1 == c1 || r1 == c2 || r1 == d0 ||
                    r1 == d1)
                continue;
            if (r2 == c0 || r2 == c1 || r2 == c2 || r2 == d0 || r2 == d1)
                continue;
            if (c0 == c1 || c0 == c2 || c0 == d0 || c0 == d1)
                continue;
            if (c1 == c2 || c1 == d0 || c1 == d1)
                continue;
            if (c2 == d0 || c2 == d1 || d0 == d1)
                continue;

            set.add(canonical(a));
        } while (nextPermutation(a));

        System.out.println(set.size());
    }

    /* ---------- 全排列生成（字典序下一个排列） ---------- */
    private static boolean nextPermutation(int[] a) {
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

    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static void reverse(int[] a, int l, int r) {
        while (l < r)
            swap(a, l++, r--);
    }

    /* ---------- D4 群规范形式 ---------- */
    /**
     * 索引映射（0..8 对应九宫格从左到右、从上到下）：
     * [0] [1] [2]
     * [3] [4] [5]
     * [6] [7] [8]
     *
     * 8 种变换由以下索引重排给出。
     */
    private static final int[][] D4 = {
            { 0, 1, 2, 3, 4, 5, 6, 7, 8 }, // 原样
            { 2, 5, 8, 1, 4, 7, 0, 3, 6 }, // 顺时针 90°
            { 8, 7, 6, 5, 4, 3, 2, 1, 0 }, // 顺时针 180°
            { 6, 3, 0, 7, 4, 1, 8, 5, 2 }, // 顺时针 270°
            { 2, 1, 0, 5, 4, 3, 8, 7, 6 }, // 左右镜像
            { 8, 5, 2, 7, 4, 1, 6, 3, 0 }, // 左右镜像 + 顺时针 90°
            { 6, 7, 8, 3, 4, 5, 0, 1, 2 }, // 左右镜像 + 顺时针 180°
            { 0, 3, 6, 1, 4, 7, 2, 5, 8 }, // 左右镜像 + 顺时针 270°
    };

    /** 返回 a 在 D4 群下字典序最小的排列（用逗号拼接成字符串）。 */
    private static String canonical(int[] a) {
        String best = null;
        for (int[] t : D4) {
            StringBuilder sb = new StringBuilder();
            for (int idx : t)
                sb.append(a[idx]).append(',');
            String s = sb.toString();
            if (best == null || s.compareTo(best) < 0)
                best = s;
        }
        return best;
    }
}
