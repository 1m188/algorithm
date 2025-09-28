/*
 * @lc app=leetcode.cn id=976 lang=golang
 * @lcpr version=30204
 *
 * [976] 三角形的最大周长
 *
 * https://leetcode.cn/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (58.19%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    116.7K
 * Total Submissions: 199.7K
 * Testcase Example:  '[2,1,2]'
 *
 * 给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回
 * 0。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,1,2]
 * 输出：5
 * 解释：你可以用三个边长组成一个三角形:1 2 2。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,1,10]
 * 输出：0
 * 解释：
 * 你不能用边长 1,1,2 来组成三角形。
 * 不能用边长 1,1,10 来构成三角形。
 * 不能用边长 1、2 和 10 来构成三角形。
 * 因为我们不能用任何三条边长来构成一个非零面积的三角形，所以我们返回 0。
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^6
 *
 *
 */
package main

import "slices"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func largestPerimeter(nums []int) int {

	slices.Sort(nums)
	for i := len(nums) - 1; i >= 2; i-- {
		for j := i - 1; j >= 1; j-- {
			k := j - 1
			if nums[i] < nums[j]+nums[k] {
				return nums[i] + nums[j] + nums[k]
			}
		}
	}
	return 0

}

// @lc code=end

/*
// @lcpr case=start
// [2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,10]\n
// @lcpr case=end

*/
