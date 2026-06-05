/*

标题：整理玩具

小明有一套玩具，一共包含NxM个部件。这些部件摆放在一个包含NxM个小格子的玩具盒中，每个小格子中恰好摆放一个部件。

每一个部件上标记有一个0~9的整数，有可能有多个部件标记相同的整数。

小明对玩具的摆放有特殊的要求：标记相同整数的部件必须摆在一起，组成一个矩形形状。

如以下摆放是满足要求的：

00022
00033
44444

12244
12244
12233

01234
56789

以下摆放不满足要求：

11122
11122
33311

111111
122221
122221
111111

11122
11113
33333

给出一种摆放方式，请你判断是否符合小明的要求。

输入
----
输入包含多组数据。
第一行包含一个整数T，代表数据组数。 (1 <= T <= 10)
以下包含T组数据。
每组数据第一行包含两个整数N和M。  (1 <= N, M <= 10)
以下包含N行M列的矩阵，代表摆放方式。

输出
---
对于每组数据，输出YES或者NO代表是否符合小明的要求。

【样例输入】
3
3 5
00022
00033
44444
3 5
11122
11122
33311
2 5
01234
56789

【样例输出】
YES
NO
YES


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.Scanner;

public class _4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            char[][] grid = new char[N][M];
            for (int i = 0; i < N; i++) {
                String line = sc.next();
                grid[i] = line.toCharArray();
            }
            System.out.println(check(grid, N, M) ? "YES" : "NO");
        }
        sc.close();
    }

    static boolean check(char[][] grid, int N, int M) {
        for (char d = '0'; d <= '9'; d++) {
            int minR = N, maxR = -1, minC = M, maxC = -1;
            // 找出数字 d 出现的最小/最大行列
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (grid[i][j] == d) {
                        if (i < minR)
                            minR = i;
                        if (i > maxR)
                            maxR = i;
                        if (j < minC)
                            minC = j;
                        if (j > maxC)
                            maxC = j;
                    }
                }
            }
            if (maxR == -1)
                continue; // 该数字未出现，跳过
            // 检查包围盒内是否全部都是数字 d
            for (int i = minR; i <= maxR; i++) {
                for (int j = minC; j <= maxC; j++) {
                    if (grid[i][j] != d)
                        return false;
                }
            }
        }
        return true;
    }
}
