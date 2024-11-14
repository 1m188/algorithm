/*
 * @lc app=leetcode.cn id=LCR 178 lang=golang
 * @lcpr version=30204
 *
 * [LCR 178] 训练计划 VI
 *
 * https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/description/
 *
 * algorithms
 * Medium (80.58%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    180.3K
 * Total Submissions: 223.7K
 * Testcase Example:  '[5,7,5,5]'
 *
 * 教学过程中，教练示范一次，学员跟做三次。该过程被混乱剪辑后，记录于数组 actions，其中 actions[i]
 * 表示做出该动作的人员编号。请返回教练的编号。
 *
 *
 *
 * 示例 1：
 *
 * 输入：actions = [5, 7, 5, 5]
 * 输出：7
 *
 *
 * 示例 2：
 *
 * 输入：actions = [12, 1, 6, 12, 6, 12, 6]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= actions.length <= 10000
 * 1 <= actions[i] < 2^31
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func trainingPlan(actions []int) int {

	mmap := map[int]int{}
	for _, v := range actions {
		mmap[v]++
	}

	for k, v := range mmap {
		if v == 1 {
			return k
		}
	}
	return 0

}

// @lc code=end

/*
// @lcpr case=start
// [5, 7, 5, 5]\n
// @lcpr case=end

// @lcpr case=start
// [12, 1, 6, 12, 6, 12, 6]\n
// @lcpr case=end

*/
