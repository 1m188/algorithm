/*
 * @lc app=leetcode.cn id=LCP 82 lang=typescript
 * @lcpr version=30204
 *
 * [LCP 82] 万灵之树
 *
 * https://leetcode.cn/problems/cnHoX6/description/
 *
 * algorithms
 * Hard (14.82%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    1.5K
 * Total Submissions: 10.3K
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
 * ⁠   - 记录数字 `1`；
 * ⁠   - 若该节点为叶节点，将额外记录该叶节点的数值；
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

// @lcpr-template-end
// @lc code=start

/**
 * 整体解题思路：
 *
 * 本题要求统计所有满足条件的二叉树组装方案数量。二叉树为满二叉树（每个内部节点均有
 * 左右两个子节点），n 颗宝石（gem）作为叶子节点。遍历规则为深度优先搜索：
 *   - 首次到达节点时记录 "1"
 *   - 若为叶子节点，额外记录该叶子节点的数值
 *   - 所有子节点访问完毕后记录 "9" 并回溯
 *
 * 因此，对于一棵子树，其遍历生成的字符串模式为：
 *   叶子节点：  "1" + value_str + "9"
 *   内部节点：  "1" + left_str + right_str + "9"
 *
 * 最终需要统计生成的整数 num 满足 num % p == target 的方案数。
 *
 * 由于 gem.length ≤ 9，采用 meet-in-the-middle 状态压缩动态规划：
 *   1. 预计算所有元素个数 ≤ 5 的子集的 DP（Map: mod -> count）直接缓存
 *   2. 对于全集合及元素数 ≥ 6 的子集，递归拆分至 ≤5 的子集后通过模逆元
 *      反查匹配项，避免构建大型 DP 表导致内存溢出
 *
 * 时间复杂度：O(∑_{k=1}^5 C(n,k) * k! * Catalan(k-1) + 递归层数 × 子集枚举)
 *           其中 n ≤ 9，Catalan(k-1) 为满二叉树结构数，递归至多 2 层
 * 空间复杂度：DP 表仅缓存 size≤5 的子集映射，最坏约 228K 个键值对
 */

