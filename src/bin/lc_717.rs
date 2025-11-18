/*
 * @lc app=leetcode.cn id=717 lang=rust
 * @lcpr version=30204
 *
 * [717] 1 比特与 2 比特字符
 *
 * https://leetcode.cn/problems/1-bit-and-2-bit-characters/description/
 *
 * algorithms
 * Easy (55.52%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    78.8K
 * Total Submissions: 141.4K
 * Testcase Example:  '[1,0,0]'
 *
 * 有两种特殊字符：
 *
 *
 * 第一种字符可以用一比特 0 表示
 * 第二种字符可以用两比特（10 或 11）表示
 *
 *
 * 给你一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一个一比特字符，则返回 true 。
 *
 *
 *
 * 示例 1:
 *
 * 输入: bits = [1, 0, 0]
 * 输出: true
 * 解释: 唯一的解码方式是将其解析为一个两比特字符和一个一比特字符。
 * 所以最后一个字符是一比特字符。
 *
 *
 * 示例 2:
 *
 * 输入：bits = [1,1,1,0]
 * 输出：false
 * 解释：唯一的解码方式是将其解析为两比特字符和两比特字符。
 * 所以最后一个字符不是一比特字符。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= bits.length <= 1000
 * bits[i] 为 0 或 1
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
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let mut index: usize = 0;
        while index < bits.len() {
            if index == bits.len() - 1 {
                return true;
            }
            if bits[index] == 1 {
                index += 2;
            } else {
                index += 1;
            }
        }
        false
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1, 0, 0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,0]\n
// @lcpr case=end

 */
