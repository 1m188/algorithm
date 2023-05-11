/*
 * @lc app=leetcode.cn id=2605 lang=typescript
 *
 * [2605] 从两个数字数组里生成最小数字
 *
 * https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/description/
 *
 * algorithms
 * Easy (64.39%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 7.5K
 * Testcase Example:  '[4,1,3]\n[5,7]'
 *
 * 给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2 ，每个数组中的元素 互不相同 ，请你返回 最小 的数字，两个数组都 至少
 * 包含这个数字的某个数位。
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [4,1,3], nums2 = [5,7]
 * 输出：15
 * 解释：数字 15 的数位 1 在 nums1 中出现，数位 5 在 nums2 中出现。15 是我们能得到的最小数字。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [3,5,2,6], nums2 = [3,1,7]
 * 输出：3
 * 解释：数字 3 的数位 3 在两个数组中都出现了。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 9
 * 1 <= nums1[i], nums2[i] <= 9
 * 每个数组中，元素 互不相同 。
 * 
 * 
 */

// @lc code=start
function minNumber(nums1: number[], nums2: number[]): number {

    nums1.sort();
    nums2.sort();

    let i1 = 0, i2 = 0;
    while (i1 < nums1.length && i2 < nums2.length) {
        if (nums1[i1] == nums2[i2]) return nums1[i1];
        if (nums1[i1] > nums2[i2]) i2++;
        else i1++;
    }

    let a = Math.min(nums1[0], nums2[0]), b = Math.max(nums1[0], nums2[0]);
    return a * 10 + b;

};
// @lc code=end

