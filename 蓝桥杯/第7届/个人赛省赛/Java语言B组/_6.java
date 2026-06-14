/*
方格填数

如下的10个格子
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+

（如果显示有问题，也可以参看【图1.jpg】）

填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）

一共有多少种可能的填数方案？

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/
public class _6 {
    /** 10 个格子的 8 方向邻接关系。
     *  编号：
     *      0  1  2
     *    3  4  5  6
     *      7  8  9
     */
    static int[][] adj = {
        {1, 3, 4, 5},         // 0
        {0, 2, 4, 5, 6},      // 1
        {1, 5, 6},            // 2
        {0, 4, 7, 8},         // 3
        {0, 1, 3, 5, 7, 8, 9},// 4
        {0, 1, 2, 4, 6, 8, 9},// 5
        {1, 2, 5, 8, 9},      // 6
        {3, 4, 8},            // 7
        {3, 4, 5, 7, 9},      // 8
        {4, 5, 6, 8},         // 9
    };

    static int[] num = new int[10];
    static boolean[] used = new boolean[10];
    static int cnt = 0;

    public static void main(String[] args) {
        dfs(0);
        System.out.println(cnt);
    }

    /** 深度优先搜索填入第 pos 个格子 */
    static void dfs(int pos) {
        if (pos == 10) {
            cnt++;
            return;
        }
        for (int n = 0; n <= 9; n++) {
            if (used[n])
                continue;
            // 检查与已填入邻格是否相邻
            boolean ok = true;
            for (int nb : adj[pos]) {
                if (nb < pos) {                // 邻格已填入
                    if (Math.abs(num[nb] - n) == 1) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok)
                continue;
            num[pos] = n;
            used[n] = true;
            dfs(pos + 1);
            used[n] = false;
        }
    }
}
