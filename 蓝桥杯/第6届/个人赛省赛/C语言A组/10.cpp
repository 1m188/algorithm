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
峰值内存消耗 < 256M
CPU消耗  < 5000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>

const int MAXN = 50005;
const int MAXM = 200005;
const int MAX_KRUSKAL = MAXN * 2; // Kruskal重构树最多2N-1个节点
const int LOGN = 17;              // log2(100000) ≈ 17
const int B = 200;                // sqrt(50000) ≈ 224，取200作为阈值

// ===== Kruskal重构树 =====
int kruskal_cnt;               // Kruskal树节点数
int weight[MAX_KRUSKAL];       // 节点权重（叶子为0，内部节点为合并时的边权）
int left_child[MAX_KRUSKAL];   // 左儿子
int right_child[MAX_KRUSKAL];  // 右儿子
int depth[MAX_KRUSKAL];        // 节点深度
int parent[LOGN][MAX_KRUSKAL]; // 倍增祖先
int dfs_in[MAX_KRUSKAL];       // DFS进入时间戳
int leaf_dfs_in[MAXN];         // 原始节点i（叶子）的DFS进入时间戳

// ===== 并查集（Kruskal用）=====
int dsu_parent[MAXN];
int dsu_rep[MAXN]; // 每个DSU连通分量对应的Kruskal树节点

int dsu_find(int x) {
    while (dsu_parent[x] != x) {
        dsu_parent[x] = dsu_parent[dsu_parent[x]];
        x = dsu_parent[x];
    }
    return x;
}

// ===== 边 =====
struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};
Edge edges[MAXM];

// ===== DFS构建深度、父节点、时间戳 =====
int dfs_timer;

void dfs(int u) {
    dfs_in[u] = ++dfs_timer;
    if (left_child[u]) {
        depth[left_child[u]] = depth[u] + 1;
        parent[0][left_child[u]] = u;
        dfs(left_child[u]);
    }
    if (right_child[u]) {
        depth[right_child[u]] = depth[u] + 1;
        parent[0][right_child[u]] = u;
        dfs(right_child[u]);
    }
}

// ===== LCA查询 =====
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        int tmp = u;
        u = v;
        v = tmp;
    }
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOGN; i++)
        if (diff & (1 << i))
            u = parent[i][u];
    if (u == v)
        return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

// ===== 小K预处理数据结构 =====
// 每个(K, C)对的块状数组，用于区间min/max查询
struct BlockData {
    int min_id, max_id; // 块内最小/最大DFS时间戳对应的原始节点编号
};

struct KCInfo {
    int K, C;
    std::vector<int> ids;          // 符合条件的节点编号（按自然顺序）
    std::vector<int> ins;          // 对应的DFS进入时间戳
    std::vector<BlockData> blocks; // 块数据
    int block_sz;                  // 块大小
};

// 小K的数据：kc_storage[K][C]
std::vector<KCInfo> kc_storage[MAXN]; // 实际上只用到K<=B

void build_kc(KCInfo &kc, int N) {
    int K = kc.K, C = kc.C;
    // 收集该(K,C)对应的所有节点
    int first = (C == 0 ? K : C);
    for (int i = first; i <= N; i += K) {
        kc.ids.push_back(i);
        kc.ins.push_back(leaf_dfs_in[i]);
    }
    int sz = (int)kc.ids.size();
    if (sz == 0) return;

    // 块大小取 sqrt(sz)，至少为1
    kc.block_sz = (int)std::sqrt(sz);
    if (kc.block_sz < 1) kc.block_sz = 1;
    int num_blocks = (sz + kc.block_sz - 1) / kc.block_sz;
    kc.blocks.resize(num_blocks);

    for (int b = 0; b < num_blocks; b++) {
        int l = b * kc.block_sz;
        int r = std::min(l + kc.block_sz, sz);
        int min_idx = l, max_idx = l;
        for (int i = l; i < r; i++) {
            if (kc.ins[i] < kc.ins[min_idx]) min_idx = i;
            if (kc.ins[i] > kc.ins[max_idx]) max_idx = i;
        }
        kc.blocks[b].min_id = kc.ids[min_idx];
        kc.blocks[b].max_id = kc.ids[max_idx];
    }
}