function treeOfInfiniteSouls(gem: number[], p: number, target: number): number {
    const n = gem.length;

    // ---------- 工具函数 ----------

    /** 快速模幂 (a^b mod m)，用于计算模逆元 */
    function modPow(a: number, b: number, m: number): number {
        let result = 1 % m;
        let base = a % m;
        while (b > 0) {
            if (b & 1) result = Number((BigInt(result) * BigInt(base)) % BigInt(m));
            base = Number((BigInt(base) * BigInt(base)) % BigInt(m));
            b >>= 1;
        }
        return result;
    }

    /** 计算非负整数 v 的十进制位数 */
    function digitCount(v: number): number {
        if (v === 0) return 1;
        return Math.floor(Math.log10(v)) + 1;
    }

    // ---------- 预处理 ----------

    const totalMasks = 1 << n;

    // digit[i] = 第 i 颗宝石的十进制位数
    const digit: number[] = new Array(n);
    for (let i = 0; i < n; i++) {
        digit[i] = digitCount(gem[i]);
    }

    // 预计算每个子集的 popcount 与长度
    const pop: number[] = new Array(totalMasks).fill(0);
    const len: number[] = new Array(totalMasks).fill(0);
    for (let mask = 1; mask < totalMasks; mask++) {
        pop[mask] = pop[mask >> 1] + (mask & 1);
    }
    for (let mask = 1; mask < totalMasks; mask++) {
        let dsum = 0;
        for (let i = 0; i < n; i++) {
            if (mask & (1 << i)) dsum += digit[i];
        }
        // 长度公式：每个叶子贡献 "1"+value+"9"=2+digit，内部节点贡献 "1"+"9"=2
        // 总长度 = 4*叶子数 - 2 + 数字位数总和
        len[mask] = 4 * pop[mask] - 2 + dsum;
    }

    const maxLen = len[totalMasks - 1];

    // pow10[i] = 10^i mod p
    const pow10: number[] = new Array(maxLen + 1);
    pow10[0] = 1 % p;
    for (let i = 1; i <= maxLen; i++) {
        pow10[i] = Number((BigInt(pow10[i - 1]) * 10n) % BigInt(p));
    }

    // 10 的模逆元 (p 为素数且 p≠2,5 时 gcd(10,p)=1)
    const inv10: number = (p === 2 || p === 5) ? 0 : modPow(10, p - 2, p);

    // powInv10[i] = (10^i)^(-1) mod p = inv10^i mod p (仅 p≠2,5 时有效)
    const powInv10: number[] = new Array(maxLen + 1);
    powInv10[0] = 1 % p;
    for (let i = 1; i <= maxLen; i++) {
        powInv10[i] = Number((BigInt(powInv10[i - 1]) * BigInt(inv10 || 0)) % BigInt(p));
    }

    // p=2 或 p=5 时的特殊处理：
    // 10 ≡ 0 (mod p)，所有含因子 10 的项均变为 0，最终 num ≡ 9 (mod p)
    // 此时结果与宝石数值及二叉树结构均无关，所有方案要么全满足要么全不满足
    // 注意：宝石以索引区分，即使数值相同也算不同方案，故不除以重复排列数
    if (p === 2 || p === 5) {
        if (target !== 9 % p) return 0;
        // 卡特兰数 C_{n-1}（n 个叶子的满二叉树结构数）
        const catalan: number[] = [1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862];
        let total = catalan[n - 1];
        for (let i = 1; i <= n; i++) total *= i;
        return total;
    }

    // ---------- DP 表 ----------
    // dp[mask] = Map<mod, count>  仅对 popcount ≤ 5 的子集存储
    const dp: Map<number, number>[] = new Array(totalMasks);
    for (let i = 0; i < totalMasks; i++) dp[i] = new Map();

    // 按 popcount 分组以方便递推
    const masksBySize: number[][] = new Array(n + 1);
    for (let i = 0; i <= n; i++) masksBySize[i] = [];
    for (let mask = 1; mask < totalMasks; mask++) {
        masksBySize[pop[mask]].push(mask);
    }

    // ---------- 基础：大小为 1 的子集（叶子节点） ----------
    for (let i = 0; i < n; i++) {
        const mask = 1 << i;
        const v = gem[i];
        const d = digit[i];
        // 叶子字符串 "1" + v_str + "9"
        // 整数值 = 10^(d+1) + v*10 + 9
        const val = Number(
            (BigInt(pow10[d + 1]) + BigInt((v % p) * 10) + 9n) % BigInt(p),
        );
        dp[mask].set(val, 1);
    }

    // ---------- 递推：大小为 2 到 5 的子集 ----------
    for (let size = 2; size <= Math.min(5, n); size++) {
        for (const mask of masksBySize[size]) {
            const map = dp[mask];

            // 枚举所有非空真子集作为左子树
            let sub = (mask - 1) & mask;
            while (sub > 0) {
                const comp = mask ^ sub;
                const leftMap = dp[sub];
                const rightMap = dp[comp];

                const lenL = len[sub];
                const lenR = len[comp];

                // 预计算的 10 的幂
                const p10_r1 = pow10[lenR + 1]; // 10^(lenR+1)
                const p10_lr1 = pow10[lenL + lenR + 1]; // 10^(lenL+lenR+1)

                // 组合公式:
                // parent = 10^(lenL+lenR+1) + leftVal * 10^(lenR+1) + rightVal*10 + 9
                for (const [modL, cntL] of leftMap) {
                    const termL = Number((BigInt(modL) * BigInt(p10_r1)) % BigInt(p));
                    for (const [modR, cntR] of rightMap) {
                        const newMod = Number(
                            (BigInt(p10_lr1) + BigInt(termL) +
                                BigInt(modR) * 10n + 9n) % BigInt(p),
                        );
                        const existing = map.get(newMod) || 0;
                        map.set(newMod, existing + cntL * cntR);
                    }
                }

                sub = (sub - 1) & mask;
            }
        }
    }

    // ---------- 若 n ≤ 5，直接从 DP 表查全集合结果 ----------
    if (n <= 5) {
        return dp[totalMasks - 1].get(target % p) || 0;
    }

    // ---------- n ≥ 6：递归计数函数 ----------
    // 对于元素数 ≤ 5 的子集直接从 DP 表查询，对于更大的子集递归拆分计算
    function countSubtree(mask: number, targetMod: number): number {
        if (pop[mask] <= 5) {
            return dp[mask].get(targetMod) || 0;
        }

        let total = 0;
        let sub = (mask - 1) & mask;
        while (sub > 0) {
            const comp = mask ^ sub;
            const lenL = len[sub];
            const lenR = len[comp];
            const p10_r1 = pow10[lenR + 1];
            const p10_lr1 = pow10[lenL + lenR + 1];

            // 遍历较小一方的 DP 表，另一方通过解线性同余方程反查
            if (pop[sub] <= pop[comp]) {
                for (const [modL, cntL] of dp[sub]) {
                    const rhs = Number(
                        (BigInt(targetMod) - BigInt(p10_lr1) -
                            BigInt(modL) * BigInt(p10_r1) - 9n) %
                        BigInt(p),
                    );
                    const needR = Number(
                        (BigInt(((rhs % p) + p) % p) * BigInt(inv10)) % BigInt(p),
                    );
                    const cntR = countSubtree(comp, needR);
                    if (cntR > 0) total += cntL * cntR;
                }
            } else {
                for (const [modR, cntR] of dp[comp]) {
                    const rhs = Number(
                        (BigInt(targetMod) - BigInt(p10_lr1) -
                            BigInt(modR) * 10n - 9n) %
                        BigInt(p),
                    );
                    const invFactor = powInv10[lenR + 1];
                    const needL = Number(
                        (BigInt(((rhs % p) + p) % p) * BigInt(invFactor)) %
                        BigInt(p),
                    );
                    const cntL = countSubtree(sub, needL);
                    if (cntL > 0) total += cntL * cntR;
                }
            }

            sub = (sub - 1) & mask;
        }
        return total;
    }

    return countSubtree(totalMasks - 1, target % p);
}

// @lc code=end



/*
// @lcpr case=start
// [2\n11391299`>\n
// @lcpr case=end

// @lcpr case=start
// [3,21\n5`>\n
// @lcpr case=end

 */
