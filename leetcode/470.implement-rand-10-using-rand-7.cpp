/*
 * @lc app=leetcode.cn id=470 lang=cpp
 * @lcpr version=30204
 *
 * [470] 用 Rand7() 实现 Rand10()
 *
 * https://leetcode.cn/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (55.18%)
 * Likes:    488
 * Dislikes: 0
 * Total Accepted:    115.3K
 * Total Submissions: 209K
 * Testcase Example:  '1'
 *
 * 给定方法 rand7 可生成 [1,7] 范围内的均匀随机整数，试写一个方法 rand10 生成 [1,10] 范围内的均匀随机整数。
 *
 * 你只能调用 rand7() 且不能调用其他方法。请不要使用系统的 Math.random() 方法。
 *
 *
 *
 *
 * 每个测试用例将有一个内部参数 n，即你实现的函数 rand10() 在测试时将被调用的次数。请注意，这不是传递给 rand10() 的参数。
 *
 *
 *
 * 示例 1:
 *
 * 输入: 1
 * 输出: [2]
 *
 *
 * 示例 2:
 *
 * 输入: 2
 * 输出: [2,8]
 *
 *
 * 示例 3:
 *
 * 输入: 3
 * 输出: [3,8,10]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= n <= 10^5
 *
 *
 *
 *
 * 进阶:
 *
 *
 * rand7()调用次数的 期望值 是多少 ?
 * 你能否尽量少调用 rand7() ?
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
int rand7();
// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // 随机对抗随机
        return (rand7() + rand7() + rand7() + rand7() + rand7()) % 10 + 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
