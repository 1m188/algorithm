/*
 * @lc app=leetcode.cn id=869 lang=javascript
 * @lcpr version=30204
 *
 * [869] 重新排序得到 2 的幂
 *
 * https://leetcode.cn/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (65.04%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    52K
 * Total Submissions: 80K
 * Testcase Example:  '1'
 *
 * 给定正整数 n ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。
 * 
 * 如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 1
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 10
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^9
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */
var reorderedPowerOf2 = function (n) {
    let arr = new Array();
    while (n > 0) {
        arr.push(n % 10);
        n = Math.floor(n / 10);
    }
    let flags = new Array(arr.length).fill(false);

    /**
     * 递归枚举
     * @param {number} n 当前数字
     * @param {number} index 当前数字的位数
     * @returns {boolean} 是否是2的幂
     */
    function calc(n = 0, index = 0) {
        if (index === arr.length) return (n & (n - 1)) === 0;
        for (let i = 0; i < arr.length; i++) {
            if (flags[i]) continue;
            if (index === 0 && arr[i] === 0) continue;
            flags[i] = true;
            if (calc(n * 10 + arr[i], index + 1)) return true;
            flags[i] = false;
        }
        return false;
    }

    return calc();
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

