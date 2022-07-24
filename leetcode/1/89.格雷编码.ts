/*
 * @lc app=leetcode.cn id=89 lang=typescript
 *
 * [89] 格雷编码
 *
 * https://leetcode.cn/problems/gray-code/description/
 *
 * algorithms
 * Medium (74.80%)
 * Likes:    524
 * Dislikes: 0
 * Total Accepted:    99.8K
 * Total Submissions: 133.4K
 * Testcase Example:  '2'
 *
 * n 位格雷码序列 是一个由 2^n 个整数组成的序列，其中：
 * 
 * 每个整数都在范围 [0, 2^n - 1] 内（含 0 和 2^n - 1）
 * 第一个整数是 0
 * 一个整数在序列中出现 不超过一次
 * 每对 相邻 整数的二进制表示 恰好一位不同 ，且
 * 第一个 和 最后一个 整数的二进制表示 恰好一位不同
 * 
 * 
 * 给你一个整数 n ，返回任一有效的 n 位格雷码序列 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：[0,1,3,2]
 * 解释：
 * [0,1,3,2] 的二进制表示是 [00,01,11,10] 。
 * - 00 和 01 有一位不同
 * - 01 和 11 有一位不同
 * - 11 和 10 有一位不同
 * - 10 和 00 有一位不同
 * [0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
 * - 00 和 10 有一位不同
 * - 10 和 11 有一位不同
 * - 11 和 01 有一位不同
 * - 01 和 00 有一位不同
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 16
 * 
 * 
 */

/**
 * 回溯，逐个枚举格雷码每个位置上的数目，判定是否符合要求，
 * 不符合的，回头重新选。
 * 
 * 关键在于，如何枚举？这里有注意的地方，不然容易超时，
 * 不能够机械枚举，会超时，枚举应该直接枚举出和左边的数
 * 只有一位不同的数，如果当前位置是最后一位，则和开头的0比较
 * 是否只有一位不同，否则则只需判断该数之前有没有选过即可。
 * 
 * 那么如何直接枚举出和左边数只有一位不同的数呢？其实就是将
 * 左边的数的某一位翻转过来即可，按顺序翻转每一位，即枚举了所有
 * 和左边的数只有一位不同的数，如何翻转某数二进制的某一位呢？
 * 答案是：异或，与该位为1，其他位为0的数进行异或，即可单独
 * 翻转该位，该数从1开始，不断地左移，注意其左移最多能到n位打止，
 * 不能再多了，因为其他的数最多也只有n位而已。
 */

// @lc code=start
function grayCode(n: number): number[] {

    let num = Math.pow(2, n);

    let res: number[] = [];
    for (let i = 0; i < num; i++) res.push(0);

    /**判断整体回溯是否已经结束 */
    let flag: boolean = false;

    /**访问控制位 */
    let vis: boolean[] = [];
    for (let i = 0; i < num; i++) vis.push(false);
    vis[0] = true; // 已经访问0了，因为开头只能为0

    /**
     * 判断两个数是否只有1位不同 \
     * 这里将两个数异或，如果只有1位不同，那么应该是2的某个次方的数，取log2，应该是一个整数
     * @param a 
     * @param b 
     * @returns 
     */
    function judge(a: number, b: number): boolean {
        return Number.isInteger(Math.log2(a ^ b));
    }

    /**
     * 回溯函数
     * @param idx 当前应该填哪个位置上的数，默认从1索引位置处开始
     * @returns 
     */
    function back(idx: number = 1): void {
        if (idx == num) {
            flag = true;
            return;
        }

        for (let i = 1; i < num; i <<= 1) {
            let x = i ^ res[idx - 1]; // 直接枚举和左边的数只有1位不同的数
            if (idx == num - 1 && !judge(x, 0)) continue; // 如果是最后一个数并且不符合要求则跳过
            if (!vis[x]) {
                vis[x] = true;
                res[idx] = x;
                back(idx + 1);
                if (flag) return;
                vis[x] = false;
            }
        }
    }

    back();

    return res;

};
// @lc code=end

