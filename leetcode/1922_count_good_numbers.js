/*
 * @lc app=leetcode.cn id=1922 lang=javascript
 * @lcpr version=30204
 *
 * [1922] 统计好数字的数目
 *
 * https://leetcode.cn/problems/count-good-numbers/description/
 *
 * algorithms
 * Medium (49.41%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    22.3K
 * Total Submissions: 45.2K
 * Testcase Example:  '1'
 *
 * 我们称一个数字字符串是 好数字 当它满足（下标从 0 开始）偶数 下标处的数字为 偶数 且 奇数 下标处的数字为 质数 （2，3，5 或
 * 7）。
 * 
 * 
 * 比方说，"2582" 是好数字，因为偶数下标处的数字（2 和 8）是偶数且奇数下标处的数字（5 和 2）为质数。但 "3245" 不是 好数字，因为 3
 * 在偶数下标处但不是偶数。
 * 
 * 
 * 给你一个整数 n ，请你返回长度为 n 且为好数字的数字字符串 总数 。由于答案可能会很大，请你将它对 10^9 + 7 取余后返回 。
 * 
 * 一个 数字字符串 是每一位都由 0 到 9 组成的字符串，且可能包含前导 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 1
 * 输出：5
 * 解释：长度为 1 的好数字包括 "0"，"2"，"4"，"6"，"8" 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 4
 * 输出：400
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 50
 * 输出：564908303
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^15
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
var countGoodNumbers = function (n) {

    const bigN = BigInt(n);
    const oushu = 5n;
    const zhishu = 4n;
    const p = 1000000007n;

    /**
     * 快速幂
     * @param {bigint} x 底数
     * @param {bigint} n 指数
     * @returns {bigint} x^n
     */
    function quickPow(x, n) {
        let res = 1n;
        let y = x % p;
        while (n > 0n) {
            if (n & 1n) { res = (res * y) % p; }
            y = (y * y) % p;
            n >>= 1n;
        }
        return res;
    }

    const cnt_oushu = (bigN + 1n) / 2n;
    const cnt_zhishu = bigN - cnt_oushu;
    console.log(cnt_oushu.toString(), cnt_zhishu.toString());
    return Number(quickPow(oushu, cnt_oushu) * quickPow(zhishu, cnt_zhishu) % p);

};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 50\n
// @lcpr case=end

 */

