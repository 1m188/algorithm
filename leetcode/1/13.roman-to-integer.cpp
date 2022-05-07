/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 *
 * https://leetcode-cn.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (56.57%)
 * Total Accepted:    38.5K
 * Total Submissions: 68K
 * Testcase Example:  '"III"'
 *
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: "III"
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 
 * 输入: "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 
 * 输入: "LVIII"
 * 输出: 58
 * 解释: L = 50, V= 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */

//想法是先判断除了最后一个的其他字符，好处是可以用类似i+1的方法判定后面的字符，从而处理特殊情况，最后再单独处理最后的情况
//需要注意的是万一特殊情况刚好跨到了最后一位，则无需继续处理最后一位了。
class Solution
{
  public:
    int romanToInt(string s)
    {
        int num = 0;
        auto cit = s.cbegin();
        for (; cit < s.cend() - 1; cit++)
        {
            switch (*cit)
            {
            case 'I':
            {
                if (*(cit + 1) == 'V')
                {
                    num += 4;
                    cit++;
                }
                else if (*(cit + 1) == 'X')
                {
                    num += 9;
                    cit++;
                }
                else
                {
                    num += 1;
                }
                break;
            }
            case 'V':
                num += 5;
                break;
            case 'X':
            {
                if (*(cit + 1) == 'L')
                {
                    num += 40;
                    cit++;
                }
                else if (*(cit + 1) == 'C')
                {
                    num += 90;
                    cit++;
                }
                else
                {
                    num += 10;
                }
                break;
            }
            case 'L':
                num += 50;
                break;
            case 'C':
            {
                if (*(cit + 1) == 'D')
                {
                    num += 400;
                    cit++;
                }
                else if (*(cit + 1) == 'M')
                {
                    num += 900;
                    cit++;
                }
                else
                {
                    num += 100;
                }
                break;
            }
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            }
        }
        if (cit < s.cend())
        {
            switch (*cit)
            {
            case 'I':
                num += 1;
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                num += 10;
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                num += 100;
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            }
        }
        return num;
    }
};

#include "string"
using namespace std;
