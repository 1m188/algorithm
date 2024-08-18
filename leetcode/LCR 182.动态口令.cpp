/*
 * @lc app=leetcode.cn id=LCR 182 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 182] 动态口令
 *
 * https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/description/
 *
 * algorithms
 * Easy (85.40%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    540.4K
 * Total Submissions: 632.7K
 * Testcase Example:  '"s3cur1tyC0d3"\n4'
 *
 * 某公司门禁密码使用动态口令技术。初始密码为字符串 password，密码更新均遵循以下步骤：
 *
 *
 * 设定一个正整数目标值 target
 * 将 password 前 target 个字符按原顺序移动至字符串末尾
 *
 *
 * 请返回更新后的密码字符串。
 *
 *
 *
 * 示例 1：
 *
 * 输入: password = "s3cur1tyC0d3", target = 4
 * 输出: "r1tyC0d3s3cu"
 *
 *
 * 示例 2：
 *
 * 输入: password = "lrloseumgh", target = 6
 * 输出: "umghlrlose"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target < password.length <= 10000
 *
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
    string dynamicPassword(string password, int target) {

        string s1 = password.substr(0, target);
        string s2 = password.substr(target);
        return s2 + s1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "s3cur1tyC0d3"\n4\n
// @lcpr case=end

// @lcpr case=start
// "lrloseumgh"\n6\n
// @lcpr case=end

 */
