'''

描述
给定一个二叉搜索树，树上的节点各不相同，请你将其修改为累加树，使每个节点的值变成原树中更大节点之和。

二叉搜索树的定义是任一节点的左子树的任意节点的值小于根节点的值，右子树则相反。

数据范围：树上节点数满足 
0
≤
�
≤
1
0
4
 
0≤n≤10 
4
   ，节点上的值满足 
∣
�
�
�
∣
≤
1
0
4
 
∣val∣≤10 
4
   。

样例图1：

样例图2：

示例1
输入：
{0,#,1}
复制
返回值：
{1,#,1}
复制
示例2
输入：
{1,0,2}
复制
返回值：
{3,3,2}

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
# @return TreeNode类
#
class Solution:

    def convertBST(self, root: TreeNode) -> TreeNode:
        # write code here

        self.maxsum = 0

        def dfs(root: TreeNode = root):
            if not root: return
            dfs(root.right)
            self.maxsum += root.val
            root.val = self.maxsum
            dfs(root.left)

        dfs()
        return root
