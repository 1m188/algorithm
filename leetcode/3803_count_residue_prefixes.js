/*
 * @lc app=leetcode.cn id=3803 lang=javascript
 * @lcpr version=30204
 *
 * [3803] 统计残差前缀
 *
 * https://leetcode.cn/problems/count-residue-prefixes/description/
 *
 * algorithms
 * Easy (75.48%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    2.7K
 * Total Submissions: 3.5K
 * Testcase Example:  '"abc"'
 *
 * 给你一个仅由小写英文字母组成的字符串 s。
 * 
 * 如果字符串 s 的某个 前缀 中 不同字符的数量 等于 len(prefix) % 3，则该前缀被称为残差前缀（residue）。
 * 
 * 返回字符串 s 中 残差前缀 的数量。
 * 
 * 字符串的 前缀 是一个 非空子字符串，从字符串的开头起始并延伸到任意位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "abc"
 * 
 * 输出: 2
 * 
 * 解释:​​​​​​​
 * 
 * 
 * 前缀 "a" 有 1 个不同字符，且长度模 3 为 1，因此它是一个残差前缀。
 * 前缀 "ab" 有 2 个不同字符，且长度模 3 为 2，因此它是一个残差前缀。
 * 前缀 "abc" 不满足条件，因此不是残差前缀。
 * 
 * 
 * 因此，答案是 2。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: s = "dd"
 * 
 * 输出: 1
 * 
 * 解释:​​​​​​​
 * 
 * 
 * 前缀 "d" 有 1 个不同字符，且长度模 3 为 1，因此它是一个残差前缀。
 * 前缀 "dd" 有 1 个不同字符，但长度模 3 为 2，因此它不是残差前缀。
 * 
 * 
 * 因此，答案是 1。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入: s = "bob"
 * 
 * 输出: 2
 * 
 * 解释:
 * 
 * 
 * 前缀 "b" 有 1 个不同字符，且长度模 3 为 1，因此它是一个残差前缀。
 * 前缀 "bo" 有 2 个不同字符，且长度模 3 为 2，因此它是一个残差前缀。
 * 前缀 "bob" 不满足条件。
 * 
 * 
 * 因此，答案是 2。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * s 仅包含小写英文字母。
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
var residuePrefixes = function (s) {
    let ans = 0;
    let alpha = new Array(26).fill(false);
    let count = 0;
    for (let i = 0; i < s.length; i++) {
        let idx = s[i].charCodeAt() - 'a'.charCodeAt();
        if (!alpha[idx]) {
            alpha[idx] = true;
            count++;
        }
        ans += count === (i + 1) % 3;
    }
    return ans;
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "dd"\n
// @lcpr case=end

// @lcpr case=start
// "bob"\n
// @lcpr case=end

 */

