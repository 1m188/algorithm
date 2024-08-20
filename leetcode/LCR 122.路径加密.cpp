/*
 * @lc app=leetcode.cn id=LCR 122 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 122] 路径加密
 *
 * https://leetcode.cn/problems/ti-huan-kong-ge-lcof/description/
 *
 * algorithms
 * Easy (74.84%)
 * Likes:    583
 * Dislikes: 0
 * Total Accepted:    748.6K
 * Total Submissions: 1M
 * Testcase Example:  '"a.aef.qerf.bb"'
 *
 * 假定一段路径记作字符串 path，其中以 "." 作为分隔符。现需将路径加密，加密方法为将 path 中的分隔符替换为空格 "
 * "，请返回加密后的字符串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：path = "a.aef.qerf.bb"
 *
 * 输出："a aef qerf bb"
 *
 *
 *
 *
 *
 * 限制：
 *
 * 0 <= path.length <= 10000
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
    string pathEncryption(string path) {
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '.') path[i] = ' ';
        }
        return path;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "a.aef.qerf.bb"\n
// @lcpr case=end

 */
