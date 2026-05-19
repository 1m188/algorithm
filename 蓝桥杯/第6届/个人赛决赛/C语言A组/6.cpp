/*

标题：铺瓷砖

为了让蓝桥杯竞赛更顺利的进行，主办方决定给竞赛的机房重新铺放瓷砖。
机房可以看成一个n*m的矩形，而这次使用的瓷砖比较特别，有两种形状，分别是：

*
**

和

*
**
*

在铺放瓷砖时，可以旋转。

主办方想知道，如果使用这两种瓷砖把机房铺满，有多少种方案。

【输入格式】
输入的第一行包含两个整数，分别表示机房两个方向的长度。

【输出格式】
输出一个整数，表示可行的方案数。这个数可能很大，请输出这个数除以65521的余数。

【样例输入1】
4 4
【样例输出1】
2
【样例说明1】
这两种方案如下【图2.png】所示：

【样例输入2】
2 6
【样例输出2】
4
【数据规模与约定】
对于20%的数据，1<=n, m<=5。
对于50%的数据，1<=n<=100，1<=m<=5。
对于100%的数据，1<=n<=10^15，1<=m<=6。

 资源约定：
峰值内存消耗 < 512M
CPU消耗  < 5000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

/*
 * ============================================================================
 * 解题思路：轮廓线 DP（Broken Profile DP）+ 稀疏矩阵快速幂
 * ============================================================================
 *
 * 【瓷砖形状】
 *   两种瓷砖（各有 4 种旋转），共 14 种摆放模式：
 *
 *   L 形瓷砖（二折形，占 3 格），4 种旋转，在 2×2 区域内：
 *     ┌─┐  ┌─┐  ┌─┐  ┌─┐
 *     │ │  │█│  │█│  │ │
 *     ├─┤  ├─┤  ├─┤  ├─┤
 *     │█│  │ │  │█│  │█│
 *     └─┘  └─┘  └─┘  └─┘
 *
 *   T 形瓷砖（三凸形，占 4 格），4 种旋转，在 2×3 或 3×2 区域内：
 *     ┌─┬─┐  ┌─┬─┐  ┌─┬─┐  ┌─┬─┐
 *     │█│ │  │ │█│  │ │ │  │█│ │
 *     ├─┼─┤  ├─┼─┤  ├─┼─┤  ├─┼─┤
 *     │█│█│  │█│█│  │█│█│  │█│█│
 *     ├─┼─┤  ├─┼─┤  ├─┼─┤  └─┴─┘
 *     │█│ │  │ │█│  │ │ │
 *     └─┴─┘  └─┴─┘  ├─┼─┤
 *                   │█│ │
 *                   └─┴─┘
 *
 *   另外 6 种复合模式（砖块重叠放置时形成的边界形态）。
 *
 * 【状态编码】
 *   由于 m ≤ 6，使用 2m 位存储状态。2m 位交替排列：
 *     位 0  位 1  位 2  位 3  ... 位 (2m-2)  位 (2m-1)
 *    cur[0] nxt[0] cur[1] nxt[1] ... cur[m-1]  nxt[m-1]
 *
 *   其中：
 *     cur[i] = 1 表示格子 (当前行, 列 i) 已被瓷砖占据
 *     nxt[i] = 1 表示格子 (下一行, 列 i) 已被瓷砖占据
 *
 * 【轮廓线 DP 转移】
 *   从左到右逐列处理。对于列 i，状态 S 中 cur[i] 和 nxt[i] 分别为 A 和 B。
 *   基本转移：cs = 清除 cur[i] 和 nxt[i]，然后将 old nxt[i] 移到 cur[i] 位置。
 *   这模拟了"向下滚动一行"的效果。
 *
 *   对每个状态，若有合适的砖块模式匹配，则在 cs 基础上设置被砖块覆盖的位。
 *   共 9 条 if 语句对应 14 种摆放模式。
 *
 * 【矩阵快速幂】
 *   对一行完整的转移矩阵 xres，计算 xres^n。
 *   使用稀疏矩阵存储（每行只存非零条目）和 uint64_t 累加器优化取模。
 *   xres[full_mask][full_mask] 即为从"全满"状态经过 n 行后仍回到"全满"的方案数。
 *   这等价于用两种瓷砖恰好铺满 n×m 网格的方案数。
 * ============================================================================
 */

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;

const uint MOD = 65521;

const int msk[13] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
const int zsk[13] = {~1, ~2, ~4, ~8, ~16, ~32, ~64, ~128, ~256, ~512, ~1024, ~2048, ~4096};

