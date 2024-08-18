#
# @lc app=leetcode.cn id=1640 lang=python3
#
# [1640] 能否连接形成数组
#
# https://leetcode-cn.com/problems/check-array-formation-through-concatenation/description/
#
# algorithms
# Easy (64.96%)
# Likes:    40
# Dislikes: 0
# Total Accepted:    14.4K
# Total Submissions: 22.2K
# Testcase Example:  '[85]\n[[85]]'
#
# 给你一个整数数组 arr ，数组中的每个整数 互不相同 。另有一个由整数数组构成的数组 pieces，其中的整数也 互不相同 。请你以 任意顺序 连接
# pieces 中的数组以形成 arr 。但是，不允许 对每个数组 pieces[i] 中的整数重新排序。
#
# 如果可以连接 pieces 中的数组形成 arr ，返回 true ；否则，返回 false 。
#
#
#
# 示例 1：
#
#
# 输入：arr = [15,88], pieces = [[88],[15]]
# 输出：true
# 解释：依次连接 [15] 和 [88]
#
#
# 示例 2：
#
#
# 输入：arr = [49,18,16], pieces = [[16,18,49]]
# 输出：false
# 解释：即便数字相符，也不能重新排列 pieces[0]
#
#
# 示例 3：
#
#
# 输入：arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
# 输出：true
# 解释：依次连接 [91]、[4,64] 和 [78]
#
#
#
# 提示：
#
#
# 1 <= pieces.length <= arr.length <= 100
# sum(pieces[i].length) == arr.length
# 1 <= pieces[i].length <= arr.length
# 1 <= arr[i], pieces[i][j] <= 100
# arr 中的整数 互不相同
# pieces 中的整数 互不相同（也就是说，如果将 pieces 扁平化成一维数组，数组中的所有整数互不相同）
#
#
#

from typing import List


# @lc code=start
class Solution:
    '''
    参考了网上人家的答案

    因为数组中的每个数都不相同，不妨考虑map，
    做一个map，对pieces中每个数组，其第一个元素作为key，
    其在pieces中的索引作为value，之后遍历arr，对每个元素
    在map中查找，找不到为false。找到之后再判断之后的元素，
    周而复始，直到整个数组都能够被找完。否则false。
    '''

    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:

        di = {}  # 用来存储数组第一个元素和其index的map
        for i in range(len(pieces)):
            di[pieces[i][0]] = i

        i = 0
        while i < len(arr):

            # 找不到直接false
            if arr[i] not in di: return False

            # 找到了接着判断后面的
            li = pieces[di[arr[i]]]
            for j in li:
                if j != arr[i]: return False
                i += 1

        return True


# @lc code=end
