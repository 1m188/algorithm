/*
 * @lc app=leetcode.cn id=LCR 166 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 166] 珠宝的最高价值
 *
 * https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/
 *
 * algorithms
 * Medium (69.34%)
 * Likes:    546
 * Dislikes: 0
 * Total Accepted:    299.3K
 * Total Submissions: 431.6K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j] 为该位置珠宝的价值。拿取珠宝的规则为：
 *
 *
 * 只能从架子的左上角开始拿珠宝
 * 每次可以移动到右侧或下侧的相邻位置
 * 到达珠宝架子的右下角时，停止拿取
 *
 *
 * 注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame = [[0]]。
 *
 *
 *
 * 示例 1:
 *
 * 输入: frame = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出: 12
 * 解释: 路径 1→3→5→2→1 可以拿到最高价值的珠宝
 *
 *
 *
 * 提示：
 *
 *
 * 0 < frame.length <= 200
 * 0 < frame[0].length <= 200
 *
 *
 *
 *
 */
#include <vector>
using namespace std;

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int jewelleryValue(vector<vector<int>> &frame) {
        int m = frame.size(), n = frame[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = frame[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int x = i - 1 >= 0 ? dp[i - 1][j] : 0;
                int y = j - 1 >= 0 ? dp[i][j - 1] : 0;
                dp[i][j] = max(frame[i][j] + x, frame[i][j] + y);
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

 */
