/*
 * @lc app=leetcode.cn id=面试题 16.01 lang=golang
 * @lcpr version=30204
 *
 * [面试题 16.01] 交换数字
 *
 * https://leetcode.cn/problems/swap-numbers-lcci/description/
 *
 * LCCI
 * Medium (80.69%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    45.8K
 * Total Submissions: 56.7K
 * Testcase Example:  '[0,2147483647]'
 *
 * 编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。
 *
 * 示例：
 *
 * 输入: numbers = [1,2]
 * 输出: [2,1]
 *
 *
 * 提示：
 *
 *
 * numbers.length == 2
 * -2147483647 <= numbers[i] <= 2147483647
 *
 *
 */
package leetcode

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func swapNumbers(numbers []int) []int {

	a := int64(numbers[0])
	b := int64(numbers[1])

	a = a + b
	b = a - b
	a = a - b

	return []int{int(a), int(b)}

}

// @lc code=end

/*
// @lcpr case=start
// [1,2]\n
// @lcpr case=end

*/
