/*
 * @lc app=leetcode.cn id=3701 lang=golang
 * @lcpr version=30204
 *
 * [3701] 计算交替和
 *
 * https://leetcode.cn/problems/compute-alternating-sum/description/
 *
 * algorithms
 * Easy (88.29%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 3.6K
 * Testcase Example:  '[1,3,5,7]'
 *
 * 给你一个整数数组 nums。
 *
 * 交替和 定义为：将 nums 中偶数下标位置的元素 相加 ，减去 奇数下标位置的元素。即：nums[0] - nums[1] + nums[2] -
 * nums[3]...
 *
 * 返回表示 nums 的交替和的整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： nums = [1,3,5,7]
 *
 * 输出： -4
 *
 * 解释：
 *
 *
 * 偶数下标位置的元素是 nums[0] = 1 和 nums[2] = 5，因为 0 和 2 是偶数。
 * 奇数下标位置的元素是 nums[1] = 3 和 nums[3] = 7，因为 1 和 3 是奇数。
 * 交替和为 nums[0] - nums[1] + nums[2] - nums[3] = 1 - 3 + 5 - 7 = -4。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入： nums = [100]
 *
 * 输出： 100
 *
 * 解释：
 *
 *
 * 唯一的偶数下标位置的元素是 nums[0] = 100，因为 0 是偶数。
 * 没有奇数下标位置的元素。
 * 交替和为 nums[0] = 100。
 *
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
func alternatingSum(nums []int) int {

	jishu := 0
	for i := range nums {
		jishu += (i & 0x1) * (-1) * nums[i]
	}

	oushu := 0
	for i := 0; i < len(nums); i += 2 {
		oushu += nums[i]
	}

	return jishu + oushu

}

// @lc code=end

/*
// @lcpr case=start
// [1,3,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [100]\n
// @lcpr case=end

*/
