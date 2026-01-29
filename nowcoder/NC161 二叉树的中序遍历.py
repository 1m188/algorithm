'''

描述
给定一个二叉树的根节点root，返回它的中序遍历结果。

数据范围：树上节点数满足 
0
≤
�
≤
1000
0≤n≤1000，树上每个节点的值满足 
−
1000
≤
�
�
�
≤
1000
−1000≤val≤1000
进阶：空间复杂度 
�
(
�
)
O(n)，时间复杂度 
�
(
�
)
O(n)
示例1
输入：
{1,2,#,#,3}
复制
返回值：
[2,3,1]
复制
说明：
  
示例2
输入：
{}
复制
返回值：
[]
复制
示例3
输入：
{1,2}
复制
返回值：
[2,1]
复制
说明：
  
示例4
输入：
{1,#,2}
复制
返回值：
[1,2]
复制
说明：
  
备注：
树中节点数目在范围 [0, 100] 内
树中的节点的值在[-100,100]以内

'''

from typing import List


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left: TreeNode = None
        self.right: TreeNode = None


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param root TreeNode类
# @return int整型一维数组
#
class Solution:

    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # write code here

        res = []

        def mid(root: TreeNode = root):
            if not root: return
            mid(root.left)
            res.append(root.val)
            mid(root.right)

        mid()
        return res
