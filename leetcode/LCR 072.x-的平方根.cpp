/*
 * @lc app=leetcode.cn id=LCR 072 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 072] x 的平方根
 *
 * https://leetcode.cn/problems/jJ0w9p/description/
 *
 * algorithms
 * Easy (42.68%)
 * Likes:    66
 * Dislikes: 0
 * Total Accepted:    47.6K
 * Total Submissions: 111.6K
 * Testcase Example:  '4'
 *
 * 给定一个非负整数 x ，计算并返回 x 的平方根，即实现 int sqrt(int x) 函数。
 *
 * 正数的平方根有两个，只输出其中的正数平方根。
 *
 * 如果平方根不是整数，输出只保留整数的部分，小数部分将被舍去。
 *
 *
 *
 * 示例 1:
 *
 * 输入: x = 4
 * 输出: 2
 *
 *
 * 示例 2:
 *
 * 输入: x = 8
 * 输出: 2
 * 解释: 8 的平方根是 2.82842...，由于小数部分将被舍去，所以返回 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 *
 *
 * 注意：本题与主站 69 题相同： https://leetcode-cn.com/problems/sqrtx/
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
    int mySqrt(int x) {

        if (x == 0) return 0;
        if (x == 1) return 1;

        unsigned long long i = 1;
        for (i = 1; i < x; i++) {
            if (i * i <= x && (i + 1) * (i + 1) > x) break;
        }
        return i;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
