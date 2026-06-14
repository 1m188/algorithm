/*

机器人塔

X星球的机器人表演拉拉队有两种服装，A和B。
他们这次表演的是搭机器人塔。

类似：

     A
    B B
   A B A
  A A B B
 B B B A B
A B A B B A

队内的组塔规则是：
  
  A 只能站在 AA 或 BB 的肩上。
  B 只能站在 AB 或 BA 的肩上。

你的任务是帮助拉拉队计算一下，在给定A与B的人数时，可以组成多少种花样的塔。

输入一行两个整数 M 和 N，空格分开（0<M,N<500）,分别表示A、B的人数，保证人数合理性。

要求输出一个整数，表示可以产生的花样种数。

例如：
用户输入：
1 2

程序应该输出：
3


再例如：
用户输入：
3 3

程序应该输出：
4

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.Scanner;

public class _4 {
    static int M, N, H; // A的数量，B的数量，塔高
    static long ans = 0; // 方案数

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt();
        N = sc.nextInt();
        sc.close();

        // 由总人数反推塔高 H：H(H+1)/2 = M+N
        int total = M + N;
        H = (int) ((Math.sqrt(1.0 + 8.0 * total) - 1) / 2);

        // 从塔顶向塔底深度优先搜索。A编码为0，B编码为1。
        // 每行首元素可任取0/1，该行其余元素由上行唯一确定：
        // 下层[cur][j] = 下层[cur][j-1] XOR 上层[prev][j-1]
        dfs(0, 0L, 0);

        System.out.println(ans);
    }

    // r: 已构建的行数（同时也是下一行的长度-1），row: 上一行的位掩码，aCnt: 已使用的A(0)的数量
    static void dfs(int r, long row, int aCnt) {
        if (aCnt > M)
            return; // 剪枝：A的数量已超标
        if (r == H) {
            if (aCnt == M)
                ans++;
            return;
        }

        int len = r + 1; // 当前行长度
        long prevMask = row & ((1L << (len - 1)) - 1); // 上一行的有效位

        // 枚举当前行首元素
        for (int first = 0; first <= 1; first++) {
            long cur = first; // 当前行的位掩码（低位对应左边）
            int addA = (first == 0) ? 1 : 0; // 统计本行新增的A(0)数量

            for (int j = 1; j < len; j++) {
                // 规则：cur[j] = cur[j-1] XOR prev[j-1]
                int leftBit = (int) ((cur >> (j - 1)) & 1);
                int upBit = (int) ((prevMask >> (j - 1)) & 1);
                int bit = leftBit ^ upBit;
                cur |= ((long) bit << j);
                if (bit == 0)
                    addA++;
            }

            dfs(r + 1, cur, aCnt + addA);
        }
    }
}
