/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 方阵中战斗力最弱的 K 行
 *
 * https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix/description/
 *
 * algorithms
 * Easy (62.66%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 5.5K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
 *
 * 给你一个大小为 m * n 的方阵 mat，方阵由若干军人和平民组成，分别用 0 和 1 表示。
 * 
 * 请你返回方阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。
 * 
 * 如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。
 * 
 * 军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：mat = 
 * [[1,1,0,0,0],
 * ⁠[1,1,1,1,0],
 * ⁠[1,0,0,0,0],
 * ⁠[1,1,0,0,0],
 * ⁠[1,1,1,1,1]], 
 * k = 3
 * 输出：[2,0,3]
 * 解释：
 * 每行中的军人数目：
 * 行 0 -> 2 
 * 行 1 -> 4 
 * 行 2 -> 1 
 * 行 3 -> 2 
 * 行 4 -> 5 
 * 从最弱到最强对这些行排序后得到 [2,0,3,1,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：mat = 
 * [[1,0,0,0],
 * [1,1,1,1],
 * [1,0,0,0],
 * [1,0,0,0]], 
 * k = 2
 * 输出：[0,2]
 * 解释： 
 * 每行中的军人数目：
 * 行 0 -> 1 
 * 行 1 -> 4 
 * 行 2 -> 1 
 * 行 3 -> 1 
 * 从最弱到最强对这些行排序后得到 [0,2,3,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 2 <= n, m <= 100
 * 1 <= k <= m
 * matrix[i][j] 不是 0 就是 1
 * 
 * 
 */

// 对从头开始的每一列进行判断，每一行如此，如果不为1，而其他的为1，说明该行更弱，如果有相同的几行为0，则从头开始push，直到满足k个的要求
// 另外，对于可能出现不满足k的情况，此时将所有未加入的行从头开始进行加入，直到满足k

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        // 标记每行的索引
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            mat[i].push_back(i);
        }

        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[j][i] == 0 && mat[j].back() != -1)
                {
                    vec.push_back(mat[j].back());
                    mat[j].back() = -1;
                    if (--k == 0)
                    {
                        goto end;
                    }
                }
            }
        }
        if (k)
        {
            int index = 0;
            while (k)
            {
                if (mat[index].back() != -1)
                {
                    vec.push_back(index);
                    k--;
                }
                index++;
            }
        }

    end:
        return vec;
    }
};
// @lc code=end
