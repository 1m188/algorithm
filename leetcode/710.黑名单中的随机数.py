#
# @lc app=leetcode.cn id=710 lang=python3
#
# [710] 黑名单中的随机数
#
# https://leetcode-cn.com/problems/random-pick-with-blacklist/description/
#
# algorithms
# Hard (30.68%)
# Likes:    42
# Dislikes: 0
# Total Accepted:    1.6K
# Total Submissions: 5.3K
# Testcase Example:  '["Solution", "pick", "pick", "pick"]\n
# [[1, []], [], [], []]'
#
# 给定一个包含 [0，n ) 中独特的整数的黑名单 B，写一个函数从 [ 0，n ) 中返回一个不在 B 中的随机整数。
#
# 对它进行优化使其尽量少调用系统方法 Math.random() 。
#
# 提示:
#
#
# 1 <= N <= 1000000000
# 0 <= B.length < min(100000, N)
# [0, N) 不包含 N，详细参见 interval notation 。
#
#
# 示例 1:
#
#
# 输入:
# ["Solution","pick","pick","pick"]
# [[1,[]],[],[],[]]
# 输出: [null,0,0,0]
#
#
# 示例 2:
#
#
# 输入:
# ["Solution","pick","pick","pick"]
# [[2,[]],[],[],[]]
# 输出: [null,1,1,1]
#
#
# 示例 3:
#
#
# 输入:
# ["Solution","pick","pick","pick"]
# [[3,[1]],[],[],[]]
# Output: [null,0,0,2]
#
#
# 示例 4:
#
#
# 输入:
# ["Solution","pick","pick","pick"]
# [[4,[2]],[],[],[]]
# 输出: [null,1,3,1]
#
#
# 输入语法说明：
#
# 输入是两个列表：调用成员函数名和调用的参数。Solution的构造函数有两个参数，N 和黑名单 B。pick
# 没有参数，输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。
#
#

from typing import List
from random import randint


# @lc code=start
class Solution:
    def __init__(self, N: int, blacklist: List[int]):
        self.intvl = []
        if not blacklist:
            self.intvl.append((0, N - 1))
            return

        blist = sorted(blacklist)
        blist.insert(0, -1)
        blist.append(N)
        for i in range(1, len(blist)):
            if blist[i] - blist[i - 1] > 1:
                self.intvl.append((blist[i - 1] + 1, blist[i] - 1))

    def pick(self) -> int:
        idx = randint(0, len(self.intvl) - 1)
        return randint(self.intvl[idx][0], self.intvl[idx][1])


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
# @lc code=end
