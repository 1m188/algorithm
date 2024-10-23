/*
 * @lc app=leetcode.cn id=LCR 018 lang=javascript
 * @lcpr version=30204
 *
 * [LCR 018] 验证回文串
 *
 * https://leetcode.cn/problems/XltzEq/description/
 *
 * algorithms
 * Easy (51.44%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    54.6K
 * Total Submissions: 106K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 本题中，将空字符串定义为有效的 回文串 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: s = "A man, a plan, a canal: Panama"
 * 输出: true
 * 解释："amanaplanacanalpanama" 是回文串
 * 
 * 示例 2:
 * 
 * 输入: s = "race a car"
 * 输出: false
 * 解释："raceacar" 不是回文串
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 2 * 10^5
 * 字符串 s 由 ASCII 字符组成
 * 
 * 
 * 
 * 
 * 注意：本题与主站 125 题相同： https://leetcode-cn.com/problems/valid-palindrome/
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {

    let str = ''
    for (let c of s) {
        c = c.toLowerCase()
        let cn = c.charCodeAt(0)
        if ((cn >= 'a'.charCodeAt(0) && cn <= 'z'.charCodeAt(0)) ||
            (cn >= '0'.charCodeAt(0) && cn <= '9'.charCodeAt(0))) {
            str += c
        }
    }

    return str.split('').reverse().join('') === str

};
// @lc code=end



/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

 */

