#
# @lc app=leetcode.cn id=3827 lang=python3
# @lcpr version=30204
#
# [3827] 统计单比特整数
#
# https://leetcode.cn/problems/count-monobit-integers/description/
#
# algorithms
# Easy (71.98%)
# Likes:    2
# Dislikes: 0
# Total Accepted:    3.2K
# Total Submissions: 4.4K
# Testcase Example:  '1'
#
# 给你一个整数 n。
#
# 如果一个整数的二进制表示中所有位都相同，则称其为 单比特数（Monobit）。
#
# 返回范围[0, n]（包括两端）内 单比特数 的个数。
#
#
#
# 示例 1：
#
#
# 输入： n = 1
#
# 输出： 2
#
# 解释：
#
#
# 范围[0, 1]内的整数对应的二进制表示为"0"和"1"。
# 每个表示都由相同的位组成，因此答案是2。
#
#
#
# 示例 2：
#
#
# 输入： n = 4
#
# 输出： 3
#
# 解释：
#
#
# 范围[0, 4]内的整数对应的二进制表示为"0"、"1"、"10"、"11"和"100"。
# 只有0、1和3满足单比特条件。因此答案是3。
#
#
#
#
#
# 提示：
#
#
# 0 <= n <= 1000
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def countMonobit(self, n: int) -> int:

        x = bin(n)[2:]
        ans = 1 + len(x)
        if "0" in x:
            ans -= 1
        return ans


# @lc code=end


#
# @lcpr case=start
# 1\n
# @lcpr case=end

# @lcpr case=start
# 4\n
# @lcpr case=end

#
