#
# @lc app=leetcode.cn id=1507 lang=python3
#
# [1507] 转变日期格式
#
# https://leetcode-cn.com/problems/reformat-date/description/
#
# algorithms
# Easy (59.33%)
# Likes:    3
# Dislikes: 0
# Total Accepted:    4.1K
# Total Submissions: 6.9K
# Testcase Example:  '"20th Oct 2052"'
#
# 给你一个字符串 date ，它的格式为 Day Month Year ，其中：
#
#
# Day 是集合 {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"} 中的一个元素。
# Month 是集合 {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
# "Oct", "Nov", "Dec"} 中的一个元素。
# Year 的范围在 ​[1900, 2100] 之间。
#
#
# 请你将字符串转变为 YYYY-MM-DD 的格式，其中：
#
#
# YYYY 表示 4 位的年份。
# MM 表示 2 位的月份。
# DD 表示 2 位的天数。
#
#
#
#
# 示例 1：
#
# 输入：date = "20th Oct 2052"
# 输出："2052-10-20"
#
#
# 示例 2：
#
# 输入：date = "6th Jun 1933"
# 输出："1933-06-06"
#
#
# 示例 3：
#
# 输入：date = "26th May 1960"
# 输出："1960-05-26"
#
#
#
#
# 提示：
#
#
# 给定日期保证是合法的，所以不需要处理异常输入。
#
#
#


# @lc code=start
class Solution:
    def __init__(self):
        self.month = {
            "Jan": '01',
            "Feb": '02',
            "Mar": '03',
            "Apr": '04',
            "May": '05',
            "Jun": '06',
            "Jul": '07',
            "Aug": '08',
            "Sep": '09',
            "Oct": '10',
            "Nov": '11',
            "Dec": '12'
        }

    def reformatDate(self, date: str) -> str:
        dl = date.split(' ')
        dl.reverse()
        dl[0] = str(dl[0])
        dl[1] = self.month[dl[1]]
        dl[2] = dl[2][:2]
        if not dl[2].isdigit():
            dl[2] = '0' + dl[2][0]
        return '-'.join(dl)


# @lc code=end
