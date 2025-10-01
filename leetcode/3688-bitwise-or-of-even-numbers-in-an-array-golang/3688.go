/*
 * @lc app=leetcode.cn id=3688 lang=golang
 * @lcpr version=30204
 *
 * [3688] 偶数的按位或运算
 *
 * https://leetcode.cn/problems/bitwise-or-of-even-numbers-in-an-array/description/
 *
 * algorithms
 * Easy (84.00%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 3.8K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一个整数数组 nums。
 *
 * 返回数组中所有 偶数 的按位 或 运算结果。
 *
 * 如果 nums 中没有偶数，返回 0。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： nums = [1,2,3,4,5,6]
 *
 * 输出： 6
 *
 * 解释：
 *
 * 偶数为 2、4 和 6。它们的按位或运算结果是 6。
 *
 *
 * 示例 2：
 *
 *
 * 输入： nums = [7,9,11]
 *
 * 输出： 0
 *
 * 解释：
 *
 * 数组中没有偶数，因此结果为 0。
 *
 *
 * 示例 3：
 *
 *
 * 输入： nums = [1,8,16]
 *
 * 输出： 24
 *
 * 解释：
 *
 * 偶数为 8 和 16。它们的按位或运算结果是 24。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func evenNumberBitwiseORs(nums []int) int {

	res := 0
	for _, v := range nums {
		if v&0x1 == 0 {
			res |= v
		}
	}
	return res

}

// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [7,9,11]\n
// @lcpr case=end

// @lcpr case=start
// [1,8,16]\n
// @lcpr case=end

*/
