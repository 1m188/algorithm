#
# @lc app=leetcode.cn id=341 lang=python3
#
# [341] 扁平化嵌套列表迭代器
#
# https://leetcode-cn.com/problems/flatten-nested-list-iterator/description/
#
# algorithms
# Medium (64.07%)
# Likes:    138
# Dislikes: 0
# Total Accepted:    10.7K
# Total Submissions: 16.7K
# Testcase Example:  '[[1,1],2,[1,1]]'
#
# 给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
#
# 列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。
#
#
#
# 示例 1:
#
# 输入: [[1,1],2,[1,1]]
# 输出: [1,1,2,1,1]
# 解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
#
# 示例 2:
#
# 输入: [1,[4,[6]]]
# 输出: [1,4,6]
# 解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。
#
#
#

# class NestedInteger:
#     pass

from typing import List


class NestedInteger:
    def isInteger(self) -> bool:
        """
       @return True if this NestedInteger holds a single integer, rather than \
           a nested list.
       """

    def getInteger(self) -> int:
        """
       @return the single integer that this NestedInteger holds, if it holds \
           a single integer
       Return None if this NestedInteger holds a nested list
       """

    def getList(self) -> [NestedInteger]:
        """
       @return the nested list that this NestedInteger holds, if it holds \
           a nested list
       Return None if this NestedInteger holds a single integer
       """


# @lc code=start
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather \
# than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it \
# holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds \
# a nested list
#        Return None if this NestedInteger holds a single integer
#        """


class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        def recur(nl: List[NestedInteger]):
            for i in nl:
                if i.isInteger():
                    self.li.append(i.getInteger())
                else:
                    recur(i.getList())

        self.li = []
        self.idx = -1
        recur(nestedList)

    def next(self) -> int:
        self.idx += 1
        return self.li[self.idx]

    def hasNext(self) -> bool:
        return self.idx + 1 < len(self.li)


# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
# @lc code=end
