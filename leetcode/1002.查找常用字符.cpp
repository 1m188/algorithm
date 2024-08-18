/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 *
 * https://leetcode-cn.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (66.51%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 15.2K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3
 * 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：["bella","label","roller"]
 * 输出：["e","l","l"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：["cool","lock","cook"]
 * 输出：["c","o"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] 是小写字母
 * 
 * 
 */

#include "vector"
#include "string"
#include "algorithm"
#include "iterator"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        sort(A[0].begin(), A[0].end());
        string str = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            string nstr;
            sort(A[i].begin(), A[i].end());
            set_intersection(str.begin(), str.end(), A[i].begin(), A[i].end(), insert_iterator<string>(nstr, nstr.begin()));
            str.swap(nstr);
        }

        vector<string> res;
        for_each(str.begin(), str.end(), [&](const char &c) { res.push_back(string() + c); });
        return res;
    }
};
// @lc code=end
