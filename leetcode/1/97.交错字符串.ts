/*
 * @lc app=leetcode.cn id=97 lang=typescript
 *
 * [97] 交错字符串
 *
 * https://leetcode.cn/problems/interleaving-string/description/
 *
 * algorithms
 * Medium (45.11%)
 * Likes:    707
 * Dislikes: 0
 * Total Accepted:    85.8K
 * Total Submissions: 190.2K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
 * 
 * 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
 * 
 * 
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 +
 * ...
 * 
 * 
 * 注意：a + b 意味着字符串 a 和 b 连接。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s1 = "", s2 = "", s3 = ""
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s1.length, s2.length <= 100
 * 0 <= s3.length <= 200
 * s1、s2、和 s3 都由小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：您能否仅使用 O(s2.length) 额外的内存空间来解决它?
 * 
 */

/**
 * 动态规划
 * 
 * 考虑dp数组，dp[i][j]表示s1的前i个字符和s2的前j个字符能够交替
 * 组成s3的前i+j个字符，那么如果s1[i-1]==s3[i+j-1]，那么只要
 * 判定s1的前i-1个字符和s2的前j个字符是否能够组成s3的前i+j-1个
 * 字符，对于s2也是同理，有状态转移方程：
 * 
 * dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
 * 
 * 此外，对于二维动态规划数组因为是从上到下从左到右进行的，而每次又只需要
 * 该行前面一行即可，所以，可以只用两行数组来保存所需的内容，每个数组大小为
 * s2.length，可以降低空间复杂度。
 */

// @lc code=start
function isInterleave(s1: string, s2: string, s3: string): boolean {

    let n = s1.length, m = s2.length, p = s3.length;

    if (n + m != p) return false;

    // 空间复杂度：O(s1.length * s2.length)

    // let dp: boolean[][] = [];
    // for (let i = 0; i <= n; i++) {
    //     dp.push([]);
    //     for (let j = 0; j <= m; j++) {
    //         dp[i].push(false);
    //     }
    // }

    // dp[0][0] = true;

    // for (let i = 0; i <= n; i++) {
    //     for (let j = 0; j <= m; j++) {
    //         if (i > 0) {
    //             dp[i][j] = s1[i - 1] == s3[i + j - 1] && dp[i - 1][j];
    //         }
    //         if (j > 0) {
    //             dp[i][j] = (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) || dp[i][j];
    //         }
    //     }
    // }

    // return dp[n][m];

    // 空间复杂度：O(s2.length)

    let dpi: boolean[] = [], dpip: boolean[] = [];
    for (let i = 0; i <= m; i++) {
        dpi.push(false);
        dpip.push(false);
    }

    dpi[0] = true;

    for (let i = 0; i <= n; i++) {
        for (let j = 0; j <= m; j++) {
            if (i > 0) {
                dpi[j] = s1[i - 1] == s3[i + j - 1] && dpip[j];
            }
            if (j > 0) {
                dpi[j] = (s2[j - 1] == s3[i + j - 1] && dpi[j - 1]) || dpi[j];
            }
            dpip = [...dpi];
        }
    }

    return dpi[m];
};
// @lc code=end

