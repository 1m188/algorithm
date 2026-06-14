/*

路径之谜

小明冒充X星球的骑士，进入了一个奇怪的城堡。
城堡里边什么都没有，只有方形石头铺成的地面。

假设城堡地面是 n x n 个方格。【如图1.png】所示。

按习俗，骑士要从西北角走到东南角。
可以横向或纵向移动，但不能斜着走，也不能跳跃。
每走到一个新方格，就要向正北方和正西方各射一箭。
（城堡的西墙和北墙内各有 n 个靶子）


同一个方格只允许经过一次。但不必做完所有的方格。

如果只给出靶子上箭的数目，你能推断出骑士的行走路线吗？

有时是可以的，比如图1.png中的例子。

本题的要求就是已知箭靶数字，求骑士的行走路径（测试数据保证路径唯一）

输入：
第一行一个整数N(0<N<20)，表示地面有 N x N 个方格
第二行N个整数，空格分开，表示北边的箭靶上的数字（自西向东）
第三行N个整数，空格分开，表示西边的箭靶上的数字（自北向南）

输出：
一行若干个整数，表示骑士路径。

为了方便表示，我们约定每个小格子用一个数字代表，从西北角开始编号: 0,1,2,3....
比如，图1.png中的方块编号为：

0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15


示例：
用户输入：
4
2 4 3 4
4 3 3 3

程序应该输出：
0 4 5 1 2 3 7 11 10 9 13 14 15



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
    static int N; // 棋盘大小
    static int[] north; // 北墙箭靶（每列）
    static int[] west; // 西墙箭靶（每行）
    static boolean[][] vis; // 访问标记
    static int[] path; // 当前路径
    static int pathLen; // 路径实际长度
    static int[][] dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; // 右下左上
    static boolean found = false; // 是否已找到解

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        north = new int[N];
        west = new int[N];
        for (int j = 0; j < N; j++)
            north[j] = sc.nextInt();
        for (int i = 0; i < N; i++)
            west[i] = sc.nextInt();
        sc.close();

        vis = new boolean[N][N];
        path = new int[N * N];

        // 从西北角 (0,0) 出发
        vis[0][0] = true;
        north[0]--;
        west[0]--;
        path[0] = 0;
        dfs(0, 0, 1);

        // 输出找到的路径
        for (int i = 0; i < pathLen; i++)
            System.out.print(path[i] + (i + 1 < pathLen ? " " : "\n"));
    }

    /** 深度优先搜索，从 (x,y) 出发，已访问 step 个格子 */
    static void dfs(int x, int y, int step) {
        if (found)
            return;

        // 到达东南角：检查所有箭靶是否归零
        if (x == N - 1 && y == N - 1) {
            for (int i = 0; i < N; i++)
                if (north[i] != 0 || west[i] != 0)
                    return;
            found = true;
            pathLen = step; // 记录路径长度
            return;
        }

        for (int[] d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (vis[nx][ny])
                continue;
            // 剪枝：该列/行的剩余箭数不能为负
            if (north[ny] <= 0 || west[nx] <= 0)
                continue;

            vis[nx][ny] = true;
            north[ny]--;
            west[nx]--;
            path[step] = nx * N + ny;
            dfs(nx, ny, step + 1);
            if (found)
                return;
            vis[nx][ny] = false;
            north[ny]++;
            west[nx]++;
        }
    }
}
