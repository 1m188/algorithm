/*
凑算式

     B      DEF
A + --- + ------- = 10
     C      GHI

（同 Java语言B组 _3）
*/
public class _6 {
    static int cnt = 0;

    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        do {
            int A = a[0], B = a[1], C = a[2];
            int D = a[3], E = a[4], F = a[5];
            int G = a[6], H = a[7], I = a[8];
            int DEF = D * 100 + E * 10 + F;
            int GHI = G * 100 + H * 10 + I;
            if (B * GHI + DEF * C == (10 - A) * C * GHI)
                cnt++;
        } while (nextPerm(a));
        System.out.println(cnt);
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
