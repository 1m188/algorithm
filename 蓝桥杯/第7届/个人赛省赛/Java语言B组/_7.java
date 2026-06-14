/*
剪邮票

如【图1.jpg】, 有12张连在一起的12生肖的邮票。
现在你要从中剪下5张来，要求必须是连着的。
（仅仅连接一个角不算相连）
比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。

请你计算，一共有多少种不同的剪取方法。

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/
public class _7 {
    /** 12 张邮票排列为 3 行 × 4 列，位置编号：
     *   0  1  2  3
     *   4  5  6  7
     *   8  9 10 11
     */
    static int R = 3, C = 4;
    static int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}}; // 上下左右四方向

    static int cnt = 0;
    static int[] chosen = new int[5];        // 选中的 5 张邮票编号

    public static void main(String[] args) {
        // 从 12 张中选 5 张，检查是否连通
        comb(0, 0);
        System.out.println(cnt);
    }

    /** 组合枚举：从 start 开始选第 dep 张（已选 dep 张） */
    static void comb(int start, int dep) {
        if (dep == 5) {
            if (connected())
                cnt++;
            return;
        }
        // 剩余的 12-start 张中还需选 5-dep 张
        for (int i = start; i <= 12 - (5 - dep); i++) {
            chosen[dep] = i;
            comb(i + 1, dep + 1);
        }
    }

    /** 检查 chosen 中的 5 个格子是否四连通 */
    static boolean connected() {
        boolean[] inSet = new boolean[12];
        for (int c : chosen)
            inSet[c] = true;

        // 从第一个选中格子开始 BFS
        boolean[] vis = new boolean[12];
        int[] queue = new int[5];
        int head = 0, tail = 0;
        queue[tail++] = chosen[0];
        vis[chosen[0]] = true;
        while (head < tail) {
            int cur = queue[head++];
            int r = cur / C, c = cur % C;
            for (int[] d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                    continue;
                int next = nr * C + nc;
                if (inSet[next] && !vis[next]) {
                    vis[next] = true;
                    queue[tail++] = next;
                }
            }
        }
        return tail == 5;                  // 5 个全部访问到即为连通
    }
}
