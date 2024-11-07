/*
 * @lc app=leetcode.cn id=LCR 085 lang=golang
 * @lcpr version=30204
 *
 * [LCR 085] 括号生成
 *
 * https://leetcode.cn/problems/IDBivT/description/
 *
 * algorithms
 * Medium (84.30%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    36.5K
 * Total Submissions: 43.3K
 * Testcase Example:  '3'
 *
 * 正整数 n 代表生成括号的对数，请设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 *
 * 示例 2：
 *
 * 输入：n = 1
 * 输出：["()"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
 *
 *
 *
 *
 * 注意：本题与主站 22 题相同： https://leetcode-cn.com/problems/generate-parentheses/
 *
 */
package main

import "strings"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func generateParenthesis(n int) []string {

	res := []string{}
	str := []string{}

	var calc func(int, int)
	calc = func(left, right int) {
		if left >= n {
			x := []string{}
			for right < left {
				x = append(x, ")")
				right++
			}
			res = append(res, strings.Join(str, "")+strings.Join(x, ""))
		} else {
			str = append(str, "(")
			calc(left+1, right)
			str = str[:len(str)-1]

			if right < left {
				str = append(str, ")")
				calc(left, right+1)
				str = str[:len(str)-1]
			}
		}
	}
	calc(0, 0)

	return res
}

// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

*/
