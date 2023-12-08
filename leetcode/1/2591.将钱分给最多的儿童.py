#
# @lc app=leetcode.cn id=2591 lang=python3
#
# [2591] 将钱分给最多的儿童
#
# https://leetcode.cn/problems/distribute-money-to-maximum-children/description/
#
# algorithms
# Easy (26.88%)
# Likes:    115
# Dislikes: 0
# Total Accepted:    29.3K
# Total Submissions: 109K
# Testcase Example:  '20\n3'
#
# 给你一个整数 money ，表示你总共有的钱数（单位为美元）和另一个整数 children ，表示你要将钱分配给多少个儿童。
#
# 你需要按照如下规则分配：
#
#
# 所有的钱都必须被分配。
# 每个儿童至少获得 1 美元。
# 没有人获得 4 美元。
#
#
# 请你按照上述规则分配金钱，并返回 最多 有多少个儿童获得 恰好 8 美元。如果没有任何分配方案，返回 -1 。
#
#
#
# 示例 1：
#
# 输入：money = 20, children = 3
# 输出：1
# 解释：
# 最多获得 8 美元的儿童数为 1 。一种分配方案为：
# - 给第一个儿童分配 8 美元。
# - 给第二个儿童分配 9 美元。
# - 给第三个儿童分配 3 美元。
# 没有分配方案能让获得 8 美元的儿童数超过 1 。
#
#
# 示例 2：
#
# 输入：money = 16, children = 2
# 输出：2
# 解释：每个儿童都可以获得 8 美元。
#
#
#
#
# 提示：
#
#
# 1 <= money <= 200
# 2 <= children <= 30
#
#
#

import math


# @lc code=start
class Solution:
    '''
    
    整体的思路是：

    假设孩子数为N，钱为M
    
    假设每个孩子都能拿到8美元，则总金额为8N
    
    如果8N<=M，则说明钱还多了或者刚好分完，考虑到每个孩子最少1美元且不为4美元，
    可以把多余的钱往一个人身上加上去，则最终就是N或者N-1个8美元

    如果8N>M，说明钱不够，这时候要从一些人身上减去钱，考虑尽可能的把少的钱分摊在较少的人身上，
    有ceil(8N-M/7)，为要减钱的人数，每个人减去7美元，保证最小的1美元，此外向上取整是说，
    剩下一个人减去的钱不够7美元。最后有8美元的人为N-ceil(8N-M/7)

    最后一个人减去的钱可能是4美元，导致最后留下来4美元，这是不行的，因此又要分情况讨论：
    1. 如果只有1个人减钱，减去4美元，说明这4美元无论如何也不能够减去，因此要多一个人和他一起分摊，
    最后还要再少一个人。
    2. 如果有多个人减钱，那么最后一个人是可以减去4美元的，因为在他之前那么多减去7美元的人可以和他一起分摊一下

    '''

    def distMoney(self, money: int, children: int) -> int:

        if money < children: return -1  # 钱比人少，每人至少分1美元，分不了

        N = children
        M = money
        x = 8 * N
        if x > M:
            r = x - M
            res = N - math.ceil(r / 7)
            if res <= 0: return 0  # 存在分配方案，但是没人有8美元
            if r == 4: return res - 1
            return res
        elif x < M:
            return N - 1
        else:
            return N


# @lc code=end
