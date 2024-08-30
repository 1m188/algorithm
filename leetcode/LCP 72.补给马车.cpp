/*
 * @lc app=leetcode.cn id=LCP 72 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 72] 补给马车
 *
 * https://leetcode.cn/problems/hqCnmP/description/
 *
 * algorithms
 * Easy (67.80%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 7.2K
 * Testcase Example:  '[7,3,6,1,8]'
 *
 * 远征队即将开启未知的冒险之旅，不过在此之前，将对补给车队进行最后的检查。`supplies[i]` 表示编号为 `i` 的补给马车装载的物资数量。
 * 考虑到车队过长容易被野兽偷袭，他们决定将车队的长度变为原来的一半（向下取整），计划为：
 * - 找出车队中 **物资之和最小** 两辆 **相邻**
 * 马车，将它们车辆的物资整合为一辆。若存在多组物资之和相同的马车，则取编号最小的两辆马车进行整合；
 * - 重复上述操作直到车队长度符合要求。
 *
 * 请返回车队长度符合要求后，物资的分布情况。
 *
 * **示例 1：**
 * >输入：`supplies = [7,3,6,1,8]`
 * >
 * >输出：`[10,15]`
 * >
 * >解释：
 * > 第 1 次合并，符合条件的两辆马车为 6,1，合并后的车队为 [7,3,7,8]；
 * > 第 2 次合并，符合条件的两辆马车为 (7,3) 和 (3,7)，取编号最小的 (7,3)，合并后的车队为 [10,7,8]；
 * > 第 3 次合并，符合条件的两辆马车为 7,8，合并后的车队为 [10,15]；
 * >返回 `[10,15]`
 *
 * **示例 2：**
 * >输入：`supplies = [1,3,1,5]`
 * >
 * >输出：`[5,5]`
 *
 * **解释：**
 * - `2 <= supplies.length <= 1000`
 * - `1 <= supplies[i] <= 1000`
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
    vector<int> supplyWagon(vector<int> &supplies) {
        int n = supplies.size();
        while (supplies.size() > n / 2) {
            int val = 5000, idx = -1;
            for (int i = 0; i < supplies.size() - 1; i++) {
                int v = supplies[i] + supplies[i + 1];
                if (v < val) {
                    val = v;
                    idx = i;
                }
            }
            supplies[idx] += supplies[idx + 1];
            supplies.erase(supplies.begin() + idx + 1);
        }
        return supplies;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,3,6,1,8]`>\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1,5]`>\n
// @lcpr case=end

 */
