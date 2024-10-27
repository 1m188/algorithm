/*
 * @lc app=leetcode.cn id=LCR 126 lang=golang
 * @lcpr version=30204
 *
 * [LCR 126] 斐波那契数
 *
 * https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/description/
 *
 * algorithms
 * Easy (35.67%)
 * Likes:    537
 * Dislikes: 0
 * Total Accepted:    530.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '2'
 *
 * 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 *
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 *
 *
 * 给定 n ，请计算 F(n) 。
 *
 * 答案需要取模 1e9+7(1000000007) ，如计算初始结果为：1000000008，请返回 1。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 *
 *
 * 示例 2：
 *
 * 输入：n = 3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 *
 *
 * 示例 3：
 *
 * 输入：n = 4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 100
 *
 *
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func fib(n int) int {

	const mod = 1000000007

	if n <= 1 {
		return n
	}

	a := 0
	b := 1
	for i := 2; i < n; i++ {
		a, b = b, a+b
		a %= mod
		b %= mod
	}

	return (a + b) % mod
}

// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

*/
