/*
 * @lc app=leetcode.cn id=LCP 18 lang=golang
 * @lcpr version=30204
 *
 * [LCP 18] 早餐组合
 *
 * https://leetcode.cn/problems/2vYnGI/description/
 *
 * algorithms
 * Easy (31.04%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    29.5K
 * Total Submissions: 94.6K
 * Testcase Example:  '[10,20,5]\n[5,5,2]\n15'
 *
 * 小扣在秋日市集选择了一家早餐摊位，一维整型数组 `staple` 中记录了每种主食的价格，一维整型数组 `drinks`
 * 中记录了每种饮料的价格。小扣的计划选择一份主食和一款饮料，且花费不超过 `x` 元。请返回小扣共有多少种购买方案。
 *
 * 注意：答案需要以 `1e9 + 7 (1000000007)` 为底取模，如：计算初始结果为：`1000000008`，请返回 `1`
 *
 * **示例 1：**
 * >输入：`staple = [10,20,5], drinks = [5,5,2], x = 15`
 * >
 * >输出：`6`
 * >
 * >解释：小扣有 6 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
 * >第 1 种方案：staple[0] + drinks[0] = 10 + 5 = 15；
 * >第 2 种方案：staple[0] + drinks[1] = 10 + 5 = 15；
 * >第 3 种方案：staple[0] + drinks[2] = 10 + 2 = 12；
 * >第 4 种方案：staple[2] + drinks[0] = 5 + 5 = 10；
 * >第 5 种方案：staple[2] + drinks[1] = 5 + 5 = 10；
 * >第 6 种方案：staple[2] + drinks[2] = 5 + 2 = 7。
 *
 * **示例 2：**
 * >输入：`staple = [2,1,1], drinks = [8,9,5,1], x = 9`
 * >
 * >输出：`8`
 * >
 * >解释：小扣有 8 种购买方案，所选主食与所选饮料在数组中对应的下标分别是：
 * >第 1 种方案：staple[0] + drinks[2] = 2 + 5 = 7；
 * >第 2 种方案：staple[0] + drinks[3] = 2 + 1 = 3；
 * >第 3 种方案：staple[1] + drinks[0] = 1 + 8 = 9；
 * >第 4 种方案：staple[1] + drinks[2] = 1 + 5 = 6；
 * >第 5 种方案：staple[1] + drinks[3] = 1 + 1 = 2；
 * >第 6 种方案：staple[2] + drinks[0] = 1 + 8 = 9；
 * >第 7 种方案：staple[2] + drinks[2] = 1 + 5 = 6；
 * >第 8 种方案：staple[2] + drinks[3] = 1 + 1 = 2；
 *
 * **提示：**
 * + `1 <= staple.length <= 10^5`
 * + `1 <= drinks.length <= 10^5`
 * + `1 <= staple[i],drinks[i] <= 10^5`
 * + `1 <= x <= 2*10^5`
 */
package main

import "sort"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func breakfastNumber(staple []int, drinks []int, x int) int {

	const mod = 1000000007

	// 二分查找到目标值索引，没有则返回符合要求的最近位置的索引
	bfind := func(vec []int, target int) int {
		left := 0
		right := len(vec) - 1
		mid := 0
		for left <= right {
			mid = (left + right) / 2
			if vec[mid] == target {
				idx := mid
				for ; idx < len(vec); idx++ {
					if vec[idx] != target {
						break
					}
				}
				return idx - 1
			} else if vec[mid] < target {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}

		if vec[mid] < target {
			for i := mid; i < len(vec); i++ {
				if vec[i] > target {
					return i - 1
				}
			}
			return len(vec) - 1
		} else {
			for i := mid; i >= 0; i-- {
				if vec[i] < target {
					return i
				}
			}
			return -1
		}
	}

	res := 0

	sort.Ints(staple)
	sort.Ints(drinks)

	for _, val := range staple {
		if val >= x {
			break
		}
		res = (res + bfind(drinks, x-val) + 1) % mod
	}

	return res

}

// @lc code=end

/*
// @lcpr case=start
// [10,20,5]\n[5,5,2]\n15`>\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1]\n[8,9,5,1]\n9`>\n
// @lcpr case=end

*/
