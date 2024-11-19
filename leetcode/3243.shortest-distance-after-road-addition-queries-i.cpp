/*
 * @lc app=leetcode.cn id=3243 lang=cpp
 * @lcpr version=30204
 *
 * [3243] 新增道路查询后的最短距离 I
 *
 * https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i/description/
 *
 * algorithms
 * Medium (41.25%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 19.4K
 * Testcase Example:  '5\n[[2,4],[0,2],[0,4]]'
 *
 * 给你一个整数 n 和一个二维整数数组 queries。
 *
 * 有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。
 *
 * queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1
 * 的最短路径的长度。
 *
 * 返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1
 * 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： n = 5, queries = [[2, 4], [0, 2], [0, 4]]
 *
 * 输出： [3, 2, 1]
 *
 * 解释：
 *
 *
 *
 * 新增一条从 2 到 4 的道路后，从 0 到 4 的最短路径长度为 3。
 *
 *
 *
 * 新增一条从 0 到 2 的道路后，从 0 到 4 的最短路径长度为 2。
 *
 *
 *
 * 新增一条从 0 到 4 的道路后，从 0 到 4 的最短路径长度为 1。
 *
 *
 * 示例 2：
 *
 *
 * 输入： n = 4, queries = [[0, 3], [0, 2]]
 *
 * 输出： [1, 1]
 *
 * 解释：
 *
 *
 *
 * 新增一条从 0 到 3 的道路后，从 0 到 3 的最短路径长度为 1。
 *
 *
 *
 * 新增一条从 0 到 2 的道路后，从 0 到 3 的最短路径长度仍为 1。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= n <= 500
 * 1 <= queries.length <= 500
 * queries[i].length == 2
 * 0 <= queries[i][0] < queries[i][1] < n
 * 1 < queries[i][1] - queries[i][0]
 * 查询中没有重复的道路。
 *
 *
 */
#include <queue>
#include <vector>

using namespace std;

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> g(n); // 用邻接表而非邻接矩阵，邻接矩阵会超时
        for (int i = 0; i < n - 1; i++) {
            g[i].push_back(i + 1);
        }
        auto bfs = [&]() -> int {
            queue<int> que;
            que.push(0);
            vector<bool> flags(n);
            flags[0] = true;
            int res = 0;
            while (!que.empty()) {
                res++;
                bool f = false;
                queue<int> que1;
                while (!que.empty()) {
                    int x = que.front();
                    que.pop();
                    if (x == n - 1) {
                        f = true;
                        break;
                    }
                    for (int y : g[x]) {
                        if (!flags[y]) {
                            flags[y] = true;
                            que1.push(y);
                        }
                    }
                }
                if (!f) {
                    que = que1;
                } else {
                    res--;
                    break;
                }
            }
            return res;
        };

        vector<int> res;
        for (const vector<int> &query : queries) {
            int u = query[0], v = query[1];
            g[u].push_back(v);
            res.push_back(bfs());
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n[[2, 4], [0, 2], [0, 4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0, 3], [0, 2]]\n
// @lcpr case=end

 */
