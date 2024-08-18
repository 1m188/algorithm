/*
 * @lc app=leetcode.cn id=179 lang=typescript
 *
 * [179] 最大数
 *
 * https://leetcode.cn/problems/largest-number/description/
 *
 * algorithms
 * Medium (41.16%)
 * Likes:    973
 * Dislikes: 0
 * Total Accepted:    165.8K
 * Total Submissions: 402.8K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 * 
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,2]
 * 输出："210"
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,30,34,5,9]
 * 输出："9534330"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

/**
 * 贪心排序，转成字符串进行排序，如果a+b>b+a则a排在b前面，
 * 这里的+指的是字符串拼接
 */

// @lc code=start
function largestNumber(nums: number[]): string {

    let snums: string[] = [];
    for (let i of nums) snums.push(i.toString());

    snums.sort((a, b) => {
        if (a + b > b + a) return -1;
        else return 1;
    });

    let res = snums.join('');
    while (res.length > 1 && res[0] == '0')
        res = res.substring(1);
    return res;

};
// @lc code=end

