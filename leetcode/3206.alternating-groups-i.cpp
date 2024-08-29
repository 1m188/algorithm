/*
 * @lc app=leetcode.cn id=3206 lang=cpp
 * @lcpr version=30204
 *
 * [3206] 交替组 I
 *
 * https://leetcode.cn/problems/alternating-groups-i/description/
 *
 * algorithms
 * Easy (74.48%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 5.3K
 * Testcase Example:  '[1,1,1]'
 *
 * 给你一个整数数组 colors ，它表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i] ：
 *
 *
 * colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
 * colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
 *
 *
 * 环中连续 3 块瓷砖的颜色如果是 交替 颜色（也就是说中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个 交替 组。
 *
 * 请你返回 交替 组的数目。
 *
 * 注意 ，由于 colors 表示一个 环 ，第一块 瓷砖和 最后一块 瓷砖是相邻的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：colors = [1,1,1]
 *
 * 输出：0
 *
 * 解释：
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：colors = [0,1,0,0,1]
 *
 * 输出：3
 *
 * 解释：
 *
 *
 *
 * 交替组包括：
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= colors.length <= 100
 * 0 <= colors[i] <= 1
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
    int numberOfAlternatingGroups(vector<int> &colors) {
        int n = colors.size();
        int res = 0;
        int len = 1;
        int i = 0, j = 2;
        while (true) {
            if (colors[j] != colors[(j - 1 + n) % n] && colors[j] == colors[i]) {
                res++;
                i = (i + 1) % n;
                j = (j + 1) % n;
            } else {
                if (colors[j] == colors[(j - 1 + n) % n]) {
                    i = (i + 1) % n;
                    j = (j + 1) % n;
                } else {
                    i = (i + 1) % n;
                    j = (j + 1) % n;
                }
            }
            if (i == 0) break;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,0,1]\n
// @lcpr case=end

 */
