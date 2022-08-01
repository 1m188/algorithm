/*
 * @lc app=leetcode.cn id=2299 lang=typescript
 *
 * [2299] 强密码检验器 II
 *
 * https://leetcode.cn/problems/strong-password-checker-ii/description/
 *
 * algorithms
 * Easy (62.53%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 8.4K
 * Testcase Example:  '"IloveLe3tcode!"'
 *
 * 如果一个密码满足以下所有条件，我们称它是一个 强 密码：
 * 
 * 
 * 它有至少 8 个字符。
 * 至少包含 一个小写英文 字母。
 * 至少包含 一个大写英文 字母。
 * 至少包含 一个数字 。
 * 至少包含 一个特殊字符 。特殊字符为："!@#$%^&*()-+" 中的一个。
 * 它 不 包含 2 个连续相同的字符（比方说 "aab" 不符合该条件，但是 "aba" 符合该条件）。
 * 
 * 
 * 给你一个字符串 password ，如果它是一个 强 密码，返回 true，否则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：password = "IloveLe3tcode!"
 * 输出：true
 * 解释：密码满足所有的要求，所以我们返回 true 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：password = "Me+You--IsMyDream"
 * 输出：false
 * 解释：密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：password = "1aB!"
 * 输出：false
 * 解释：密码不符合长度要求。所以我们返回 false 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= password.length <= 100
 * password 包含字母，数字和 "!@#$%^&*()-+" 这些特殊字符。
 * 
 * 
 */

// @lc code=start
function strongPasswordCheckerII(password: string): boolean {

    if (password.length < 8) return false;

    let set: Set<string> = new Set(['!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+']);
    let f1 = false, f2 = false, f3 = false, f4 = false;
    for (let c of password) {
        if (c >= 'a' && c <= 'z') f1 = true;
        else if (c >= 'A' && c <= 'Z') f2 = true;
        else if (c >= '0' && c <= '9') f3 = true;
        else if (set.has(c)) f4 = true;
    }
    if (!f1 || !f2 || !f3 || !f4) return false;

    for (let i = 1; i < password.length; i++) {
        if (password[i] == password[i - 1]) return false;
    }

    return true;

};
// @lc code=end

