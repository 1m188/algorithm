/*
 * @lc app=leetcode.cn id=3483 lang=golang
 * @lcpr version=30204
 *
 * [3483] 不同三位偶数的数目
 *
 * https://leetcode.cn/problems/unique-3-digit-even-numbers/description/
 *
 * algorithms
 * Easy (68.26%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 5.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个数字数组 digits，你需要从中选择三个数字组成一个三位偶数，你的任务是求出 不同 三位偶数的数量。
 *
 * 注意：每个数字在三位偶数中都只能使用 一次 ，并且 不能 有前导零。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： digits = [1,2,3,4]
 *
 * 输出： 12
 *
 * 解释： 可以形成的 12 个不同的三位偶数是 124，132，134，142，214，234，312，314，324，342，412 和
 * 432。注意，不能形成 222，因为数字 2 只有一个。
 *
 *
 * 示例 2：
 *
 *
 * 输入： digits = [0,2,2]
 *
 * 输出： 2
 *
 * 解释： 可以形成的三位偶数是 202 和 220。注意，数字 2 可以使用两次，因为数组中有两个 2 。
 *
 *
 * 示例 3：
 *
 *
 * 输入： digits = [6,6,6]
 *
 * 输出： 1
 *
 * 解释： 只能形成 666。
 *
 *
 * 示例 4：
 *
 *
 * 输入： digits = [1,3,5]
 *
 * 输出： 0
 *
 * 解释： 无法形成三位偶数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= digits.length <= 10
 * 0 <= digits[i] <= 9
 *
 *
 */

package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func totalNumbers(digits []int) int {
	set := make(map[int]struct{})

	n := len(digits)
	for i := range n {
		if digits[i]&0x1 != 0 {
			continue
		}
		for j := range n {
			if i == j {
				continue
			}
			for k := range n {
				if i == k || j == k || digits[k] == 0 {
					continue
				}
				set[digits[i]+digits[j]*10+digits[k]*100] = struct{}{}
			}
		}
	}

	return len(set)
}

// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

*/
