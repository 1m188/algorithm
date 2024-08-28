/*
 * @lc app=leetcode.cn id=LCP 07 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 07] 传递信息
 *
 * https://leetcode.cn/problems/chuan-di-xin-xi/description/
 *
 * algorithms
 * Easy (75.19%)
 * Likes:    285
 * Dislikes: 0
 * Total Accepted:    59.9K
 * Total Submissions: 79.6K
 * Testcase Example:  '5\n[[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]]\n3'
 *
 * 小朋友 A 在和 ta 的小伙伴们玩传信息游戏，游戏规则如下：
 *
 *
 * 有 n 名玩家，所有玩家编号分别为 0 ～ n-1，其中小朋友 A 的编号为 0
 * 每个玩家都有固定的若干个可传信息的其他玩家（也可能没有）。传信息的关系是单向的（比如 A 可以向 B 传信息，但 B 不能向 A 传信息）。
 * 每轮信息必须需要传递给另一个人，且信息可重复经过同一个人
 *
 *
 * 给定总玩家数 n，以及按 [玩家编号,对应可传递玩家编号] 关系组成的二维数组 relation。返回信息从小 A (编号 0 ) 经过 k
 * 轮传递到编号为 n-1 的小伙伴处的方案数；若不能到达，返回 0。
 *
 * 示例 1：
 *
 *
 * 输入：n = 5, relation = [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]], k = 3
 *
 * 输出：3
 *
 * 解释：信息从小 A 编号 0 处开始，经 3 轮传递，到达编号 4。共有 3 种方案，分别是 0->2->0->4， 0->2->1->4，
 * 0->2->3->4。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, relation = [[0,2],[2,1]], k = 2
 *
 * 输出：0
 *
 * 解释：信息不能从小 A 处经过 2 轮传递到编号 2
 *
 *
 * 限制：
 *
 *
 * 2 <= n <= 10
 * 1 <= k <= 5
 * 1 <= relation.length <= 90, 且 relation[i].length == 2
 * 0 <= relation[i][0],relation[i][1] < n 且 relation[i][0] != relation[i][1]
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
    int numWays(int n, vector<vector<int>> &relation, int k) {
        vector<vector<bool>> g(n, vector<bool>(n, false));
        for (const vector<int> &r : relation) {
            g[r[0]][r[1]] = true;
        }
        int res = 0;

        function<void(int, int)> func = [&](int node, int kk) {
            if (kk == k) {
                if (node == n - 1) res++;
            } else {
                for (int i = 0; i < n; i++) {
                    if (g[node][i]) {
                        func(i, kk + 1);
                    }
                }
            }
        };
        func(0, 0);

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n[[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]]\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,2],[2,1]]\n2\n
// @lcpr case=end

 */
