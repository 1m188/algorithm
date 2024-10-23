/*
 * @lc app=leetcode.cn id=LCR 127 lang=javascript
 * @lcpr version=30204
 *
 * [LCR 127] 跳跃训练
 *
 * https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/description/
 *
 * algorithms
 * Easy (45.28%)
 * Likes:    421
 * Dislikes: 0
 * Total Accepted:    409.6K
 * Total Submissions: 904.8K
 * Testcase Example:  '2'
 *
 * 今天的有氧运动训练内容是在一个长条形的平台上跳跃。平台有 num 个小格子，每次可以选择跳 一个格子 或者
 * 两个格子。请返回在训练过程中，学员们共有多少种不同的跳跃方式。
 * 
 * 结果可能过大，因此结果需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 * 
 * 示例 1：
 * 
 * 输入：n = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 5
 * 输出：8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 100
 * 
 * 
 * 注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {number} num
 * @return {number}
 */
var trainWays = function (num) {

    if (num == 0 || num == 1) return 1

    const mod = 1000000007

    let a = 0, b = 1
    for (let i = 0; i < num; i++) {
        [a, b] = [b, (a + b) % mod]
    }

    return b

};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

