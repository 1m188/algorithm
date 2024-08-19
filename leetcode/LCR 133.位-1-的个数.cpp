/*
 * @lc app=leetcode.cn id=LCR 133 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 133] 位 1 的个数
 *
 * https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/description/
 *
 * algorithms
 * Easy (76.05%)
 * Likes:    339
 * Dislikes: 0
 * Total Accepted:    353.8K
 * Total Submissions: 465.2K
 * Testcase Example:  '00000000000000000000000000001011'
 *
 * 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
 *
 *
 *
 * 提示：
 *
 *
 * 请注意，在某些语言（如
 * Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
 * 在 Java 中，编译器使用 二进制补码 记法来表示有符号整数。因此，在上面的 示例 3 中，输入表示有符号整数 -3。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 11 (控制台输入 00000000000000000000000000001011)
 * 输出：3
 * 解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
 *
 *
 * 示例 2：
 *
 * 输入：n = 128 (控制台输入 00000000000000000000000010000000)
 * 输出：1
 * 解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
 *
 *
 * 示例 3：
 *
 * 输入：n = 4294967293 (控制台输入 11111111111111111111111111111101，部分语言中 n = -3）
 * 输出：31
 * 解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
 *
 *
 *
 * 提示：
 *
 *
 * 输入必须是长度为 32 的 二进制串 。
 *
 *
 *
 *
 * 注意：本题与主站 191 题相同：https://leetcode-cn.com/problems/number-of-1-bits/
 *
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
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 11 (控制台输入 00000000000000000000000000001011)\n
// @lcpr case=end

// @lcpr case=start
// 128 (控制台输入 00000000000000000000000010000000)\n
// @lcpr case=end

// @lcpr case=start
// -3）\n
// @lcpr case=end

 */
