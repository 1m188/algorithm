/*
 * @lc app=leetcode.cn id=LCP 60 lang=javascript
 * @lcpr version=30204
 *
 * [LCP 60] 力扣泡泡龙
 *
 * https://leetcode.cn/problems/WInSav/description/
 *
 * algorithms
 * Hard (20.73%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    1.5K
 * Total Submissions: 7.3K
 * Testcase Example:  '[6,0,3,null,8]'
 *
 * 欢迎各位勇者来到力扣城，本次试炼主题为「力扣泡泡龙」。
 *
 * 游戏初始状态的泡泡形如二叉树 `root`，每个节点值对应了该泡泡的分值。勇者最多可以击破一个节点泡泡，要求满足：
 * - 被击破的节点泡泡 **至多** 只有一个子节点泡泡
 * - 当被击破的节点泡泡有子节点泡泡时，则子节点泡泡将取代被击破泡泡的位置
 *     > 注：即整棵子树泡泡上移
 *
 * 请问在击破一个节点泡泡操作或无击破操作后，二叉泡泡树的最大「层和」是多少。
 *
 * **注意：**
 * - 「层和」为同一高度的所有节点的分值之和
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var getMaxLayerSum = function (root) {
    // ============ Phase 1: DFS to compute in/out times, depths, layer sums ============
    let inTime = 0;
    let maxDepth = 0;
    const layerSums = [];           // layerSums[d] = total sum at depth d
    const layerCounts = [];         // layerCounts[d] = number of nodes at depth d
    const depthInTimes = [];        // depthInTimes[d] = [in_time, ...]  sorted by in-time
    const depthVals = [];           // depthVals[d] = [val, ...]         aligned with depthInTimes
    const depthPrefix = [];         // depthPrefix[d][i] = prefix sum of first i vals

    /**
     * First DFS: assign in/out times and depth metadata.
     * Uses iterative approach to avoid stack overflow for deep trees.
     */
    function dfs1Preprocess(rootNode) {
        const stack = [];
        // State: 0 = entering (before children), 1 = exiting (after children)
        stack.push({ node: rootNode, depth: 0, state: 0 });

        while (stack.length > 0) {
            const frame = stack.pop();
            const { node, depth, state } = frame;

            if (state === 0) {
                // Entering node
                inTime++;
                node.in = inTime;
                node.depth = depth;
                maxDepth = Math.max(maxDepth, depth);

                // Track layer sums and counts
                while (layerSums.length <= depth) {
                    layerSums.push(0);
                    layerCounts.push(0);
                    depthInTimes.push([]);
                    depthVals.push([]);
                    depthPrefix.push([0]);
                }
                layerSums[depth] += node.val;
                layerCounts[depth] += 1;
                depthInTimes[depth].push(node.in);
                depthVals[depth].push(node.val);

                // Push exiting frame
                stack.push({ node, depth, state: 1 });

                // Push child frames (right first so left is processed first)
                if (node.right) {
                    stack.push({ node: node.right, depth: depth + 1, state: 0 });
                }
                if (node.left) {
                    stack.push({ node: node.left, depth: depth + 1, state: 0 });
                }
            } else {
                // Exiting node — record out time (max in-time in subtree)
                node.out = inTime;
            }
        }
    }
    dfs1Preprocess(root);

    // ============ Phase 2: Build sorted per-depth arrays and prefix sums ============
    let baseAnswer = -Infinity;

    for (let d = 0; d <= maxDepth; d++) {
        // Sort by in-time (they should already be in order, but sort to be safe)
        const len = depthInTimes[d].length;
        // Create indices for sorting
        const indices = Array.from({ length: len }, (_, i) => i);
        indices.sort((a, b) => depthInTimes[d][a] - depthInTimes[d][b]);

        const sortedTimes = [];
        const sortedVals = [];
        const prefix = [0];

        for (let i = 0; i < len; i++) {
            const idx = indices[i];
            sortedTimes.push(depthInTimes[d][idx]);
            sortedVals.push(depthVals[d][idx]);
            prefix.push(prefix[i] + depthVals[d][idx]);
        }

        depthInTimes[d] = sortedTimes;
        depthVals[d] = sortedVals;
        depthPrefix[d] = prefix;

        if (prefix[len] > baseAnswer) {
            baseAnswer = prefix[len];
        }
    }

    // ============ Helper functions ============

    /**
     * Find the interval [L, R] of nodes in subtree(node) at the given depth.
     * Returns [-1, -1] if the subtree has no nodes at that depth.
     * The interval is a contiguous range in the per-depth sorted array.
     */
    const findInterval = (node, depth) => {
        if (depth > maxDepth || depth < 0) return [-1, -1];
        const times = depthInTimes[depth];
        if (!times || times.length === 0) return [-1, -1];

        const inNode = node.in;
        const outNode = node.out;

        // Binary search: first index where in_time >= inNode
        let lo = 0, hi = times.length;
        while (lo < hi) {
            const mid = (lo + hi) >> 1;
            if (times[mid] >= inNode) hi = mid;
            else lo = mid + 1;
        }
        const L = lo;
        if (L >= times.length) return [-1, -1];

        // Binary search: last index where in_time <= outNode
        lo = 0; hi = times.length;
        while (lo < hi) {
            const mid = (lo + hi) >> 1;
            if (times[mid] > outNode) hi = mid;
            else lo = mid + 1;
        }
        const R = lo - 1;

        if (L > R) return [-1, -1];
        return [L, R];
    };

    /**
     * Get the sum of values at the given depth within interval [L, R] (inclusive).
     */
    const getSum = (depth, L, R) => {
        if (L > R || depth > maxDepth) return 0;
        const prefix = depthPrefix[depth];
        return prefix[R + 1] - prefix[L];
    };

    // ============ Phase 3: Process all deletable nodes with pruning ============
    let answer = baseAnswer;
    const visited = new Set();

    /**
     * Process a single deletable candidate node.
     */
    const processNode = (node) => {
        const D = node.depth;
        const left = node.left;
        const right = node.right;
        const childCount = (left ? 1 : 0) + (right ? 1 : 0);

        if (childCount > 1) return; // 无法击破有两个子节点的节点

        const child = left || right;

        if (!child) {
            // Case 1: 叶子节点 — 直接移除该节点
            // 若移除后该层无节点，则不应计入层和
            if (layerCounts[D] > 1) {
                const newSum = layerSums[D] - node.val;
                if (newSum > answer) answer = newSum;
            }
            return;
        }

        // Case 2: 只有一个子节点 — 子树上移一层
        // 先处理深度 D 的特殊情况（子树的节点不在深度 D，但会移到深度 D）
        const [L_first, R_first] = findInterval(child, D + 1);
        if (L_first !== -1) {
            const subtreeSumNext = getSum(D + 1, L_first, R_first);
            const newSum = layerSums[D] - node.val + subtreeSumNext;
            if (newSum > answer) answer = newSum;
        } else {
            const newSum = layerSums[D] - node.val;
            if (newSum > answer) answer = newSum;
        }

        // 遍历更深层，计算新的层和
        // 核心剪枝：若某层的区间已被访问过，则更深层的区间也必定相同，立即停止
        for (let k = D + 1; k <= maxDepth; k++) {
            const [L, R] = findInterval(child, k);
            if (L === -1) break; // 该深度没有子树节点，更深处也不会有

            // 剪枝：相同深度、相同区间已经处理过
            const key = k + ',' + L + ',' + R;
            if (visited.has(key)) break;
            visited.add(key);

            const subtreeSum = getSum(k, L, R);
            const intervalSize = R - L + 1;

            const [L2, R2] = findInterval(child, k + 1);
            const subtreeSumNext = L2 !== -1 ? getSum(k + 1, L2, R2) : 0;
            const intervalSizeNext = L2 !== -1 ? R2 - L2 + 1 : 0;

            // 若操作后该层没有任何节点（全部上移且没有新节点进入），跳过
            const remainingCount = (layerCounts[k] - intervalSize) + intervalSizeNext;
            if (remainingCount === 0) continue;

            const newSum = layerSums[k] - subtreeSum + subtreeSumNext;
            if (newSum > answer) answer = newSum;
        }
    };

    // 后序遍历处理所有节点
    function dfs2Iterative(rootNode) {
        const stack = [rootNode];
        const output = [];

        // Post-order: push nodes in order for processing
        while (stack.length > 0) {
            const node = stack.pop();
            output.push(node);
            if (node.left) stack.push(node.left);
            if (node.right) stack.push(node.right);
        }

        // Process in reverse pre-order = post-order
        for (let i = output.length - 1; i >= 0; i--) {
            processNode(output[i]);
        }
    }
    dfs2Iterative(root);

    return answer;
};
// @lc code=end



/*
// @lcpr case=start
// [6,0,3,null,8]
// @lcpr case=end

// @lcpr case=start
// [5,6,2,4,null,null,1,3,5]
// @lcpr case=end

// @lcpr case=start
// [-5,1,7]
// @lcpr case=end

*/
