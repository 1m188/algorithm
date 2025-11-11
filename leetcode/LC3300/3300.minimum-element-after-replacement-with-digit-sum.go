/*
 * @lc app=leetcode.cn id=3300 lang=golang
 * @lcpr version=30204
 *
 * [3300] 替换为数位和以后的最小元素
 *
 * https://leetcode.cn/problems/minimum-element-after-replacement-with-digit-sum/description/
 *
 * algorithms
 * Easy (86.04%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    2.8K
 * Total Submissions: 3.2K
 * Testcase Example:  '[10,12,13,14]'
 *
 * 给你一个整数数组 nums 。
 *
 * 请你将 nums 中每一个元素都替换为它的各个数位之 和 。
 *
 * 请你返回替换所有元素以后 nums 中的 最小 元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,12,13,14]
 *
 * 输出：1
 *
 * 解释：
 *
 * nums 替换后变为 [1, 3, 4, 5] ，最小元素为 1 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,4]
 *
 * 输出：1
 *
 * 解释：
 *
 * nums 替换后变为 [1, 2, 3, 4] ，最小元素为 1 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [999,19,199]
 *
 * 输出：10
 *
 * 解释：
 *
 * nums 替换后变为 [27, 10, 19] ，最小元素为 10 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 10^4
 *
 *
 */
package leetcode

// @lcpr-template-start
import "math"

// @lcpr-template-end
// @lc code=start
func minElement(nums []int) int {

	sum := func(num int) int {
		res := 0
		for num > 0 {
			res += num % 10
			num /= 10
		}
		return res
	}

	for index, value := range nums {
		nums[index] = sum(value)
	}

	res := math.MaxInt
	for _, value := range nums {
		if value < res {
			res = value
		}
	}
	return res

}

// @lc code=end

/*
// @lcpr case=start
// [10,12,13,14]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [999,19,199]\n
// @lcpr case=end

*/
