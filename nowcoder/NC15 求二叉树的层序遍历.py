'''
描述
给定一个二叉树，返回该二叉树层序遍历的结果，（从左到右，一层一层地遍历）
例如：
给定的二叉树是{3,9,20,#,#,15,7},

该二叉树层序遍历的结果是
[
[3],
[9,20],
[15,7]

]


提示:
0 <= 二叉树的结点数 <= 1500


示例1
输入：
{1,2}
复制
返回值：
[[1],[2]]
复制
示例2
输入：
{1,2,3,4,#,#,5}
复制
返回值：
[[1],[2,3],[4,5]]
'''

from typing import List


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param root TreeNode类
# @return int整型二维数组
#
class Solution:

    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        # write code here

        if not root: return []

        res = []
        que = [root]
        while que:
            res.append([])
            nque = []
            while que:
                x = que.pop(0)
                res[-1].append(x.val)
                if x.left: nque.append(x.left)
                if x.right: nque.append(x.right)
            que = nque
        return res