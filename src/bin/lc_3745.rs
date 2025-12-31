/*
 * @lc app=leetcode.cn id=3745 lang=rust
 * @lcpr version=30204
 *
 * [3745] 三元素表达式的最大值
 *
 * https://leetcode.cn/problems/maximize-expression-of-three-elements/description/
 *
 * algorithms
 * Easy (74.97%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 4.5K
 * Testcase Example:  '[1,4,2,5]'
 *
 * 给你一个整数数组 nums。
 *
 * 从 nums 中选择三个元素 a、b 和 c，它们的下标需 互不相同 ，使表达式 a + b - c 的值最大化。
 *
 * 返回该表达式可能的 最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： nums = [1,4,2,5]
 *
 * 输出： 8
 *
 * 解释：
 *
 * 可以选择 a = 4，b = 5，c = 1。表达式的值为 4 + 5 - 1 = 8，这是可能的最大值。
 *
 *
 * 示例 2：
 *
 *
 * 输入： nums = [-2,0,5,-2,4]
 *
 * 输出： 11
 *
 * 解释：
 *
 * 可以选择 a = 5，b = 4，c = -2。表达式的值为 5 + 4 - (-2) = 11，这是可能的最大值。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 100
 * -100 <= nums[i] <= 100
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
    pub fn maximize_expression_of_three(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let a: &i32 = &nums[nums.len() - 1];
        let b: &i32 = &nums[nums.len() - 2];
        let c: &i32 = &nums[0];
        return a + b - c;
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,4,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,5,-2,4]\n
// @lcpr case=end

 */
