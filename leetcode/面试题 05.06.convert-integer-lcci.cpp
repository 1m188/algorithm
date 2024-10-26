/*
 * @lc app=leetcode.cn id=面试题 05.06 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 05.06] 整数转换
 *
 * https://leetcode.cn/problems/convert-integer-lcci/description/
 *
 * LCCI
 * Easy (51.22%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    24.4K
 * Total Submissions: 47.6K
 * Testcase Example:  '29\n15'
 *
 * 整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
 *
 * ⁠示例1:
 *
 * ⁠输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
 * ⁠输出：2
 *
 *
 * ⁠示例2:
 *
 * ⁠输入：A = 1，B = 2
 * ⁠输出：2
 *
 *
 * ⁠提示:
 *
 *
 * A，B范围在[-2147483648, 2147483647]之间
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
    int convertInteger(int A, int B) {

        int cnt = 0;

        if ((A < 0 && B > 0) && (A > 0 && B < 0)) cnt++;

        for (int i = 0; i < 32; i++) {
            cnt += ((A >> i) & 0x1) != ((B >> i) & 0x1);
        }

        return cnt;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 29 （或者0b11101）\n15（或者0b01111）\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
