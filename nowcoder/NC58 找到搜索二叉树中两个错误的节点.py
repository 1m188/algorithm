'''
描述
一棵二叉树原本是搜索二叉树，但是其中有两个节点调换了位置，使得这棵二叉树不再是搜索二叉树，请按升序输出这两个错误节点的值。(每个节点的值各不相同)
搜索二叉树：满足每个节点的左子节点小于当前节点，右子节点大于当前节点。
样例1图

样例2图

数据范围：
3
≤
n
≤
100000
3≤n≤100000,节点上的值满足 
1
≤
v
a
l
≤
n
1≤val≤n ，保证每个value各不相同
进阶：空间复杂度 
O
(
1
)
O(1)，时间复杂度 
O
(
n
)
O(n)
示例1
输入：
{1,2,3}
复制
返回值：
[1,2]
复制
说明：
如题面图    
示例2
输入：
{4,2,5,3,1}
复制
返回值：
[1,3]
'''

from typing import List


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param root TreeNode类 the root
# @return int整型一维数组
#
class Solution:

    def findError(self, root: TreeNode) -> List[int]:
        # write code here

        res = []
        self.pre = float('-inf')

        def mid(node: TreeNode = root):
            if not node: return
            mid(node.left)
            if self.pre > node.val:
                if len(res) == 0:
                    res.append(self.pre)
                    res.append(node.val)
                else:
                    res.pop()
                    res.append(node.val)
            self.pre = node.val
            mid(node.right)

        mid()

        return sorted(res)
