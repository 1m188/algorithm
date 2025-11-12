/*
 * @lc app=leetcode.cn id=3663 lang=rust
 * @lcpr version=30204
 *
 * [3663] 出现频率最低的数字
 *
 * https://leetcode.cn/problems/find-the-least-frequent-digit/description/
 *
 * algorithms
 * Easy (71.54%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 3K
 * Testcase Example:  '1553322'
 *
 * 给你一个整数 n，找出在其十进制表示中出现频率 最低 的数字。如果多个数字的出现频率相同，则选择 最小 的那个数字。
 *
 * 以整数形式返回所选的数字。
 *
 * 数字 x 的出现频率是指它在 n 的十进制表示中的出现次数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入： n = 1553322
 *
 * 输出： 1
 *
 * 解释：
 *
 * 在 n 中，出现频率最低的数字是 1，它只出现了一次。所有其他数字都出现了两次。
 *
 *
 * 示例 2:
 *
 *
 * 输入： n = 723344511
 *
 * 输出： 2
 *
 * 解释：
 *
 * 在 n 中，出现频率最低的数字是 7、2 和 5，它们都只出现了一次。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= n <= 2^31 - 1
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
    pub fn get_least_frequent_digit(n: i32) -> i32 {
        let mut nn = n;
        let mut cnt = vec![0; 10];
        while nn > 0 {
            cnt[(nn % 10) as usize] += 1;
            nn /= 10;
        }

        let mut res: i32 = -1;
        let mut min_cnt = i32::MAX;
        for i in 0..10 {
            if cnt[i] == 0 {
                continue;
            };
            if cnt[i] < min_cnt {
                min_cnt = cnt[i];
                res = i as i32;
            }
        }

        res
    }
}
// @lc code=end

/*
// @lcpr case=start
// 1553322\n
// @lcpr case=end

// @lcpr case=start
// 723344511\n
// @lcpr case=end

 */
