/*
 * 自描述序列 (Golomb sequence)
 *
 * G(1) = 1
 * G(n) = 1 + G(n - G(G(n-1)))  for n > 1
 *
 * 性质：值 k 在序列中出现恰好 G(k) 次，且序列不下降。
 *
 * 设 A[k] = sum_{i=1}^{k} G[i]（前缀和），则 G(n) = k 当 A[k-1] < n <= A[k]。
 *
 * G 自身也有"块"结构：G[v] = c 对 v ∈ (A[c-1], A[c]]，块长 G[c]。
 * 块 c 对 A 的贡献 = c * G[c]。
 * 所以 A[k] = block_sum[G[k]-1] + (k - A[G[k]-1]) * G[k]
 *   其中 block_sum[c] = sum_{i=1}^{c} i * G[i]
 *
 * 对于任意 k，G[k] 可以通过在 A[1..M] 上二分查找得到（只要 G[k] <= M）。
 * n <= 2e15 时答案 G(n) ≈ 3.44e9，而 G(G(n)) ≈ 9.2e5 < M=2e6，满足条件。
 *
 * 时间复杂度：O(M) 预计算 + O(log M * log n) 查询
 * 空间复杂度：O(M)
 */

#include <cmath>
#include <cstdio>

typedef long long ll;

const int M = 2000000; // 预计算 200 万项

int G[M + 1];    // G[i] = Golomb 序列第 i 项
ll A[M + 1];     // A[i] = sum_{j=1}^{i} G[j]
ll block[M + 1]; // block[i] = sum_{j=1}^{i} j * G[j]

// 计算 A[k] = sum_{i=1}^{k} G[i]（对于 k <= A[M] 有效）
ll prefix_sum(ll k) {
    if (k <= 0) return 0;

    // 二分查找 c = G[k]：满足 A[c-1] < k <= A[c]
    int lo = 1, hi = M;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (A[mid] >= k)
            hi = mid;
        else
            lo = mid + 1;
    }
    int c = lo; // c = G[k]

    // block[c-1] 是前 c-1 个完整块的贡献，再加上部分块
    return block[c - 1] + (k - A[c - 1]) * c;
}

int main() {
    ll n;
    scanf("%lld", &n);

    // ---- 预计算 G[1..M], A[1..M], block[1..M] ----
    G[1] = 1;
    A[1] = 1;
    block[1] = 1; // 1 * G[1]

    for (int i = 2; i <= M; i++) {
        G[i] = 1 + G[i - G[G[i - 1]]];
        A[i] = A[i - 1] + G[i];
        block[i] = block[i - 1] + (ll)i * G[i];
    }

    // ---- n 在预计算范围内：直接在 A 上二分 ----
    if (n <= A[M]) {
        int lo = 1, hi = M;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (A[mid] >= n)
                hi = mid;
            else
                lo = mid + 1;
        }
        printf("%d\n", lo);
        return 0;
    }

    // ---- n 超出预计算范围：用渐近公式估算，再精确验证 ----
    // G(n) ≈ φ^(2-φ) * n^(φ-1) ≈ 1.20176 * n^0.618034
    double approx = 1.20176 * pow((double)n, 0.618034);
    ll k = (ll)(approx + 0.5);
    if (k <= M) k = M + 1;

    // 微调（误差不超过 ±2）
    while (true) {
        ll cur = prefix_sum(k);
        ll prv = prefix_sum(k - 1);
        if (prv < n && n <= cur) {
            printf("%lld\n", k);
            return 0;
        }
        if (n <= prv)
            k--;
        else
            k++;
    }
}
