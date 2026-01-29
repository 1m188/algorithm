'''
描述
给定一个二叉树根节点，请你判断这棵树是不是二叉搜索树。

二叉搜索树满足每个节点的左子树上的所有节点均小于当前节点且右子树上的所有节点均大于当前节点。

例：

图1

图2

数据范围：节点数量满足 1 \le n\le 10^4 \1≤n≤10 
4
   ，节点上的值满足 -2^{31} \le val \le 2^{31}-1\−2 
31
 ≤val≤2 
31
 −1 
示例1
输入：
{1,2,3}
复制
返回值：
false
复制
说明：
如题面图1 
示例2
输入：
{2,1,3}
复制
返回值：
true
复制
说明：
如题面图2 
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
# @return bool布尔型
#
class Solution:

    def isValidBST(self, root: TreeNode) -> bool:
        # write code here

        self.pre = None

        def mid(root: TreeNode) -> bool:
            if root:
                if not mid(root.left): return False
                if not self.pre: self.pre = root.val
                elif root.val <= self.pre: return False
                else: self.pre = root.val
                return mid(root.right)
            return True

        return mid(root)
