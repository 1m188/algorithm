/*
 * @lc app=leetcode.cn id=3683 lang=golang
 * @lcpr version=30204
 *
 * [3683] 完成一个任务的最早时间
 *
 * https://leetcode.cn/problems/earliest-time-to-finish-one-task/description/
 *
 * algorithms
 * Easy (86.78%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 4K
 * Testcase Example:  '[[1,6],[2,3]]'
 *
 * 给你一个二维整数数组 tasks，其中 tasks[i] = [si, ti]。
 *
 * 数组中的每个 [si, ti] 表示一个任务，该任务的开始时间为 si，完成该任务需要 ti 个时间单位。
 *
 * 返回至少完成一个任务的最早时间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： tasks = [[1,6],[2,3]]
 *
 * 输出： 5
 *
 * 解释：
 *
 * 第一个任务从时间 t = 1 开始，并在 1 + 6 = 7 时完成。第二个任务在时间 t = 2 开始，并在 2 + 3 = 5
 * 时完成。因此，最早完成的任务在时间 5。
 *
 *
 * 示例 2：
 *
 *
 * 输入： tasks = [[100,100],[100,100],[100,100]]
 *
 * 输出： 200
 *
 * 解释：
 *
 * 三个任务都在时间 100 + 100 = 200 时完成。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= tasks.length <= 100
 * tasks[i] = [si, ti]
 * 1 <= si, ti <= 100
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func earliestTime(tasks [][]int) int {

	x := tasks[0][0] + tasks[0][1]
	for i := 1; i < len(tasks); i++ {
		if tasks[i][0]+tasks[i][1] < x {
			x = tasks[i][0] + tasks[i][1]
		}
	}
	return x

}

// @lc code=end

/*
// @lcpr case=start
// [[1,6],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[100,100],[100,100],[100,100]]\n
// @lcpr case=end

*/
