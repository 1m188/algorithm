'''

描述
给定一个升序排序的数组，将其转化为平衡二叉搜索树（BST）.

平衡二叉搜索树指树上每个节点 node 都满足左子树中所有节点的的值都小于 node 的值，右子树中所有节点的值都大于 node 的值，并且左右子树的节点数量之差不大于1

数据范围：
0
≤
�
≤
10000
0≤n≤10000，数组中每个值满足 
∣
�
�
�
∣
≤
5000
∣val∣≤5000
进阶：空间复杂度 
�
(
�
)
O(n) ，时间复杂度 
�
(
�
)
O(n)

例如当输入的升序数组为[-1,0,1,2]时，转化后的平衡二叉搜索树（BST）可以为{1,0,2,-1}，如下图所示：

或为{0,-1,1,#,#,#,2}，如下图所示：

返回任意一种即可。
示例1
输入：
[-1,0,1,2]
复制
返回值：
{1,0,2,-1}
复制
示例2
输入：
[]
复制
返回值：
{}

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
# @param nums int整型一维数组
# @return TreeNode类
#
class Solution:

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        # write code here

        def dfs(li: list[int]) -> TreeNode:
            if not li: return None
            mid = len(li) // 2
            node = TreeNode(li[mid])
            node.left = dfs(li[:mid])
            node.right = dfs(li[mid + 1:])
            return node

        return dfs(nums)
