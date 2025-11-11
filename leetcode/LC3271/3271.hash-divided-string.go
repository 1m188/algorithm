/*
 * @lc app=leetcode.cn id=3271 lang=golang
 * @lcpr version=30204
 *
 * [3271] 哈希分割字符串
 *
 * https://leetcode.cn/problems/hash-divided-string/description/
 *
 * algorithms
 * Medium (86.88%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 3.5K
 * Testcase Example:  '"abcd"\n2'
 *
 * 给你一个长度为 n 的字符串 s 和一个整数 k ，n 是 k 的 倍数 。你的任务是将字符串 s 哈希为一个长度为 n / k 的新字符串
 * result 。
 *
 * 首先，将 s 分割成 n / k 个 子字符串 ，每个子字符串的长度都为 k 。然后，将 result 初始化为一个 空 字符串。
 *
 * 我们依次从前往后处理每一个 子字符串 ：
 *
 *
 * 一个字符的 哈希值 是它在 字母表 中的下标（也就是 'a' → 0 ，'b' → 1 ，... ，'z' → 25）。
 * 将子字符串中字母的 哈希值 求和。
 * 将和对 26 取余，将结果记为 hashedChar 。
 * 找到小写字母表中 hashedChar 对应的字符。
 * 将该字符添加到 result 的末尾。
 *
 *
 * 返回 result 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abcd", k = 2
 *
 * 输出："bf"
 *
 * 解释：
 *
 * 第一个字符串为 "ab" ，0 + 1 = 1 ，1 % 26 = 1 ，result[0] = 'b' 。
 *
 * 第二个字符串为： "cd" ，2 + 3 = 5 ，5 % 26 = 5 ，result[1] = 'f' 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "mxz", k = 3
 *
 * 输出："i"
 *
 * 解释：
 *
 * 唯一的子字符串为 "mxz" ，12 + 23 + 25 = 60 ，60 % 26 = 8 ，result[0] = 'i' 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= 100
 * k <= s.length <= 1000
 * s.length 能被 k 整除。
 * s 只含有小写英文字母。
 *
 *
 */
package leetcode

// @lcpr-template-start
import (
	"fmt"
	"strings"
)

// @lcpr-template-end
// @lc code=start
func stringHash(s string, k int) string {
	strs := []string{}

	for i := 0; i < len(s); i += k {
		strs = append(strs, s[i:i+k])
	}

	result := []string{}
	for _, str := range strs {
		sum := 0
		for _, c := range str {
			sum += int(c - 'a')
		}
		hashedChar := rune(sum%26 + 'a')
		result = append(result, fmt.Sprintf("%c", hashedChar))
	}
	return strings.Join(result, "")
}

// @lc code=end

/*
// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

// @lcpr case=start
// "mxz"\n3\n
// @lcpr case=end

*/
