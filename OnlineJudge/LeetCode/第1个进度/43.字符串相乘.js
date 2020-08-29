/*
 * @lc app=leetcode.cn id=43 lang=javascript
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (42.61%)
 * Likes:    463
 * Dislikes: 0
 * Total Accepted:    101.2K
 * Total Submissions: 227.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start

/**
 * 单位数和字符串数相乘
 * @param {string} sn
 * @param {string} n
 * @returns {string}
 */
function smul(sn, n) {
    let res = "", ca = 0;
    const numsn = parseInt(sn);

    for (let i = n.length - 1; i >= 0; i--) {
        let r = numsn * parseInt(n[i]) + ca;
        res = r % 10 + res;
        ca = parseInt(r / 10);
    }
    if (ca) res = ca + res;

    return res;
}

/**
 * 字符串数相加
 * @param {string} n1
 * @param {string} n2
 * @returns {string}
 */
function add(n1, n2) {
    let ni = n1.length - 1, nni = n2.length - 1, ca = 0, res = "";

    while (ni >= 0 && nni >= 0) {
        let r = parseInt(n1[ni]) + parseInt(n2[nni]) + ca;
        res = r % 10 + res;
        ca = parseInt(r / 10);
        ni--, nni--;
    }

    if (nni >= 0) ni = nni, n1 = n2;

    while (ni >= 0) {
        let r = parseInt(n1[ni]) + ca;
        res = r % 10 + res;
        ca = parseInt(r / 10);
        ni--;
    }

    if (ca) res = ca + res;

    return res;
}

/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function (num1, num2) {
    if (num1 === "0" || num2 === "0") return "0";

    let res = "";

    for (const c of num1)
        res = add(res + '0', smul(c, num2));

    return res;
};
// @lc code=end

