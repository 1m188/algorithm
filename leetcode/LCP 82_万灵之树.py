#
# @lc app=leetcode.cn id=LCP 82 lang=python3
# @lcpr version=30204
#
# [LCP 82] 万灵之树
#
# https://leetcode.cn/problems/cnHoX6/description/
#
# algorithms
# Hard (14.30%)
# Likes:    19
# Dislikes: 0
# Total Accepted:    1.4K
# Total Submissions: 9.9K
# Testcase Example:  '[2,3]\n100000007\n11391299'
#
# 探险家小扣终于来到了万灵之树前，挑战最后的谜题。
# 已知小扣拥有足够数量的链接节点和 `n` 颗幻境宝石，`gem[i]` 表示第 `i`
# 颗宝石的数值。现在小扣需要使用这些链接节点和宝石组合成一颗二叉树，其组装规则为：
# - 链接节点将作为二叉树中的非叶子节点，且每个链接节点必须拥有 `2` 个子节点；
# - 幻境宝石将作为二叉树中的叶子节点，所有的幻境宝石都必须被使用。
#
# 能量首先进入根节点，而后将按如下规则进行移动和记录：
# - 若能量首次到达该节点时：
# ⁠   - 记录数字 `1`；
# ⁠   - 若该节点为叶节点，将额外记录该叶节点的数值；
# - 若存在未到达的子节点，则选取未到达的一个子节点（优先选取左子节点）进入；
# - 若无子节点或所有子节点均到达过，此时记录 `9`，并回到当前节点的父节点（若存在）。
#
# 如果最终记下的数依序连接成一个整数 `num`，满足 $num \mod~p=target$，则视为解开谜题。
# 请问有多少种二叉树的组装方案，可以使得最终记录下的数字可以解开谜题
#
# **注意：**
# - 两棵结构不同的二叉树，作为不同的组装方案
# - 两棵结构相同的二叉树且存在某个相同位置处的宝石编号不同，也作为不同的组装方案
# - 可能存在数值相同的两颗宝石
#
# **示例 1：**
# > 输入：`gem = [2,3]`
# > `p = 100000007`
# > `target = 11391299`
# >
# > 输出：`1`
# >
# > 解释：
# > 包含 `2` 个叶节点的结构只有一种。
# > 假设 B、C 节点的值分别为 3、2，对应 target 为 11391299，如下图所示。
# > 11391299 % 100000007 = 11391299，满足条件;
# > 假设 B、C 节点的值分别为 2、3，对应 target 为 11291399;
# > 11291399 % 100000007 = 11291399，不满足条件；
# > 因此只存在 1 种方案，返回 1
# ![万灵
# (1).gif](https://pic.leetcode.cn/1682397079-evMssw-%E4%B8%87%E7%81%B5%20\(1\).gif){:height=300px}
#
#
# **示例 2：**
# > 输入：`gem = [3,21,3]`
# > `p = 7`
# > `target = 5`
# >
# > 输出：`4`
# >
# > 解释：
# 包含 `3` 个叶节点树结构有两种，列举如下：
# 满足条件的组合有四种情况：
# > 当结构为下图（1）时：叶子节点的值为 [3,3,21] 或 [3,3,21]，得到的整数为 `11139139912199`。
# > 当结构为下图（2）时：叶子节点的值为 [21,3,3] 或 [21,3,3]，得到的整数为 `11219113913999`。
#
# ![image.png](https://pic.leetcode.cn/1682322894-vfqJIV-image.png){:width=500px}
#
#
# **提示：**
# - `1 <= gem.length <= 9`
# - `0 <= gem[i] <= 10^9`
# - `1 <= p <= 10^9`，保证 $p$ 为素数。
# - `0 <= target < p`
# - 存在 2 组 `gem.length == 9` 的用例
#


# @lcpr-template-start
from typing import List
import math


