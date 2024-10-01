/*
 * @lc app=leetcode.cn id=LCR 169 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 169] 招式拆解 II
 *
 * https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/description/
 *
 * algorithms
 * Easy (61.82%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    343.1K
 * Total Submissions: 555K
 * Testcase Example:  '"abbccdeff"'
 *
 * 某套连招动作记作仅由小写字母组成的序列 arr，其中 arr[i] 第 i 个招式的名字。请返回第一个只出现一次的招式名称，如不存在请返回空格。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = "abbccdeff"
 * 输出：'a'
 *
 *
 * 示例 2：
 *
 * 输入：arr = "ccdd"
 * 输出：' '
 *
 *
 *
 *
 * 限制：
 *
 * 0 <= arr.length <= 50000
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
    char dismantlingAction(string arr) {

        vector<int> cnts(26, 0);
        for (const char &c : arr) {
            cnts[c - 'a']++;
        }
        for (const char &c : arr) {
            if (cnts[c - 'a'] == 1) return c;
        }
        return ' ';
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abbccdeff"\n
// @lcpr case=end

// @lcpr case=start
// "ccdd"\n
// @lcpr case=end

 */
