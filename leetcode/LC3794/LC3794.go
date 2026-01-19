/*
 * @lc app=leetcode.cn id=3794 lang=golang
 * @lcpr version=30204
 *
 * [3794] 反转字符串前缀
 *
 * https://leetcode.cn/problems/reverse-string-prefix/description/
 *
 * algorithms
 * Easy (88.88%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    1.9K
 * Total Submissions: 2.2K
 * Testcase Example:  '"abcd"\n2'
 *
 * 给你一个字符串 s 和一个整数 k。
 *
 * 反转 s 的前 k 个字符，并返回结果字符串。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcd", k = 2
 *
 * 输出: "bacd"
 *
 * 解释:
 *
 * 前 k = 2 个字符 "ab" 反转为 "ba"。最终得到的结果字符串为 "bacd"。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "xyz", k = 3
 *
 * 输出: "zyx"
 *
 * 解释:
 *
 * 前 k = 3 个字符 "xyz" 反转为 "zyx"。最终得到的结果字符串为 "zyx"。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "hey", k = 1
 *
 * 输出: "hey"
 *
 * 解释:
 *
 * 前 k = 1 个字符 "h" 在反转后保持不变。最终得到的结果字符串为 "hey"。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length <= 100
 * s 仅由小写英文字母组成。
 * 1 <= k <= s.length
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func reversePrefix(s string, k int) string {
	b := []byte(s)
	i, j := 0, k-1
	for i < j {
		b[i], b[j] = b[j], b[i]
		i++
		j--
	}
	return string(b)
}

// @lc code=end

/*
// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

// @lcpr case=start
// "xyz"\n3\n
// @lcpr case=end

// @lcpr case=start
// "hey"\n1\n
// @lcpr case=end

*/
