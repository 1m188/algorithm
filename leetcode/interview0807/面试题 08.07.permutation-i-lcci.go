/*
 * @lc app=leetcode.cn id=面试题 08.07 lang=golang
 * @lcpr version=30204
 *
 * [面试题 08.07] 无重复字符串的排列组合
 *
 * https://leetcode.cn/problems/permutation-i-lcci/description/
 *
 * LCCI
 * Medium (81.07%)
 * Likes:    95
 * Dislikes: 0
 * Total Accepted:    37.3K
 * Total Submissions: 46.1K
 * Testcase Example:  '"qwe"'
 *
 * 无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。
 *
 * ⁠示例1:
 *
 * ⁠输入：S = "qwe"
 * ⁠输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
 *
 *
 * ⁠示例2:
 *
 * ⁠输入：S = "ab"
 * ⁠输出：["ab", "ba"]
 *
 *
 * ⁠提示:
 *
 *
 * 字符都是英文字母。
 * 字符串长度在[1, 9]之间。
 *
 *
 */
package leetcode

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func permutation(S string) []string {

	res := []string{}
	tmp := ""
	flags := make([]bool, len(S))

	var dfs func(int)
	dfs = func(cnt int) {
		if cnt == len(S) {
			res = append(res, tmp)
			return
		}

		for i := 0; i < len(S); i++ {
			if flags[i] {
				continue
			}

			flags[i] = true
			tmp += string(S[i])
			dfs(cnt + 1)
			tmp = tmp[:len(tmp)-1]
			flags[i] = false
		}
	}
	dfs(0)

	return res

}

// @lc code=end

/*
// @lcpr case=start
// "qwe"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n
// @lcpr case=end

*/
