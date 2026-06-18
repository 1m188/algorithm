/*
 * @lc app=leetcode.cn id=LCP 82 lang=javascript
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
 * Total Submissions: 10.2K
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
 * @param {number[]} gem
 * @param {number} p
 * @param {number} target
 * @return {number}
 */
var treeOfInfiniteSouls = function (gem, p, target) {
    const n = gem.length;

    // 特殊处理 p=2 或 p=5：
    // 序列总是以 "9" 结尾，故数字恒为奇数（mod 2 = 1）或恒为 9 (mod 5 = 4)
    // 所有二叉树得到相同的 mod p 值，与宝石分配及树结构无关
    if (p === 2 || p === 5) {
        const constVal = 9 % p;
        if (target !== constVal) return 0;
        // 总方案数 = Catalan(n-1) * n!（单个宝石时仅为 1）
        if (n <= 1) return 1;
        // 计算 Catalan(n-1)
        let catalan = 1; // C_0 = 1
        for (let i = 1; i <= n - 1; i++) {
            catalan = catalan * (4 * i - 2) / (i + 1);
        }
        // 乘以 n!
        let fact = 1;
        for (let i = 2; i <= n; i++) fact *= i;
        return catalan * fact;
    }

    // ---------- 预处理 ----------

    // 每颗宝石的十进制位数
    const digLen = new Array(n);
    for (let i = 0; i < n; i++) {
        digLen[i] = gem[i] === 0 ? 1 : Math.floor(Math.log10(gem[i])) + 1;
    }

    const totalMasks = 1 << n;
    const lenArr = new Array(totalMasks);
    const pop = new Array(totalMasks);
    for (let mask = 0; mask < totalMasks; mask++) {
        let k = 0;
        let sumDig = 0;
        let m = mask;
        while (m) {
            const lsb = m & -m;
            const idx = 31 - Math.clz32(lsb);
            k++;
            sumDig += digLen[idx];
            m ^= lsb;
        }
        pop[mask] = k;
        lenArr[mask] = k === 0 ? 0 : 4 * k - 2 + sumDig;
    }

    // 10 的幂次模 p
    const maxLen = lenArr[totalMasks - 1];
    const pow10 = new Array(maxLen + 1);
    pow10[0] = 1 % p;
    for (let i = 1; i <= maxLen; i++) {
        pow10[i] = (pow10[i - 1] * 10) % p;
    }

    // BigInt 安全模乘
    const modMul = (a, b) => {
        return Number((BigInt(a) * BigInt(b)) % BigInt(p));
    };

    // 扩展欧几里得求模逆
    const modInv = (a, mod) => {
        let t = 0, newt = 1;
        let r = mod, newr = a;
        while (newr !== 0) {
            const q = Math.floor(r / newr);
            const tmp = newt;
            newt = t - q * newt;
            t = tmp;
            const tmpR = newr;
            newr = r - q * newr;
            r = tmpR;
        }
        if (t < 0) t += mod;
        return t;
    };

    // 10 的逆元（p 已保证与 10 互质）
    const inv10 = modInv(10, p);

    // 模正归一化：确保结果在 [0, p) 内
    const norm = (x) => {
        x %= p;
        if (x < 0) x += p;
        return x;
    };

    // ---------- 预计算 dp[mask]（仅对大小 ≤ 5 的子集存储完整 Map）----------
    const MAX_PRECOMP = Math.min(n, 5);
    const dp = new Array(totalMasks);
    for (let mask = 0; mask < totalMasks; mask++) dp[mask] = null;

    // 单颗宝石（叶节点）
    for (let i = 0; i < n; i++) {
        const mask = 1 << i;
        const d = digLen[i];
        // 叶节点序列 "1" + str(g) + "9" 对应的数值：10^{d+1} + g*10 + 9
        const val = (pow10[d + 1] + (gem[i] * 10) % p + 9) % p;
        const map = new Map();
        map.set(val, 1);
        dp[mask] = map;
    }

    const fullMask = totalMasks - 1;

    // 按大小递增顺序预计算 dp
    for (let k = 2; k <= MAX_PRECOMP; k++) {
        for (let mask = 1; mask <= fullMask; mask++) {
            if (pop[mask] !== k) continue;

            const curMap = new Map();
            let L = mask;
            while (L) {
                L = (L - 1) & mask;
                if (L === 0) continue;
                const R = mask ^ L;

                const dpL = dp[L], dpR = dp[R];
                if (!dpL || !dpR) continue;

                const lenL = lenArr[L], lenR = lenArr[R];
                // 组合公式：val = 10^{lenL+lenR+1} + vL·10^{lenR+1} + vR·10 + 9
                const P1 = pow10[lenL + lenR + 1];
                const P2 = pow10[lenR + 1];
                const C = 10 % p;
                const D = 9 % p;

                for (const _pairL of dpL) {
                    const vL = _pairL[0], cntL = _pairL[1];
                    const termL = (P1 + modMul(vL, P2) + D) % p;
                    for (const _pairR of dpR) {
                        const vR = _pairR[0], cntR = _pairR[1];
                        const val = (termL + (vR * C) % p) % p;
                        curMap.set(val, (curMap.get(val) || 0) + cntL * cntR);
                    }
                }
            }

            dp[mask] = curMap;
        }
    }

    // ---------- 记忆化递归：计算更大子集的结果 ----------
    const memo = {};

    // 获取 P2 = 10^{lenR+1} 的逆元缓存
    const invP2Cache = {};
    const getInvP2 = (lenR) => {
        if (invP2Cache[lenR] === undefined) {
            invP2Cache[lenR] = modInv(pow10[lenR + 1], p);
        }
        return invP2Cache[lenR];
    };

    // 递归求解：返回使用 mask 中宝石、生成数值 ≡ targetVal (mod p) 的二叉树数目
    const solve = (mask, targetVal) => {
        // 已预计算的小子集直接查表
        if (dp[mask] !== null) {
            return dp[mask].get(targetVal) || 0;
        }

        const key = mask + ',' + targetVal;
        if (key in memo) return memo[key];

        let ans = 0;

        // 枚举所有非空真子集 L 作为左子树
        let L = mask;
        while (L) {
            L = (L - 1) & mask;
            if (L === 0) continue;
            const R = mask ^ L;

            const lenL = lenArr[L], lenR = lenArr[R];
            const P1 = pow10[lenL + lenR + 1];
            const P2 = pow10[lenR + 1];
            const C = 10 % p;    // 对于 p ≠ 2,5 恒有 C ≠ 0
            const D = 9 % p;

            // 选择 dp 条目更少的一侧进行迭代
            if (dp[L] !== null && dp[R] !== null) {
                if (dp[L].size <= dp[R].size) {
                    for (const _pairL of dp[L]) {
                        const vL = _pairL[0], cntL = _pairL[1];
                        // 注意：norm 结果 × inv10 可能溢出 Number，必须用 BigInt
                        const neededVR = modMul(norm(targetVal - P1 - modMul(vL, P2) - D), inv10);
                        ans += cntL * (dp[R].get(neededVR) || 0);
                    }
                } else {
                    const invP2 = getInvP2(lenR);
                    for (const _pairR of dp[R]) {
                        const vR = _pairR[0], cntR = _pairR[1];
                        const neededVL = modMul(norm(targetVal - P1 - (vR * C) % p - D), invP2);
                        ans += cntR * (dp[L].get(neededVL) || 0);
                    }
                }
            } else if (dp[L] !== null) {
                for (const _pairL of dp[L]) {
                    const vL = _pairL[0], cntL = _pairL[1];
                    const neededVR = modMul(norm(targetVal - P1 - modMul(vL, P2) - D), inv10);
                    ans += cntL * solve(R, neededVR);
                }
            } else if (dp[R] !== null) {
                const invP2 = getInvP2(lenR);
                for (const _pairR of dp[R]) {
                    const vR = _pairR[0], cntR = _pairR[1];
                    const neededVL = modMul(norm(targetVal - P1 - (vR * C) % p - D), invP2);
                    ans += cntR * solve(L, neededVL);
                }
            }
        }

        memo[key] = ans;
        return ans;
    };

    // 对于 n ≤ MAX_PRECOMP，已全部预计算完毕
    if (n <= MAX_PRECOMP) {
        return dp[fullMask].get(target) || 0;
    }

    return solve(fullMask, target);
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

