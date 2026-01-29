'''

描述
二叉树里面的路径被定义为:从该树的任意节点出发，经过父=>子或者子=>父的连接，达到任意节点的序列。
注意:
1.同一个节点在一条二叉树路径里中最多出现一次
2.一条路径至少包含一个节点，且不一定经过根节点

给定一个二叉树的根节点root，请你计算它的最大路径和

例如：
给出以下的二叉树，

最优路径是:2=>1=>3，或者3=>1=>2，最大路径和=2+1+3=6

数据范围：节点数满足 
1
≤
�
≤
1
0
5
1≤n≤10 
5
  ，节点上的值满足 
∣
�
�
�
∣
≤
1000
∣val∣≤1000
要求：空间复杂度 
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
{1,2,3}
复制
返回值：
6
复制
示例2
输入：
{-20,8,20,#,#,15,6}
复制
返回值：
41
复制
说明：

其中一条最大路径为:15=>20=>6，路径和为15+20+6=41   
示例3
输入：
{-2,#,-3}
复制
返回值：
-2

'''

import sys


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

    def maxPathSum(self, root: TreeNode) -> int:
        # write code here

        sys.setrecursionlimit(10**5 + 5)

        self.res = float('-inf')

        def max_gain(root: TreeNode) -> int:
            if not root: return 0
            left = max_gain(root.left)
            if left < 0: left = 0
            right = max_gain(root.right)
            if right < 0: right = 0
            self.res = max(self.res, left + right + root.val)
            return max(left + root.val, right + root.val)

        max_gain(root)

        return self.res
