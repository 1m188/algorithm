/*
 * @lc app=leetcode.cn id=2342 lang=typescript
 *
 * [2342] 数位和相等数对的最大和
 *
 * https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
 *
 * algorithms
 * Medium (52.52%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 17.5K
 * Testcase Example:  '[18,43,36,13,7]'
 *
 * 给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与
 * nums[j] 的数位和相等。
 * 
 * 请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [18,43,36,13,7]
 * 输出：54
 * 解释：满足条件的数对 (i, j) 为：
 * - (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
 * - (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
 * 所以可以获得的最大和是 54 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [10,12,19,14]
 * 输出：-1
 * 解释：不存在满足条件的数对，返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
function maximumSum(nums: number[]): number {

    if (nums.length < 2) return -1;

    function calc(n: number): number {
        let res = 0;
        while (n) {
            res += n % 10;
            n = Math.floor(n / 10);
        }
        return res;
    }

    let map: Map<number, number[]> = new Map();
    for (let i = 0; i < nums.length; i++) {
        let x = calc(nums[i]);
        let v = map.get(x);
        if (v === undefined) map.set(x, [i]);
        else v.push(i);
    }

    // 极高的复杂度
    let res = -1;
    for (let [_, v] of map) {
        for (let i = 0; i < v.length; i++) {
            for (let j = i + 1; j < v.length; j++) {
                res = Math.max(res, nums[v[i]] + nums[v[j]]);
            }
        }
    }
    return res;

};
// @lc code=end

