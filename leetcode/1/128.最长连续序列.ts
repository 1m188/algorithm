/*
 * @lc app=leetcode.cn id=128 lang=typescript
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (55.06%)
 * Likes:    1332
 * Dislikes: 0
 * Total Accepted:    294.1K
 * Total Submissions: 534.1K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

/**
 * 取了巧，题目要求O(n)的事件复杂度，这里用了排序，
 * 至少是O(nlog2n)
 */

// @lc code=start
function longestConsecutive(nums: number[]): number {

    if (nums.length == 0) return 0;

    nums.sort((a, b) => a - b); // 注意js的排序很不一样
    // console.log(nums);

    let res = 0;
    let now = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] == nums[i - 1] + 1) now++;
        else {
            res = Math.max(res, now);
            now = 1;
        }
    }
    res = Math.max(res, now);

    return res;

};
// @lc code=end

