'''

描述
在一个牧场中，有n头牛，牛的品种分为黑牛和白牛，用0和1分别表示。现在需要对牛群进行排序，使得相同品种的牛相邻，并按照黑牛和白牛的顺序排列。为此，我们决定使用二叉树进行排序，其中根节点为-1，0在左子树，1在右子树。此外，左右子树都必须是完全二叉树。给定一个整数数组 cows，表示牛群的初始排序，你需要返回排序后的二叉树的根节点。
示例1
输入：
[1,0,1,0,1]
复制
返回值：
{-1,0,1,0,#,1,1}
复制
示例2
输入：
[0,1,0,1,0]
复制
返回值：
{-1,0,1,0,0,1}
复制
备注：
1 <= n <= 1000
Node.val ∈ {0, 1}

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
# @param cows int整型一维数组
# @return TreeNode类
#
class Solution:

    def sortCowsTree(self, cows: List[int]) -> TreeNode:
        # write code here

        n = len(cows)

        zeros = cows.count(0)
        ones = n - zeros
        zeros = [TreeNode(0) for _ in range(zeros)]
        ones = [TreeNode(1) for _ in range(ones)]

        def build(li: list[TreeNode]):
            n = len(li)
            for i, v in enumerate(li):
                if 2 * i + 1 < n: v.left = li[2 * i + 1]
                if 2 * i + 2 < n: v.right = li[2 * i + 2]

        build(zeros)
        build(ones)

        root = TreeNode(-1)
        if zeros: root.left = zeros[0]
        if ones: root.right = ones[0]
        return root
