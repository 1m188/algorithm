/*
 * @lc app=leetcode.cn id=264 lang=javascript
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (50.65%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    31.5K
 * Total Submissions: 59.1K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start

/**
 * @param {Array} vec
 * @param {number} num
 */
function uglynum(vec, num) {
    vec.push(1);
    let p2 = 0, p3 = 0, p5 = 0;
    while (vec.length < num) {
        let r = Math.min(vec[p2] * 2, vec[p3] * 3, vec[p5] * 5);
        vec.push(r);

        // 三个判断语句独立，避免重复添加
        if (r === vec[p2] * 2) p2++;
        if (r === vec[p3] * 3) p3++;
        if (r === vec[p5] * 5) p5++;
    }
}

let uvec = new Array();
uglynum(uvec, 1690);

/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function (n) {
    return uvec[n - 1];
};
// @lc code=end

