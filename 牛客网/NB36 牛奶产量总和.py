'''

描述
农场里有许多牛，每头牛经过一个二叉树状的草料区域后，进行产奶，每头牛各自走一条从根结点到叶子结点的路径。草料区域也就是二叉树的每个结点有一个产奶量值，范围在0到9之间，将一头牛经过的路径的所有数字拼接起来就是该头牛的最终产奶量，牧场主人想知道最终所有牛的产奶量之和。

示例1
输入：
{1,2,3}
复制
返回值：
25
复制
说明：
从根到叶子节点路径 1->2 代表牛奶产量 12
从根到叶子节点路径 1->3 代表牛奶产量 13
因此，牛奶产量总和 = 12 + 13 = 25
备注：
树中节点的数目在范围 [1, 1000] 内
0 <= Node.val <= 9
树的深度不超过 6

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

    def sumNumbers(self, root: TreeNode) -> int:
        # write code here

        self.res = 0

        def dfs(node: TreeNode, s: str = ''):
            if not node: return
            if not node.left and not node.right:
                self.res += int(s + str(node.val))
                return
            s += str(node.val)
            dfs(node.left, s)
            dfs(node.right, s)
            s = s[:-1]

        dfs(root)
        return self.res
