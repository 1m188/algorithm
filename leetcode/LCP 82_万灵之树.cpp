/*
 * @lc app=leetcode.cn id=LCP 82 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 82] 万灵之树
 *
 * https://leetcode.cn/problems/cnHoX6/description/
 *
 * algorithms
 * Hard (14.55%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    1.5K
 * Total Submissions: 10.1K
 * Testcase Example:  '[2,3]\n100000007\n11391299'
 *
 * 探险家小扣终于来到了万灵之树前，挑战最后的谜题。
 * 已知小扣拥有足够数量的链接节点和 `n` 颗幻境宝石，`gem[i]` 表示第 `i`
 * 颗宝石的数值。现在小扣需要使用这些链接节点和宝石组合成一颗二叉树，其组装规则为：
 * - 链接节点将作为二叉树中的非叶子节点，且每个链接节点必须拥有 `2` 个子节点；
 * - 幻境宝石将作为二叉树中的叶子节点，所有的幻境宝石都必须被使用。
 *
 * 能量首先进入根节点，而后将按如下规则进行移动和记录：
 * - 若能量首次到达该节点时：
 *    - 记录数字 `1`；
 *    - 若该节点为叶节点，将额外记录该叶节点的数值；
 * - 若存在未到达的子节点，则选取未到达的一个子节点（优先选取左子节点）进入；
 * - 若无子节点或所有子节点均到达过，此时记录 `9`，并回到当前节点的父节点（若存在）。
 *
 * 如果最终记下的数依序连接成一个整数 `num`，满足 $num \mod~p=target$，则视为解开谜题。
 * 请问有多少种二叉树的组装方案，可以使得最终记录下的数字可以解开谜题
 *
 * **注意：**
 * - 两棵结构不同的二叉树，作为不同的组装方案
 * - 两棵结构相同的二叉树且存在某个相同位置处的宝石编号不同，也作为不同的组装方案
 * - 可能存在数值相同的两颗宝石
 *
 * **示例 1：**
 * > 输入：`gem = [2,3]`
 * > `p = 100000007`
 * > `target = 11391299`
 * >
 * > 输出：`1`
 * >
 * > 解释：
 * > 包含 `2` 个叶节点的结构只有一种。
 * > 假设 B、C 节点的值分别为 3、2，对应 target 为 11391299，如下图所示。
 * > 11391299 % 100000007 = 11391299，满足条件;
 * > 假设 B、C 节点的值分别为 2、3，对应 target 为 11291399;
 * > 11291399 % 100000007 = 11291399，不满足条件；
 * > 因此只存在 1 种方案，返回 1
 * ![万灵
 * (1).gif](https://pic.leetcode.cn/1682397079-evMssw-%E4%B8%87%E7%81%B5%20\(1\).gif){:height=300px}
 *
 *
 * **示例 2：**
 * > 输入：`gem = [3,21,3]`
 * > `p = 7`
 * > `target = 5`
 * >
 * > 输出：`4`
 * >
 * > 解释：
 * 包含 `3` 个叶节点树结构有两种，列举如下：
 * 满足条件的组合有四种情况：
 * > 当结构为下图（1）时：叶子节点的值为 [3,3,21] 或 [3,3,21]，得到的整数为 `11139139912199`。
 * > 当结构为下图（2）时：叶子节点的值为 [21,3,3] 或 [21,3,3]，得到的整数为 `11219113913999`。
 *
 * ![image.png](https://pic.leetcode.cn/1682322894-vfqJIV-image.png){:width=500px}
 *
 *
 * **提示：**
 * - `1 <= gem.length <= 9`
 * - `0 <= gem[i] <= 10^9`
 * - `1 <= p <= 10^9`，保证 $p$ 为素数。
 * - `0 <= target < p`
 * - 存在 2 组 `gem.length == 9` 的用例
 */

