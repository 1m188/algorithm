#
# @lc app=leetcode.cn id=535 lang=python3
#
# [535] TinyURL 的加密与解密
#
# https://leetcode-cn.com/problems/encode-and-decode-tinyurl/description/
#
# algorithms
# Medium (82.30%)
# Likes:    89
# Dislikes: 0
# Total Accepted:    10.4K
# Total Submissions: 12.6K
# Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
#
# TinyURL是一种URL简化服务， 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl
# 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.
#
# 要求：设计一个 TinyURL 的加密 encode 和解密 decode
# 的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。
#
#


# @lc code=start
class Codec:
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        return longUrl

        # res = []
        # for i in longUrl:
        #     res.append(str(ord(i)))
        # return '/'.join(res)

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return shortUrl

        # res = []
        # for i in shortUrl.split('/'):
        #     res.append(chr(int(i)))
        # return ''.join(res)


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
# @lc code=end
