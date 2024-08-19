/*
 * @lc app=leetcode.cn id=面试题 08.09 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 08.09] 括号
 *
 * https://leetcode.cn/problems/bracket-lcci/description/
 *
 * LCCI
 * Medium (82.25%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    36.7K
 * Total Submissions: 44.7K
 * Testcase Example:  '3'
 *
 * 括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。
 *
 * 说明：解集不能包含重复的子集。
 *
 * 例如，给出 n = 3，生成结果为：
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;

        int left = 0, right = 0;
        function<void(string)> func = [&](string str) {
            if (left == n) {
                string s = str;
                for (int i = 0; i < left - right; i++)
                    s.push_back(')');
                res.push_back(s);
            } else {
                left++;
                str.push_back('(');
                func(str);
                str.pop_back();
                left--;
                if (right < left) {
                    right++;
                    str.push_back(')');
                    func(str);
                    str.pop_back();
                    right--;
                }
            }
        };
        string str;
        func(str);

        return res;
    }
};
// @lc code=end
