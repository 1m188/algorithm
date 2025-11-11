/*
 * @lc app=leetcode.cn id=3211 lang=golang
 * @lcpr version=30204
 *
 * [3211] 生成不含相邻零的二进制字符串
 *
 * https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/description/
 *
 * algorithms
 * Medium (83.26%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 7.8K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n。
 *
 * 如果一个二进制字符串 x 的所有长度为 2 的子字符串中包含 至少 一个 "1"，则称 x 是一个 有效 字符串。
 *
 * 返回所有长度为 n 的 有效 字符串，可以以任意顺序排列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： n = 3
 *
 * 输出： ["010","011","101","110","111"]
 *
 * 解释：
 *
 * 长度为 3 的有效字符串有："010"、"011"、"101"、"110" 和 "111"。
 *
 *
 * 示例 2：
 *
 *
 * 输入： n = 1
 *
 * 输出： ["0","1"]
 *
 * 解释：
 *
 * 长度为 1 的有效字符串有："0" 和 "1"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 18
 *
 *
 */
package leetcode

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func validStrings(n int) []string {

	if n == 1 {
		return []string{"0", "1"}
	}

	res := []string{}

	var dfs func(int, string)
	dfs = func(num int, str string) {
		if num == n {
			res = append(res, str)
			return
		}

		if str[len(str)-1] == '0' {
			dfs(num+1, str+"1")
		} else {
			dfs(num+1, str+"1")
			dfs(num+1, str+"0")
		}
	}
	dfs(1, "0")
	dfs(1, "1")

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
