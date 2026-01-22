/*
 * @lc app=leetcode.cn id=3507 lang=golang
 * @lcpr version=30204
 *
 * [3507] 移除最小数对使数组有序 I
 *
 * https://leetcode.cn/problems/minimum-pair-removal-to-sort-array-i/description/
 *
 * algorithms
 * Easy (50.97%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 8.8K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个数组 nums，你可以执行以下操作任意次数：
 *
 *
 * 选择 相邻 元素对中 和最小 的一对。如果存在多个这样的对，选择最左边的一个。
 * 用它们的和替换这对元素。
 *
 *
 * 返回将数组变为 非递减 所需的 最小操作次数 。
 *
 * 如果一个数组中每个元素都大于或等于它前一个元素（如果存在的话），则称该数组为非递减。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： nums = [5,2,3,1]
 *
 * 输出： 2
 *
 * 解释：
 *
 *
 * 元素对 (3,1) 的和最小，为 4。替换后 nums = [5,2,4]。
 * 元素对 (2,4) 的和为 6。替换后 nums = [5,6]。
 *
 *
 * 数组 nums 在两次操作后变为非递减。
 *
 *
 * 示例 2：
 *
 *
 * 输入： nums = [1,2,2]
 *
 * 输出： 0
 *
 * 解释：
 *
 * 数组 nums 已经是非递减的。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50
 * -1000 <= nums[i] <= 1000
 *
 *
 */

// @lcpr-template-start
package main

// @lcpr-template-end
// @lc code=start
func minimumPairRemoval(nums []int) int {
	if len(nums) <= 1 {
		return 0
	}

	judge := func() bool {
		for i := 1; i < len(nums); i++ {
			if nums[i] < nums[i-1] {
				return false
			}
		}
		return true
	}

	res := 0
	for !judge() {
		index := 0
		for i := 1; i < len(nums)-1; i++ {
			if nums[i]+nums[i+1] < nums[index]+nums[index+1] {
				index = i
			}
		}
		nums = append(nums[:index], append([]int{nums[index] + nums[index+1]}, nums[index+2:]...)...)
		res++
	}
	return res
}

// @lc code=end

/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

*/
