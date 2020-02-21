/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.19%)
 * Likes:    498
 * Dislikes: 0
 * Total Accepted:    109K
 * Total Submissions: 183.3K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        auto it = nums.begin();
        for (int i = 0; i < nums.size(); i++)
        {
            if (*it == 0)
            {
                it = nums.erase(it);
                nums.push_back(0);
            }
            else
            {
                it++;
            }
        }
    }
};
// @lc code=end
