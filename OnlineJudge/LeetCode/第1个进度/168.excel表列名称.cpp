/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (30.57%)
 * Total Accepted:    6K
 * Total Submissions: 19.8K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
class Solution
{
  public:
    string convertToTitle(int n)
    {
        string str;

        while (n)
        {
            int x = n % 26;
            if (x == 0)
            {
                x = 26;
            }
            str.push_back(x + 'A' - 1);
            n /= 26;
            if (x == 26)
            {
                n--;
            }
        }
        reverse(str.begin(), str.end());

        return str;
    }
};

#include "string"
#include "algorithm"
using namespace std;
