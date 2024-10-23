/*
 * @lc app=leetcode.cn id=面试题 01.06 lang=javascript
 * @lcpr version=30204
 *
 * [面试题 01.06] 字符串压缩
 *
 * https://leetcode.cn/problems/compress-string-lcci/description/
 *
 * LCCI
 * Easy (45.79%)
 * Likes:    187
 * Dislikes: 0
 * Total Accepted:    122.6K
 * Total Submissions: 267.7K
 * Testcase Example:  '"aabcccccaa"'
 *
 * 
 * 字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。
 * 
 * ⁠示例1:
 * 
 * ⁠输入："aabcccccaaa"
 * ⁠输出："a2b1c5a3"
 * 
 * 
 * ⁠示例2:
 * 
 * ⁠输入："abbccd"
 * ⁠输出："abbccd"
 * ⁠解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
 * 
 * 
 * 提示：
 * 
 * 
 * 字符串长度在[0, 50000]范围内。
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function (S) {

    let str = ''
    for (let i = 0; i < S.length;) {
        let ch = S[i]
        let cnt = 1

        let j = i + 1
        while (j < S.length) {
            if (S[j] === ch) {
                cnt++
                j++
            } else {
                break
            }
        }

        str += `${ch}${cnt}`
        i = j
    }

    return str.length < S.length ? str : S

};
// @lc code=end



/*
// @lcpr case=start
// "aabcccccaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abbccd"\n
// @lcpr case=end

 */

