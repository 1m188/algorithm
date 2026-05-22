#
# @lc app=leetcode.cn id=LCP 60 lang=python3
# @lcpr version=30204
#
# [LCP 60] 力扣泡泡龙
#
# https://leetcode.cn/problems/WInSav/description/
#
# algorithms
# Hard (20.58%)
# Likes:    16
# Dislikes: 0
# Total Accepted:    1.5K
# Total Submissions: 7.2K
# Testcase Example:  '[6,0,3,null,8]'
#
# 欢迎各位勇者来到力扣城，本次试炼主题为「力扣泡泡龙」。
#
# 游戏初始状态的泡泡形如二叉树 `root`，每个节点值对应了该泡泡的分值。勇者最多可以击破一个节点泡泡，要求满足：
# - 被击破的节点泡泡 **至多** 只有一个子节点泡泡
# - 当被击破的节点泡泡有子节点泡泡时，则子节点泡泡将取代被击破泡泡的位置
# ⁠   > 注：即整棵子树泡泡上移
#
# 请问在击破一个节点泡泡操作或无击破操作后，二叉泡泡树的最大「层和」是多少。
#
# **注意：**
# - 「层和」为同一高度的所有节点的分值之和
#
# **示例 1：**
# > 输入：`root = [6,0,3,null,8]`
# >
# > 输出：`11`
# >
# > 解释：勇者的最佳方案如图所示
#
# >![image.png](https://pic.leetcode.cn/1648180809-XSWPLu-image.png){:height="100px"}
#
#
#
# **示例 2：**
# > 输入：`root = [5,6,2,4,null,null,1,3,5]`
# >
# > 输出：`9`
# >
# > 解释：勇者击破 6 节点，此时「层和」最大为 3+5+1 = 9
#
# >![image.png](https://pic.leetcode.cn/1648180769-TLpYop-image.png){:height="200px"}
#
#
#
# **示例 3：**
# > 输入：`root = [-5,1,7]`
# >
# > 输出：`8`
# >
# > 解释：勇者不击破节点，「层和」最大为 1+7 = 8
#
#
# **提示**：
# - `2 <= 树中节点个数 <= 10^5`
# - `-10000 <= 树中节点的值 <= 10000`
#
#


