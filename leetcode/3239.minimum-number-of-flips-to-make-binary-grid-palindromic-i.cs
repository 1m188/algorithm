/*
 * @lc app=leetcode.cn id=3239 lang=csharp
 * @lcpr version=30204
 *
 * [3239] 最少翻转次数使二进制矩阵回文 I
 *
 * https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/
 *
 * algorithms
 * Medium (85.36%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 3.6K
 * Testcase Example:  '[[1,0,0],[0,0,0],[0,0,1]]'
 *
 * 给你一个 m x n 的二进制矩阵 grid 。
 * 
 * 如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 回文 的。
 * 
 * 你可以将 grid 中任意格子的值 翻转 ，也就是将格子里的值从 0 变成 1 ，或者从 1 变成 0 。
 * 
 * 请你返回 最少 翻转次数，使得矩阵 要么 所有行是 回文的 ，要么所有列是 回文的 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[1,0,0],[0,0,0],[0,0,1]]
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 
 * 
 * 将高亮的格子翻转，得到所有行都是回文的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[0,1],[0,1],[0,0]]
 * 
 * 输出：1
 * 
 * 解释：
 * 
 * 
 * 
 * 将高亮的格子翻转，得到所有列都是回文的。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：grid = [[1],[0]]
 * 
 * 输出：0
 * 
 * 解释：
 * 
 * 所有行已经是回文的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m * n <= 2 * 10^5
 * 0 <= grid[i][j] <= 1
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
using System;

public class Solution
{
    public int MinFlips(int[][] grid)
    {
        int m = grid.Length, n = grid[0].Length;

        var lambda = (int[] arr) =>
        {
            int res = 0;
            int left = 0, right = arr.Length - 1;
            while (left <= right)
            {
                res += arr[left] != arr[right] ? 1 : 0;
                left++; right--;
            }
            return res;
        };

        int x = 0;
        for (int i = 0; i < m; i++)
        {
            x += lambda(grid[i]);
        }

        int y = 0;
        for (int i = 0; i < n; i++)
        {
            var arr = new int[m];
            for (int j = 0; j < m; j++)
            {
                arr[j] = grid[j][i];
            }
            y += lambda(arr);
        }

        return Math.Min(x, y);
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,0,0],[0,0,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[0]]\n
// @lcpr case=end

 */

