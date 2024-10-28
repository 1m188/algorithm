/*
 * @lc app=leetcode.cn id=LCR 186 lang=golang
 * @lcpr version=30204
 *
 * [LCR 186] 文物朝代判断
 *
 * https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/description/
 *
 * algorithms
 * Easy (45.04%)
 * Likes:    369
 * Dislikes: 0
 * Total Accepted:    234.2K
 * Total Submissions: 519.9K
 * Testcase Example:  '[0,6,9,0,7]'
 *
 * 展览馆展出来自 13 个朝代的文物，每排展柜展出 5 个文物。某排文物的摆放情况记录于数组 places，其中 places[i] 表示处于第 i
 * 位文物的所属朝代编号。其中，编号为 0
 * 的朝代表示未知朝代。请判断并返回这排文物的所属朝代编号是否能够视为连续的五个朝代（如遇未知朝代可算作连续情况）。
 *
 *
 *
 * 示例 1：
 *
 * 输入: places = [0, 6, 9, 0, 7]
 * 输出: True
 *
 *
 *
 *
 * 示例 2：
 *
 * 输入: places = [7, 8, 9, 10, 11]
 * 输出: True
 *
 *
 *
 *
 * 提示：
 *
 *
 * places.length = 5
 * 0 <= places[i] <= 13
 *
 *
 *
 *
 */
package main

import "sort"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func checkDynasty(places []int) bool {

	nums := []int{}
	zeros := 0

	for _, val := range places {
		if val == 0 {
			zeros++
		} else {
			nums = append(nums, val)
		}
	}

	if zeros == 5 {
		return true
	}

	sort.Ints(nums)

	for i := 1; i < len(nums); i++ {
		x := nums[i] - nums[i-1] - 1
		if x < 0 {
			return false
		}
		zeros -= x
	}

	return zeros >= 0

}

// @lc code=end

/*
// @lcpr case=start
// [0, 6, 9, 0, 7]\n
// @lcpr case=end

// @lcpr case=start
// [7, 8, 9, 10, 11]\n
// @lcpr case=end

*/
