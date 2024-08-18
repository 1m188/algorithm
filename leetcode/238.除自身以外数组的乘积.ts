/*
 * @lc app=leetcode.cn id=238 lang=typescript
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode.cn/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (73.97%)
 * Likes:    1212
 * Dislikes: 0
 * Total Accepted:    208.5K
 * Total Submissions: 281.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 * 
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
 * 
 * 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [-1,1,0,-3,3]
 * 输出: [0,0,9,0,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
 * 
 * 
 * 
 * 
 * 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 * 
 */

// @lc code=start
function productExceptSelf(nums: number[]): number[] {

    let res: number[] = [];
    for (let i = 0; i < nums.length; i++) res.push(0);

    // O(n)空间复杂度

    // let lvec: number[] = [], rvec: number[] = [];
    // for (let i = 0; i < nums.length; i++)
    //     lvec.push(0), rvec.push(0);

    // lvec[0] = 1, rvec[rvec.length - 1] = 1;
    // for (let i = 1, t = nums[0]; i < nums.length; i++) {
    //     lvec[i] = t;
    //     t *= nums[i];
    // }
    // for (let i = nums.length - 2, t = nums[nums.length - 1]; i >= 0; i--) {
    //     rvec[i] = t;
    //     t *= nums[i];
    // }

    // for (let i = 0; i < nums.length; i++)
    //     res[i] = lvec[i] * rvec[i];

    // O(1)空间复杂度
    // O(1)其实就是来回乘两遍，这里是利用上了输出数组，
    // 严格意义上不能算O(1)的，但是比上面那种算法节省了
    // 不少是真的

    for (let i = 0, t = 1; i < nums.length; i++) {
        res[i] = t;
        t *= nums[i];
    }
    for (let i = nums.length - 1, t = 1; i >= 0; i--) {
        res[i] *= t;
        t *= nums[i];
    }

    return res;

};
// @lc code=end

