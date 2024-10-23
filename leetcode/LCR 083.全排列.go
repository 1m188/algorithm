/*
 * @lc app=leetcode.cn id=LCR 083 lang=golang
 * @lcpr version=30204
 *
 * [LCR 083] 全排列
 *
 * https://leetcode.cn/problems/VvJkup/description/
 *
 * algorithms
 * Medium (83.63%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    44.5K
 * Total Submissions: 53.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的整数数组 nums ，返回其 所有可能的全排列 。可以 按任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 *
 *
 *
 *
 * 注意：本题与主站 46 题相同：https://leetcode-cn.com/problems/permutations/
 *
 */
package leetcode

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func permute(nums []int) [][]int {

	res := [][]int{}
	tmp := []int{}
	flags := make([]bool, len(nums))

	var dfs func()
	dfs = func() {
		f := false
		for index, value := range nums {
			if flags[index] {
				continue
			}

			f = true
			flags[index] = true
			tmp = append(tmp, value)
			dfs()
			tmp = tmp[:len(tmp)-1]
			flags[index] = false
		}
		if !f {
			res = append(res, make([]int, len(tmp)))
			copy(res[len(res)-1], tmp)
		}
	}
	dfs()

	return res

}

// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

*/
