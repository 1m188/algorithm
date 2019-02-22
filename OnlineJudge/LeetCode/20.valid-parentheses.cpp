/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.26%)
 * Total Accepted:    44.7K
 * Total Submissions: 123.4K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (auto cit = s.cbegin(); cit != s.cend(); cit++)
        {
            if (!stack.empty())
            {
                if ((*cit == ')' && stack.top() == '(') || (*cit == ']' && stack.top() == '[') || (*cit == '}' && stack.top() == '{'))
                {
                    stack.pop();
                }
                else
                {
                    stack.push(*cit);
                }
            }
            else
            {
                stack.push(*cit);
            }
        }

        return stack.empty();
    }
};

#include "string"
#include "stack"
using namespace std;
