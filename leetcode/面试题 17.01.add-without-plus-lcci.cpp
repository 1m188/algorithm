/*
 * @lc app=leetcode.cn id=面试题 17.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 17.01] 不用加号的加法
 *
 * https://leetcode.cn/problems/add-without-plus-lcci/description/
 *
 * LCCI
 * Easy (64.11%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    28.4K
 * Total Submissions: 44.3K
 * Testcase Example:  '1\n2'
 *
 * 设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。
 *
 * 示例:
 *
 * 输入: a = 1, b = 1
 * 输出: 2
 *
 *
 *
 * 提示：
 *
 *
 * a, b 均可能是负数或 0
 * 结果不会溢出 32 位整数
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
    int add(int a, int b) {
        while (b) {
            int temp = a ^ b;         // 无进位累加值
            int carry = (a & b) << 1; // 进位值
            // a=无进位累加值 b=进位值
            a = temp;
            b = carry;
        }
        return a;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
