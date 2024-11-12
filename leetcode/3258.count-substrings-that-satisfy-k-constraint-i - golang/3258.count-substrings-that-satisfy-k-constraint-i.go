/*
 * @lc app=leetcode.cn id=3258 lang=golang
 * @lcpr version=30204
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
 *
 * https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/description/
 *
 * algorithms
 * Easy (80.45%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 15.7K
 * Testcase Example:  '"10101"\n1'
 *
 * 给你一个 二进制 字符串 s 和一个整数 k。
 *
 * 如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：
 *
 *
 * 字符串中 0 的数量最多为 k。
 * 字符串中 1 的数量最多为 k。
 *
 *
 * 返回一个整数，表示 s 的所有满足 k 约束 的子字符串的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "10101", k = 1
 *
 * 输出：12
 *
 * 解释：
 *
 * s 的所有子字符串中，除了 "1010"、"10101" 和 "0101" 外，其余子字符串都满足 k 约束。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "1010101", k = 2
 *
 * 输出：25
 *
 * 解释：
 *
 * s 的所有子字符串中，除了长度大于 5 的子字符串外，其余子字符串都满足 k 约束。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "11111", k = 1
 *
 * 输出：15
 *
 * 解释：
 *
 * s 的所有子字符串都满足 k 约束。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 50
 * 1 <= k <= s.length
 * s[i] 是 '0' 或 '1'。
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func countKConstraintSubstrings(s string, k int) int {

	find := func(idx int) int {
		zero, one := 0, 0
		res := 0
		for i := idx; i < len(s); i++ {
			if s[i] == '0' {
				zero++
			} else {
				one++
			}

			if zero <= k || one <= k {
				res++
			} else {
				return res
			}
		}
		return res
	}

	res := 0
	for i, _ := range s {
		res += find(i)
	}
	return res

}

// @lc code=end

/*
// @lcpr case=start
// "10101"\n1\n
// @lcpr case=end

// @lcpr case=start
// "1010101"\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n1\n
// @lcpr case=end

*/
