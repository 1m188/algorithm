/*
 * @lc app=leetcode.cn id=LCR 019 lang=rust
 * @lcpr version=30204
 *
 * [LCR 019] 验证回文串 II
 *
 * https://leetcode.cn/problems/RQku0D/description/
 *
 * algorithms
 * Easy (45.40%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    47.7K
 * Total Submissions: 105.1K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。
 *
 *
 *
 * 示例 1：
 *
 * 输入: s = "aba"
 * 输出: true
 *
 *
 * 示例 2：
 *
 * 输入: s = "abca"
 * 输出: true
 * 解释: 可以删除 "c" 字符 或者 "b" 字符
 *
 *
 * 示例 3：
 *
 * 输入: s = "abc"
 * 输出: false
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 *
 *
 *
 *
 * 注意：本题与主站 680 题相同： https://leetcode-cn.com/problems/valid-palindrome-ii/
 *
 */

// @lcpr-template-start
#![no_main]
#![allow(dead_code)]
struct Solution {}
// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        mod local {
            pub fn judge(vec: &Vec<char>, left: usize, right: usize, flag: bool) -> bool {
                if left >= right {
                    return true;
                }
                if vec[left] == vec[right] {
                    return judge(vec, left + 1, right - 1, flag);
                }
                if !flag {
                    let f = judge(vec, left + 1, right, true);
                    return f || judge(vec, left, right - 1, true);
                }
                false
            }
        }

        if s.len() <= 1 {
            return true;
        }

        let vec = s.chars().collect::<Vec<char>>();

        local::judge(&vec, 0, vec.len() - 1, false)
    }
}
// @lc code=end

/*
// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */
