#
# @lc app=leetcode.cn id=779 lang=python3
# @lcpr version=30204
#
# [779] 第K个语法符号
#
# https://leetcode.cn/problems/k-th-symbol-in-grammar/description/
#
# algorithms
# Medium (50.12%)
# Likes:    315
# Dislikes: 0
# Total Accepted:    55.9K
# Total Submissions: 111.5K
# Testcase Example:  '1\n1'
#
# 我们构建了一个包含 n 行( 索引从 1  开始 )的表。首先在第一行我们写上一个
# 0。接下来的每一行，将前一行中的0替换为01，1替换为10。
#
#
# 例如，对于 n = 3 ，第 1 行是 0 ，第 2 行是 01 ，第3行是 0110 。
#
#
# 给定行数 n 和序数 k，返回第 n 行中第 k 个字符。（ k 从索引 1 开始）
#
#
# 示例 1:
#
# 输入: n = 1, k = 1
# 输出: 0
# 解释: 第一行：0
#
#
# 示例 2:
#
# 输入: n = 2, k = 1
# 输出: 0
# 解释:
# 第一行: 0
# 第二行: 01
#
#
# 示例 3:
#
# 输入: n = 2, k = 2
# 输出: 1
# 解释:
# 第一行: 0
# 第二行: 01
#
#
#
#
# 提示:
#
#
# 1 <= n <= 30
# 1 <= k <= 2^n - 1
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        """
        位运算：popcount 奇偶性

        核心思路：
        - 生成规则：0→01, 1→10，即前一行第 ceil(k/2) 位决定后一行 k 位：
          若 k 为奇数，继承父位；若 k 为偶数，翻转父位
        - 递归到第 1 行 k=1，翻转次数 = (k-1) 二进制中 1 的个数
        - 翻转偶数次→0，翻转奇数次→1
        """
        return bin(k - 1).count("1") & 1


# @lc code=end


#
# @lcpr case=start
# 1\n1\n
# @lcpr case=end

# @lcpr case=start
# 2\n1\n
# @lcpr case=end

# @lcpr case=start
# 2\n2\n
# @lcpr case=end

#
