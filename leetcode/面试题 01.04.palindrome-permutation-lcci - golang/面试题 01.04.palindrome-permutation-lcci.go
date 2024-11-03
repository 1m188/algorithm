/*
 * @lc app=leetcode.cn id=面试题 01.04 lang=golang
 * @lcpr version=30204
 *
 * [面试题 01.04] 回文排列
 *
 * https://leetcode.cn/problems/palindrome-permutation-lcci/description/
 *
 * LCCI
 * Easy (53.18%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    78.6K
 * Total Submissions: 147.8K
 * Testcase Example:  '"code"'
 *
 * 给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
 *
 * 回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
 *
 * 回文串不一定是字典当中的单词。
 *
 *
 *
 * 示例1：
 *
 * 输入："tactcoa"
 * 输出：true（排列有"tacocat"、"atcocta"，等等）
 *
 *
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func canPermutePalindrome(s string) bool {

	cnts := map[rune]int{}

	for _, c := range s {
		n, ok := cnts[c]
		if !ok {
			cnts[c] = 1
		} else {
			cnts[c] = n + 1
		}
	}

	if len(s)%2 == 0 {
		for _, v := range cnts {
			if v%2 == 1 {
				return false
			}
		}
	} else {
		cnt := 0
		for _, v := range cnts {
			if v%2 == 1 {
				cnt++
			}
		}
		if cnt != 1 {
			return false
		}
	}

	return true

}

// @lc code=end

/*
// @lcpr case=start
// "tactcoa"\n
// @lcpr case=end

*/
