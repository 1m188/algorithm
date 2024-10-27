/*
 * @lc app=leetcode.cn id=面试题 10.05 lang=golang
 * @lcpr version=30204
 *
 * [面试题 10.05] 稀疏数组搜索
 *
 * https://leetcode.cn/problems/sparse-array-search-lcci/description/
 *
 * LCCI
 * Easy (57.01%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 60.7K
 * Testcase Example:  '["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]\n"ta"'
 *
 * 稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。
 *
 * 示例1:
 *
 * ⁠输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "",
 * ""], s = "ta"
 * ⁠输出：-1
 * ⁠说明: 不存在返回-1。
 *
 *
 * 示例2:
 *
 * ⁠输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""],
 * s = "ball"
 * ⁠输出：4
 *
 *
 * 提示:
 *
 *
 * words的长度在[1, 1000000]之间
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func findString(words []string, s string) int {

	umap := map[string]int{}

	for idx, val := range words {
		if val == "" {
			continue
		}
		umap[val] = idx
	}

	idx, ok := umap[s]
	if ok {
		return idx
	} else {
		return -1
	}

}

// @lc code=end

/*
// @lcpr case=start
// ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""]\n"ta"\n
// @lcpr case=end

// @lcpr case=start
// ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""]\n"ball"\n
// @lcpr case=end

*/
