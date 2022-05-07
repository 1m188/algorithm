#
# @lc app=leetcode.cn id=449 lang=python3
#
# [449] 序列化和反序列化二叉搜索树
#
# https://leetcode-cn.com/problems/serialize-and-deserialize-bst/description/
#
# algorithms
# Medium (52.65%)
# Likes:    104
# Dislikes: 0
# Total Accepted:    7.6K
# Total Submissions: 14.4K
# Testcase Example:  '[2,1,3]'
#
# 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
#
# 设计一个算法来序列化和反序列化二叉搜索树。 对序列化/反序列化算法的工作方式没有限制。
# 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
#
# 编码的字符串应尽可能紧凑。
#
# 注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。
#
#


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        if not root:
            return ""
        s = []
        st = []
        while root or st:
            if root:
                s.append(str(root.val))
                st.append(root)
                root = root.left
            else:
                root = st.pop()
                root = root.right
        return '/'.join(s)

    def insert(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            root = TreeNode(key)
            return root

        if key < root.val:
            root.left = self.insert(root.left, key)
        elif key > root.val:
            root.right = self.insert(root.right, key)
        return root

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        if not data:
            return None
        data = data.split('/')
        root = None
        for k in data:
            root = self.insert(root, int(k))
        return root


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
# @lc code=end
