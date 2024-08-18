#
# @lc app=leetcode.cn id=208 lang=python3
#
# [208] 实现 Trie (前缀树)
#
# https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
#
# algorithms
# Medium (68.34%)
# Likes:    392
# Dislikes: 0
# Total Accepted:    53.2K
# Total Submissions: 77.5K
# Testcase Example:  '["Trie","insert","search","search","startsWith","insert"
# ,"search"]\n' +'[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
#
# 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
#
# 示例:
#
# Trie trie = new Trie();
#
# trie.insert("apple");
# trie.search("apple");   // 返回 true
# trie.search("app");     // 返回 false
# trie.startsWith("app"); // 返回 true
# trie.insert("app");
# trie.search("app");     // 返回 true
#
# 说明:
#
#
# 你可以假设所有的输入都是由小写字母 a-z 构成的。
# 保证所有输入均为非空字符串。
#
#
#


# @lc code=start
class Trie:
    class Node:
        def __init__(self):
            self.child = {}
            self.isWord = False

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = self.Node()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        cur = self.root
        for i in word:
            cur.child.setdefault(i, self.Node())
            cur = cur.child[i]
        cur.isWord = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        cur = self.root
        for i in word:
            if i not in cur.child:
                return False
            cur = cur.child[i]
        return cur.isWord

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the \
            given prefix.
        """
        cur = self.root
        for i in prefix:
            if i not in cur.child:
                return False
            cur = cur.child[i]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# @lc code=end
