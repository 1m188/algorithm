/*
 * @lc app=leetcode.cn id=LCR 146 lang=golang
 * @lcpr version=30204
 *
 * [LCR 146] 螺旋遍历二维数组
 *
 * https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/
 *
 * algorithms
 * Easy (42.16%)
 * Likes:    606
 * Dislikes: 0
 * Total Accepted:    292.4K
 * Total Submissions: 693.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个二维数组 array，请返回「螺旋遍历」该数组的结果。
 *
 * 螺旋遍历：从左上角开始，按照 向右、向下、向左、向上 的顺序 依次 提取元素，然后再进入内部一层重复相同的步骤，直到提取完所有元素。
 *
 *
 *
 * 示例 1：
 *
 * 输入：array = [[1,2,3],[8,9,4],[7,6,5]]
 * 输出：[1,2,3,4,5,6,7,8,9]
 *
 *
 * 示例 2：
 *
 * 输入：array  = [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
 * 输出：[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
 *
 *
 *
 *
 * 限制：
 *
 *
 * 0 <= array.length <= 100
 * 0 <= array[i].length <= 100
 *
 *
 * 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/
 *
 *
 *
 */
package main

import "slices"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func spiralArray(array [][]int) []int {

	res := []int{}

	for len(array) != 0 {

		res = append(res, array[0]...)
		array = array[1:]

		for i := 0; i < len(array); i++ {
			n := len(array[i])
			if n <= 0 {
				continue
			}
			res = append(res, array[i][n-1])
			array[i] = array[i][:n-1]
		}

		if len(array) != 0 {
			slices.Reverse(array[len(array)-1])
			res = append(res, array[len(array)-1]...)
			array = array[:len(array)-1]
		} else {
			break
		}

		for i := len(array) - 1; i >= 0; i-- {
			n := len(array[i])
			if n <= 0 {
				continue
			}
			res = append(res, array[i][0])
			array[i] = array[i][1:]
		}
	}

	return res

}

// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[8,9,4],[7,6,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]\n
// @lcpr case=end

*/
