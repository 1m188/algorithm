'''
描述
给定一棵二叉树，已知其中的节点没有重复值，请判断该二叉树是否为搜索二叉树和完全二叉树。
输出描述：分别输出是否为搜索二叉树、完全二叉树。


数据范围：二叉树节点数满足 0 \le n \le 5000000≤n≤500000 ，二叉树上的值满足 0 \le val \le 1000000≤val≤100000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)

注意：空子树我们认为同时符合搜索二叉树和完全二叉树。
示例1
输入：
{2,1,3}
复制
返回值：
[true,true]
复制
示例2
输入：
{1,#,2}
复制
返回值：
[true,false]
复制
说明：
由于节点的右儿子大于根节点，无左子树，所以是搜索二叉树但不是完全二叉树     
示例3
输入：
{}
复制
返回值：
[true,true]
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
# @param root TreeNode类 the root
# @return bool布尔型一维数组
#
class Solution:

    def judgeIt(self, root: TreeNode) -> List[bool]:
        # write code here

        if not root: return [True, True]
        return [self.judge_s(root), self.judge_c(root)]

    def judge_s(self, root: TreeNode) -> bool:

        li = []

        def inorder(node: TreeNode):
            if node:
                inorder(node.left)
                li.append(node.val)
                inorder(node.right)

        inorder(root)
        for i in range(1, len(li)):
            if li[i] <= li[i - 1]: return False
        return True

    def judge_c(self, root: TreeNode) -> bool:

        li = []
        que = [root]
        while que:
            x = que.pop(0)
            li.append(x)
            if x:
                que.append(x.left)
                que.append(x.right)

        for i in range(len(li)):
            if not li[i]: break
        for j in range(i + 1, len(li)):
            if li[j]: return False
        return True