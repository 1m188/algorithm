#
# @lc app=leetcode.cn id=201 lang=python3
#
# [201] 数字范围按位与
#
# https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/description/
#
# algorithms
# Medium (53.22%)
# Likes:    375
# Dislikes: 0
# Total Accepted:    59.5K
# Total Submissions: 111.8K
# Testcase Example:  '5\n7'
#
# 给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right
# 端点）。
#
#
#
# 示例 1：
#
#
# 输入：left = 5, right = 7
# 输出：4
#
#
# 示例 2：
#
#
# 输入：left = 0, right = 0
# 输出：0
#
#
# 示例 3：
#
#
# 输入：left = 1, right = 2147483647
# 输出：0
#
#
#
#
# 提示：
#
#
# 0 <= left <= right <= 2^31 - 1
#
#
#


# @lc code=start
class Solution:
    '''
    找到区间内所有数字的公共前缀

    事实上只要找到开始和结尾两个数字的公共前缀即可

    因为在与的过程中只要有一个0就全都是0 不同的话必然是有0的存在

    所以只要找到公共前缀 之后后面的位数再用0补全即可
    '''

    def rangeBitwiseAnd(self, left: int, right: int) -> int:

        shift = 0
        while left != right:
            left >>= 1
            right >>= 1
            shift += 1
        return left << shift


# @lc code=end
