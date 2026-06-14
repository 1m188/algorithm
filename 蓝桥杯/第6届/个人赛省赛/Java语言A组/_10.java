/*
灾后重建

Pear市一共有N（<=50000）个居民点，居民点之间有M（<=200000）条双向道路相连。这些居民点两两之间都可以通过双向道路到达。这种情况一直持续到最近，一次严重的地震毁坏了全部M条道路。
震后，Pear打算修复其中一些道路，修理第i条道路需要Pi的时间。不过，Pear并不打算让全部的点连通，而是选择一些标号特殊的点让他们连通。
Pear有Q（<=50000）次询问，每次询问，他会选择所有编号在[l,r]之间，并且 编号 mod K  = C 的点，修理一些路使得它们连通。由于所有道路的修理可以同时开工，所以完成修理的时间取决于花费时间最长的一条路，即涉及到的道路中Pi的最大值。

你能帮助Pear计算出每次询问时需要花费的最少时间么？这里询问是独立的，也就是上一个询问里的修理计划并没有付诸行动。

【输入格式】
第一行三个正整数N、M、Q，含义如题面所述。
接下来M行，每行三个正整数Xi、Yi、Pi，表示一条连接Xi和Yi的双向道路，修复需要Pi的时间。可能有自环，可能有重边。1<=Pi<=1000000。

接下来Q行，每行四个正整数Li、Ri、Ki、Ci，表示这次询问的点是[Li,Ri]区间中所有编号Mod Ki=Ci的点。保证参与询问的点至少有两个。

【输出格式】
输出Q行，每行一个正整数表示对应询问的答案。

【样例输入】
7 10 4
1 3 10
2 6 9
4 1 5
3 7 4
3 6 9
1 5 8
2 7 4
3 2 10
1 7 6
7 6 9
1 7 1 0
1 7 3 1
2 5 1 0
3 7 2 1

【样例输出】
9
6
8
8

【数据范围】
对于20%的数据，N,M,Q<=30
对于40%的数据，N,M,Q<=2000
对于100%的数据，N<=50000,M<=2*10^5,Q<=50000. Pi<=10^6. Li,Ri,Ki均在[1,N]范围内，Ci在[0,对应询问的Ki)范围内。

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 5000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。
*/

/*
 * 解题思路：
 * 问题等价于：对于选定的点集 S，求用 n - 1 条边使其连通时，所需最大边权的最小值。
 * 即求 S 在 MST 上的最小瓶颈生成树的瓶颈值。
 *
 * 1. 对原图建 MST（Kruskal）。
 * 2. 在 MST 上预处理 LCA（二进制提升），同时维护 max_up[node][j]
 *    —— 从 node 到其第 2^j 级祖先路径上的最大边权。
 * 3. 对于任意两点 (a,b)，其 MST 路径上的最大边权可通过 LCA 在
 *    O(log N) 时间内求得（maxEdge 函数）。
 * 4. 对于询问点集 S，将所有点按其 MST 的 DFS 序排序，则点集连通
 *    所需的最大边权 = max_{i} maxEdge(S[i], S[i+1])（连续元素 LCAmax）。
 * 5. 对每次询问，按步长 K 收集满足条件的点，排序 DFS 序，求相邻
 *    路径最大值即可。
 *
 * 复杂度：建 MST O(M log M + M α(N))，LCA 预处理 O(N log N)，
 *         每次询问 O(cnt log cnt + cnt log N)。在非极端数据下可高效运行。
 */

import java.io.*;
import java.util.*;

public class _10 {

    static final int LOG = 17; // 2^17 = 131072 > max_nodes (100000)

    static int N, M, Q;
    static Edge[] edges;

    // MST adjacency
    static ArrayList<TreeEdge>[] adj;

