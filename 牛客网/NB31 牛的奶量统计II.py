'''

描述
农场里有许多牛，每头牛都有一个奶量值。农场主想知道，在二叉树表示的牛编号中，是否存在一组牛，它们的奶量和等于给定的目标值。每头牛都有一个唯一的编号，编号表示它们的产奶量。为了方便管理，农场主将牛的编号按照二叉树的形式排列。

给定一棵表示牛编号的二叉树的根节点 root 和一个表示目标奶量和的整数 targetSum。判断该树中是否存在任意节点到其任意子节点的路径，这条路径上所有牛的奶量和等于目标奶量和 targetSum。如果存在，返回 true ；否则，返回 false。                                                                                                                                                                                                                                                                 

示例1
输入：
{1, 4, 8, 11, #, 13, 3, 7, 2, #, #, #, 5},18
复制
返回值：
true
复制
示例2
输入：
{1, 2, 3},5
复制
返回值：
false
复制
示例3
输入：
{1, 2, 3},7
复制
返回值：
false
复制
备注：
树中节点的数目在范围 [0, 5000] 内
0 <= Node.val <= 1000
0 <= targetSum <= 2000

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
# @param targetSum int整型
# @return bool布尔型
#
class Solution:

    def hasPathSumII(self, root: TreeNode, targetSum: int) -> bool:
        # write code here

        def calc(node: TreeNode, tmp: int = 0) -> bool:
            if not node: return False if tmp != targetSum else True
            tmp += node.val
            if tmp == targetSum: return True
            elif tmp > targetSum: return False
            else: return calc(node.left, tmp) or calc(node.right, tmp)

        def pre(node: TreeNode) -> bool:
            if not node: return False
            if pre(node.left): return True
            if calc(node): return True
            if pre(node.right): return True
            return False

        return pre(root)
