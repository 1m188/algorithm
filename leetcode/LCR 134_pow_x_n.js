/*
 * @lc app=leetcode.cn id=LCR 134 lang=javascript
 * @lcpr version=30204
 *
 * [LCR 134] Pow(x, n)
 *
 * https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/description/
 *
 * algorithms
 * Medium (35.27%)
 * Likes:    446
 * Dislikes: 0
 * Total Accepted:    258.8K
 * Total Submissions: 733.8K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：x = 2.00000, n = 10
 * 输出：1024.00000
 * 
 * 
 * 示例 2：
 * 
 * 输入：x = 2.10000, n = 3
 * 输出：9.26100
 * 
 * 示例 3：
 * 
 * 输入：x = 2.00000, n = -2
 * 输出：0.25000
 * 解释：2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 * 
 * 
 * 
 * 
 * 注意：本题与主站 50 题相同：https://leetcode.cn/problems/powx-n/
 * 
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (x == 0) return 0;
    if (x == Infinity) return 0;
    if (n < 0) return myPow(1 / x, -n);
    return myPow(x * x, n >> 1) * (n & 1 ? x : 1);
};
// @lc code=end



/*
// @lcpr case=start
// 2.00000\n10\n
// @lcpr case=end

// @lcpr case=start
// 2.10000\n3\n
// @lcpr case=end

// @lcpr case=start
// 2.00000\n-2\n
// @lcpr case=end

 */

