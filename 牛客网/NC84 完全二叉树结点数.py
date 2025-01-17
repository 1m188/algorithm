'''
描述
给定一棵完全二叉树的头节点head，返回这棵树的节点个数。

完全二叉树指：设二叉树的深度为h，则 [1,h-1] 层的节点数都满足 
2
i
−
1
2 
i−1
 个

数据范围：节点数量满足 
0
≤
n
≤
100000
0≤n≤100000，节点上每个值都满足 
0
≤
v
a
l
≤
100000
0≤val≤100000
进阶：空间复杂度 
O
(
1
)
O(1) ， 时间复杂度 
O
(
n
)
O(n)
示例1
输入：
{1,2,3} 
复制
返回值：
3
复制
示例2
输入：
{}
复制
返回值：
0
'''


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param head TreeNode类
# @return int整型
#
class Solution:

    def nodeNum(self, head: TreeNode) -> int:
        # write code here

        if not head: return 0
        return self.nodeNum(head.left) + self.nodeNum(head.right) + 1
