/*
 * @lc app=leetcode.cn id=3105 lang=golang
 * @lcpr version=30204
 *
 * [3105] 最长的严格递增或递减子数组
 *
 * https://leetcode.cn/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/
 *
 * algorithms
 * Easy (62.72%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 13.3K
 * Testcase Example:  '[1,4,3,3,2]'
 *
 * 给你一个整数数组 nums 。
 *
 * 返回数组 nums 中 严格递增 或 严格递减 的最长非空子数组的长度。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,4,3,3,2]
 *
 * 输出：2
 *
 * 解释：
 *
 * nums 中严格递增的子数组有[1]、[2]、[3]、[3]、[4] 以及 [1,4] 。
 *
 * nums 中严格递减的子数组有[1]、[2]、[3]、[3]、[4]、[3,2] 以及 [4,3] 。
 *
 * 因此，返回 2 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,3,3,3]
 *
 * 输出：1
 *
 * 解释：
 *
 * nums 中严格递增的子数组有 [3]、[3]、[3] 以及 [3] 。
 *
 * nums 中严格递减的子数组有 [3]、[3]、[3] 以及 [3] 。
 *
 * 因此，返回 1 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [3,2,1]
 *
 * 输出：3
 *
 * 解释：
 *
 * nums 中严格递增的子数组有 [3]、[2] 以及 [1] 。
 *
 * nums 中严格递减的子数组有 [3]、[2]、[1]、[3,2]、[2,1] 以及 [3,2,1] 。
 *
 * 因此，返回 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50
 * 1 <= nums[i] <= 50
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func longestMonotonicSubarray(nums []int) int {

	calc := func(nums []int, f bool) int {
		res := 1

		left := 0
		right := 0
		for right+1 < len(nums) {
			if f {
				if nums[right+1] > nums[right] {
					right++
				} else {
					res = max(res, right-left+1)
					left = right + 1
					right = left
				}
			} else {
				if nums[right+1] < nums[right] {
					right++
				} else {
					res = max(res, right-left+1)
					left = right + 1
					right = left
				}
			}
		}
		res = max(res, right-left+1)

		return res
	}

	return max(calc(nums, true), calc(nums, false))

}

// @lc code=end

/*
// @lcpr case=start
// [1,4,3,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

*/
