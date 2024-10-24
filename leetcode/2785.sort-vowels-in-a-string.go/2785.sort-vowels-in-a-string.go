/*
 * @lc app=leetcode.cn id=2785 lang=golang
 * @lcpr version=30204
 *
 * [2785] 将字符串中的元音字母排序
 *
 * https://leetcode.cn/problems/sort-vowels-in-a-string/description/
 *
 * algorithms
 * Medium (77.35%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 6.4K
 * Testcase Example:  '"lEetcOde"'
 *
 * 给你一个下标从 0 开始的字符串 s ，将 s 中的元素重新 排列 得到新的字符串 t ，它满足：
 *
 *
 * 所有辅音字母都在原来的位置上。更正式的，如果满足 0 <= i < s.length 的下标 i 处的 s[i] 是个辅音字母，那么 t[i] =
 * s[i] 。
 * 元音字母都必须以他们的 ASCII 值按 非递减 顺序排列。更正式的，对于满足 0 <= i < j < s.length 的下标 i 和 j  ，如果
 * s[i] 和 s[j] 都是元音字母，那么 t[i] 的 ASCII 值不能大于 t[j] 的 ASCII 值。
 *
 *
 * 请你返回结果字母串。
 *
 * 元音字母为 'a' ，'e' ，'i' ，'o' 和 'u' ，它们可能是小写字母也可能是大写字母，辅音字母是除了这 5 个字母以外的所有字母。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "lEetcOde"
 * 输出："lEOtcede"
 * 解释：'E' ，'O' 和 'e' 是 s 中的元音字母，'l' ，'t' ，'c' 和 'd' 是所有的辅音。将元音字母按照 ASCII
 * 值排序，辅音字母留在原地。
 *
 *
 * 示例 2：
 *
 * 输入：s = "lYmpH"
 * 输出："lYmpH"
 * 解释：s 中没有元音字母（s 中都为辅音字母），所以我们返回 "lYmpH" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 只包含英语字母表中的 大写 和 小写 字母。
 *
 *
 */
package main

import (
	"sort"
	"strings"
)

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func sortVowels(s string) string {

	t := make([]string, len(s))
	vowels := []string{}

	for index, value := range s {
		if value == 'a' || value == 'A' ||
			value == 'e' || value == 'E' ||
			value == 'i' || value == 'I' ||
			value == 'o' || value == 'O' ||
			value == 'u' || value == 'U' {
			vowels = append(vowels, string(value))
		} else {
			t[index] = string(value)
		}
	}

	sort.Slice(vowels, func(i, j int) bool {
		return vowels[i] < vowels[j]
	})

	idx := 0
	for index, value := range t {
		if value != "" {
			continue
		}

		t[index] = vowels[idx]
		idx++
	}

	return strings.Join(t, "")

}

// @lc code=end

/*
// @lcpr case=start
// "lEetcOde"\n
// @lcpr case=end

// @lcpr case=start
// "lYmpH"\n
// @lcpr case=end

*/
