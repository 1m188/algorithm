/*
 * @lc app=leetcode.cn id=2729 lang=csharp
 *
 * [2729] 判断一个数是否迷人
 *
 * https://leetcode.cn/problems/check-if-the-number-is-fascinating/description/
 *
 * algorithms
 * Easy (62.56%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    2.7K
 * Total Submissions: 4.2K
 * Testcase Example:  '192'
 *
 * 给你一个三位数整数 n 。
 * 
 * 如果经过以下修改得到的数字 恰好 包含数字 1 到 9 各一次且不包含任何 0 ，那么我们称数字 n 是 迷人的 ：
 * 
 * 
 * 将 n 与数字 2 * n 和 3 * n 连接 。
 * 
 * 
 * 如果 n 是迷人的，返回 true，否则返回 false 。
 * 
 * 连接 两个数字表示把它们首尾相接连在一起。比方说 121 和 371 连接得到 121371 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 192
 * 输出：true
 * 解释：我们将数字 n = 192 ，2 * n = 384 和 3 * n = 576 连接，得到 192384576 。这个数字包含 1 到 9
 * 恰好各一次。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 100
 * 输出：false
 * 解释：我们将数字 n = 100 ，2 * n = 200 和 3 * n = 300 连接，得到 100200300
 * 。这个数字不符合上述条件。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 100 <= n <= 999
 * 
 * 
 */


// @lc code=start
public class Solution
{
    public bool IsFascinating(int n)
    {
        string s = n.ToString() + (2 * n).ToString() + (3 * n).ToString();
        bool[] flags = new bool[10];
        foreach (char c in s)
        {
            int ch = c - '0';
            if (ch == 0) return false;
            if (flags[ch]) return false;
            flags[ch] = true;
        }
        for (int i = 1; i < flags.Length; i++)
        {
            if (!flags[i]) return false;
        }
        return true;
    }
}
// @lc code=end

