/*
 * @lc app=leetcode.cn id=1238 lang=typescript
 *
 * [1238] 循环码排列
 *
 * https://leetcode.cn/problems/circular-permutation-in-binary-representation/description/
 *
 * algorithms
 * Medium (66.78%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    4.1K
 * Total Submissions: 6.1K
 * Testcase Example:  '2\n3'
 *
 * 给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：
 * 
 * 
 * p[0] = start
 * p[i] 和 p[i+1] 的二进制表示形式只有一位不同
 * p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 2, start = 3
 * 输出：[3,2,0,1]
 * 解释：这个排列的二进制表示是 (11,10,00,01)
 * ⁠    所有的相邻元素都有一位是不同的，另一个有效的排列是 [3,1,0,2]
 * 
 * 
 * 示例 2：
 * 
 * 输出：n = 3, start = 2
 * 输出：[2,6,7,5,4,0,1,3]
 * 解释：这个排列的二进制表示是 (010,110,111,101,100,000,001,011)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 16
 * 0 <= start < 2^n
 * 
 * 
 */

// @lc code=start
function circularPermutation(n: number, start: number): number[] {

    let num = Math.pow(2, n);
    let res: number[] = new Array(num);
    res[0] = start;
    let vis: boolean[] = new Array(num).fill(false);
    vis[start] = true;
    let f = false;

    /**
     * 判断两个数的二进制位是否只有一位不同
     * 
     * 两个数二进制位只有1位不同，则异或之后应该是2^N形式，
     * 求其指数，应该是一个整数
     * @param n1 
     * @param n2 
     * @returns 
     */
    function judge(n1: number, n2: number): boolean {
        return Number.isInteger(Math.log2(n1 ^ n2));
    }

    /**
     * 递归求一个符合要求的数组
     * @param idx 当前所填写的数的位置
     * @returns 
     */
    function back(idx: number = 1): void {
        if (idx == num) { // 递归出口
            if (judge(res[num - 1], res[0])) f = true; // 判断最后一个数字和第一个数字是否符合要求，符合则置标志位
            return;
        }

        // 直接枚举和前一个数只有一位不同的数
        for (let i = 1; i < num; i <<= 1) {
            let x = i ^ res[idx - 1];
            if (vis[x]) continue;
            vis[x] = true;
            res[idx] = x;
            back(idx + 1);
            if (f) return;
            vis[x] = false;
        }
    }

    back();

    return res;

};
// @lc code=end

