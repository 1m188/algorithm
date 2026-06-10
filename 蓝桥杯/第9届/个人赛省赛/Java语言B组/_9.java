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

import java.util.*;

public class _9 {

    /* 地图大小 */
    static int N;
    /* 海域照片，'.' 表示海洋，'#' 表示陆地 */
    static char[][] grid;
    /* 访问标记，防止重复遍历 */
    static boolean[][] visited;
    /* 四个方向（上、下、左、右）的行偏移量 */
    static int[] dx = { -1, 1, 0, 0 };
    /* 四个方向（上、下、左、右）的列偏移量 */
    static int[] dy = { 0, 0, -1, 1 };

    /**
     * 全球变暖
     *
     * 核心思路：
     * 1. 使用 BFS 遍历每一座岛屿。
     * 2. 在遍历过程中，检查岛屿中是否存在"内陆"像素——
     * 即上下左右四个相邻位置全都是陆地（'#'）的像素。
     * 3. 如果某个岛屿没有任何内陆像素（全部像素均为沿海），
     * 则该岛屿会被完全淹没，答案加一。
     * 4. 若岛屿存在至少一个内陆像素，该像素不会被淹没，
     * 岛屿就不会被完全淹没。
     *
     * 正确性说明：
     * - 沿海像素：上下左右四个方向中至少有一个方向是海洋（'.'）
     * → 会被海水淹没。
     * - 内陆像素：上下左右四个方向全都是陆地（'#'）
     * → 不会被淹没，岛屿至少有一块陆地保留。
     * - 因此，岛屿被完全淹没 ⇔ 岛屿中不存在内陆像素。
     *
     * 时间复杂度：O(N²)，每个格子仅被访问一次。
     * 空间复杂度：O(N²)，用于 visited 数组和 BFS 队列。
     */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        /* 读取地图尺寸 */
        N = sc.nextInt();
        grid = new char[N][N];
        visited = new boolean[N][N];

        /* 逐行读取海域照片 */
        for (int i = 0; i < N; i++) {
            String line = sc.next();
            grid[i] = line.toCharArray();
        }
        sc.close();

        /* 记录完全淹没的岛屿数量 */
        int submergedCount = 0;

        /* 扫描整个地图，寻找未访问的陆地（新岛屿的起点） */
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '#' && !visited[i][j]) {
                    /*
                     * 发现一座新的岛屿，使用 BFS 遍历该岛屿。
                     * 若岛屿中没有内陆像素，则计入答案。
                     */
                    if (!bfsHasInland(i, j)) {
                        submergedCount++;
                    }
                }
            }
        }

        System.out.println(submergedCount);
    }

    /**
     * 使用广度优先搜索（BFS）遍历从 (startX, startY) 开始的整座岛屿，
     * 并判断该岛屿是否包含内陆像素。
     *
     * 采用 BFS 而非 DFS 的原因：
     * 地图尺寸最大为 1000×1000，最坏情况下岛屿可能包含约 10⁶ 个像素，
     * DFS 递归深度可能超过 JVM 栈容量导致 StackOverflowError。
     * BFS 使用显式队列，无递归栈溢出风险。
     *
     * @param startX 岛屿起点的行坐标
     * @param startY 岛屿起点的列坐标
     * @return true 表示岛屿中存在内陆像素（不会被完全淹没）；
     *         false 表示岛屿中所有像素均为沿海（会被完全淹没）。
     */
    static boolean bfsHasInland(int startX, int startY) {
        /*
         * 使用两个同步队列分别存储待访问格子的行坐标和列坐标，
         * 等价于 Queue<int[]> 但无需 Java 5 泛型数组。
         */
        Queue<Integer> qx = new LinkedList<Integer>();
        Queue<Integer> qy = new LinkedList<Integer>();

        qx.add(startX);
        qy.add(startY);
        visited[startX][startY] = true;

        boolean hasInlandPixel = false;

        while (!qx.isEmpty()) {
            int x = qx.poll().intValue();
            int y = qy.poll().intValue();

            /*
             * 判断当前像素是否为内陆像素：
             * 上下左右四个方向全都是陆地（'#'）。
             *
             * 注意：由于题目保证地图边界为海洋，
             * 陆地像素不会出现在 (0,*), (*,0), (N-1,*), (*,N-1) 位置，
             * 因此无需额外判断越界。
             */
            boolean isInland = true;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (grid[nx][ny] == '.') {
                    isInland = false;
                    break;
                }
            }
            if (isInland) {
                hasInlandPixel = true;
            }

            /*
             * 向四个方向扩展 BFS，将相邻未访问的陆地加入队列。
             */
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                /* 边界内的陆地且未访问过 */
                if (nx >= 0 && nx < N && ny >= 0 && ny < N
                        && grid[nx][ny] == '#' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    qx.add(nx);
                    qy.add(ny);
                }
            }
        }

        /*
         * 返回值含义：hasInlandPixel == true 表示该岛屿有内陆像素，不会被完全淹没；
         * hasInlandPixel == false 表示全部海水，会被完全淹没。
         * 函数命名为 bfsHasInland 以表达"是否存在内陆"的语义。
         * 调用处取反后累加。
         */
        return hasInlandPixel;
    }
}
