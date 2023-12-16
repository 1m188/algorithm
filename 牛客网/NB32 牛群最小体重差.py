'''

描述
在一个牧场中，有很多牛。为了方便管理，牧场主将牛的体重排列成一棵二叉搜索树，假设所有牛的体重都不同。现在牧场主想知道牛群中任意两牛体重之间的最小差值。请你编写一个程序，给定一棵二叉搜索树的根节点 root，返回树中任意两不同节点值之间的最小差值，这个体重差至少是个正数。


示例1
输入：
{4, 2, 5, 1, 3}
复制
返回值：
1
复制
示例2
输入：
{5, 1, 48, #, #, 12, 50}
复制
返回值：
2
复制
备注：
树中节点的数目范围是 [2, 2000]
0 <= Node.val <= 10000

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
# @param root TreeNode类
# @return int整型
#
class Solution:

    def getMinimumDifference(self, root: TreeNode) -> int:
        # write code here

        self.pre_val = None
        self.res = float('inf')
        self.mid(root)
        return self.res

    def mid(self, node: TreeNode):
        if not node: return
        self.mid(node.left)
        if self.pre_val != None:
            x = node.val - self.pre_val
            self.res = min(self.res, x)
        self.pre_val = node.val
        self.mid(node.right)
