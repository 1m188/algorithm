/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 *
 * https://leetcode-cn.com/problems/powerful-integers/description/
 *
 * algorithms
 * Easy (39.20%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 13.2K
 * Testcase Example:  '2\n3\n10'
 *
 * 给定两个正整数 x 和 y，如果某一整数等于 x^i + y^j，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个强整数。
 * 
 * 返回值小于或等于 bound 的所有强整数组成的列表。
 * 
 * 你可以按任何顺序返回答案。在你的回答中，每个值最多出现一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：x = 2, y = 3, bound = 10
 * 输出：[2,3,4,5,7,9,10]
 * 解释： 
 * 2 = 2^0 + 3^0
 * 3 = 2^1 + 3^0
 * 4 = 2^0 + 3^1
 * 5 = 2^1 + 3^1
 * 7 = 2^2 + 3^1
 * 9 = 2^3 + 3^0
 * 10 = 2^0 + 3^2
 * 
 * 
 * 示例 2：
 * 
 * 输入：x = 3, y = 5, bound = 15
 * 输出：[2,4,6,8,10,14]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= x <= 100
 * 1 <= y <= 100
 * 0 <= bound <= 10^6
 * 
 * 
 */

#include "vector"
#include "cmath"
#include "unordered_set"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        if (bound < 2)
        {
            return {};
        }

        if (x == 1 && y == 1)
        {
            return {2};
        }
        else if (x == 1)
        {
            vector<int> res;
            int j = 0;
            long long integer = 0;
            while ((integer = x + pow(y, j)) <= bound)
            {
                res.push_back(static_cast<int>(integer));
                j++;
            }
            return res;
        }
        else if (y == 1)
        {
            vector<int> res;
            int i = 0;
            long long integer = 0;
            while ((integer = pow(x, i) + y) <= bound)
            {
                res.push_back(static_cast<int>(integer));
                i++;
            }
            return res;
        }

        unordered_set<int> res;
        int i = 0, j = 0;
        long long integer = 0;
    again:
        while ((integer = pow(x, i) + pow(y, j)) <= bound)
        {
            res.insert(static_cast<int>(integer));
            j++;
        }
        if (j)
        {
            i++;
            j = 0;
            goto again;
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end
