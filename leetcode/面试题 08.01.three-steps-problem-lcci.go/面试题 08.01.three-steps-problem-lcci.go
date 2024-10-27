/*
 * @lc app=leetcode.cn id=面试题 08.01 lang=golang
 * @lcpr version=30204
 *
 * [面试题 08.01] 三步问题
 *
 * https://leetcode.cn/problems/three-steps-problem-lcci/description/
 *
 * LCCI
 * Easy (36.38%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    75.3K
 * Total Submissions: 207.1K
 * Testcase Example:  '3'
 *
 *
 * 三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。
 *
 * ⁠示例1:
 *
 * ⁠输入：n = 3
 * ⁠输出：4
 * ⁠说明: 有四种走法
 *
 *
 * ⁠示例2:
 *
 * ⁠输入：n = 5
 * ⁠输出：13
 *
 *
 * ⁠提示:
 *
 *
 * n范围在[1, 1000000]之间
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func waysToStep(n int) int {

	const mod = 1000000007

	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	if n == 3 {
		return 4
	}

	vec := make([]int, n+1)
	vec[1] = 1
	vec[2] = 2
	vec[3] = 4

	for i := 4; i <= n; i++ {
		vec[i] = (vec[i-1] + vec[i-2] + vec[i-3]) % mod
	}

	return vec[n]

}

// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

*/
