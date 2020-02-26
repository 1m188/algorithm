/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (45.38%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 30.8K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abab"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aba"
 * 
 * 输出: False
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcabcabcabc"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
 * 
 * 
 */

// 这也太巧妙了吧。。。
// 两个s相加，从索引1开始寻找s，如果s由重复子串组成，则s+s从1开始的下一个s必然会在中间的之前的部分开始
// 如果s不由重复组成，则下一个s必然在中间的部分开始，也就是s.size()

#include "string"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).find(s, 1) != s.size();
    }
};
// @lc code=end
