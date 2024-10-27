/*
 * @lc app=leetcode.cn id=面试题 01.09 lang=golang
 * @lcpr version=30204
 *
 * [面试题 01.09] 字符串轮转
 *
 * https://leetcode.cn/problems/string-rotation-lcci/description/
 *
 * LCCI
 * Easy (53.59%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    94.1K
 * Total Submissions: 175.6K
 * Testcase Example:  '"waterbottle"\n"erbottlewat"'
 *
 * 字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
 *
 * 示例1:
 *
 * ⁠输入：s1 = "waterbottle", s2 = "erbottlewat"
 * ⁠输出：True
 *
 *
 * 示例2:
 *
 * ⁠输入：s1 = "aa", s2 = "aba"
 * ⁠输出：False
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 字符串长度在[0, 100000]范围内。
 *
 *
 * 说明:
 *
 *
 * 你能只调用一次检查子串的方法吗？
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func isFlipedString(s1 string, s2 string) bool {

	if len(s1) != len(s2) {
		return false
	}

	if s1 == s2 && s2 == "" {
		return true
	}

	for i := 0; i < len(s1); i++ {
		if s1[i] != s2[0] {
			continue
		}

		if s1[i:]+s1[:i] == s2 {
			return true
		}
	}
	return false

}

// @lc code=end

/*
// @lcpr case=start
// "waterbottle"\n"erbottlewat"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aba"\n
// @lcpr case=end

*/
