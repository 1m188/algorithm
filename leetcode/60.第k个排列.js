/*
 * @lc app=leetcode.cn id=60 lang=javascript
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (49.09%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    44.6K
 * Total Submissions: 90.9K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */

// @lc code=start
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function (n, k) {

    /** 结果 */
    let res = "";
    /** 计数器 */
    let num = 0;
    /** 标志数组 */
    let flags = new Array(n).fill(false);


    function dfs() {
        if (res.length >= flags.length) num++;
        else {
            for (let i = 0; i < flags.length; i++)
                if (!flags[i]) {
                    flags[i] = true;
                    res += i + 1;
                    dfs();
                    if (num === k) return;
                    res = res.substr(0, res.length - 1);
                    flags[i] = false;
                }
        }
    }


    dfs();
    return res;
};
// @lc code=end

