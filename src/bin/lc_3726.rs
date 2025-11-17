/*
 * @lc app=leetcode.cn id=3726 lang=rust
 * @lcpr version=30204
 *
 * [3726] 移除十进制表示中的所有零
 *
 * https://leetcode.cn/problems/remove-zeros-in-decimal-representation/description/
 *
 * algorithms
 * Easy (75.69%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 4.3K
 * Testcase Example:  '1020030'
 *
 * 给你一个正整数n。
 *
 * 返回一个整数，该整数是将 n 的十进制表示中所有的零都移除后得到的结果。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： n = 1020030
 *
 * 输出： 123
 *
 * 解释：
 *
 * 从 1020030 中移除所有的零后，得到 123。
 *
 *
 * 示例 2：
 *
 *
 * 输入： n = 1
 *
 * 输出： 1
 *
 * 解释：
 *
 * 1 的十进制表示中没有零，因此结果为 1。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^15
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
    pub fn remove_zeros(n: i64) -> i64 {
        let mut res: i64 = 0;
        let mut n = n;
        let mut b: i64 = 1;
        while n > 0 {
            let x = n % 10;
            n /= 10;
            if x != 0 {
                res = b * x + res;
                b *= 10;
            }
        }
        res
    }
}
// @lc code=end

/*
// @lcpr case=start
// 1020030\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