    // LCA 预处理
    static int[] depth, dfsIn, parent, parentWeight;
    static int[][] up, maxUp;
    static int timer;

    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        edges = new Edge[M];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1; // 0-indexed
            int y = Integer.parseInt(st.nextToken()) - 1;
            int p = Integer.parseInt(st.nextToken());
            edges[i] = new Edge(x, y, p);
        }

        // 1. 建 MST
        buildMST();

        // 2. LCA 预处理
        depth = new int[N];
        dfsIn = new int[N];
        parent = new int[N];
        parentWeight = new int[N];
        up = new int[N][LOG];
        maxUp = new int[N][LOG];
        timer = 0;
        dfsPreprocess();

        // 3. 处理询问
        PrintWriter out = new PrintWriter(System.out);
        for (int qi = 0; qi < Q; qi++) {
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            // 收集满足条件的点（0-indexed 内部编号）
            ArrayList<Integer> nodes = new ArrayList<>();
            // 找第一个在 [L-1, R-1] 范围内满足 (id+1) % K == C 的点
            // id+1 = i (1-indexed), i in [L,R], i % K == C
            int rem = L % K;      // L mod K
            int first = L;
            if (rem <= C)
                first += (C - rem);
            else
                first += (K - rem + C);

            for (int id = first - 1; id <= R - 1; id += K) // 0-indexed
                nodes.add(id);

            if (nodes.size() <= 1) {
                out.println(0);
                continue;
            }

            // 按 DFS 序排序
            nodes.sort(Comparator.comparingInt(v -> dfsIn[v]));

            int ans = 0;
            for (int i = 0; i < nodes.size() - 1; i++) {
                int a = nodes.get(i);
                int b = nodes.get(i + 1);
                int me = maxEdge(a, b);
                if (me > ans) ans = me;
            }
            out.println(ans);
        }
        out.flush();
    }

    // ---- Kruskal MST ----
    static void buildMST() {
        Arrays.sort(edges);
        adj = new ArrayList[N];
        for (int i = 0; i < N; i++)
            adj[i] = new ArrayList<>();

        DSU dsu = new DSU(N);
        int cnt = 0;
        for (Edge e : edges) {
            if (dsu.union(e.u, e.v)) {
                adj[e.u].add(new TreeEdge(e.v, e.w));
                adj[e.v].add(new TreeEdge(e.u, e.w));
                cnt++;
                if (cnt == N - 1) break;
            }
        }
    }

    // ---- DFS（迭代）计算 depth、parent、dfsIn、binary lifting ----
    static void dfsPreprocess() {
        int[] stack = new int[N];
        int top = 0;
        stack[top++] = 0;
        parent[0] = 0;  // 根的父节点设为自身
        parentWeight[0] = 0;
        boolean[] visited = new boolean[N];
        int[] order = new int[N]; // DFS 序

        while (top > 0) {
            int v = stack[--top];
            if (!visited[v]) {
                visited[v] = true;
                dfsIn[v] = timer;
                order[timer] = v;
                timer++;
                for (TreeEdge e : adj[v]) {
                    if (!visited[e.to]) {
                        depth[e.to] = depth[v] + 1;
                        parent[e.to] = v;
                        parentWeight[e.to] = e.weight;
                        stack[top++] = e.to;
                    }
                }
            }
        }

        // 填充 binary lifting 表（按 DFS 序保证父节点先处理）
        for (int i = 0; i < N; i++) {
            int v = order[i];
            up[v][0] = parent[v];
            maxUp[v][0] = parentWeight[v];
            for (int j = 1; j < LOG; j++) {
                up[v][j] = up[up[v][j - 1]][j - 1];
                maxUp[v][j] = Math.max(maxUp[v][j - 1], maxUp[up[v][j - 1]][j - 1]);
            }
        }
    }

    // ---- 计算两点间最大边权（LCA + maxUp） ----
    static int maxEdge(int a, int b) {
        if (a == b) return 0;
        int max = 0;
        if (depth[a] < depth[b]) {
            int t = a; a = b; b = t;
        }

        // 将 a 提升到与 b 同一深度
        int diff = depth[a] - depth[b];
        for (int j = 0; j < LOG; j++) {
            if ((diff >> j & 1) == 1) {
                max = Math.max(max, maxUp[a][j]);
                a = up[a][j];
            }
        }

        if (a == b) return max;

        // 同步向上跳跃
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                max = Math.max(max, maxUp[a][j]);
                max = Math.max(max, maxUp[b][j]);
                a = up[a][j];
                b = up[b][j];
            }
        }

        // 最后一步到 LCA
        max = Math.max(max, maxUp[a][0]);
        max = Math.max(max, maxUp[b][0]);
        return max;
    }

    // ---- 辅助类 ----
    static class Edge implements Comparable<Edge> {
        int u, v, w;
        Edge(int u, int v, int w) { this.u = u; this.v = v; this.w = w; }
        public int compareTo(Edge o) { return Integer.compare(this.w, o.w); }
    }

    static class TreeEdge {
        int to, weight;
        TreeEdge(int to, int w) { this.to = to; this.weight = w; }
    }

    static class DSU {
        int[] parent, rank;
        DSU(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        boolean union(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return false;
            if (rank[ra] < rank[rb]) parent[ra] = rb;
            else if (rank[ra] > rank[rb]) parent[rb] = ra;
            else { parent[rb] = ra; rank[ra]++; }
            return true;
        }
    }
}
