/*
 * @lc app=leetcode.cn id=LCR 002 lang=typescript
 * @lcpr version=30204
 *
 * [LCR 002] 二进制求和
 *
 * https://leetcode.cn/problems/JFETK5/description/
 *
 * algorithms
 * Easy (53.76%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    65.9K
 * Total Submissions: 122.6K
 * Testcase Example:  '"11"\n"10"'
 *
 * 给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "10"
 * 输出: "101"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 * 
 * 
 * 注意：本题与主站 67 题相同：https://leetcode-cn.com/problems/add-binary/
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
function addBinary(a: string, b: string): string {

    if (a.length < b.length) {
        a = new Array(b.length - a.length).fill('0').join('') + a;
    } else if (a.length > b.length) {
        b = new Array(a.length - b.length).fill('0').join('') + b;
    }

    let res: string[] = new Array(a.length).fill('0');
    let x = 0;
    for (let i = a.length - 1; i >= 0; i--) {
        let y = Number(a[i]) + Number(b[i]) + x;
        x = 0;
        if (y <= 1) res[i] = String(y);
        else {
            x = 1;
            y -= 2;
            res[i] = String(y);
        }
    }

    if (x == 1) res.unshift(String(x));
    return res.join('');

};
// @lc code=end



/*
// @lcpr case=start
// "11"\n"10"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */

