/*
 * @lc app=leetcode.cn id=LCP 28 lang=golang
 * @lcpr version=30204
 *
 * [LCP 28] 采购方案
 *
 * https://leetcode.cn/problems/4xy4Wx/description/
 *
 * algorithms
 * Easy (32.90%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 66.3K
 * Testcase Example:  '[2,5,3,5]\n6'
 *
 * 小力将 N 个零件的报价存于数组 `nums`。小力预算为
 * `target`，假定小力仅购买两个零件，要求购买零件的花费不超过预算，请问他有多少种采购方案。
 *
 * 注意：答案需要以 `1e9 + 7 (1000000007)` 为底取模，如：计算初始结果为：`1000000008`，请返回 `1`
 *
 *
 * **示例 1：**
 * >输入：`nums = [2,5,3,5], target = 6`
 * >
 * >输出：`1`
 * >
 * >解释：预算内仅能购买 nums[0] 与 nums[2]。
 *
 * **示例 2：**
 * >输入：`nums = [2,2,1,9], target = 10`
 * >
 * >输出：`4`
 * >
 * >解释：符合预算的采购方案如下：
 * >nums[0] + nums[1] = 4
 * >nums[0] + nums[2] = 3
 * >nums[1] + nums[2] = 3
 * >nums[2] + nums[3] = 10
 *
 * **提示：**
 * - `2 <= nums.length <= 10^5`
 * - `1 <= nums[i], target <= 10^5`
 *
 */
package main

import (
	"sort"
)

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func purchasePlans(nums []int, target int) int {

	const mod = 1000000007

	bfind := func(nums []int, target int) int {
		left := 0
		right := len(nums) - 1
		mid := 0
		for left <= right {
			mid = (left + right) / 2
			if nums[mid] == target {
				for i := mid; i < len(nums); i++ {
					if nums[i] > target {
						return i
					}
				}
				return len(nums)
			} else if nums[mid] > target {
				right = mid - 1
			} else {
				left = mid + 1
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

	sort.Ints(nums)

	res := 0
	for i := 0; i < len(nums)-1; i++ {
		x := target - nums[i]
		if x < nums[0] {
			break
		} else {
			tmp := nums[i+1:]
			res = (res + bfind(tmp, x)) % mod
		}
	}
	return res

}

// @lc code=end

/*
// @lcpr case=start
// [2,5,3,5]\n6`>\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,9]\n10`>\n
// @lcpr case=end

*/
