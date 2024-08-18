/*
 * @lc app=leetcode.cn id=2574 lang=typescript
 *
 * [2574] 左右元素和的差值
 *
 * https://leetcode.cn/problems/left-and-right-sum-differences/description/
 *
 * algorithms
 * Easy (85.17%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 12.2K
 * Testcase Example:  '[10,4,8,3]'
 *
 * 给你一个下标从 0 开始的整数数组 nums ，请你找出一个下标从 0 开始的整数数组 answer ，其中：
 * 
 * 
 * answer.length == nums.length
 * answer[i] = |leftSum[i] - rightSum[i]|
 * 
 * 
 * 其中：
 * 
 * 
 * leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。
 * rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。
 * 
 * 
 * 返回数组 answer 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [10,4,8,3]
 * 输出：[15,1,11,22]
 * 解释：数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
 * 数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1]
 * 输出：[0]
 * 解释：数组 leftSum 为 [0] 且数组 rightSum 为 [0] 。
 * 数组 answer 为 [|0 - 0|] = [0] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
function leftRigthDifference(nums: number[]): number[] {

    let res: number[] = new Array(nums.length);

    let leftSum = 0, rightSum = 0;
    nums.forEach(v => rightSum += v); // 先获取整个数组之和，遍历一遍
    for (let i = 0; i < res.length; i++) { // 之后通过保存的左右和对当前元素进行加减，再遍历一遍
        rightSum -= nums[i];
        res[i] = Math.abs(leftSum - rightSum);
        leftSum += nums[i];
    }

    // 总共遍历两边数组，一共是O(N)的复杂度

    return res;

};
// @lc code=end

