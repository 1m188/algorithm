/*
 * @lc app=leetcode.cn id=3783 lang=rust
 * @lcpr version=30204
 *
 * [3783] 整数的镜像距离
 *
 * https://leetcode.cn/problems/mirror-distance-of-an-integer/description/
 *
 * algorithms
 * Easy (83.18%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 3.5K
 * Testcase Example:  '25'
 *
 * 给你一个整数 n。
 *
 * 定义它的 镜像距离 为：abs(n - reverse(n))​​​​​​​，其中 reverse(n) 表示将 n 的数字反转后形成的整数。
 *
 * 返回表示 n 的镜像距离的整数。
 *
 * 其中，abs(x) 表示 x 的绝对值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： n = 25
 *
 * 输出： 27
 *
 * 解释：
 *
 *
 * reverse(25) = 52。
 * 因此，答案为 abs(25 - 52) = 27。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入： n = 10
 *
 * 输出： 9
 *
 * 解释：
 *
 *
 * reverse(10) = 01，即 1。
 * 因此，答案为 abs(10 - 1) = 9。
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入： n = 7
 *
 * 输出： 0
 *
 * 解释：
 *
 *
 * reverse(7) = 7。
 * 因此，答案为 abs(7 - 7) = 0。
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^9
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
    pub fn mirror_distance(n: i32) -> i32 {
        let mut nn = n;
        let mut rn = 0;
        while nn > 0 {
            rn = rn * 10 + nn % 10;
            nn /= 10;
        }
        (n - rn).abs()
    }
}
// @lc code=end

/*
// @lcpr case=start
// 25\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

 */
