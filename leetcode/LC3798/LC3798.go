/*
 * @lc app=leetcode.cn id=3798 lang=golang
 * @lcpr version=30204
 *
 * [3798] 最大的偶数
 *
 * https://leetcode.cn/problems/largest-even-number/description/
 *
 * algorithms
 * Easy (74.28%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    2.8K
 * Total Submissions: 3.7K
 * Testcase Example:  '"1112"'
 *
 * 给你一个仅由字符'1'和'2'组成的字符串s。
 *
 * 你可以删除字符串s中的任意数量的字符，但必须保持剩余字符的顺序不变。
 *
 * 返回可以表示 偶数 整数的 最大结果字符串 。如果不存在这样的字符串，则返回空字符串""。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: s = "1112"
 *
 * 输出: "1112"
 *
 * 解释:
 *
 * 该字符串已经表示了最大的偶数，因此不需要删除任何字符。
 *
 *
 * 示例 2：
 *
 *
 * 输入: s = "221"
 *
 * 输出: "22"
 *
 * 解释:
 *
 * 删除'1'后，可以得到最大的偶数，即 22。
 *
 *
 * 示例 3：
 *
 *
 * 输入: s = "1"
 *
 * 输出: ""
 *
 * 解释:
 *
 * 无法通过删除字符得到偶数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 100
 * s 仅由字符 '1' 和 '2' 组成。
 *
 *
 */

// @lcpr-template-start
package main

// @lcpr-template-end
// @lc code=start
func largestEven(s string) string {
	index := len(s)
	for index-1 >= 0 && s[index-1] == '1' {
		index--
	}
	return s[:index]
}

// @lc code=end

/*
// @lcpr case=start
// "1112"\n
// @lcpr case=end

// @lcpr case=start
// "221"\n
// @lcpr case=end

// @lcpr case=start
// "1"\n
// @lcpr case=end

*/
