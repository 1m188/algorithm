/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (37.51%)
 * Total Accepted:    38.3K
 * Total Submissions: 102K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */
class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> vec(digits);
        vec.back()++;
        int carry = 0;
        int index = vec.size() - 1;
        while (true)
        {
            int num = vec[index] + carry;
            vec[index] = num % 10;
            num /= 10;
            carry = num;
            if (carry == 0)
            {
                break;
            }
            index--;
            if (index < 0)
            {
                vec.insert(vec.begin(), carry);
                break;
            }
        }
        return vec;
    }
};

#include "vector"
using namespace std;
