/*
 * @lc app=leetcode.cn id=743 lang=typescript
 *
 * [743] 网络延迟时间
 *
 * https://leetcode.cn/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (54.53%)
 * Likes:    563
 * Dislikes: 0
 * Total Accepted:    84K
 * Total Submissions: 153.9K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 n 个网络节点，标记为 1 到 n。
 * 
 * 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
 * wi 是一个信号从源节点传递到目标节点的时间。
 * 
 * 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：times = [[1,2,1]], n = 2, k = 1
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：times = [[1,2,1]], n = 2, k = 2
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * 所有 (ui, vi) 对都 互不相同（即，不含重复边）
 * 
 * 
 */

/**
 * 先用bfs判断连通，再用dijkstra算法求单源最短路径，取其中的
 * 最大值，即为传播到整个网络上所需时间
 */

// @lc code=start
function networkDelayTime(times: number[][], n: number, k: number): number {

    let g: number[][] = [];
    for (let i = 0; i <= n; i++) {
        g.push([]);
        for (let j = 0; j <= n; j++) {
            g[i].push(Infinity);
            if (i == j) g[i][j] = 0;
        }
    }
    for (let [u, v, w] of times)
        g[u][v] = w;

    /**
     * bfs判断是否连通
     * @returns 
     */
    function bfs(): boolean {
        let vis: boolean[] = new Array(n + 1);
        for (let i = 1; i <= n; i++) vis[i] = false;
        let que: number[] = [k];
        vis[k] = true;

        while (que.length != 0) {
            let x = que.shift() as number;
            for (let i = 1; i <= n; i++) {
                if (!vis[i] && g[x][i] != Infinity) {
                    vis[i] = true;
                    que.push(i);
                }
            }
        }

        for (let i = 1; i <= n; i++)
            if (!vis[i]) return false;
        return true;
    }

    /**
     * dijkstra单源最短路径算法
     * @returns 起始点到其他点的最短路径
     */
    function dijkstra(): number[] {
        let set: Set<number> = new Set([k]);
        let dist: number[] = new Array(n + 1);
        dist[0] = -1;
        for (let i = 1; i <= n; i++) dist[i] = g[k][i];

        while (set.size < n) {
            let idx = 0;
            for (let i = 1; i <= n; i++)
                if (!set.has(i) && (idx == 0 || dist[i] < dist[idx]))
                    idx = i;

            set.add(idx);

            for (let i = 1; i <= n; i++)
                if (!set.has(i) && dist[i] > dist[idx] + g[idx][i])
                    dist[i] = dist[idx] + g[idx][i];
        }

        return dist;
    }

    if (!bfs()) return -1;
    return Math.max(...dijkstra());

};
// @lc code=end

