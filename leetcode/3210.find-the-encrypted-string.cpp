/*
 * @lc app=leetcode.cn id=3210 lang=cpp
 * @lcpr version=30204
 *
 * [3210] 找出加密后的字符串
 *
 * https://leetcode.cn/problems/find-the-encrypted-string/description/
 *
 * algorithms
 * Easy (71.96%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 8.7K
 * Testcase Example:  '"dart"\n3'
 *
 * 给你一个字符串 s 和一个整数 k。请你使用以下算法加密字符串：
 *
 *
 * 对于字符串 s 中的每个字符 c，用字符串中 c 后面的第 k 个字符替换 c（以循环方式）。
 *
 *
 * 返回加密后的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： s = "dart", k = 3
 *
 * 输出： "tdar"
 *
 * 解释：
 *
 *
 * 对于 i = 0，'d' 后面的第 3 个字符是 't'。
 * 对于 i = 1，'a' 后面的第 3 个字符是 'd'。
 * 对于 i = 2，'r' 后面的第 3 个字符是 'a'。
 * 对于 i = 3，'t' 后面的第 3 个字符是 'r'。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入： s = "aaa", k = 1
 *
 * 输出： "aaa"
 *
 * 解释：
 *
 * 由于所有字符都相同，加密后的字符串也将相同。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 100
 * 1 <= k <= 10^4
 * s 仅由小写英文字母组成。
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
    string getEncryptedString(string s, int k) {
        k %= s.size();

        auto reverse = [](string &s, int left, int right) {
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        };

        reverse(s, 0, k - 1);
        reverse(s, k, s.size() - 1);
        reverse(s, 0, s.size() - 1);
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "dart"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n1\n
// @lcpr case=end

 */
