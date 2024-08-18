/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (54.09%)
 * Total Accepted:    10.5K
 * Total Submissions: 19.4K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex < 2)
        {
            return vector<int>(rowIndex + 1, 1);
        }
        else
        {

            vector<int> vec(2, 1), t(vec);
            for (int i = 1; i < rowIndex; i++)
            {
                t.resize(i + 2, 1);
                for (int j = 1; j <= i; j++)
                {
                    t[j] = vec[j - 1] + vec[j];
                }
                vec = t;
            }
            return vec;
        }
    }
};

#include "vector"
using namespace std;
