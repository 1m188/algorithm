/*
 * @lc app=leetcode.cn id=面试题 17.10 lang=golang
 * @lcpr version=30204
 *
 * [面试题 17.10] 主要元素
 *
 * https://leetcode.cn/problems/find-majority-element-lcci/description/
 *
 * LCCI
 * Easy (56.00%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    81.6K
 * Total Submissions: 145.8K
 * Testcase Example:  '[3,2,3]'
 *
 * 数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。若没有，返回 -1 。请设计时间复杂度为 O(N) 、空间复杂度为
 * O(1) 的解决方案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[1,2,5,9,5,9,5,5,5]
 * 输出：5
 *
 * 示例 2：
 *
 * 输入：[3,2]
 * 输出：-1
 *
 * 示例 3：
 *
 * 输入：[2,2,1,1,1,2,2]
 * 输出：2
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func majorityElement(nums []int) int {

	res := nums[0]
	cnt := 1

	for i, v := range nums {
		if i == 0 {
			continue
		}

		if v == res {
			cnt++
		} else {
			cnt--
			if cnt <= 0 {
				res = v
				cnt = 1
			}
		}
	}

	cnt = 0
	for _, v := range nums {
		if v == res {
			cnt++
		}
	}

	if cnt > len(nums)/2 {
		return res
	} else {
		return -1
	}

}

// @lc code=end

/*
// @lcpr case=start
// [1,2,5,9,5,9,5,5,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

*/
