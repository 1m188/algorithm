/*
 * @lc app=leetcode.cn id=LCR 110 lang=golang
 * @lcpr version=30204
 *
 * [LCR 110] 所有可能的路径
 *
 * https://leetcode.cn/problems/bP4bmD/description/
 *
 * algorithms
 * Medium (80.89%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    23.9K
 * Total Submissions: 29.6K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * 给定一个有 n 个节点的有向无环图，用二维数组 graph 表示，请找到所有从 0 到 n-1 的路径并输出（不要求按顺序）。
 *
 * graph 的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a
 * ），若为空，就是没有下一个节点了。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：graph = [[1,2],[3],[3],[]]
 * 输出：[[0,1,3],[0,2,3]]
 * 解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
 * 输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 *
 *
 * 示例 3：
 *
 * 输入：graph = [[1],[]]
 * 输出：[[0,1]]
 *
 *
 * 示例 4：
 *
 * 输入：graph = [[1,2,3],[2],[3],[]]
 * 输出：[[0,1,2,3],[0,2,3],[0,3]]
 *
 *
 * 示例 5：
 *
 * 输入：graph = [[1,3],[2],[3],[]]
 * 输出：[[0,1,2,3],[0,3]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == graph.length
 * 2 <= n <= 15
 * 0 <= graph[i][j] < n
 * graph[i][j] != i
 * 保证输入为有向无环图 (GAD)
 *
 *
 *
 *
 * 注意：本题与主站 797
 * 题相同：https://leetcode-cn.com/problems/all-paths-from-source-to-target/
 *
 */
package leetcode

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func allPathsSourceTarget(graph [][]int) [][]int {

	n := len(graph)
	flags := make([]bool, n)
	res := [][]int{}
	path := []int{}

	var dfs func(int)
	dfs = func(node int) {
		if node == n-1 {
			res = append(res, make([]int, len(path)))
			copy(res[len(res)-1], path)
			return
		}

		for _, value := range graph[node] {
			if flags[value] {
				continue
			}

			path = append(path, value)
			flags[value] = true
			dfs(value)
			flags[value] = false
			path = path[:len(path)-1]
		}
	}
	path = append(path, 0)
	flags[0] = true
	dfs(0)
	flags[0] = false
	path = path[:len(path)-1]

	return res

}

// @lc code=end

/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[2],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[2],[3],[]]\n
// @lcpr case=end

*/
