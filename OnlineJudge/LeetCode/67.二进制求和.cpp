/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (46.58%)
 * Total Accepted:    17.2K
 * Total Submissions: 36.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
class Solution
{
  public:
    string addBinary(string a, string b)
    {
        if (a.size() < b.size())
        {
            while (a.size() != b.size())
            {
                a.insert(a.begin(), '0');
            }
        }
        else if (a.size() > b.size())
        {
            while (a.size() != b.size())
            {
                b.insert(b.begin(), '0');
            }
        }

        string str;
        int index = a.size() - 1;
        int carry = 0;
        while (index >= 0)
        {
            int num = a[index] - '0' + b[index] - '0' + carry;
            if (num >= 2)
            {
                carry = 1;
                str.push_back(num - 2 + '0');
            }
            else
            {
                carry = 0;
                str.push_back(num + '0');
            }
            index--;
        }

        if (carry)
        {
            str.push_back('1');
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

#include "vector"
#include "algorithm"
using namespace std;