// @lcpr-template-start
#include <algorithm>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int treeOfInfiniteSouls(vector<int> &gem, int p, int target) {
        int n = gem.size();

        // ---- 0. 特判：p=2 或 p=5 时 10≡0(mod p)，所有树产出一致的 b=9%p ----
        if (p == 2 || p == 5) {
            if (target == 9 % p) {
                const int catalan[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430};
                const int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
                return catalan[n - 1] * fact[n];
            }
            return 0;
        }

        // ---- 1. 计算每颗宝石的十进制位数 ----
        vector<int> digits(n);
        int total_digits = 0;
        for (int i = 0; i < n; i++) {
            int g = gem[i];
            if (g == 0) {
                digits[i] = 1;
            } else {
                int d = 0;
                while (g > 0) {
                    d++;
                    g /= 10;
                }
                digits[i] = d;
            }
            total_digits += digits[i];
        }

        // ---- 2. 预处理 10 的幂次模 p ----
        int max_len = 4 * n + total_digits;
        vector<int> pow10(max_len + 1, 1);
        for (int i = 1; i <= max_len; i++) {
            pow10[i] = (int)(1LL * pow10[i - 1] * 10 % p);
        }

        // ---- 3. 预处理每个 mask 的 a 值 ----
        int total_masks = 1 << n;
        vector<int> a_val(total_masks, 0);
        vector<int> sum_digits_mask(total_masks, 0);
        for (int mask = 1; mask < total_masks; mask++) {
            int lsb = mask & -mask;
            int idx = __builtin_ctz(lsb);
            int prev = mask ^ lsb;
            sum_digits_mask[mask] = sum_digits_mask[prev] + digits[idx];
            int len = 4 * __builtin_popcount(mask) + sum_digits_mask[mask] - 2;
            a_val[mask] = pow10[len];
        }

        // ---- 4. 快速幂和模逆元 ----
        auto mod_pow = [p](long long base, int exp) -> int {
            long long result = 1;
            while (exp > 0) {
                if (exp & 1) result = result * base % p;
                base = base * base % p;
                exp >>= 1;
            }
            return (int)result;
        };
        int inv10 = mod_pow(10, p - 2);

        // inv_a[mask] = a_val[mask]^(-1) mod p
        vector<int> inv_a(total_masks, 0);
        for (int mask = 1; mask < total_masks; mask++) {
            if (a_val[mask] != 0) {
                inv_a[mask] = mod_pow(a_val[mask], p - 2);
            }
        }

        // ---- 5. dp[mask] = 有序 (b, cnt) 列表（仅存储大小 ≤ 6 的 mask）----
        vector<vector<pair<int, int>>> dp(total_masks);

        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            int d = digits[i];
            long long g = gem[i];
            int b = (int)((pow10[d + 1] + 10 * g + 9) % p);
            dp[mask].push_back({b, 1});
        }

        vector<vector<int>> masks_by_size(n + 1);
        for (int mask = 1; mask < total_masks; mask++) {
            masks_by_size[__builtin_popcount(mask)].push_back(mask);
        }

        int max_store = min(6, n); // 只存到大小 6，大小 7+ 通过递归 count_b 按需计算

        // DP 递推，复用缓冲区避免重复分配
        vector<int> bR_mapped;
        for (int sz = 2; sz <= max_store; sz++) {
            for (int mask : masks_by_size[sz]) {
                // 预估容量
                int total_pairs = 0;
                for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
                    int other = mask ^ sub;
                    total_pairs += (int)dp[sub].size() * (int)dp[other].size();
                }

                vector<pair<int, int>> entries;
                entries.reserve(total_pairs);

                for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
                    int other = mask ^ sub;
                    int aL = a_val[sub], aR = a_val[other];
                    int C = (int)((10LL * aL % p) * aR % p + 9) % p;
                    int coeff_bL = (int)(10LL * aR % p);

                    const auto *other_data = dp[other].data();
                    const int other_sz = (int)dp[other].size();

                    // 预计算 (10 * bR) % p
                    bR_mapped.resize(other_sz);
                    for (int j = 0; j < other_sz; j++) {
                        bR_mapped[j] = (int)(10LL * other_data[j].first % p);
                    }

                    for (const auto &[bL, cntL] : dp[sub]) {
                        int prod = (int)(1LL * coeff_bL * bL % p);
                        int term = C + prod;
                        term = term >= p ? term - p : term;

                        for (int j = 0; j < other_sz; j++) {
                            int sum = term + bR_mapped[j];
                            int b = sum >= p ? sum - p : sum;
                            entries.push_back({b, cntL * other_data[j].second});
                        }
                    }
                }

                sort(entries.begin(), entries.end());
                vector<pair<int, int>> merged;
                for (const auto &[b, cnt] : entries) {
                    if (merged.empty() || merged.back().first != b) {
                        merged.push_back({b, cnt});
                    } else {
                        merged.back().second += cnt;
                    }
                }
                dp[mask] = std::move(merged);
            }
        }

        // ---- 辅助：在 dp[vec] 中二分查找 b 值的计数 ----
        auto lookup = [&](const vector<pair<int, int>> &vec, int b_val) -> long long {
            auto it = lower_bound(vec.begin(), vec.end(), make_pair(b_val, 0));
            if (it != vec.end() && it->first == b_val) return it->second;
            return 0;
        };

        // ---- 6. 递归 count_b：计算恰好产生指定 b 值的方案数（用于大小 7 和 8）----
        auto count_b = [&](auto &self, int mask, int need_b) -> long long {
            int sz = __builtin_popcount(mask);
            if (sz <= 6) {
                return lookup(dp[mask], need_b);
            }
            // mask 大小为 7 或 8，遍历所有有序划分
            long long total = 0;
            for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
                int other = mask ^ sub;
                int sz_sub = __builtin_popcount(sub);
                int sz_other = sz - sz_sub;
                int aL = a_val[sub], aR = a_val[other];
                int C = (int)((10LL * aL % p) * aR % p + 9) % p;
                int coeff_bL = (int)(10LL * aR % p);

                // b = (C + coeff_bL * bL + 10 * bR) % p == need_b
                // 必须迭代已存储（大小 ≤ 6）的那一侧；若两侧均已存储则选较小的
                bool sub_avail = (sz_sub <= 6);
                bool other_avail = (sz_other <= 6);

                if (sub_avail && (!other_avail || dp[sub].size() <= dp[other].size())) {
                    // 迭代 sub 侧，另一侧用递归 lookup
                    for (auto &[bL, cntL] : dp[sub]) {
                        long long need =
                            (need_b - C - 1LL * coeff_bL * bL) % p;
                        if (need < 0) need += p;
                        need = need * inv10 % p;
                        int nb = (int)need;
                        long long cntR = (sz_other <= 6)
                                             ? lookup(dp[other], nb)
                                             : self(self, other, nb);
                        if (cntR > 0) total += 1LL * cntL * cntR;
                    }
                } else {
                    // 迭代 other 侧，sub 侧用递归 lookup
                    int inv_coeff = (int)(1LL * inv10 * inv_a[other] % p);
                    for (auto &[bR, cntR] : dp[other]) {
                        long long need =
                            (need_b - C - 10LL * bR) % p;
                        if (need < 0) need += p;
                        need = need * inv_coeff % p;
                        int nb = (int)need;
                        long long cntL = (sz_sub <= 6)
                                             ? lookup(dp[sub], nb)
                                             : self(self, sub, nb);
                        if (cntL > 0) total += 1LL * cntR * cntL;
                    }
                }
            }
            return total;
        };

        int full = (1 << n) - 1;
        long long ans = 0;

        // ---- 7. n ≤ max_store：直接从 dp[full] 查找（full 的 dp 已存储）----
        if (n <= max_store) {
            return (int)lookup(dp[full], target);
        }

        // ---- 8. n = 8 或 n = 9 的统一处理 ----
        for (int L = 1; L < full; L++) {
            int R = full ^ L;
            int szL = __builtin_popcount(L);
            int szR = n - szL;

            // 两侧均已存储（均 ≤ 6）：标准 hash-join
            if (szL <= 6 && szR <= 6) {
                int aL = a_val[L], aR = a_val[R];
                int C = (int)((10LL * aL % p) * aR % p + 9) % p;
                int coeff_bL = (int)(10LL * aR % p);

                if (dp[L].size() <= dp[R].size()) {
                    for (auto &[bL, cntL] : dp[L]) {
                        long long need =
                            (target - C - 1LL * coeff_bL * bL) % p;
                        if (need < 0) need += p;
                        need = need * inv10 % p;
                        int nb = (int)need;
                        auto it = lower_bound(dp[R].begin(), dp[R].end(),
                                              make_pair(nb, 0));
                        if (it != dp[R].end() && it->first == nb) {
                            ans += 1LL * cntL * it->second;
                        }
                    }
                } else {
                    int inv_coeff = (int)(1LL * inv10 * inv_a[R] % p);
                    for (auto &[bR, cntR] : dp[R]) {
                        long long need =
                            (target - C - 10LL * bR) % p;
                        if (need < 0) need += p;
                        need = need * inv_coeff % p;
                        int nb = (int)need;
                        auto it = lower_bound(dp[L].begin(), dp[L].end(),
                                              make_pair(nb, 0));
                        if (it != dp[L].end() && it->first == nb) {
                            ans += 1LL * cntR * it->second;
                        }
                    }
                }
            }
            // 一侧大小为 7 或 8：使用递归 count_b
            else {
                int small_side, big_side;
                bool big_is_right;
                if (szL <= szR) {
                    small_side = L;
                    big_side = R;
                    big_is_right = true;
                } else {
                    small_side = R;
                    big_side = L;
                    big_is_right = false;
                }

                int a_small = a_val[small_side];
                int a_big = a_val[big_side];
                int C, coeff_small;

                if (big_is_right) {
                    // b_root = (C + coeff * b_small + 10 * b_big) % p
                    C = (int)((10LL * a_small % p) * a_big % p + 9) % p;
                    coeff_small = (int)(10LL * a_big % p);
                    for (auto &[bS, cntS] : dp[small_side]) {
                        long long need =
                            (target - C - 1LL * coeff_small * bS) % p;
                        if (need < 0) need += p;
                        need = need * inv10 % p;
                        int nb = (int)need;
                        long long cntB = count_b(count_b, big_side, nb);
                        if (cntB > 0) ans += 1LL * cntS * cntB;
                    }
                } else {
                    // big 在左，small 在右
                    // b_root = (C + coeff_big * b_big + 10 * b_small) % p
                    C = (int)((10LL * a_big % p) * a_small % p + 9) % p;
                    coeff_small = (int)(10LL * a_small % p);
                    // 注意：coeff 在这里对应的是 big 侧的 b
                    for (auto &[bS, cntS] : dp[small_side]) {
                        // need_big = (target - C - 10*bS) * inv(coeff_big)
                        long long need =
                            (target - C - 10LL * bS) % p;
                        if (need < 0) need += p;
                        int inv_coeff =
                            (int)(1LL * inv10 * inv_a[small_side] % p);
                        need = need * inv_coeff % p;
                        int nb = (int)need;
                        long long cntB = count_b(count_b, big_side, nb);
                        if (cntB > 0) ans += 1LL * cntS * cntB;
                    }
                }
            }
        }

        return (int)ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2\n11391299`>\n
// @lcpr case=end

// @lcpr case=start
// [3,21\n5`>\n
// @lcpr case=end

 */
