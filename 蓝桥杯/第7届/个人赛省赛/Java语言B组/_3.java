/*
凑算式

     B      DEF
A + --- + ------- = 10
     C      GHI
     
（如果显示有问题，可以参见【图1.jpg】）
	 
这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。

这个算式一共有多少种解法？

注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。
*/
public class _3 {
    static int cnt = 0;

    public static void main(String[] args) {
        int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        // 枚举 1~9 的全排列，A=a[0], B=a[1], C=a[2], D=a[3], E=a[4], F=a[5],
        // G=a[6], H=a[7], I=a[8]
        // 算式：A + B/C + (D*100+E*10+F)/(G*100+H*10+I) = 10
        do {
            int A = a[0], B = a[1], C = a[2];
            int D = a[3], E = a[4], F = a[5];
            int G = a[6], H = a[7], I = a[8];
            int DEF = D * 100 + E * 10 + F;
            int GHI = G * 100 + H * 10 + I;
            // 交叉相乘避免浮点误差：B*GHI + DEF*C == (10-A)*C*GHI
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
    static void reverse(int[] a, int l, int r) {
        while (l < r) swap(a, l++, r--);
    }
}
