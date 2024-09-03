/*
 * @lc app=leetcode.cn id=3216 lang=cpp
 * @lcpr version=30204
 *
 * [3216] 交换后字典序最小的字符串
 *
 * https://leetcode.cn/problems/lexicographically-smallest-string-after-a-swap/description/
 *
 * algorithms
 * Easy (63.66%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    5.9K
 * Total Submissions: 9.5K
 * Testcase Example:  '"45320"'
 *
 * 给你一个仅由数字组成的字符串 s，在最多交换一次 相邻 且具有相同 奇偶性 的数字后，返回可以得到的字典序最小的字符串。
 *
 * 如果两个数字都是奇数或都是偶数，则它们具有相同的奇偶性。例如，5 和 9、2 和 4 奇偶性相同，而 6 和 9 奇偶性不同。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： s = "45320"
 *
 * 输出： "43520"
 *
 * 解释：
 *
 * s[1] == '5' 和 s[2] == '3' 都具有相同的奇偶性，交换它们可以得到字典序最小的字符串。
 *
 *
 * 示例 2：
 *
 *
 * 输入： s = "001"
 *
 * 输出： "001"
 *
 * 解释：
 *
 * 无需进行交换，因为 s 已经是字典序最小的。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= s.length <= 100
 * s 仅由数字组成。
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
    string getSmallestString(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            int left = s[i] - '0';
            int right = s[i + 1] - '0';
            if ((left & 0x1) == (right & 0x1) && right < left) {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "45320"\n
// @lcpr case=end

// @lcpr case=start
// "001"\n
// @lcpr case=end

 */
