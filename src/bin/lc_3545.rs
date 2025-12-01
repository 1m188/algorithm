/*
 * @lc app=leetcode.cn id=3545 lang=rust
 * @lcpr version=30204
 *
 * [3545] 不同字符数量最多为 K 时的最少删除数
 *
 * https://leetcode.cn/problems/minimum-deletions-for-at-most-k-distinct-characters/description/
 *
 * algorithms
 * Easy (75.98%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 8.3K
 * Testcase Example:  '"abc"\n2'
 *
 * 给你一个字符串 s（由小写英文字母组成）和一个整数 k。
 *
 * 你的任务是删除字符串中的一些字符（可以不删除任何字符），使得结果字符串中的 不同字符数量 最多为 k。
 *
 * 返回为达到上述目标所需删除的 最小 字符数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： s = "abc", k = 2
 *
 * 输出： 1
 *
 * 解释：
 *
 *
 * s 有三个不同的字符：'a'、'b' 和 'c'，每个字符的出现频率为 1。
 * 由于最多只能有 k = 2 个不同字符，需要删除某一个字符的所有出现。
 * 例如，删除所有 'c' 后，结果字符串中的不同字符数最多为 k。因此，答案是 1。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入： s = "aabb", k = 2
 *
 * 输出： 0
 *
 * 解释：
 *
 *
 * s 有两个不同的字符（'a' 和 'b'），它们的出现频率分别为 2 和 2。
 * 由于最多可以有 k = 2 个不同字符，不需要删除任何字符。因此，答案是 0。
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入： s = "yyyzz", k = 1
 *
 * 输出： 2
 *
 * 解释：
 *
 *
 * s 有两个不同的字符（'y' 和 'z'），它们的出现频率分别为 3 和 2。
 * 由于最多只能有 k = 1 个不同字符，需要删除某一个字符的所有出现。
 * 删除所有 'z' 后，结果字符串中的不同字符数最多为 k。因此，答案是 2。
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 16
 * 1 <= k <= 16
 * s 仅由小写英文字母组成。
 *
 *
 *
 *
 */

// @lcpr-template-start
#![no_main]
#![allow(dead_code)]
struct Solution {}
// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_deletion(s: String, k: i32) -> i32 {
        let mut arr = [0; 26];
        for c in s.chars() {
            arr[(c as u8 - b'a') as usize] += 1;
        }

        arr.sort();

        let mut ans = 0;

        for i in 0..26 - k as usize {
            ans += arr[i];
        }

        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// "abc"\n2\n
// @lcpr case=end

// @lcpr case=start
// "aabb"\n2\n
// @lcpr case=end

// @lcpr case=start
// "yyyzz"\n1\n
// @lcpr case=end

 */
