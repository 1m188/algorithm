'''
描述
给定一个二叉树，确定他是否是一个完全二叉树。

完全二叉树的定义：若二叉树的深度为 h，除第 h 层外，其它各层的结点数都达到最大个数，第 h 层所有的叶子结点都连续集中在最左边，这就是完全二叉树。（第 h 层可能包含 [1~2h] 个节点）

数据范围：节点数满足 1 \le n \le 100 \1≤n≤100 
样例图1：

样例图2：

样例图3：

示例1
输入：
{1,2,3,4,5,6}
复制
返回值：
true
复制
示例2
输入：
{1,2,3,4,5,6,7}
复制
返回值：
true
复制
示例3
输入：
{1,2,3,4,5,#,6}
复制
返回值：
false
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

    def isCompleteTree(self, root: TreeNode) -> bool:
        # write code here

        li = []
        que = [root]
        while que:
            x = que.pop(0)
            li.append(x)
            if not x: continue
            que.append(x.left)
            que.append(x.right)

        for i in range(len(li)):
            if not li[i]: break
        for j in range(i + 1, len(li)):
            if li[j]: return False
        return True