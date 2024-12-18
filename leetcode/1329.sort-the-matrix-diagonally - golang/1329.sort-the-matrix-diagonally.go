/*
 * @lc app=leetcode.cn id=1329 lang=golang
 * @lcpr version=30204
 *
 * [1329] 将矩阵按对角线排序
 *
 * https://leetcode.cn/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (81.05%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 34.7K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * 矩阵对角线 是一条从矩阵最上面行或者最左侧列中的某个元素开始的对角线，沿右下方向一直到矩阵末尾的元素。例如，矩阵 mat 有 6 行 3 列，从
 * mat[2][0] 开始的 矩阵对角线 将会经过 mat[2][0]、mat[3][1] 和 mat[4][2] 。
 *
 * 给你一个 m * n 的整数矩阵 mat ，请你将同一条 矩阵对角线 上的元素按升序排序后，返回排好序的矩阵。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * 输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 *
 *
 * 示例 2：
 *
 * 输入：mat =
 * [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
 *
 * 输出：[[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 *
 *
 */
package main

import "sort"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func diagonalSort(mat [][]int) [][]int {

	m, n := len(mat), len(mat[0])

	get := func(a, b int) []int {
		res := []int{}
		for a >= 0 && a < m && b >= 0 && b < n {
			res = append(res, mat[a][b])
			a++
			b++
		}
		return res
	}

	set := func(a, b int, arr []int) {
		idx := 0
		for a >= 0 && a < m && b >= 0 && b < n {
			mat[a][b] = arr[idx]
			a++
			b++
			idx++
		}
	}

	for i := n - 1; i >= 0; i-- {
		arr := get(0, i)
		sort.Ints(arr)
		set(0, i, arr)
	}
	for i := 1; i < m; i++ {
		arr := get(i, 0)
		sort.Ints(arr)
		set(i, 0, arr)
	}

	return mat

}

// @lc code=end

/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

*/
