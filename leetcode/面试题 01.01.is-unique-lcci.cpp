/*
 * @lc app=leetcode.cn id=面试题 01.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 01.01] 判定字符是否唯一
 *
 * https://leetcode.cn/problems/is-unique-lcci/description/
 *
 * LCCI
 * Easy (71.20%)
 * Likes:    334
 * Dislikes: 0
 * Total Accepted:    174.1K
 * Total Submissions: 244.5K
 * Testcase Example:  '"leetcode"'
 *
 * 实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
 *
 * 示例 1：
 *
 * 输入: s = "leetcode"
 * 输出: false
 *
 *
 * 示例 2：
 *
 * 输入: s = "abc"
 * 输出: true
 *
 *
 * 限制：
 *
 *
 * 0 <= len(s) <= 100
 * s[i]仅包含小写字母
 * 如果你不使用额外的数据结构，会很加分。
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
    bool isUnique(string astr) {
        bool flags[26];
        for (int i = 0; i < 26; i++)
            flags[i] = false;
        for (const char &c : astr) {
            int idx = c - 'a';
            if (!flags[idx]) {
                flags[idx] = true;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */
