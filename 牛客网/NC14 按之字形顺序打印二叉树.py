'''
描述
给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）

数据范围：
0
≤
�
≤
1500
0≤n≤1500,树上每个节点的val满足 
∣
�
�
�
∣
<
=
1500
∣val∣<=1500
要求：空间复杂度：
�
(
�
)
O(n)，时间复杂度：
�
(
�
)
O(n)
例如：
给定的二叉树是{1,2,3,#,#,4,5}

该二叉树之字形层序遍历的结果是
[
[1],
[3,2],
[4,5]
]
示例1
输入：
{1,2,3,#,#,4,5}
复制
返回值：
[[1],[3,2],[4,5]]
复制
说明：
如题面解释，第一层是根节点，从左到右打印结果，第二层从右到左，第三层从左到右。     
示例2
输入：
{8,6,10,5,7,9,11}
复制
返回值：
[[8],[10,6],[5,7,9,11]]
复制
示例3
输入：
{1,2,3,4,5}
复制
返回值：
[[1],[3,2],[4,5]]
'''

from typing import List


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param pRoot TreeNode类
# @return int整型二维数组
#
class Solution:

    def Print(self, pRoot: TreeNode) -> List[List[int]]:
        # write code here

        if not pRoot: return []

        res = []
        que = [pRoot]
        is_reverse = False
        while que:
            if is_reverse: res.append([x.val for x in que[::-1]])
            else: res.append([x.val for x in que])
            is_reverse = not is_reverse
            nque = []
            while que:
                p = que.pop(0)
                if p.left: nque.append(p.left)
                if p.right: nque.append(p.right)
            que = nque
        return res