# @lcpr-template-start
from typing import Optional


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def getMaxLayerSum(self, root: Optional[TreeNode]) -> int:
        # ---------- pass 1: BFS for depths + per-level sums / counts ----------
        from collections import deque

        node_depth = {}
        S = {}
        cnt = {}
        q = deque([(root, 0)])
        while q:
            node, d = q.popleft()
            node_depth[node] = d
            S[d] = S.get(d, 0) + node.val
            cnt[d] = cnt.get(d, 0) + 1
            if node.left:
                q.append((node.left, d + 1))
            if node.right:
                q.append((node.right, d + 1))

        max_depth = max(S.keys())
        S_arr = [S[d] for d in range(max_depth + 1)]
        cnt_arr = [cnt[d] for d in range(max_depth + 1)]

        pref_max = [float("-inf")] * (max_depth + 1)
        pref_max[0] = S_arr[0]
        for i in range(1, len(pref_max)):
            pref_max[i] = max(pref_max[i - 1], S_arr[i])

        suff_max = [float("-inf")] * (max_depth + 1)
        suff_max[-1] = S_arr[-1]
        for i in range(len(suff_max) - 2, -1, -1):
            suff_max[i] = max(suff_max[i + 1], S_arr[i])

        def pref(d: int) -> int:
            if d < 0:
                return float("-inf")
            return pref_max[d]

        def suff(d: int) -> int:
            if d > max_depth:
                return float("-inf")
            return suff_max[d]

        ans = max(S_arr)

        # ---------- pass 2: iterative post-order ----------
        post_order = []
        stack = [(root, False)]
        while stack:
            node, visited = stack.pop()
            if visited:
                post_order.append(node)
            else:
                stack.append((node, True))
                if node.right:
                    stack.append((node.right, False))
                if node.left:
                    stack.append((node.left, False))

        H_map = {}  # node -> H dict
        # For each node store (best_val, best_dep, best2_val, best2_dep)
        best_info = {}

        def _add_best(b1, d1, b2, d2, val, dep):
            """Insert (val, dep) into top-2 tracker, returning new (b1,d1,b2,d2)."""
            if val > b1:
                return val, dep, b1, d1
            elif val > b2:
                return b1, d1, val, dep
            return b1, d1, b2, d2

        for node in post_order:
            d = node_depth[node]
            left = node.left
            right = node.right
            children = [c for c in (left, right) if c]
            num_children = len(children)

            # ---------- build H ----------
            if num_children == 0:
                H = {}
                b1, d1, b2, d2 = float("-inf"), -1, float("-inf"), -1
            elif num_children == 1:
                c = children[0]
                H = H_map.pop(c)
                b1, d1, b2, d2 = best_info.pop(c)
                child_below = b1  # save for candidate evaluation
            else:
                # two children: small-to-large merge + incremental best update
                H_left = H_map.pop(left)
                H_right = H_map.pop(right)
                b1L, d1L, b2L, d2L = best_info.pop(left)
                b1R, d1R, b2R, d2R = best_info.pop(right)

                if len(H_left) >= len(H_right):
                    H = H_left
                    other = H_right
                    b1_orig, d1_orig = b1L, d1L
                    b2_orig, d2_orig = b2L, d2L
                else:
                    H = H_right
                    other = H_left
                    b1_orig, d1_orig = b1R, d1R
                    b2_orig, d2_orig = b2R, d2R

                affected = set()

                for dep, (s_val, c_val) in other.items():
                    if dep in H:
                        H[dep][0] += s_val
                        H[dep][1] += c_val
                    else:
                        H[dep] = [s_val, c_val]
                    affected.add(dep)
                    if dep - 1 > d:
                        affected.add(dep - 1)

                # recompute X from scratch for affected depths + unaffected original tops
                b1, d1, b2, d2 = float("-inf"), -1, float("-inf"), -1

                for dep in affected:
                    hs, hc = H[dep]
                    hs_d1, hc_d1 = H.get(dep + 1, [0, 0])
                    if cnt_arr[dep] - hc + hc_d1 > 0:
                        cand = S_arr[dep] - hs + hs_d1
                        b1, d1, b2, d2 = _add_best(b1, d1, b2, d2, cand, dep)
                    dm1 = dep - 1
                    if dm1 > d and dm1 not in affected:
                        hs_dm1, hc_dm1 = H.get(dm1, [0, 0])
                        if cnt_arr[dm1] - hc_dm1 + hc > 0:
                            cand2 = S_arr[dm1] - hs_dm1 + hs
                            b1, d1, b2, d2 = _add_best(b1, d1, b2, d2, cand2, dm1)

                # re-add original top values if their depths were unaffected
                if d1_orig not in affected and d1_orig > d:
                    b1, d1, b2, d2 = _add_best(b1, d1, b2, d2, b1_orig, d1_orig)
                if d2_orig not in affected and d2_orig > d:
                    b1, d1, b2, d2 = _add_best(b1, d1, b2, d2, b2_orig, d2_orig)

            # ---------- add the node itself ----------
            if d in H:
                H[d][0] += node.val
                H[d][1] += 1
            else:
                H[d] = [node.val, 1]

            # ---------- X at the node's own depth ----------
            hs_d, hc_d = H[d]
            hs_d1, hc_d1 = H.get(d + 1, [0, 0])
            if cnt_arr[d] - hc_d + hc_d1 > 0:
                X_self = S_arr[d] - hs_d + hs_d1
                b1, d1, b2, d2 = _add_best(b1, d1, b2, d2, X_self, d)

            best_below = b1

            # ---------- evaluate candidate ----------
            if num_children <= 1:
                if num_children == 0:
                    prefix = pref(d - 1)
                    suffix = suff(d + 1)
                    cand = prefix if prefix > suffix else suffix
                    if cnt_arr[d] > 1:
                        leaf_val = S_arr[d] - node.val
                        if leaf_val > cand:
                            cand = leaf_val
                    if cand > ans:
                        ans = cand
                else:
                    c = children[0]
                    prefix = pref(d - 1)
                    cand = prefix
                    mid = S_arr[d] - node.val + c.val
                    if mid > cand:
                        cand = mid
                    if child_below > cand:
                        cand = child_below
                    if cand > ans:
                        ans = cand

            H_map[node] = H
            best_info[node] = (b1, d1, b2, d2)

        return ans


# @lc code=end


#
# @lcpr case=start
# [6,0,3,null,8]`>\n
# @lcpr case=end

# @lcpr case=start
# [5,6,2,4,null,null,1,3,5]`>\n
# @lcpr case=end

# @lcpr case=start
# [-5,1,7]`>\n
# @lcpr case=end

#
