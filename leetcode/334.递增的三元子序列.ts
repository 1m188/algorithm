/*
 * @lc app=leetcode.cn id=334 lang=typescript
 *
 * [334] 递增的三元子序列
 *
 * https://leetcode.cn/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (43.26%)
 * Likes:    596
 * Dislikes: 0
 * Total Accepted:    100.7K
 * Total Submissions: 232.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
 * 
 * 如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回
 * true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4,5]
 * 输出：true
 * 解释：任何 i < j < k 的三元组都满足题意
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,4,3,2,1]
 * 输出：false
 * 解释：不存在满足题意的三元组
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [2,1,5,0,4,6]
 * 输出：true
 * 解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：你能实现时间复杂度为 O(n) ，空间复杂度为 O(1) 的解决方案吗？
 * 
 */

// @lc code=start
function increasingTriplet(nums: number[]): boolean {

    let n = nums.length;

    if (n < 3) return false;

    let rb: number[] = new Array(n),
        ls: number = nums[0];
    rb[n - 1] = nums[n - 1];

    // 这里之前用的是unshift，超时，看来这个操作很
    // 消耗时间，如果数组长度固定的话还是得先固定，
    // 之后挨个赋值
    for (let i = n - 2; i >= 0; i--)
        rb[i] = Math.max(rb[i + 1], nums[i]);

    for (let i = 1; i < n - 1; i++) {
        if (rb[i + 1] > nums[i] && ls < nums[i]) return true;
        ls = Math.min(ls, nums[i]);
    }
    return false;

};
// @lc code=end

