#
# @lc app=leetcode.cn id=2196 lang=python3
#
# [2196] 根据描述创建二叉树
#
# https://leetcode.cn/problems/create-binary-tree-from-descriptions/description/
#
# algorithms
# Medium (73.15%)
# Likes:    26
# Dislikes: 0
# Total Accepted:    7.7K
# Total Submissions: 10.5K
# Testcase Example:  '[[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]'
#
# 给你一个二维整数数组 descriptions ，其中 descriptions[i] = [parenti, childi, isLefti] 表示
# parenti 是 childi 在 二叉树 中的 父节点，二叉树中各节点的值 互不相同 。此外：
#
#
# 如果 isLefti == 1 ，那么 childi 就是 parenti 的左子节点。
# 如果 isLefti == 0 ，那么 childi 就是 parenti 的右子节点。
#
#
# 请你根据 descriptions 的描述来构造二叉树并返回其 根节点 。
#
# 测试用例会保证可以构造出 有效 的二叉树。
#
#
#
# 示例 1：
#
#
#
#
# 输入：descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
# 输出：[50,20,80,15,17,19]
# 解释：根节点是值为 50 的节点，因为它没有父节点。
# 结果二叉树如上图所示。
#
#
# 示例 2：
#
#
#
#
# 输入：descriptions = [[1,2,1],[2,3,0],[3,4,1]]
# 输出：[1,2,null,null,3,4]
# 解释：根节点是值为 1 的节点，因为它没有父节点。
# 结果二叉树如上图所示。
#
#
#
# 提示：
#
#
# 1 <= descriptions.length <= 10^4
# descriptions[i].length == 3
# 1 <= parenti, childi <= 10^5
# 0 <= isLefti <= 1
# descriptions 所描述的二叉树是一棵有效二叉树
#
#
#

from typing import List, Optional


class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def createBinaryTree(self,
                         descriptions: List[List[int]]) -> Optional[TreeNode]:
        n = 10**5 + 1
        li: List[Optional[TreeNode]] = [None for _ in range(n)]
        vis = [None for _ in range(n)]

        for parent, child, isleft in descriptions:
            if vis[parent] == None: vis[parent] = True
            vis[child] = False
            if not li[parent]:
                li[parent] = TreeNode(parent)
            if not li[child]:
                li[child] = TreeNode(child)
            if isleft: li[parent].left = li[child]
            else: li[parent].right = li[child]

        for i in range(n):
            if vis[i] == True: break
        return li[i]


# @lc code=end