# @lcpr-template-end
# @lc code=start
class Solution:
    def treeOfInfiniteSouls(self, gem: List[int], p: int, target: int) -> int:
        n = len(gem)

        # p=2 or p=5: 10 is not invertible modulo p
        # The traversal always ends with "9", so num % 2 == 9 % 2 == 1,
        # num % 5 == 9 % 5 == 4
        if p == 2 or p == 5:
            catalan = math.comb(2 * (n - 1), n - 1) // n if n >= 1 else 1
            total = catalan * math.factorial(n)
            if p == 2:
                return total if target == 1 else 0
            else:
                return total if target == 4 else 0

        # digit lengths of each gem
        d = [len(str(x)) for x in gem]

        # maximum possible string length
        max_len = sum(d) + 4 * n - 2

        # pow10[i] = 10^i % p
        pow10 = [1] * (max_len + 1)
        for i in range(1, max_len + 1):
            pow10[i] = (pow10[i - 1] * 10) % p

        # modular inverse of 10 modulo p (p is prime and p != 2,5)
        inv10 = pow(10, p - 2, p)

        # pinv10[i] = inv10^i mod p
        pinv10 = [1] * (max_len + 1)
        for i in range(1, max_len + 1):
            pinv10[i] = (pinv10[i - 1] * inv10) % p

        # leaf_val[i], leaf_len[i] for each gem
        leaf_val = [0] * n
        leaf_len = [0] * n
        for i, x in enumerate(gem):
            leaf_len[i] = d[i] + 2
            leaf_val[i] = (pow10[d[i] + 1] + x * 10 + 9) % p

        total_masks = 1 << n

        # len_full[mask] = total string length for a full binary tree
        # with gems in mask. Formula: sum(d_i) + 4*k - 2
        len_full = [0] * total_masks
        for mask in range(1, total_masks):
            k = mask.bit_count()
            s = 0
            m = mask
            while m:
                lb = m & -m
                idx = lb.bit_length() - 1
                s += d[idx]
                m ^= lb
            len_full[mask] = s + 4 * k - 2

        # full[mask] = dict {mod_val: count} for full binary trees
        full = [None] * total_masks

        def compute_full(mask: int) -> dict:
            if full[mask] is not None:
                return full[mask]

            k = mask.bit_count()
            if k == 1:
                idx = (mask & -mask).bit_length() - 1
                full[mask] = {leaf_val[idx]: 1}
                return full[mask]

            result = {}
            sub = (mask - 1) & mask
            len_mask = len_full[mask]
            while sub:
                left = sub
                right = mask ^ sub
                full_L = compute_full(left)
                full_R = compute_full(right)
                lenL = len_full[left]
                lenR = len_full[right]

                # val = (10^{lenL+lenR+1} + val_L * 10^{lenR+1} + val_R * 10 + 9) % p
                base = (pow10[lenL + lenR + 1] + 9) % p
                pow10_lenR1 = pow10[lenR + 1]
                for val_L, cnt_L in full_L.items():
                    term_L = (val_L * pow10_lenR1) % p
                    add_L = (base + term_L) % p
                    for val_R, cnt_R in full_R.items():
                        new_val = (add_L + val_R * 10) % p
                        result[new_val] = result.get(new_val, 0) + cnt_L * cnt_R
                sub = (sub - 1) & mask

            full[mask] = result
            return result

        # Precompute full for masks of size <= 6
        B = min(n, 6)
        for mask in range(1, total_masks):
            if mask.bit_count() <= B:
                compute_full(mask)

        # top-down counting with memoization
        memo_count = {}

        def count(mask: int, target_mod: int) -> int:
            k = mask.bit_count()
            if k <= B:
                return full[mask].get(target_mod, 0)

            key = (mask, target_mod)
            if key in memo_count:
                return memo_count[key]

            total = 0
            sub = (mask - 1) & mask
            while sub:
                left = sub
                right = mask ^ sub
                kL = left.bit_count()
                kR = right.bit_count()
                lenL = len_full[left]
                lenR = len_full[right]

                if kL <= B and kL <= kR:
                    full_L = full[left]
                    base = (pow10[lenL + lenR + 1] + 9) % p
                    term_mult = pow10[lenR + 1]
                    for val_L, cnt_L in full_L.items():
                        needed_R = (
                            ((target_mod - base - val_L * term_mult) % p) * inv10 % p
                        )
                        cnt_R = count(right, needed_R)
                        if cnt_R:
                            total += cnt_L * cnt_R
                elif kR <= B:
                    full_R = full[right]
                    base = (pow10[lenL + lenR + 1] + 9) % p
                    for val_R, cnt_R in full_R.items():
                        needed_L = (
                            ((target_mod - base - val_R * 10) % p)
                            * pinv10[lenR + 1]
                            % p
                        )
                        cnt_L = count(left, needed_L)
                        if cnt_L:
                            total += cnt_L * cnt_R

                sub = (sub - 1) & mask

            memo_count[key] = total
            return total

        return count(total_masks - 1, target)


# @lc code=end


#
# @lcpr case=start
# [2\n11391299`>\n
# @lcpr case=end

# @lcpr case=start
# [3,21\n5`>\n
# @lcpr case=end

#
