/*
四平方和

四平方和定理，又称为拉格朗日定理：
每个正整数都可以表示为至多4个正整数的平方和。
如果把0包括进去，就正好可以表示为4个数的平方和。

（同 Java语言B组 _8）
*/

import java.util.Scanner;

public class _9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();

        int max = (int) Math.sqrt(N);
        int[] first = new int[N + 1];
        int[] second = new int[N + 1];
        for (int i = 0; i <= N; i++)
            first[i] = -1;

        // 预存 c²+d² 的最小 c
        for (int c = 0; c <= max; c++) {
            int c2 = c * c;
            for (int d = c; d <= max; d++) {
                int sum = c2 + d * d;
                if (sum > N)
                    break;
                if (first[sum] == -1) {
                    first[sum] = c;
                    second[sum] = d;
                }
            }
        }

        // 枚举 a, b
        for (int a = 0; a <= max; a++) {
            int a2 = a * a;
            if (a2 > N)
                break;
            for (int b = a; b <= max; b++) {
                int ab = a2 + b * b;
                if (ab > N)
                    break;
                int rem = N - ab;
                if (first[rem] != -1) {
                    System.out.println(a + " " + b + " " + first[rem] + " " + second[rem]);
                    return;
                }
            }
        }
    }
}
