/*
 * @lc app=leetcode.cn id=2343 lang=golang
 * @lcpr version=30204
 *
 * [2343] 裁剪数字后查询第 K 小的数字
 *
 * https://leetcode.cn/problems/query-kth-smallest-trimmed-number/description/
 *
 * algorithms
 * Medium (43.49%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 27.1K
 * Testcase Example:  '["102","473","251","814"]\n[[1,1],[2,3],[4,2],[1,2]]'
 *
 * 给你一个下标从 0 开始的字符串数组 nums ，其中每个字符串 长度相等 且只包含数字。
 *
 * 再给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [ki, trimi] 。对于每个 queries[i]
 * ，你需要：
 *
 *
 * 将 nums 中每个数字 裁剪 到剩下 最右边 trimi 个数位。
 * 在裁剪过后的数字中，找到 nums 中第 ki 小数字对应的 下标 。如果两个裁剪后数字一样大，那么下标 更小 的数字视为更小的数字。
 * 将 nums 中每个数字恢复到原本字符串。
 *
 *
 * 请你返回一个长度与 queries 相等的数组 answer，其中 answer[i]是第 i 次查询的结果。
 *
 * 提示：
 *
 *
 * 裁剪到剩下最右边 x 个数位的意思是不断删除最左边的数位，直到剩下 x 个数位。
 * nums 中的字符串可能会有前导 0 。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = ["102","473","251","814"], queries = [[1,1],[2,3],[4,2],[1,2]]
 * 输出：[2,2,1,0]
 * 解释：
 * 1. 裁剪到只剩 1 个数位后，nums = ["2","3","1","4"] 。最小的数字是 1 ，下标为 2 。
 * 2. 裁剪到剩 3 个数位后，nums 没有变化。第 2 小的数字是 251 ，下标为 2 。
 * 3. 裁剪到剩 2 个数位后，nums = ["02","73","51","14"] 。第 4 小的数字是 73 ，下标为 1 。
 * 4. 裁剪到剩 2 个数位后，最小数字是 2 ，下标为 0 。
 * ⁠  注意，裁剪后数字 "02" 值为 2 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = ["24","37","96","04"], queries = [[2,1],[2,2]]
 * 输出：[3,0]
 * 解释：
 * 1. 裁剪到剩 1 个数位，nums = ["4","7","6","4"] 。第 2 小的数字是 4 ，下标为 3 。
 * ⁠  有两个 4 ，下标为 0 的 4 视为小于下标为 3 的 4 。
 * 2. 裁剪到剩 2 个数位，nums 不变。第二小的数字是 24 ，下标为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i].length <= 100
 * nums[i] 只包含数字。
 * 所有 nums[i].length 的长度 相同 。
 * 1 <= queries.length <= 100
 * queries[i].length == 2
 * 1 <= ki <= nums.length
 * 1 <= trimi <= nums[0].length
 *
 *
 *
 *
 * 进阶：你能使用 基数排序算法 解决此问题吗？这种解法的复杂度又是多少？
 *
 */

// @lcpr-template-start
package main

import "slices"

// @lcpr-template-end
// @lc code=start
func smallestTrimmedNumbers(nums []string, queries [][]int) []int {

	// 添加索引

	type query struct {
		K           int
		Trim        int
		Index       int // 该查询在原查询序列中所处的索引
		TargetIndex int // 该查询的答案在最终答案中的索引
	}
	queries2 := make([]query, 0, len(queries))
	for i, q := range queries {
		queries2 = append(queries2, query{K: q[0], Trim: q[1], Index: i, TargetIndex: -1})
	}
	slices.SortFunc(queries2, func(a, b query) int {
		return a.Trim - b.Trim
	})

	// 构建索引和数字字符串的混合体

	type nump struct {
		N     string
		Index int
	}

	numps := make([]nump, 0, len(nums))
	for i, n := range nums {
		numps = append(numps, nump{N: n, Index: i})
	}

	// 基数排序
	index := 0 // 当前 query 索引（是哪个 query 正在被考量）
	for i := len(nums[0]) - 1; i >= 0; i-- {
		bottles := make([][]nump, 10)
		for j := range bottles {
			bottles[j] = make([]nump, 0)
		}
		for _, n := range numps {
			bottles[n.N[i]-'0'] = append(bottles[n.N[i]-'0'], n)
		}
		numps = make([]nump, 0)
		for j := range bottles {
			numps = append(numps, bottles[j]...)
		}

		for index < len(queries2) && queries2[index].Trim == len(nums[0])-i {
			queries2[index].TargetIndex = numps[queries2[index].K-1].Index
			index++
		}
	}

	// 按照查询索引顺序返回答案
	slices.SortFunc(queries2, func(a, b query) int {
		return a.Index - b.Index
	})
	res := make([]int, 0)
	for _, q := range queries2 {
		res = append(res, q.TargetIndex)
	}
	return res

}

// @lc code=end

/*
// @lcpr case=start
// ["102","473","251","814"]\n[[1,1],[2,3],[4,2],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// ["24","37","96","04"]\n[[2,1],[2,2]]\n
// @lcpr case=end

*/
