/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode-cn.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (62.73%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    28.2K
 * Total Submissions: 44.9K
 * Testcase Example:  '1'
 *
 * 写一个程序，输出从 1 到 n 数字的字符串表示。
 * 
 * 1. 如果 n 是3的倍数，输出“Fizz”；
 * 
 * 2. 如果 n 是5的倍数，输出“Buzz”；
 * 
 * 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 * 
 * 示例：
 * 
 * n = 15,
 * 
 * 返回:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */

#include "string"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        int three = 3, five = 5;
        string threeStr = "Fizz", fiveStr = "Buzz";
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            string str = "";
            if (!--three)
            {
                str.append(threeStr);
                three = 3;
            }
            if (!--five)
            {
                str.append(fiveStr);
                five = 5;
            }
            if (str.empty())
            {
                str = to_string(i);
            }
            res.push_back(str);
        }
        return res;
    }
};
// @lc code=end
