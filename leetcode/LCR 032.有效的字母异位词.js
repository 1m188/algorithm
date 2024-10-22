/*
 * @lc app=leetcode.cn id=LCR 032 lang=javascript
 * @lcpr version=30204
 *
 * [LCR 032] 有效的字母异位词
 *
 * https://leetcode.cn/problems/dKk3P7/description/
 *
 * algorithms
 * Easy (57.86%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    42.2K
 * Total Submissions: 73K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和 t 互为变位词（字母异位词）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "a", t = "a"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 * 
 * 
 * 注意：本题与主站 242 题相似（字母异位词定义不同）：https://leetcode-cn.com/problems/valid-anagram/
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s == t) return false
    if (s.length != t.length) return false

    let arr_s = [], arr_t = []
    arr_s.length = 26
    arr_t.length = 26
    for (let i = 0; i < 26; i++) {
        arr_s[i] = 0
        arr_t[i] = 0
    }

    for (let i = 0; i < s.length; i++) {
        arr_s[s.charCodeAt(i) - 'a'.charCodeAt(0)]++
        arr_t[t.charCodeAt(i) - 'a'.charCodeAt(0)]++
    }

    for (let i = 0; i < 26; i++) {
        if (arr_s[i] != arr_t[i]) return false
    }
    return true
};
// @lc code=end



/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

 */

