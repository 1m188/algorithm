/*
 * @lc app=leetcode.cn id=3005 lang=golang
 * @lcpr version=30204
 *
 * [3005] 最大频率元素计数
 *
 * https://leetcode.cn/problems/count-elements-with-maximum-frequency/description/
 *
 * algorithms
 * Easy (70.86%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 17.2K
 * Testcase Example:  '[1,2,2,3,1,4]'
 *
 * 给你一个由 正整数 组成的数组 nums 。
 *
 * 返回数组 nums 中所有具有 最大 频率的元素的 总频率 。
 *
 * 元素的 频率 是指该元素在数组中出现的次数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,2,3,1,4]
 * 输出：4
 * 解释：元素 1 和 2 的频率为 2 ，是数组中的最大频率。
 * 因此具有最大频率的元素在数组中的数量是 4 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,4,5]
 * 输出：5
 * 解释：数组中的所有元素的频率都为 1 ，是最大频率。
 * 因此具有最大频率的元素在数组中的数量是 5 。
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

import "sort"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func maxFrequencyElements(nums []int) int {
	mmap := make(map[int]int, len(nums))
	for _, v := range nums {
		mmap[v]++
	}
	keys := make([]int, 0, len(mmap))
	for k := range mmap {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool {
		return mmap[keys[i]] > mmap[keys[j]]
	})

	res := mmap[keys[0]]
	for i := 1; i < len(keys); i++ {
		if mmap[keys[i]] < mmap[keys[i-1]] {
			break
		}
		res += mmap[keys[i]]
	}
	return res
}

// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

*/
