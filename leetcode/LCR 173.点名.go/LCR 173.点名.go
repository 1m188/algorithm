/*
 * @lc app=leetcode.cn id=LCR 173 lang=golang
 * @lcpr version=30204
 *
 * [LCR 173] 点名
 *
 * https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (44.81%)
 * Likes:    433
 * Dislikes: 0
 * Total Accepted:    379K
 * Total Submissions: 845.9K
 * Testcase Example:  '[0,1,2,3,5]'
 *
 * 某班级 n 位同学的学号为 0 ~ n-1。点名结果记录于升序数组 records。假定仅有一位同学缺席，请返回他的学号。
 *
 *
 *
 * 示例 1:
 *
 * 输入: records = [0,1,2,3,5]
 * 输出: 4
 *
 *
 * 示例 2:
 *
 * 输入: records = [0, 1, 2, 3, 4, 5, 6, 8]
 * 输出: 7
 *
 *
 *
 * 提示：
 *
 * 1 <= records.length <= 10000
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func takeAttendance(records []int) int {

	arr := make([]bool, len(records)+1)

	for _, val := range records {
		arr[val] = true
	}

	for idx, val := range arr {
		if !val {
			return idx
		}
	}
	return len(arr)

}

// @lc code=end

/*
// @lcpr case=start
// [0,1,2,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [0, 1, 2, 3, 4, 5, 6, 8]\n
// @lcpr case=end

*/
