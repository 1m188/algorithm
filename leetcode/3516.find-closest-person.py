#
# @lc app=leetcode.cn id=3516 lang=python3
# @lcpr version=30204
#
# [3516] 找到最近的人
#
# https://leetcode.cn/problems/find-closest-person/description/
#
# algorithms
# Easy (89.60%)
# Likes:    3
# Dislikes: 0
# Total Accepted:    7.3K
# Total Submissions: 8.1K
# Testcase Example:  '2\n7\n4'
#
# 给你三个整数 x、y 和 z，表示数轴上三个人的位置：
#
#
# x 是第 1 个人的位置。
# y 是第 2 个人的位置。
# z 是第 3 个人的位置，第 3 个人 不会移动 。
#
#
# 第 1 个人和第 2 个人以 相同 的速度向第 3 个人移动。
#
# 判断谁会 先 到达第 3 个人的位置：
#
#
# 如果第 1 个人先到达，返回 1 。
# 如果第 2 个人先到达，返回 2 。
# 如果两个人同时到达，返回 0 。
#
#
# 根据上述规则返回结果。
#
#
#
# 示例 1：
#
#
# 输入： x = 2, y = 7, z = 4
#
# 输出： 1
#
# 解释：
#
#
# 第 1 个人在位置 2，到达第 3 个人（位置 4）需要 2 步。
# 第 2 个人在位置 7，到达第 3 个人需要 3 步。
#
#
# 由于第 1 个人先到达，所以输出为 1。
#
#
# 示例 2：
#
#
# 输入： x = 2, y = 5, z = 6
#
# 输出： 2
#
# 解释：
#
#
# 第 1 个人在位置 2，到达第 3 个人（位置 6）需要 4 步。
# 第 2 个人在位置 5，到达第 3 个人需要 1 步。
#
#
# 由于第 2 个人先到达，所以输出为 2。
#
#
# 示例 3：
#
#
# 输入： x = 1, y = 5, z = 3
#
# 输出： 0
#
# 解释：
#
#
# 第 1 个人在位置 1，到达第 3 个人（位置 3）需要 2 步。
# 第 2 个人在位置 5，到达第 3 个人需要 2 步。
#
#
# 由于两个人同时到达，所以输出为 0。
#
#
#
#
# 提示：
#
#
# 1 <= x, y, z <= 100
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def findClosest(self, x: int, y: int, z: int) -> int:
        if abs(x - z) < abs(y - z):
            return 1
        elif abs(x - z) > abs(y - z):
            return 2
        else:
            return 0


# @lc code=end

#
# @lcpr case=start
# 2\n7\n4\n
# @lcpr case=end

# @lcpr case=start
# 2\n5\n6\n
# @lcpr case=end

# @lcpr case=start
# 1\n5\n3\n
# @lcpr case=end

#
