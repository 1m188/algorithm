/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 *
 * https://leetcode-cn.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (28.17%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 36.6K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * 给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入： A = "ab", B = "ba"
 * 输出： true
 * 
 * 
 * 示例 2：
 * 
 * 输入： A = "ab", B = "ab"
 * 输出： false
 * 
 * 
 * 示例 3:
 * 
 * 输入： A = "aa", B = "aa"
 * 输出： true
 * 
 * 
 * 示例 4：
 * 
 * 输入： A = "aaaaaaabc", B = "aaaaaaacb"
 * 输出： true
 * 
 * 
 * 示例 5：
 * 
 * 输入： A = "", B = "aa"
 * 输出： false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A 和 B 仅由小写字母构成。
 * 
 * 
 */

#include "string"
#include "vector"
#include "algorithm"
#include "unordered_set"
using namespace std;

// @lc code=start
class Solution
{
private:
    bool hasSame(string s)
    {
        unordered_set<char> us;
        for (const char &c : s)
        {
            us.insert(c);
        }
        return !(us.size() == s.size());
    }

public:
    bool buddyStrings(string A, string B)
    {
        if (A.size() != 0 && B.size() != 0 && A.size() == B.size())
        {
            vector<int> difference;
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i] != B[i])
                {
                    if (difference.size() < 2)
                    {
                        difference.push_back(i);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if (difference.size() < 2)
            {
                return hasSame(A);
            }
            swap(A[difference[0]], A[difference[1]]);
            return A == B;
        }
        return false;
    }
};
// @lc code=end
