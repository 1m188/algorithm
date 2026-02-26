#
# @lc app=leetcode.cn id=1404 lang=python3
# @lcpr version=30204
#
# [1404] 将二进制表示减到 1 的步骤数
#
# https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/
#
# algorithms
# Medium (52.63%)
# Likes:    67
# Dislikes: 0
# Total Accepted:    17.4K
# Total Submissions: 30.6K
# Testcase Example:  '"1101"'
#
# 给你一个以二进制形式表示的数字 s 。请你返回按下述规则将其减少到 1 所需要的步骤数：
#
#
#
# 如果当前数字为偶数，则将其除以 2 。
#
#
# 如果当前数字为奇数，则将其加上 1 。
#
#
#
# 题目保证你总是可以按上述规则将测试用例变为 1 。
#
#
#
# 示例 1：
#
# 输入：s = "1101"
# 输出：6
# 解释："1101" 表示十进制数 13 。
# Step 1) 13 是奇数，加 1 得到 14
# Step 2) 14 是偶数，除 2 得到 7
# Step 3) 7  是奇数，加 1 得到 8
# Step 4) 8  是偶数，除 2 得到 4
# Step 5) 4  是偶数，除 2 得到 2
# Step 6) 2  是偶数，除 2 得到 1
#
#
# 示例 2：
#
# 输入：s = "10"
# 输出：1
# 解释："10" 表示十进制数 2 。
# Step 1) 2 是偶数，除 2 得到 1
#
#
# 示例 3：
#
# 输入：s = "1"
# 输出：0
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 500
# s 由字符 '0' 或 '1' 组成。
# s[0] == '1'
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def numSteps(self, s: str) -> int:

        def addOne(s: str) -> str:
            s: list[str] = list(s)
            x = 1
            index = len(s) - 1
            while x > 0 and index >= 0:
                if s[index] == "1":
                    s[index] = "0"
                else:
                    s[index] = "1"
                    x = 0
                index -= 1
            if x > 0:
                s.insert(0, "1")
            return "".join(s)

        def divTwo(s: str) -> str:
            return s[: len(s) - 1]

        ans = 0
        while not (len(s) == 1 and s[0] == "1"):
            if s[-1] == "1":
                s = addOne(s)
            else:
                s = divTwo(s)
            ans += 1
        return ans


# @lc code=end


#
# @lcpr case=start
# "1101"\n
# @lcpr case=end

# @lcpr case=start
# "10"\n
# @lcpr case=end

# @lcpr case=start
# "1"\n
# @lcpr case=end

#
