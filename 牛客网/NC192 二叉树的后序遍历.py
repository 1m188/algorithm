'''

描述
给定一个二叉树，返回他的后序遍历的序列。

后序遍历是值按照 左节点->右节点->根节点 的顺序的遍历。

数据范围：二叉树的节点数量满足 
1
≤
�
≤
100
 
1≤n≤100  ，二叉树节点的值满足 
1
≤
�
�
�
≤
100
 
1≤val≤100  ，树的各节点的值各不相同

样例图


示例1
输入：
{1,#,2,3}
复制
返回值：
[3,2,1]
复制
说明：
如题面图  
示例2
输入：
{1}
复制
返回值：
[1]

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

    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # write code here

        self.res = []

        def post(root: TreeNode = root):
            if not root: return
            post(root.left)
            post(root.right)
            self.res.append(root.val)

        post()
        return self.res
