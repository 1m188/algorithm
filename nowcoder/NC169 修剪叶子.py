'''
描述
有一棵有
n
n个节点的二叉树，其根节点为
r
o
o
t
root。修剪规则如下:
1.修剪掉当前二叉树的叶子节点，但是不能直接删除叶子节点
2.只能修剪叶子节点的父节点，修剪了父节点之后，叶子节点也会对应删掉
3.如果想在留下尽可能多的节点前提下，修剪掉所有的叶子节点。请你返回修剪后的二叉树。
有如下二叉树:
     o
    / \
   o   o
  / \  / \
 o  o o   o
修剪过后仅会留下根节点。
示例1
输入：
{1,1,1,1,1,1,1}
复制
返回值：
{1}
复制
说明：

叶子节点为最下面的4个1节点，但是不能直接修剪，只能修剪中间的2个1，修剪掉之后，只有根节点了
     
示例2
输入：
{1,#,1,#,1,#,1,#,1}
复制
返回值：
{1,#,1,#,1}
复制
说明：
退化为一条链了，将最后两个节点删除。
     
备注：
2
≤
n
≤
1
0
5
2≤n≤10 
5
 ，删除根节点时返回为空。
'''


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left: 'TreeNode' = None
        self.right: 'TreeNode' = None


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

    def pruneLeaves(self, root: TreeNode) -> TreeNode:
        # write code here
        if not root: return root
        res = root
        if root.left:
            node = root.left
            if not node.left and not node.right:
                res = None
        if res == None: return res
        if root.right:
            node = root.right
            if not node.left and not node.right:
                res = None
        root.left = self.pruneLeaves(root.left)
        root.right = self.pruneLeaves(root.right)
        return res
