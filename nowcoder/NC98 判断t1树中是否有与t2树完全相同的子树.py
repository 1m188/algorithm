'''

描述
给定彼此独立的两棵二叉树，树上的节点值两两不同，判断 t1 树是否有与 t2 树完全相同的子树。

子树指一棵树的某个节点的全部后继节点

数据范围：树的节点数满足 
0
<
�
≤
500000
0<n≤500000，树上每个节点的值一定在32位整型范围内
进阶：空间复杂度: 
�
(
1
)
O(1)，时间复杂度 
�
(
�
)
O(n)
示例1
输入：
{1,2,3,4,5,6,7,#,8,9},{2,4,5,#,8,9}
复制
返回值：
true
复制
备注：
1
≤
�
≤
500000
1≤n≤500000

'''


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
# @param root1 TreeNode类
# @param root2 TreeNode类
# @return bool布尔型
#
class Solution:

    def isContains(self, root1: TreeNode, root2: TreeNode) -> bool:
        # write code here

        if not root1: return False
        return self.judge(root1, root2) or self.isContains(root1.left, root2) or self.isContains(root1.right, root2)

    def judge(self, root1: TreeNode, root2: TreeNode) -> bool:
        if not root1 and not root2: return True
        if not root1 or not root2 or root1.val != root2.val: return False
        return self.judge(root1.left, root2.left) and self.judge(root1.right, root2.right)
