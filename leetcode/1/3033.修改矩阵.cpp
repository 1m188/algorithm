/*
 * @lc app=leetcode.cn id=3033 lang=cpp
 *
 * [3033] 修改矩阵
 *
 * https://leetcode.cn/problems/modify-the-matrix/description/
 *
 * algorithms
 * Easy (79.69%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 17.4K
 * Testcase Example:  '[[1,2,-1],[4,-1,6],[7,8,9]]'
 *
 * 给你一个下标从 0 开始、大小为 m x n 的整数矩阵 matrix ，新建一个下标从 0 开始、名为 answer 的矩阵。使 answer 与
 * matrix 相等，接着将其中每个值为 -1 的元素替换为所在列的 最大 元素。
 *
 * 返回矩阵 answer 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
 * 输出：[[1,2,9],[4,8,6],[7,8,9]]
 * 解释：上图显示了发生替换的元素（蓝色区域）。
 * - 将单元格 [1][1] 中的值替换为列 1 中的最大值 8 。
 * - 将单元格 [0][2] 中的值替换为列 2 中的最大值 9 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[3,-1],[5,2]]
 * 输出：[[3,2],[5,2]]
 * 解释：上图显示了发生替换的元素（蓝色区域）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 2 <= m, n <= 50
 * -1 <= matrix[i][j] <= 100
 * 测试用例中生成的输入满足每列至少包含一个非负整数。
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix) {

        auto answer = matrix;
        int m = answer.size(), n = answer[0].size();

        vector<int> max(n, -1);
        for (int i = 0; i < n; i++) { // 求出每列最大值
            int x = answer[0][i];
            for (int j = 0; j < m; j++) {
                if (answer[j][i] > x) x = answer[j][i];
            }
            max[i] = x;
        }

        // 替换
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (answer[i][j] == -1) answer[i][j] = max[j];
            }
        }

        return answer;
    }
};
// @lc code=end
