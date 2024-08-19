/*
 * @lc app=leetcode.cn id=LCR 003 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 003] 比特位计数
 *
 * https://leetcode.cn/problems/w3tCBm/description/
 *
 * algorithms
 * Easy (78.11%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    83K
 * Total Submissions: 106.3K
 * Testcase Example:  '2'
 *
 * 给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。
 *
 *
 *
 * 示例 1:
 *
 * 输入: n = 2
 * 输出: [0,1,1]
 * 解释:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 *
 * 示例 2:
 *
 * 输入: n = 5
 * 输出: [0,1,1,2,1,2]
 * 解释:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 *
 *
 *
 * 说明 :
 *
 *
 * 0 <= n <= 10^5
 *
 *
 *
 *
 * 进阶:
 *
 *
 * 给出时间复杂度为 O(n*sizeof(integer)) 的解答非常容易。但你可以在线性时间 O(n) 内用一趟扫描做到吗？
 * 要求算法的空间复杂度为 O(n) 。
 * 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount ）来执行此操作。
 *
 *
 *
 *
 * 注意：本题与主站 338 题相同：https://leetcode-cn.com/problems/counting-bits/
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
    vector<int> countBits(int n) {

        auto func = [](int x) -> int {
            int res = 0;
            while (x) {
                res += x & 1;
                x >>= 1;
            }
            return res;
        };

        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++) {
            if ((i & 1) == 1)
                res[i] = res[i - 1] + 1;
            else
                res[i] = func(i);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */
