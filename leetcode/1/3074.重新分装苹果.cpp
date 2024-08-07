/*
 * @lc app=leetcode.cn id=3074 lang=cpp
 *
 * [3074] 重新分装苹果
 *
 * https://leetcode.cn/problems/apple-redistribution-into-boxes/description/
 *
 * algorithms
 * Easy (74.34%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    7.9K
 * Total Submissions: 10.7K
 * Testcase Example:  '[1,3,2]\n[4,3,1,5,2]'
 *
 * 给你一个长度为 n 的数组 apple 和另一个长度为 m 的数组 capacity 。
 *
 * 一共有 n 个包裹，其中第 i 个包裹中装着 apple[i] 个苹果。同时，还有 m 个箱子，第 i 个箱子的容量为 capacity[i]
 * 个苹果。
 *
 * 请你选择一些箱子来将这 n 个包裹中的苹果重新分装到箱子中，返回你需要选择的箱子的 最小 数量。
 *
 * 注意，同一个包裹中的苹果可以分装到不同的箱子中。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：apple = [1,3,2], capacity = [4,3,1,5,2]
 * 输出：2
 * 解释：使用容量为 4 和 5 的箱子。
 * 总容量大于或等于苹果的总数，所以可以完成重新分装。
 *
 *
 * 示例 2：
 *
 *
 * 输入：apple = [5,5,5], capacity = [2,4,2,7]
 * 输出：4
 * 解释：需要使用所有箱子。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n == apple.length <= 50
 * 1 <= m == capacity.length <= 50
 * 1 <= apple[i], capacity[i] <= 50
 * 输入数据保证可以将包裹中的苹果重新分装到箱子中。
 *
 *
 */

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity) {

        int apple_sum = std::accumulate(apple.begin(), apple.end(), 0);
        std::sort(capacity.begin(), capacity.end(), [&](const int &a, const int &b) {
            return a > b;
        });

        int sum = 0;
        int cnt = 0;
        for (const int &e : capacity) {
            sum += e;
            cnt++;
            if (sum >= apple_sum) return cnt;
        }
        return cnt;
    }
};
// @lc code=end
