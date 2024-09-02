/*
 * @lc app=leetcode.cn id=面试题 01.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 01.02] 判定是否互为字符重排
 *
 * https://leetcode.cn/problems/check-permutation-lcci/description/
 *
 * LCCI
 * Easy (65.61%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    141.1K
 * Total Submissions: 215.1K
 * Testcase Example:  '"abc"\n"bca"'
 *
 * 给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
 *
 * 示例 1：
 *
 * 输入: s1 = "abc", s2 = "bca"
 * 输出: true
 *
 *
 * 示例 2：
 *
 * 输入: s1 = "abc", s2 = "bad"
 * 输出: false
 *
 *
 * 说明：
 *
 *
 * 0 <= len(s1) <= 100
 * 0 <= len(s2) <= 100
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
#include <numeric>
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
    bool CheckPermutation(string s1, string s2) {
        vector<int> vec(26, 0);
        for (const char &c : s1) {
            vec[c - 'a']++;
        }
        for (const char &c : s2) {
            vec[c - 'a']--;
            if (vec[c - 'a'] < 0) return false;
        }
        return accumulate(vec.begin(), vec.end(), 0) == 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"bca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"bad"\n
// @lcpr case=end

 */
