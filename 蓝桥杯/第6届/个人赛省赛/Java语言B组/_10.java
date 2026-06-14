/*
生命之树

在X森林里，上帝创建了生命之树。

他给每棵树的每个节点（叶子也称为一个节点）上，都标了一个整数，代表这个点的和谐值。
上帝要在这棵树内选出一个非空节点集S，使得对于S中的任意两个点a,b，都存在一个点列 {a, v1, v2, ..., vk, b} 使得这个点列中的每个点都是S里面的元素，且序列中相邻两个点间有一条边相连。

在这个前提下，上帝要使得S中的点所对应的整数的和尽量大。
这个最大的和就是上帝给生命之树的评分。

经过atm的努力，他已经知道了上帝给每棵树上每个节点上的整数。但是由于 atm 不擅长计算，他不知道怎样有效的求评分。他需要你为他写一个程序来计算一棵树的分数。

「输入格式」
第一行一个整数 n 表示这棵树有 n 个节点。
第二行 n 个整数，依次表示每个节点的评分。
接下来 n-1 行，每行 2 个整数 u, v，表示存在一条 u 到 v 的边。由于这是一棵树，所以是不存在环的。

「输出格式」
输出一行一个数，表示上帝给这棵树的分数。

「样例输入」
5
1 -2 -3 4 5
4 2
3 1
1 2
2 5

「样例输出」
8

「数据范围」
对于 30% 的数据，n <= 10
对于 100% 的数据，0 < n <= 10^5, 每个节点的评分的绝对值不超过 10^6 。

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。
*/

/*
 * 解题思路：
 * S 必须是树的一个连通子集。问题等价于：在树上选一个连通块，
 * 使得块内节点的权值和最大。即最大连通子图权值和。
 *
 * 树形 DP：任选根（如节点 1），DFS。
 * dp[u] = 以 u 为根的子树中，包含 u 的最大连通块权值。
 * dp[u] = w[u] + Σ max(0, dp[v])（对每个子节点 v）。
 * 最终答案 = max(dp[u]) 对全部节点 u。
 *
 * 用迭代 DFS 避免栈溢出（n ≤ 10^5）。
 */
import java.io.*;
import java.util.*;

public class _10 {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        long[] w = new long[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++)
            w[i] = Long.parseLong(st.nextToken());

        // 建邻接表
        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            adj[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
            adj[v].add(u);
        }

        // 迭代 DFS：先用栈收集后序遍历顺序
        int[] parent = new int[n + 1];
        int[] order = new int[n]; // 后序遍历顺序
        int[] stack = new int[n];
        boolean[] visited = new boolean[n + 1];
        int top = 0, idx = 0;
        stack[top++] = 1;
        visited[1] = true;

        while (top > 0) {
            int u = stack[--top];
            order[idx++] = u;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    stack[top++] = v;
                }
            }
        }

        // 按后序遍历逆序 DP（先处理叶子）
        long[] dp = new long[n + 1];
        long ans = Long.MIN_VALUE;

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            dp[u] = w[u];
            for (int v : adj[u]) {
                if (v != parent[u] && dp[v] > 0)
                    dp[u] += dp[v];
            }
            if (dp[u] > ans)
                ans = dp[u];
        }

        System.out.println(ans);
    }
}
