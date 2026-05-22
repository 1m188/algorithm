#
# @lc app=leetcode.cn id=3582 lang=python3
# @lcpr version=30204
#
# [3582] 为视频标题生成标签
#
# https://leetcode.cn/problems/generate-tag-for-video-caption/description/
#
# algorithms
# Easy (34.66%)
# Likes:    3
# Dislikes: 0
# Total Accepted:    3.5K
# Total Submissions: 10.1K
# Testcase Example:  '"Leetcode daily streak achieved"'
#
# 给你一个字符串 caption，表示一个视频的标题。
#
# 需要按照以下步骤 按顺序 生成一个视频的 有效标签 ：
#
#
#
# 将 所有单词 组合为单个 驼峰命名字符串 ，并在前面加上 '#'。驼峰命名字符串
# 指的是除第一个单词外，其余单词的首字母大写，且每个单词的首字母之后的字符必须是小写。
#
#
# 移除 所有不是英文字母的字符，但 保留 第一个字符 '#'。
#
#
# 将结果 截断 为最多 100 个字符。
#
#
#
# 对 caption 执行上述操作后，返回生成的 标签 。
#
#
#
# 示例 1：
#
#
# 输入： caption = "Leetcode daily streak achieved"
#
# 输出： "#leetcodeDailyStreakAchieved"
#
# 解释：
#
# 除了 "leetcode" 以外的所有单词的首字母需要大写。
#
#
# 示例 2：
#
#
# 输入： caption = "can I Go There"
#
# 输出： "#canIGoThere"
#
# 解释：
#
# 除了 "can" 以外的所有单词的首字母需要大写。
#
#
# 示例 3：
#
#
# 输入： caption =
# "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
#
# 输出：
# "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
#
# 解释：
#
# 由于第一个单词长度为 101，因此需要从单词末尾截去最后两个字符。
#
#
#
#
# 提示：
#
#
# 1 <= caption.length <= 150
# caption 仅由英文字母和 ' ' 组成。
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def generateTag(self, caption: str) -> str:

        res = ["#"]
        for i, word in enumerate(caption.strip().split()):
            word = word.lower()
            if i > 0:
                word = word[0].upper() + word[1:]
            res.append(word)
        return "".join(res)[:100]


# @lc code=end


#
# @lcpr case=start
# "Leetcode daily streak achieved"\n
# @lcpr case=end

# @lcpr case=start
# "can I Go There"\n
# @lcpr case=end

# @lcpr case=start
# "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"\n
# @lcpr case=end

#
