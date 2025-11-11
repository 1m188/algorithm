/*
 * @lc app=leetcode.cn id=LCR 079 lang=golang
 * @lcpr version=30204
 *
 * [LCR 079] 子集
 *
 * https://leetcode.cn/problems/TVdhkn/description/
 *
 * algorithms
 * Medium (84.61%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    41.2K
 * Total Submissions: 48.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * nums 中的所有元素 互不相同
 *
 *
 *
 *
 * 注意：本题与主站 78 题相同： https://leetcode-cn.com/problems/subsets/
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

// @lcpr case=start
// [0]\n
// @lcpr case=end

*/
