/*
 * @lc app=leetcode.cn id=3668 lang=golang
 * @lcpr version=30204
 *
 * [3668] 重排完成顺序
 *
 * https://leetcode.cn/problems/restore-finishing-order/description/
 *
 * algorithms
 * Easy (87.81%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 4K
 * Testcase Example:  '[3,1,2,5,4]\n[1,3,4]'
 *
 * 给你一个长度为 n 的整数数组 order 和一个整数数组 friends。
 *
 *
 * order 包含从 1 到 n 的每个整数，且 恰好出现一次 ，表示比赛中参赛者按照 完成顺序 的 ID。
 * friends 包含你朋友们的 ID，按照 严格递增 的顺序排列。friends 中的每个 ID 都保证出现在 order 数组中。
 *
 *
 * 请返回一个数组，包含你朋友们的 ID，按照他们的 完成顺序 排列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：order = [3,1,2,5,4], friends = [1,3,4]
 *
 * 输出：[3,1,4]
 *
 * 解释：
 *
 * 完成顺序是 [3, 1, 2, 5, 4]。因此，你朋友的完成顺序是 [3, 1, 4]。
 *
 *
 * 示例 2：
 *
 *
 * 输入：order = [1,4,5,3,2], friends = [2,5]
 *
 * 输出：[5,2]
 *
 * 解释：
 *
 * 完成顺序是 [1, 4, 5, 3, 2]。因此，你朋友的完成顺序是 [5, 2]。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n == order.length <= 100
 * order 包含从 1 到 n 的每个整数，且恰好出现一次
 * 1 <= friends.length <= min(8, n)
 * 1 <= friends[i] <= n
 * friends 是严格递增的
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func recoverOrder(order []int, friends []int) []int {

	friendsMap := make(map[int]struct{})
	for _, v := range friends {
		friendsMap[v] = struct{}{}
	}

	res := make([]int, 0, len(friends))
	for _, v := range order {
		if _, ok := friendsMap[v]; ok {
			res = append(res, v)
		}
	}

	return res

}

// @lc code=end

/*
// @lcpr case=start
// [3,1,2,5,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,5,3,2]\n[2,5]\n
// @lcpr case=end

*/
