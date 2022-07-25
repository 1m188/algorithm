/*
 * @lc app=leetcode.cn id=131 lang=typescript
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.15%)
 * Likes:    1209
 * Dislikes: 0
 * Total Accepted:    215.3K
 * Total Submissions: 294.3K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：[["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 16
 * s 仅由小写英文字母组成
 * 
 * 
 */

/**
 * 回溯分割字符串
 */

// @lc code=start
function partition(s: string): string[][] {

    let res: string[][] = [];

    function judge(s: string): boolean {
        if (s.length == 0) return false;
        return s.split('').reverse().join('') == s;
    }

    function back(tmp: string[], size: number, idx: number): void {
        if (tmp.length == size - 1) {
            let str = s.substring(idx);
            if (judge(str)) res.push([...tmp, str]);
            return;
        }

        for (let i = idx + 1; i <= s.length; i++) {
            let str = s.substring(idx, i);
            if (!judge(str)) continue;
            tmp.push(str);
            back(tmp, size, i);
            tmp.pop();
        }
    }

    for (let i = s.length; i >= 1; i--)
        back([], i, 0);

    return res;

};
// @lc code=end

