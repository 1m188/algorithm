/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 * @lcpr version=30204
 *
 * [1184] 公交站间的距离
 *
 * https://leetcode.cn/problems/distance-between-bus-stops/description/
 *
 * algorithms
 * Easy (61.61%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    54.3K
 * Total Submissions: 86.3K
 * Testcase Example:  '[1,2,3,4]\n0\n1'
 *
 * 环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i
 * 的车站和编号为 (i + 1) % n 的车站之间的距离。
 *
 * 环线上的公交车都可以按顺时针和逆时针的方向行驶。
 *
 * 返回乘客从出发点 start 到目的地 destination 之间的最短距离。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：distance = [1,2,3,4], start = 0, destination = 1
 * 输出：1
 * 解释：公交站 0 和 1 之间的距离是 1 或 9，最小值是 1。
 *
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：distance = [1,2,3,4], start = 0, destination = 2
 * 输出：3
 * 解释：公交站 0 和 2 之间的距离是 3 或 7，最小值是 3。
 *
 *
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：distance = [1,2,3,4], start = 0, destination = 3
 * 输出：4
 * 解释：公交站 0 和 3 之间的距离是 6 或 4，最小值是 4。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 * distance.length == n
 * 0 <= start, destination < n
 * 0 <= distance[i] <= 10^4
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
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        int n = distance.size();

        int d1 = 0;
        for (int i = start; i != destination; i = (i + 1) % n) {
            d1 += distance[i];
        }

        int d2 = 0;
        for (int i = start; i != destination; i = (i - 1 + n) % n) {
            d2 += distance[(i - 1 + n) % n];
        }

        return min(d1, d2);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n0\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n3\n
// @lcpr case=end

 */
