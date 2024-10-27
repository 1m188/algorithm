/*
 * @lc app=leetcode.cn id=LCR 068 lang=golang
 * @lcpr version=30204
 *
 * [LCR 068] 搜索插入位置
 *
 * https://leetcode.cn/problems/N6YdxV/description/
 *
 * algorithms
 * Easy (48.32%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    39.8K
 * Total Submissions: 82.4K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序的整数数组 nums 和一个整数目标值 target ，请在数组中找到 target
 * ，并返回其下标。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 *
 * 请必须使用时间复杂度为 O(log n) 的算法。
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 *
 *
 * 示例 2:
 *
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 *
 *
 * 示例 3:
 *
 * 输入: nums = [1,3,5,6], target = 7
 * 输出: 4
 *
 *
 * 示例 4:
 *
 * 输入: nums = [1,3,5,6], target = 0
 * 输出: 0
 *
 *
 * 示例 5:
 *
 * 输入: nums = [1], target = 0
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 为无重复元素的升序排列数组
 * -10^4 <= target <= 10^4
 *
 *
 *
 *
 * 注意：本题与主站 35 题相同： https://leetcode-cn.com/problems/search-insert-position/
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func searchInsert(nums []int, target int) int {

	left := 0
	right := len(nums) - 1
	mid := 0

	for left <= right {
		mid = (left + right) / 2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	if nums[mid] < target {
		for i := mid; i < len(nums); i++ {
			if nums[i] > target {
				return i
			}
		}
		return len(nums)
	} else {
		for i := mid; i >= 0; i-- {
			if nums[i] < target {
				return i + 1
			}
		}
		return 0
	}

}

// @lc code=end

/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

*/
