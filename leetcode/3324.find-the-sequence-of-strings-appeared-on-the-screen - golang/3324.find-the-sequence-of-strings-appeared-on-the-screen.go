/*
 * @lc app=leetcode.cn id=3324 lang=golang
 * @lcpr version=30204
 *
 * [3324] 出现在屏幕上的字符串序列
 *
 * https://leetcode.cn/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/
 *
 * algorithms
 * Medium (81.39%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    4.5K
 * Total Submissions: 5.5K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 target。
 *
 * Alice 将会使用一种特殊的键盘在她的电脑上输入 target，这个键盘 只有两个 按键：
 *
 *
 * 按键 1：在屏幕上的字符串后追加字符 'a'。
 * 按键 2：将屏幕上字符串的 最后一个 字符更改为英文字母表中的 下一个 字符。例如，'c' 变为 'd'，'z' 变为 'a'。
 *
 *
 * 注意，最初屏幕上是一个空字符串 ""，所以她 只能 按按键 1。
 *
 * 请你考虑按键次数 最少 的情况，按字符串出现顺序，返回 Alice 输入 target 时屏幕上出现的所有字符串列表。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： target = "abc"
 *
 * 输出： ["a","aa","ab","aba","abb","abc"]
 *
 * 解释：
 *
 * Alice 按键的顺序如下：
 *
 *
 * 按下按键 1，屏幕上的字符串变为 "a"。
 * 按下按键 1，屏幕上的字符串变为 "aa"。
 * 按下按键 2，屏幕上的字符串变为 "ab"。
 * 按下按键 1，屏幕上的字符串变为 "aba"。
 * 按下按键 2，屏幕上的字符串变为 "abb"。
 * 按下按键 2，屏幕上的字符串变为 "abc"。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入： target = "he"
 *
 * 输出： ["a","b","c","d","e","f","g","h","ha","hb","hc","hd","he"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target.length <= 400
 * target 仅由小写英文字母组成。
 *
 *
 */
package main

import "strings"

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func stringSequence(target string) []string {

	res := []string{}
	str := strings.Builder{}

	for _, c := range target {
		x := 'a'
		for x != c {
			res = append(res, str.String()+string(x))
			x++
		}
		str.WriteRune(x)
		res = append(res, str.String())
	}

	return res

}

// @lc code=end

/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "he"\n
// @lcpr case=end

*/
