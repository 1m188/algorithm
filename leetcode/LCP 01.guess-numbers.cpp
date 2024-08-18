/*
 * @lc app=leetcode.cn id=LCP 01 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 01] 猜数字
 *
 * https://leetcode.cn/problems/guess-numbers/description/
 *
 * algorithms
 * Easy (84.56%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    108.1K
 * Total Submissions: 127.9K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 小A 和 小B 在玩猜数字。小B 每次从 1, 2, 3 中随机选择一个，小A 每次也从 1, 2, 3 中选择一个猜。他们一共进行三次这个游戏，请返回
 * 小A 猜对了几次？
 *
 * 输入的guess数组为 小A 每次的猜测，answer数组为 小B 每次的选择。guess和answer的长度都等于3。
 *
 *
 *
 * 示例 1：
 *
 * 输入：guess = [1,2,3], answer = [1,2,3]
 * 输出：3
 * 解释：小A 每次都猜对了。
 *
 * 示例 2：
 *
 * 输入：guess = [2,2,3], answer = [3,2,1]
 * 输出：1
 * 解释：小A 只猜对了第二次。
 *
 *
 *
 * 限制：
 *
 *
 * guess 的长度 = 3
 * answer 的长度 = 3
 * guess 的元素取值为 {1, 2, 3} 之一。
 * answer 的元素取值为 {1, 2, 3} 之一。
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
    int game(vector<int> &guess, vector<int> &answer) {
        return (guess[0] == answer[0]) + (guess[1] == answer[1]) + (guess[2] == answer[2]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,3]\n[3,2,1]\n
// @lcpr case=end

 */
