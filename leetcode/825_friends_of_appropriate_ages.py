#
# @lc app=leetcode.cn id=825 lang=python3
# @lcpr version=30204
#
# [825] 适龄的朋友
#
# https://leetcode.cn/problems/friends-of-appropriate-ages/description/
#
# algorithms
# Medium (47.45%)
# Likes:    280
# Dislikes: 0
# Total Accepted:    57.8K
# Total Submissions: 121.7K
# Testcase Example:  '[16,16]'
#
# 在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。
#
# 如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：
#
#
# ages[y] <= 0.5 * ages[x] + 7
# ages[y] > ages[x]
# ages[y] > 100 && ages[x] < 100
#
#
# 否则，x 将会向 y 发送一条好友请求。
#
# 注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。
#
# 返回在该社交媒体网站上产生的好友请求总数。
#
#
#
# 示例 1：
#
# 输入：ages = [16,16]
# 输出：2
# 解释：2 人互发好友请求。
#
#
# 示例 2：
#
# 输入：ages = [16,17,18]
# 输出：2
# 解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
#
#
# 示例 3：
#
# 输入：ages = [20,30,100,110,120]
# 输出：3
# 解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
#
#
#
#
# 提示：
#
#
# n == ages.length
# 1 <= n <= 2 * 10^4
# 1 <= ages[i] <= 120
#
#
#


# @lcpr-template-start
from typing import List

# @lcpr-template-end
# @lc code=start


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        # 年龄范围 1~120，统计每个年龄的人数
        cnt = [0] * 121
        for age in ages:
            cnt[age] += 1

        ans = 0
        # 枚举发送方年龄 x，接收方年龄 y 需满足 0.5*x+7 < y <= x
        for x in range(1, 121):
            if cnt[x] == 0:
                continue
            min_y = int(0.5 * x + 7) + 1  # y 的最小合法值
            if min_y > x:
                continue  # 该年龄的用户无法发送请求

            for y in range(min_y, x + 1):
                if cnt[y] == 0:
                    continue
                if x == y:
                    ans += cnt[x] * (cnt[x] - 1)  # 同年龄：不能给自己发送
                else:
                    ans += cnt[x] * cnt[y]

        return ans


# @lc code=end


#
# @lcpr case=start
# [16,16]\n
# @lcpr case=end

# @lcpr case=start
# [16,17,18]\n
# @lcpr case=end

# @lcpr case=start
# [20,30,100,110,120]\n
# @lcpr case=end

#
