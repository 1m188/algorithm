/*
 * @lc app=leetcode.cn id=1437 lang=rust
 * @lcpr version=30204
 *
 * [1437] 是否所有 1 都至少相隔 k 个元素
 *
 * https://leetcode.cn/problems/check-if-all-1s-are-at-least-length-k-places-away/description/
 *
 * algorithms
 * Easy (56.30%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    24K
 * Total Submissions: 41.9K
 * Testcase Example:  '[1,0,0,0,1,0,0,1]\n2'
 *
 * 给你一个由若干 0 和 1 组成的数组 nums 以及整数 k。如果所有 1 都至少相隔 k 个元素，则返回 true ；否则，返回 false
 * 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：nums = [1,0,0,0,1,0,0,1], k = 2
 * 输出：true
 * 解释：每个 1 都至少相隔 2 个元素。
 *
 * 示例 2：
 *
 *
 *
 * 输入：nums = [1,0,0,1,0,1], k = 2
 * 输出：false
 * 解释：第二个 1 和第三个 1 之间只隔了 1 个元素。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= k <= nums.length
 * nums[i] 的值为 0 或 1
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
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let mut pre_index: usize = 0;
        for i in 0..nums.len() {
            if nums[i] == 1 {
                pre_index = i;
                break;
            }
        }

        for i in pre_index + 1..nums.len() {
            if nums[i] == 1 {
                if i - pre_index - 1 < k as usize {
                    return false;
                }
                pre_index = i;
            }
        }

        true
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,0,0,0,1,0,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,1,0,1]\n2\n
// @lcpr case=end

 */
