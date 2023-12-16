'''

描述
在一片牧场上，农场主人种植了两棵大树，每棵树的叶子上都住着一头牛。树的叶子按从左到右的顺序排列形成一个叶值序列，每个叶子上的牛都有其特定的编号。

现在农场主人想要知道，这两棵树的叶子（牛的编号）是否刚好为逆序。也就是说，第一棵树从左到右的叶子顺序，是否与第二棵树从右到左的叶子顺序一致。

如果是，则返回 true；否则返回 false。

示例1
输入：
{1,2,3},{1,3,2}
复制
返回值：
true
复制
示例2
输入：
{3,2,1},{1,2,3}
复制
返回值：
false
复制
备注：
给定的两棵树结点数在 [1, 200] 范围内
给定的两棵树上的值在 [0, 200] 范围内

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

    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        # write code here

        def dfs(root: TreeNode, li: list):
            if not root: return
            if not root.left and not root.right: li.append(root.val)
            dfs(root.left, li)
            dfs(root.right, li)

        li1, li2 = [], []
        dfs(root1, li1)
        dfs(root2, li2)
        li2.reverse()
        return li1 == li2
