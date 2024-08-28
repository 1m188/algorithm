/*
 * @lc app=leetcode.cn id=面试题 16.07 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.07] 最大数值
 *
 * https://leetcode.cn/problems/maximum-lcci/description/
 *
 * LCCI
 * Easy (74.98%)
 * Likes:    154
 * Dislikes: 0
 * Total Accepted:    41K
 * Total Submissions: 54.6K
 * Testcase Example:  '2147483647\n-2147483648'
 *
 * 编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。
 * 示例：
 * 输入： a = 1, b = 2
 * 输出： 2
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
    int maximum(int a, int b) {
        long long a1 = a, b1 = b;
        long long x = (a1 - b1) >> 63 & 0x1;
        long long res = (1 - x) * a1 + x * b1;
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

 */
