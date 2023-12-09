#
# @lc app=leetcode.cn id=2558 lang=python3
#
# [2558] 从数量最多的堆取走礼物
#
# https://leetcode.cn/problems/take-gifts-from-the-richest-pile/description/
#
# algorithms
# Easy (71.53%)
# Likes:    52
# Dislikes: 0
# Total Accepted:    29.2K
# Total Submissions: 40.8K
# Testcase Example:  '[25,64,9,4,100]\n4'
#
# 给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：
#
#
# 选择礼物数量最多的那一堆。
# 如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
# 选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。
#
#
# 返回在 k 秒后剩下的礼物数量。
#
#
#
# 示例 1：
#
#
# 输入：gifts = [25,64,9,4,100], k = 4
# 输出：29
# 解释：
# 按下述方式取走礼物：
# - 在第一秒，选中最后一堆，剩下 10 个礼物。
# - 接着第二秒选中第二堆礼物，剩下 8 个礼物。
# - 然后选中第一堆礼物，剩下 5 个礼物。
# - 最后，再次选中最后一堆礼物，剩下 3 个礼物。
# 最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。
#
#
# 示例 2：
#
#
# 输入：gifts = [1,1,1,1], k = 4
# 输出：4
# 解释：
# 在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。
# 也就是说，你无法获取任一堆中的礼物。
# 所以，剩下礼物的总数量是 4 。
#
#
#
#
# 提示：
#
#
# 1 <= gifts.length <= 10^3
# 1 <= gifts[i] <= 10^9
# 1 <= k <= 10^3
#
#
#

from typing import List


# @lc code=start
class Solution:
    '''

    两种思路，一种是排序+循环，一种是用大根堆。

    前者需要确定每个元素之间的大小顺序，后者只需要选出最大的那个即可。

    但是构建堆可能会花不少时间。

    随着k的增大，后者方法的优势会逐渐凸显。

    '''

    def pickGifts(self, gifts: List[int], k: int) -> int:

        # return self.direct(gifts, k)

        # 用堆解决
        def adjust(li: list, start_i: int):
            while True:
                left_i = start_i * 2 + 1
                right_i = start_i * 2 + 2
                max_i = start_i
                if left_i < len(li) and li[left_i] > li[max_i]: max_i = left_i
                if right_i < len(li) and li[right_i] > li[max_i]: max_i = right_i
                if max_i == start_i: break
                li[start_i], li[max_i] = li[max_i], li[start_i]
                start_i = max_i

        def build_heap(li: list):  # 构建大根堆
            length = len(li)
            for i in range((length - 1) // 2, -1, -1):
                adjust(li, i)

        build_heap(gifts)
        for _ in range(k):
            y = int(gifts[0]**0.5)
            if y == gifts[0]: continue
            gifts[0] = y
            adjust(gifts, 0)
        return sum(gifts)

    def direct(self, gifts: List[int], k: int) -> int:
        '''排序 + 暴力循环'''

        gifts.sort()
        for _ in range(k):
            x = gifts[-1]
            y = int(x**0.5)
            if y == x: continue
            else: gifts.pop()
            f = False
            for i in range(len(gifts)):
                if y <= gifts[i]:
                    f = True
                    gifts.insert(i, y)
                    break
            if not f: gifts.append(y)
        return sum(gifts)


# @lc code=end
