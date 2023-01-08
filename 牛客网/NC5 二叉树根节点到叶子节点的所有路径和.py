'''
描述
给定一个二叉树的根节点root，该树的节点值都在数字\ 0-9 0−9 之间，每一条从根节点到叶子节点的路径都可以用一个数字表示。
1.该题路径定义为从树的根结点开始往下一直到叶子结点所经过的结点
2.叶子节点是指没有子节点的节点
3.路径只能从父节点到子节点，不能从子节点到父节点
4.总节点数目为n

例如根节点到叶子节点的一条路径是1\to 2\to 31→2→3,那么这条路径就用\ 123 123 来代替。
找出根节点到叶子节点的所有路径表示的数字之和
例如：

这颗二叉树一共有两条路径，
根节点到叶子节点的路径 1\to 21→2 用数字\ 12 12 代替
根节点到叶子节点的路径 1\to 31→3 用数字\ 13 13 代替
所以答案为\ 12+13=25 12+13=25

数据范围：节点数 0 \le n \le 1000≤n≤100，保证结果在32位整型范围内
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n^2)O(n 
2
 )
进阶：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
{1,2,3}
复制
返回值：
25
复制
示例2
输入：
{1,0}
复制
返回值：
10
复制
示例3
输入：
{1,2,0,3,4}
复制
返回值：
257
'''


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


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

        def dfs(node: TreeNode = root, tmp: int = 0):
            if node:
                x = tmp * 10 + node.val
                if not node.left and not node.right: self.res += x
                else:
                    if node.left: dfs(node.left, x)
                    if node.right: dfs(node.right, x)

        dfs()
        return self.res