/*
 * @lc app=leetcode.cn id=LCR 098 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 098] 不同路径
 *
 * https://leetcode.cn/problems/2AoeFn/description/
 *
 * algorithms
 * Medium (75.42%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    28.7K
 * Total Submissions: 38.1K
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：m = 3, n = 7
 * 输出：28
 *
 * 示例 2：
 *
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 *
 *
 * 示例 3：
 *
 * 输入：m = 7, n = 3
 * 输出：28
 *
 *
 * 示例 4：
 *
 * 输入：m = 3, n = 3
 * 输出：6
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10^9
 *
 *
 *
 *
 * 注意：本题与主站 62 题相同： https://leetcode-cn.com/problems/unique-paths/
 *
 */
#include <vector>
using namespace std;

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int x = i - 1 >= 0 ? dp[i - 1][j] : 0;
                int y = j - 1 >= 0 ? dp[i][j - 1] : 0;
                dp[i][j] = x + y;
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */
