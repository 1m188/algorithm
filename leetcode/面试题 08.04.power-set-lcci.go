/*
 * @lc app=leetcode.cn id=面试题 08.04 lang=golang
 * @lcpr version=30204
 *
 * [面试题 08.04] 幂集
 *
 * https://leetcode.cn/problems/power-set-lcci/description/
 *
 * LCCI
 * Medium (82.06%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    35.2K
 * Total Submissions: 42.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。
 *
 * 说明：解集不能包含重复的子集。
 *
 * 示例:
 *
 * ⁠输入： nums = [1,2,3]
 * ⁠输出：
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 *
 */
package leetcode

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func subsets(nums []int) [][]int {

	res := [][]int{{}}
	tmp := []int{}

	var dfs func(int)
	dfs = func(index int) {
		for i := index; i < len(nums); i++ {
			tmp = append(tmp, nums[i])

			res = append(res, make([]int, len(tmp)))
			copy(res[len(res)-1], tmp)

			dfs(i + 1)

			tmp = tmp[:len(tmp)-1]
		}
	}
	dfs(0)

	return res

}

// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

*/
