/*

标题：全球变暖

你有一张某海域NxN像素的照片，"."表示海洋、"#"表示陆地，如下所示：

.......
.##....
.##....
....##.
..####.
...###.
.......

其中"上下左右"四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有2座岛屿。  

由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。  

例如上图中的海域未来会变成如下样子：

.......
.......
.......
.......
....#..
.......
.......

请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。  

【输入格式】
第一行包含一个整数N。  (1 <= N <= 1000)  
以下N行N列代表一张海域照片。  

照片保证第1行、第1列、第N行、第N列的像素都是海洋。  

【输出格式】
一个整数表示答案。


【输入样例】
7 
.......
.##....
.##....
....##.
..####.
...###.
.......  

【输出样例】
1  



资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。

*/

public class _8 {

    /**
     * 四个方向的偏移量：上、下、左、右，用于遍历相邻像素
     */
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    /**
     * 判断某个陆地像素是否与海洋相邻（即是否会因全球变暖而被淹没）
     *
     * @param grid 海域照片矩阵，'.'表示海洋，'#'表示陆地
     * @param x    当前像素的行坐标
     * @param y    当前像素的列坐标
     * @param n    矩阵的边长大小
     * @return true表示该陆地像素至少有一个方向相邻海洋，会被淹没；false表示四个方向全是陆地，不会被淹没
     */
    static boolean isAdjacentToOcean(char[][] grid, int x, int y, int n) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '.') {
                return true;
            }
        }
        return false;
    }

    /**
     * 使用广度优先搜索（BFS）遍历一座岛屿的所有陆地像素
     *
     * @param grid    海域照片矩阵
     * @param visited 已访问标记矩阵，避免重复访问
     * @param sx      起始陆地像素的行坐标
     * @param sy      起始陆地像素的列坐标
     * @param n       矩阵的边长大小
     * @return true表示该岛屿会被完全淹没（所有像素都与海洋相邻）；
     *         false表示该岛屿不会被完全淹没（至少有一个像素四面全是陆地，是岛屿的"内核"）
     */
    static boolean bfs(char[][] grid, boolean[][] visited, int sx, int sy, int n) {
        java.util.Queue<int[]> queue = new java.util.LinkedList<>();
        queue.offer(new int[] { sx, sy });
        visited[sx][sy] = true;

        /*
         * submergedCount: 岛屿中被淹没（与海洋相邻）的像素数量
         * totalCount: 岛屿中所有像素的总数量
         * 如果 submergedCount == totalCount，说明整座岛屿都被淹没
         */
        int submergedCount = 0;
        int totalCount = 0;

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int x = cell[0];
            int y = cell[1];
            totalCount++;

            if (isAdjacentToOcean(grid, x, y, n)) {
                submergedCount++;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n
                        && !visited[nx][ny] && grid[nx][ny] == '#') {
                    visited[nx][ny] = true;
                    queue.offer(new int[] { nx, ny });
                }
            }
        }

        /*
         * 如果岛屿中每个像素都与海洋相邻，则整座岛屿会被完全淹没
         * 否则，岛屿至少有一个"内核"像素不会被淹没，岛屿不会消失
         */
        return submergedCount == totalCount;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        char[][] grid = new char[n][n];

        for (int i = 0; i < n; i++) {
            grid[i] = scanner.next().toCharArray();
        }

        /*
         * visited矩阵用于标记已经访问过的陆地像素，
         * 避免在遍历不同岛屿时重复处理同一个像素
         */
        boolean[][] visited = new boolean[n][n];

        /*
         * completelySubmerged: 完全被淹没的岛屿数量
         * 遍历整个海域矩阵，每发现一座未被访问过的岛屿，
         * 就通过BFS遍历其所有像素，判断该岛屿是否会完全淹没
         */
        int completelySubmerged = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#' && !visited[i][j]) {
                    if (bfs(grid, visited, i, j, n)) {
                        completelySubmerged++;
                    }
                }
            }
        }

        System.out.println(completelySubmerged);
    }
}
