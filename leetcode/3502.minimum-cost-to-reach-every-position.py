#
# @lc app=leetcode.cn id=3502 lang=python3
# @lcpr version=30204
#
# [3502] 到达每个位置的最小费用
#
# https://leetcode.cn/problems/minimum-cost-to-reach-every-position/description/
#
# algorithms
# Easy (90.34%)
# Likes:    4
# Dislikes: 0
# Total Accepted:    4.2K
# Total Submissions: 4.7K
# Testcase Example:  '[5,3,4,1,3,2]'
#
# 给你一个长度为 n 的整数数组 cost 。当前你位于位置 n（队伍的末尾），队伍中共有 n + 1 人，编号从 0 到 n 。
#
# 你希望在队伍中向前移动，但队伍中每个人都会收取一定的费用才能与你 交换位置。与编号 i 的人交换位置的费用为 cost[i] 。
#
# 你可以按照以下规则与他人交换位置：
#
#
# 如果对方在你前面，你 必须 支付 cost[i] 费用与他们交换位置。
# 如果对方在你后面，他们可以免费与你交换位置。
#
#
# 返回一个大小为 n 的数组 answer，其中 answer[i] 表示到达队伍中每个位置 i 所需的 最小 总费用。
#
#
#
# 示例 1：
#
#
# 输入: cost = [5,3,4,1,3,2]
#
# 输出: [5,3,3,1,1,1]
#
# 解释:
#
# 我们可以通过以下方式到达每个位置：
#
#
# i = 0。可以花费 5 费用与编号 0 的人交换位置。
# i = 1。可以花费 3 费用与编号 1 的人交换位置。
# i = 2。可以花费 3 费用与编号 1 的人交换位置，然后免费与编号 2 的人交换位置。
# i = 3。可以花费 1 费用与编号 3 的人交换位置。
# i = 4。可以花费 1 费用与编号 3 的人交换位置，然后免费与编号 4 的人交换位置。
# i = 5。可以花费 1 费用与编号 3 的人交换位置，然后免费与编号 5 的人交换位置。
#
#
#
# 示例 2：
#
#
# 输入: cost = [1,2,4,6,7]
#
# 输出: [1,1,1,1,1]
#
# 解释:
#
# 可以花费 1 费用与编号 0 的人交换位置，然后可以免费到达队伍中的任何位置 i。
#
#
#
#
# 提示
#
#
# 1 <= n == cost.length <= 100
# 1 <= cost[i] <= 100
#
#
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def minCosts(self, cost: List[int]) -> List[int]:
        res = [0 for _ in range(len(cost))]
        res[0] = cost[0]
        for i in range(1, len(cost)):
            res[i] = min(res[i - 1], cost[i])
        return res


# @lc code=end

#
# @lcpr case=start
# [5,3,4,1,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,4,6,7]\n
# @lcpr case=end

#
