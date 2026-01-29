'''

描述
给定一颗二叉树，求二叉树的直径。
1.该题的直径定义为：树上任意两个节点路径长度的最大值
2.该题路径长度定义为：不需要从根节点开始，也不需要在叶子节点结束，也不需要必须从父节点到子节点，一个节点到底另外一个节点走的边的数目
3.这个路径可能穿过根节点，也可能不穿过
4.树为空时，返回 0
如，输入{1,2,3,#,#,4,5}，二叉树如下:

那么：
从4到5的路径为4=>3=>5，路径长度为2
从4到2的路径为4=>3=>1=>2，路径长度为3

如，输入{1,2,3,#,#,4,5,9,#,#,6,#,7,#,8}，二叉树如下:

那么路径长度最长为:7=>9=>4=>3=>5=>6=>8，长度为6

数据范围：节点数量满足 
0
≤
�
≤
100
 
0≤n≤100 
示例1
输入：
{1,2,3,#,#,4,5}
复制
返回值：
3
复制
示例2
输入：
{1,2,3,#,#,4,5,9,#,#,6,#,7,#,8}
复制
返回值：
6
复制
示例3
输入：
{1,2,3}
复制
返回值：
2

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

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        # write code here

        if not root: return 0

        self.maxsum = 0

        def dfs(root: TreeNode = root) -> int:
            if not root: return 0
            left = dfs(root.left)
            right = dfs(root.right)
            self.maxsum = max(self.maxsum, left + right + 1)
            return max(left, right) + 1

        dfs()
        return self.maxsum - 1