struct SparseMat {
    int N;
    vector<pair<int, uint>> *rows;
    SparseMat(int n) : N(n) { rows = new vector<pair<int, uint>>[N]; }
    SparseMat(const SparseMat &o) : N(o.N) {
        rows = new vector<pair<int, uint>>[N];
        for (int i = 0; i < N; i++)
            rows[i] = o.rows[i];
    }
    SparseMat &operator=(const SparseMat &o) {
        if (this != &o) {
            delete[] rows;
            N = o.N;
            rows = new vector<pair<int, uint>>[N];
            for (int i = 0; i < N; i++)
                rows[i] = o.rows[i];
        }
        return *this;
    }
    ~SparseMat() { delete[] rows; }
};

SparseMat mat_mul(const SparseMat &A, const SparseMat &B) {
    int N = A.N;
    SparseMat C(N);
    ull *tmp = new ull[N]();

    for (int i = 0; i < N; i++) {
        if (A.rows[i].empty()) continue;
        for (const auto &kv : A.rows[i]) {
            int k = kv.first;
            uint av = kv.second;
            for (const auto &bkv : B.rows[k]) {
                tmp[bkv.first] += (ull)av * bkv.second;
            }
        }
        for (int j = 0; j < N; j++) {
            if (tmp[j]) {
                C.rows[i].push_back({j, (uint)(tmp[j] % MOD)});
                tmp[j] = 0;
            }
        }
    }
    delete[] tmp;
    return C;
}

SparseMat build_xres(int m) {
    int N = 1 << (2 * m);
    SparseMat xres(N);
    for (int i = 0; i < N; i++)
        xres.rows[i].push_back({i, 1});

    for (int col = 0; col < m; col++) {
        SparseMat tmp_mat(N);
        for (int S = 0; S < N; S++) {
            int L = col * 2;
            bool A = S & msk[L], B = S & msk[L + 1];
            int cs = (S & zsk[L] & zsk[L + 1]) | (B << L);

            auto add = [&](int tgt) {
                for (auto &kv : tmp_mat.rows[S]) {
                    if (kv.first == tgt) {
                        kv.second = (kv.second + 1) % MOD;
                        return;
                    }
                }
                tmp_mat.rows[S].push_back({tgt, 1});
            };

            if (A) add(cs);
            if (col > 1 && !(S & msk[L - 3]) && !(S & msk[L - 2]) && !(S & msk[L - 1]) && A)
                add(cs | msk[L - 3] | msk[L - 2] | msk[L - 1] | msk[L + 1]);
            if (col && !(S & msk[L - 2]) && !A && !B)
                add(cs | msk[L - 2] | msk[L] | msk[L + 1]);
            if (col > 1 && !(S & msk[L - 4]) && !(S & msk[L - 2]) && !(S & msk[L - 1]) && A && !B)
                add(cs | msk[L - 4] | msk[L - 2] | msk[L - 1] | msk[L]);
            if (col != m - 1 && !(S & msk[L + 3]) && !A && !B)
                add(cs | msk[L + 3] | msk[L] | msk[L + 1]);
            if (col && !(S & msk[L - 1]) && A && !B)
                add(cs | msk[L - 1] | msk[L] | msk[L + 1]);
            if (col && !(S & msk[L - 2]) && !(S & msk[L - 1]) && A)
                add(cs | msk[L - 2] | msk[L - 1] | msk[L + 1]);
            if (col && !(S & msk[L - 2]) && A && !B)
                add(cs | msk[L - 2] | msk[L] | msk[L + 1]);
            if (col && !(S & msk[L - 2]) && !(S & msk[L - 1]) && A && !B)
                add(cs | msk[L - 2] | msk[L - 1] | msk[L]);
        }
        xres = mat_mul(xres, tmp_mat);
    }
    return xres;
}

SparseMat mat_pow(const SparseMat &base, ll exp) {
    int N = base.N;
    SparseMat res(N);
    for (int i = 0; i < N; i++)
        res.rows[i].push_back({i, 1});

    SparseMat cur = base;
    while (exp > 0) {
        if (exp & 1) res = mat_mul(res, cur);
        cur = mat_mul(cur, cur);
        exp >>= 1;
    }
    return res;
}

int main() {
    ll n;
    int m;
    scanf("%lld%d", &n, &m);
    if (n < (ll)m) {
        ll t = n;
        n = m;
        m = (int)t;
    }

    SparseMat xres = build_xres(m);
    SparseMat res = mat_pow(xres, n - 1);
    res = mat_mul(res, xres);

    int full = (1 << (2 * m)) - 1;
    uint ans = 0;
    for (const auto &kv : res.rows[full]) {
        if (kv.first == full) {
            ans = kv.second;
            break;
        }
    }
    printf("%u\n", ans);
    return 0;
}
