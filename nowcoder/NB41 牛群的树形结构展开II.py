'''

描述
农场里有一群牛，牛群的成员分布在山坡上，形成了一个二叉树结构。每头牛都有一个编号，表示它在牛群中的身份。现在农场主想要将牛群的二叉树结构展开为一个链表。展开后的链表应该同样使用 TreeNode ，其中 left 子指针指向空，而 right 子指针指向链表中后一个结点。展开后的链表应该与二叉树中序遍历顺序相同。


示例1
输入：
{1, 2, 5, 3, 4, #, 6}
复制
返回值：
{3,#,2,#,4,#,1,#,5,#,6}
复制
示例2
输入：
{1,2,3}
复制
返回值：
{2,#,1,#,3}
复制
备注：
树中结点数在范围 [0, 3000] 内
0 <= Node.val <= 200
#表示空节点

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
# @return TreeNode类
#
class Solution:

    def flattenII(self, root: TreeNode) -> TreeNode:
        # write code here

        if not root: return root

        self.pre: TreeNode = None

        node = root
        while node.left:
            node = node.left

        def mid(node: TreeNode):
            if not node: return
            mid(node.left)
            if not self.pre:
                self.pre = node
            else:
                self.pre.right = node
                self.pre.left = None
                self.pre = node
            mid(node.right)

        mid(root)

        return node
