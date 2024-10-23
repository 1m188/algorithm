/*
 * @lc app=leetcode.cn id=LCR 080 lang=golang
 * @lcpr version=30204
 *
 * [LCR 080] 组合
 *
 * https://leetcode.cn/problems/uUsW3B/description/
 *
 * algorithms
 * Medium (81.94%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    38.4K
 * Total Submissions: 46.8K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 *
 *
 *
 * 示例 1:
 *
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2:
 *
 * 输入: n = 1, k = 1
 * 输出: [[1]]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 *
 *
 * 注意：本题与主站 77 题相同： https://leetcode-cn.com/problems/combinations/
 *
 */
package leetcode

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func combine(n int, k int) [][]int {

	res := [][]int{}
	tmp := []int{}
	flags := make([]bool, n+1)

	var dfs func(int, int)
	dfs = func(num, cnt int) {
		if cnt == k {
			res = append(res, make([]int, len(tmp)))
			copy(res[len(res)-1], tmp)
			return
		}

		for i := num; i <= n; i++ {
			if flags[i] {
				continue
			}

			flags[i] = true
			tmp = append(tmp, i)
			dfs(i+1, cnt+1)
			tmp = tmp[:len(tmp)-1]
			flags[i] = false
		}
	}
	dfs(1, 0)

	return res

}

// @lc code=end

/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

*/
