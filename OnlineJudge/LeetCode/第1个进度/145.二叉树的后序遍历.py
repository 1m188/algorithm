#
# @lc app=leetcode.cn id=145 lang=python3
#
# [145] 二叉树的后序遍历
#
# https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
#
# algorithms
# Hard (72.18%)
# Likes:    385
# Dislikes: 0
# Total Accepted:    113.2K
# Total Submissions: 156.6K
# Testcase Example:  '[1,null,2,3]'
#
# 给定一个二叉树，返回它的 后序 遍历。
#
# 示例:
#
# 输入: [1,null,2,3]
# ⁠  1
# ⁠   \
# ⁠    2
# ⁠   /
# ⁠  3
#
# 输出: [3,2,1]
#
# 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
#
#

from typing import List


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
    def postorder(self, root: TreeNode, res: List[int]):
        '''
        递归版
        '''

        if root:
            self.postorder(root.left, res)
            self.postorder(root.right, res)
            res.append(root.val)

    def postorder_c(self, root: TreeNode, res: List[int]):
        '''
        非递归版
        '''

        r = None  # 标志前一个访问节点，判断从左子树还是右子树返回
        st = []
        while root or len(st):
            if root:
                st.append(root)
                root = root.left
            else:
                root = st[-1]
                if root.right and r != root.right:
                    root = root.right
                else:
                    res.append(root.val)
                    st.pop()
                    r = root
                    root = None

    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        # self.postorder(root, res)
        self.postorder_c(root, res)
        return res


# @lc code=end
