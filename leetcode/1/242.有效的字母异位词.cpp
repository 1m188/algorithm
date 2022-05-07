/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (51.30%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    75.2K
 * Total Submissions: 128.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

#include "string"
#include "algorithm"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // AC
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;

        vector<int> vec(26, 0);
        for (const char &c : s)
        {
            vec[c - 'a']++;
        }
        for (const char &c : t)
        {
            vec[c - 'a']--;
        }
        auto it = find_if(vec.begin(), vec.end(), [](const int &x) { return x != 0; });
        return it == vec.end();
    }
};
// @lc code=end
