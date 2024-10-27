/*
 * @lc app=leetcode.cn id=面试题 01.03 lang=golang
 * @lcpr version=30204
 *
 * [面试题 01.03] URL化
 *
 * https://leetcode.cn/problems/string-to-url-lcci/description/
 *
 * LCCI
 * Easy (57.65%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    87.3K
 * Total Submissions: 151.4K
 * Testcase Example:  '"Mr John Smith    "\n13'
 *
 *
 * URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）
 *
 *
 *
 * 示例 1：
 *
 * 输入："Mr John Smith    ", 13
 * 输出："Mr%20John%20Smith"
 *
 *
 * 示例 2：
 *
 * 输入："               ", 5
 * 输出："%20%20%20%20%20"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 字符串长度在 [0, 500000] 范围内。
 *
 *
 */
package main

import "strings"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func replaceSpaces(S string, length int) string {

	res := strings.Builder{}
	for i, c := range S {
		if i == length {
			break
		}
		if c == ' ' {
			res.WriteString("%20")
		} else {
			res.WriteRune(c)
		}
	}
	return res.String()

	// arr := strings.Split(S, "")[:length]
	// for i, v := range arr {
	// 	if v == " " {
	// 		arr[i] = "%20"
	// 	}
	// }
	// return strings.Join(arr, "")

}

// @lc code=end

/*
// @lcpr case=start
// "Mr John Smith    ", 13\n
// @lcpr case=end

// @lcpr case=start
// "               ", 5\n
// @lcpr case=end

*/
