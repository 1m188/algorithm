/*
 * @lc app=leetcode.cn id=LCR 034 lang=golang
 * @lcpr version=30204
 *
 * [LCR 034] 验证外星语词典
 *
 * https://leetcode.cn/problems/lwyVBB/description/
 *
 * algorithms
 * Easy (56.40%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 51.4K
 * Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
 *
 * 某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。
 *
 * 给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回
 * false。
 *
 *
 *
 * 示例 1：
 *
 * 输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * 输出：true
 * 解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
 *
 * 示例 2：
 *
 * 输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * 输出：false
 * 解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
 *
 * 示例 3：
 *
 * 输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * 输出：false
 * 解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中
 * '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * 在 words[i] 和 order 中的所有字符都是英文小写字母。
 *
 *
 *
 *
 * 注意：本题与主站 953 题相同：
 * https://leetcode-cn.com/problems/verifying-an-alien-dictionary/
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func isAlienSorted(words []string, order string) bool {

	judge := func(x1, x2 int) bool {
		m := len(words[x1])
		n := len(words[x2])
		len := min(m, n)
		for i := 0; i < len; i++ {
			c1 := words[x1][i]
			c2 := words[x2][i]
			if c1 == c2 {
				continue
			} else {
				for _, c := range order {
					if c == rune(c1) {
						return true
					}
					if c == rune(c2) {
						return false
					}
				}
			}
		}
		return m <= n
	}

	for i := 0; i < len(words)-1; i++ {
		if !judge(i, i+1) {
			return false
		}
	}
	return true

}

// @lc code=end

/*
// @lcpr case=start
// ["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"\n
// @lcpr case=end

// @lcpr case=start
// ["word","world","row"]\n"worldabcefghijkmnpqstuvxyz"\n
// @lcpr case=end

// @lcpr case=start
// ["apple","app"]\n"abcdefghijklmnopqrstuvwxyz"\n
// @lcpr case=end

*/
