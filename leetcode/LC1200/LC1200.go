/*
 * @lc app=leetcode.cn id=1200 lang=golang
 * @lcpr version=30204
 *
 * [1200] 最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (72.56%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    69.5K
 * Total Submissions: 95.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你个整数数组 arr，其中每个元素都 不相同。
 *
 * 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
 *
 * 每对元素对 [a,b] 如下：
 *
 *
 * a , b 均为数组 arr 中的元素
 * a < b
 * b - a 等于 arr 中任意两个元素的最小绝对差
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [4,2,1,3]
 * 输出：[[1,2],[2,3],[3,4]]
 *
 *
 * 示例 2：
 *
 * 输入：arr = [1,3,6,10,15]
 * 输出：[[1,3]]
 *
 *
 * 示例 3：
 *
 * 输入：arr = [3,8,-10,23,19,-4,-14,27]
 * 输出：[[-14,-10],[19,23],[23,27]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 *
 *
 */

// @lcpr-template-start
package main

import (
	"math"
	"slices"
)

// @lcpr-template-end
// @lc code=start
func minimumAbsDifference(arr []int) [][]int {
	slices.Sort(arr)

	diff := math.MaxInt
	for i := 1; i < len(arr); i++ {
		if d := arr[i] - arr[i-1]; d < diff {
			diff = d
		}
	}

	ans := make([][]int, 0, len(arr))
	for i := 1; i < len(arr); i++ {
		if arr[i]-arr[i-1] == diff {
			ans = append(ans, []int{arr[i-1], arr[i]})
		}
	}

	return ans
}

// @lc code=end

/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,6,10,15]\n
// @lcpr case=end

// @lcpr case=start
// [3,8,-10,23,19,-4,-14,27]\n
// @lcpr case=end

*/
