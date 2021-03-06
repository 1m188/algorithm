/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (58.30%)
 * Total Accepted:    29.8K
 * Total Submissions: 51.2K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int num = 0;

        map<int, int> m;
        for (const int &n : nums)
        {
            if (m.count(n) == 0)
            {
                m.insert({n, 1});
            }
            else
            {
                m.at(n)++;
            }
            if (m.at(n) > nums.size() / 2)
            {
                num = n;
                break;
            }
        }

        return num;
    }
};

#include "vector"
#include "map"
using namespace std;
