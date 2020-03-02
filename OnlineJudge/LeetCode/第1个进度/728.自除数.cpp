/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 *
 * https://leetcode-cn.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (72.54%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    17.8K
 * Total Submissions: 24.5K
 * Testcase Example:  '1\n22'
 *
 * 自除数 是指可以被它包含的每一位数除尽的数。
 * 
 * 例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
 * 
 * 还有，自除数不允许包含 0 。
 * 
 * 给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。
 * 
 * 示例 1：
 * 
 * 
 * 输入： 
 * 上边界left = 1, 下边界right = 22
 * 输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 注意：
 * 
 * 
 * 每个输入参数的边界满足 1 <= left <= right <= 10000。
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int i = left; i <= right; i++)
        {
            int tmp = i;
            while (tmp)
            {
                int n = tmp % 10;
                tmp /= 10;
                if (n == 0 || i % n != 0)
                {
                    goto next;
                }
            }
            res.push_back(i);
        next:;
        }
        return res;
    }
};
// @lc code=end
