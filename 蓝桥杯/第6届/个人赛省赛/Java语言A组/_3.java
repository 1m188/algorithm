/*
九数分三组

1~9的数字可以组成3个3位数，设为：A,B,C,  现在要求满足如下关系：
B = 2 * A
C = 3 * A

请你写出A的所有可能答案，数字间用空格分开，数字按升序排列。

注意：只提交A的值，严格按照格式要求输出。
*/

/*
 * 解题思路：
 * 9 个数字共 3! 种排列，将 1~9 分成 3 组三位数 A、B、C。
 * 检查 B == 2*A 且 C == 3*A。
 * A 的范围：100~329（3A ≤ 987），但不能有重复数字。
 * 枚举所有 1~9 的排列，或直接枚举 A 并检查。
 * 已知答案：192 219 273 327（升序排列）。
 */
public class _3 {
    public static void main(String[] args) {
        // 枚举 1~9 的所有排列
        int[] p = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        java.util.List<Integer> ans = new java.util.ArrayList<>();
        do {
            int A = p[0] * 100 + p[1] * 10 + p[2];
            int B = p[3] * 100 + p[4] * 10 + p[5];
            int C = p[6] * 100 + p[7] * 10 + p[8];
            if (B == 2 * A && C == 3 * A)
                ans.add(A);
        } while (nextPermutation(p));

        // 排序输出
        java.util.Collections.sort(ans);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) sb.append(" ");
            sb.append(ans.get(i));
        }
        System.out.println(sb);
    }

    static boolean nextPermutation(int[] a) {
        int i = a.length - 2;
        while (i >= 0 && a[i] >= a[i + 1]) i--;
        if (i < 0) return false;
        int j = a.length - 1;
        while (a[j] <= a[i]) j--;
        swap(a, i, j);
        for (int l = i + 1, r = a.length - 1; l < r; l++, r--)
            swap(a, l, r);
        return true;
    }

    static void swap(int[] a, int i, int j) {
        int t = a[i]; a[i] = a[j]; a[j] = t;
    }
}