// 查询(K,C)序列中范围[L,R]内节点的min/max
// 返回{min_id, max_id}
void query_kc(KCInfo &kc, int L, int R, int &min_node, int &max_node) {
    int min_in = INT_MAX, max_in = -1;
    min_node = max_node = -1;

    int sz = (int)kc.ids.size();
    // 二分定位
    int idx_l = (int)(std::lower_bound(kc.ids.begin(), kc.ids.end(), L) - kc.ids.begin());
    int idx_r = (int)(std::upper_bound(kc.ids.begin(), kc.ids.end(), R) - kc.ids.begin()) - 1;
    if (idx_l > idx_r || idx_l >= sz || idx_r < 0) return;

    int bl = idx_l / kc.block_sz;
    int br = idx_r / kc.block_sz;

    if (bl == br) {
        for (int i = idx_l; i <= idx_r; i++) {
            if (kc.ins[i] < min_in) {
                min_in = kc.ins[i];
                min_node = kc.ids[i];
            }
            if (kc.ins[i] > max_in) {
                max_in = kc.ins[i];
                max_node = kc.ids[i];
            }
        }
    } else {
        // 左端散块
        int lend = (bl + 1) * kc.block_sz;
        for (int i = idx_l; i < lend && i <= idx_r; i++) {
            if (kc.ins[i] < min_in) {
                min_in = kc.ins[i];
                min_node = kc.ids[i];
            }
            if (kc.ins[i] > max_in) {
                max_in = kc.ins[i];
                max_node = kc.ids[i];
            }
        }
        // 中间完整块
        for (int b = bl + 1; b < br; b++) {
            int bmin_id = kc.blocks[b].min_id;
            int bmax_id = kc.blocks[b].max_id;
            int bmin_in = leaf_dfs_in[bmin_id];
            int bmax_in = leaf_dfs_in[bmax_id];
            if (bmin_in < min_in) {
                min_in = bmin_in;
                min_node = bmin_id;
            }
            if (bmax_in > max_in) {
                max_in = bmax_in;
                max_node = bmax_id;
            }
        }
        // 右端散块
        int rstart = br * kc.block_sz;
        for (int i = rstart; i <= idx_r && i < sz; i++) {
            if (kc.ins[i] < min_in) {
                min_in = kc.ins[i];
                min_node = kc.ids[i];
            }
            if (kc.ins[i] > max_in) {
                max_in = kc.ins[i];
                max_node = kc.ids[i];
            }
        }
    }
}

// ===== 主函数 =====
int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    // 读入边
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    // 读入询问
    struct Query {
        int L, R, K, C;
        int id;
        int ans;
    };
    std::vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &queries[i].L, &queries[i].R, &queries[i].K, &queries[i].C);
        queries[i].id = i;
        queries[i].ans = 0;
    }

    // ===== 1. Kruskal构建MST及重构树 =====
    std::sort(edges, edges + M);

    for (int i = 1; i <= N; i++) {
        dsu_parent[i] = i;
        dsu_rep[i] = i;
    }
    kruskal_cnt = N;
    for (int i = 1; i <= N; i++) {
        weight[i] = 0;
        left_child[i] = 0;
        right_child[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int ru = dsu_find(edges[i].u);
        int rv = dsu_find(edges[i].v);
        if (ru != rv) {
            kruskal_cnt++;
            weight[kruskal_cnt] = edges[i].w;
            left_child[kruskal_cnt] = dsu_rep[ru];
            right_child[kruskal_cnt] = dsu_rep[rv];

            dsu_parent[ru] = rv;
            dsu_rep[rv] = kruskal_cnt;
        }
    }

    // ===== 2. DFS预处理Kruskal树 =====
    int root = dsu_rep[dsu_find(1)];
    depth[root] = 0;
    parent[0][root] = 0;
    dfs_timer = 0;
    dfs(root);

    // 记录叶子节点的DFS进入时间戳
    for (int i = 1; i <= N; i++) {
        leaf_dfs_in[i] = dfs_in[i];
    }

    // 倍增表
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= kruskal_cnt; i++) {
            int p = parent[j - 1][i];
            parent[j][i] = (p == 0 ? 0 : parent[j - 1][p]);
        }
    }

    // ===== 3. 分类询问 =====
    // need_kc[K] 记录该K值下有哪些C值需要预构建
    std::vector<int> small_q; // 小K询问下标
    std::vector<int> large_q; // 大K询问下标
    for (int i = 0; i < Q; i++) {
        if (queries[i].K <= B)
            small_q.push_back(i);
        else
            large_q.push_back(i);
    }

    // 对于小K，按(K,C)分组
    // used[K][C] = 该(K,C)在kc_storage[K]中的索引
    for (int K = 1; K <= B; K++) {
        kc_storage[K].resize(K);
        for (int C = 0; C < K; C++) {
            kc_storage[K][C].K = K;
            kc_storage[K][C].C = C;
        }
    }
    // 按需构建使用到的(K,C)
    for (int qi : small_q) {
        int K = queries[qi].K;
        int C = queries[qi].C;
        KCInfo &kc = kc_storage[K][C];
        if (kc.ids.empty() && kc.blocks.empty()) {
            build_kc(kc, N);
        }
    }

    // 处理小K询问
    for (int qi : small_q) {
        Query &q = queries[qi];
        KCInfo &kc = kc_storage[q.K][q.C];

        int min_node, max_node;
        query_kc(kc, q.L, q.R, min_node, max_node);

        if (min_node == max_node) {
            q.ans = 0;
        } else {
            int lca_node = lca(min_node, max_node);
            q.ans = weight[lca_node];
        }
    }

    // 处理大K询问：直接枚举
    for (int qi : large_q) {
        Query &q = queries[qi];
        int min_in = INT_MAX, max_in = -1;
        int min_node = -1, max_node = -1;

        int first = (q.C == 0 ? q.K : q.C);
        for (int i = first; i <= N; i += q.K) {
            if (i >= q.L && i <= q.R) {
                int tin = leaf_dfs_in[i];
                if (tin < min_in) {
                    min_in = tin;
                    min_node = i;
                }
                if (tin > max_in) {
                    max_in = tin;
                    max_node = i;
                }
            }
        }

        if (min_node == max_node) {
            q.ans = 0;
        } else {
            int lca_node = lca(min_node, max_node);
            q.ans = weight[lca_node];
        }
    }

    // 按原始顺序输出
    for (int i = 0; i < Q; i++) {
        printf("%d\n", queries[i].ans);
    }

    return 0;
}
