/*
 
标题：穿越雷区

X星的坦克战车很奇怪，它必须交替地穿越正能量辐射区和负能量辐射区才能保持正常运转，否则将报废。
某坦克需要从A区到B区去（A，B区本身是安全区，没有正能量或负能量特征），怎样走才能路径最短？

已知的地图是一个方阵，上面用字母标出了A，B区，其它区都标了正号或负号分别表示正负能量辐射区。
例如：
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -

坦克车只能水平或垂直方向上移动到相邻的区。

数据格式要求：

输入第一行是一个整数n，表示方阵的大小， 4<=n<100
接下来是n行，每行有n个数据，可能是A，B，+，-中的某一个，中间用空格分开。
A，B都只出现一次。

要求输出一个整数，表示坦克从A区到B区的最少移动步数。
如果没有方案，则输出-1

例如：
用户输入：
5
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -

则程序应该输出：
10

资源约定：
峰值内存消耗（含虚拟机） < 512M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。


*/

import java.util.*;

/**
 * 解法：BFS 最短路 + 正负能量交替约束
 *
 * 状态设计：(行, 列, 上一步类型)
 * 上一步类型：0 = 从A出发（无前驱），1 = 上一步是 '+'，2 = 上一步是 '-'
 *
 * 转移规则：
 * - 从 A（prev=0）：可踏入 '+' 或 '-'，更新 prev 为对应类型
 * - 从 '+'（prev=1）：必须踏入 '-'
 * - 从 '-'（prev=2）：必须踏入 '+'
 * - 到达 B 立即返回步数
 *
 * 使用三维 visited[n][n][3] 去重，BFS 保证首次到达 B 即为最短路。
 */
public class _4 {
    public static void main(String[] args) {
        Main.solve();
    }
}

class Main {
    static final int[][] DIRS = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        String[][] grid = new String[n][n];
        int startR = -1, startC = -1, endR = -1, endC = -1;

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine().trim();
            String[] parts = line.split(" ");
            for (int j = 0; j < n; j++) {
                grid[i][j] = parts[j];
                if (parts[j].equals("A")) {
                    startR = i;
                    startC = j;
                } else if (parts[j].equals("B")) {
                    endR = i;
                    endC = j;
                }
            }
        }
        sc.close();

        int ans = bfs(grid, n, startR, startC, endR, endC);
        System.out.println(ans);
    }

    static int bfs(String[][] grid, int n, int sr, int sc, int er, int ec) {
        // visited[i][j][k]: k=0 prev=none, k=1 prev='+', k=2 prev='-'
        boolean[][][] visited = new boolean[n][n][3];
        Queue<int[]> q = new LinkedList<int[]>();
        // 队列元素: {row, col, prevType, steps}
        // prevType: 0 = 从 A 出发, 1 = 上一步是 '+', 2 = 上一步是 '-'
        q.add(new int[] { sr, sc, 0, 0 });
        visited[sr][sc][0] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int r = cur[0], c = cur[1], prev = cur[2], steps = cur[3];

            for (int[] d : DIRS) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                    continue;
                }

                // 到达 B
                if (nr == er && nc == ec) {
                    return steps + 1;
                }

                String cell = grid[nr][nc];

                if (prev == 0) {
                    // 从 A 出发：可踏入 '+' 或 '-'
                    if (cell.equals("+") && !visited[nr][nc][1]) {
                        visited[nr][nc][1] = true;
                        q.add(new int[] { nr, nc, 1, steps + 1 });
                    } else if (cell.equals("-") && !visited[nr][nc][2]) {
                        visited[nr][nc][2] = true;
                        q.add(new int[] { nr, nc, 2, steps + 1 });
                    }
                } else if (prev == 1 && cell.equals("-") && !visited[nr][nc][2]) {
                    // 上一步是 '+'，必须踏入 '-'
                    visited[nr][nc][2] = true;
                    q.add(new int[] { nr, nc, 2, steps + 1 });
                } else if (prev == 2 && cell.equals("+") && !visited[nr][nc][1]) {
                    // 上一步是 '-'，必须踏入 '+'
                    visited[nr][nc][1] = true;
                    q.add(new int[] { nr, nc, 1, steps + 1 });
                }
            }
        }

        return -1;
    }
}
