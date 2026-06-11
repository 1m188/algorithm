/*

标题：分考场

n个人参加某项特殊考试。
为了公平，要求任何两个认识的人不能分在同一个考场。
求是少需要分几个考场才能满足条件。

输入格式：
第一行，一个整数n(1<n<100)，表示参加考试的人数。
第二行，一个整数m，表示接下来有m行数据
以下m行每行的格式为：两个整数a，b，用空格分开 (1<=a,b<=n)  表示第a个人与第b个人认识。

输出格式：
一行一个整数，表示最少分几个考场。

例如：
输入：
5
8
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5

程序应该输出：
4

再比如：
输入：
5
10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5

则程序应该输出：
5

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

 
*/

import java.io.*;
import java.util.*;

public class _5 {
    static int n;
    static boolean[][] adj; // 邻接矩阵
    static int[] deg; // 各顶点度数
    static int best; // 当前最优（最少考场数）
    static int[] color; // 各顶点颜色（考场编号）

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        adj = new boolean[n + 1][n + 1];
        deg = new int[n + 1];

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a][b] = adj[b][a] = true;
            deg[a]++;
            deg[b]++;
        }

        // 按度数降序排列顶点（复杂顶点先着色，剪枝更有效）
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++)
            order[i] = i + 1;
        Arrays.sort(order, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return deg[b] - deg[a]; // 降序
            }
        });

        // 贪心着色作为上界
        color = new int[n + 1];
        best = greedy(order);
        Arrays.fill(color, 0);

        // 回溯搜索更优解
        dfs(0, 0, order);
        System.out.println(best);
    }

    /** 贪心着色，返回所用颜色数（上界） */
    static int greedy(Integer[] order) {
        int maxColor = 0;
        for (int idx = 0; idx < n; idx++) {
            int v = order[idx];
            // 统计邻居已用的颜色
            boolean[] used = new boolean[n + 1];
            for (int u = 1; u <= n; u++) {
                if (adj[v][u] && color[u] > 0) {
                    used[color[u]] = true;
                }
            }
            // 选最小可用颜色
            int c = 1;
            while (c <= n && used[c])
                c++;
            color[v] = c;
            if (c > maxColor)
                maxColor = c;
        }
        return maxColor;
    }

    /**
     * 回溯搜索：为第 idx 个顶点（按 order 排序）着色
     * 
     * @param idx      当前处理的顶点索引
     * @param maxColor 目前已使用的最大颜色编号
     * @param order    顶点处理顺序
     */
    static void dfs(int idx, int maxColor, Integer[] order) {
        // 全部着色完成，更新最优解
        if (idx == n) {
            if (maxColor < best)
                best = maxColor;
            return;
        }

        // 剪枝：已用颜色数已不优于当前最优
        if (maxColor >= best)
            return;

        int v = order[idx];

        // 统计 v 的邻居中已使用的颜色
        boolean[] used = new boolean[maxColor + 2];
        for (int u = 1; u <= n; u++) {
            if (adj[v][u] && color[u] > 0) {
                used[color[u]] = true;
            }
        }

        // 优先尝试复用已有颜色
        for (int c = 1; c <= maxColor; c++) {
            if (!used[c]) {
                color[v] = c;
                dfs(idx + 1, maxColor, order);
                color[v] = 0;
            }
        }

        // 尝试启用新颜色
        if (maxColor + 1 < best) {
            color[v] = maxColor + 1;
            dfs(idx + 1, maxColor + 1, order);
            color[v] = 0;
        }
    }
}
