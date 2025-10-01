/*
 * @lc app=leetcode.cn id=3658 lang=golang
 * @lcpr version=30204
 *
 * [3658] 奇数和与偶数和的最大公约数
 *
 * https://leetcode.cn/problems/gcd-of-odd-and-even-sums/description/
 *
 * algorithms
 * Easy (84.25%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 4.3K
 * Testcase Example:  '4'
 *
 * 给你一个整数 n。请你计算以下两个值的 最大公约数（GCD）：
 *
 *
 *
 * sumOdd：前 n 个奇数的总和。
 *
 *
 * sumEven：前 n 个偶数的总和。
 *
 *
 *
 * 返回 sumOdd 和 sumEven 的 GCD。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： n = 4
 *
 * 输出： 4
 *
 * 解释：
 *
 *
 * 前 4 个奇数的总和 sumOdd = 1 + 3 + 5 + 7 = 16
 * 前 4 个偶数的总和 sumEven = 2 + 4 + 6 + 8 = 20
 *
 *
 * 因此，GCD(sumOdd, sumEven) = GCD(16, 20) = 4。
 *
 *
 * 示例 2：
 *
 *
 * 输入： n = 5
 *
 * 输出： 5
 *
 * 解释：
 *
 *
 * 前 5 个奇数的总和 sumOdd = 1 + 3 + 5 + 7 + 9 = 25
 * 前 5 个偶数的总和 sumEven = 2 + 4 + 6 + 8 + 10 = 30
 *
 *
 * 因此，GCD(sumOdd, sumEven) = GCD(25, 30) = 5。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func gcdOfOddEvenSums(n int) int {

	sumOdd := (2*n*(2*n+1)/2 - n) / 2
	sumEven := sumOdd + n

	var gcd func(int, int) int
	gcd = func(a, b int) int {
		if b == 0 {
			return a
		}
		return gcd(b, a%b)
	}

	return gcd(sumOdd, sumEven)

}

// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

*/
