#
# @lc app=leetcode.cn id=386 lang=python3
#
# [386] 字典序排数
#
# https://leetcode-cn.com/problems/lexicographical-numbers/description/
#
# algorithms
# Medium (71.44%)
# Likes:    119
# Dislikes: 0
# Total Accepted:    11.8K
# Total Submissions: 16.4K
# Testcase Example:  '13'
#
# 给定一个整数 n, 返回从 1 到 n 的字典顺序。
#
# 例如，
#
# 给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
#
# 请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
#
#

from typing import List


# @lc code=start
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = []
        for i in range(1, n + 1):
            res.append(str(i))
        res.sort()
        for e in res:
            e = int(e)
        return res


# @lc code=end
