/*
标题：方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 就是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。


解题思路：
从中心点 (3,3) 出发，DFS 沿着格线对称裁剪。
方格 6×6 的格线交点坐标范围为 0~6。
中心对称条件：若某条边被剪开，则关于中心 (3,3) 对称的边也必须被剪开。
DFS 时同时标记当前点和对称点，保证两部分连通且分割线连续。
到达边界时找到一种分割方法。
由于每种分割被计 4 次（起点的 4 个方向），结果除以 4。
答案：509
*/
public class _4 {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static boolean[][] vis = new boolean[7][7];
    static int ans = 0;

    public static void main(String[] args) {
        vis[3][3] = true;
        dfs(3, 3);
        System.out.println(ans / 4);
    }

    static void dfs(int x, int y) {
        if (x == 0 || x == 6 || y == 0 || y == 6) {
            ans++;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            int sx = 6 - nx, sy = 6 - ny; // 对称点
            if (!vis[nx][ny]) {
                vis[nx][ny] = vis[sx][sy] = true;
                dfs(nx, ny);
                vis[nx][ny] = vis[sx][sy] = false;
            }
        }
    }
}
