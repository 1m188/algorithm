/*
 * @lc app=leetcode.cn id=LCP 60 lang=typescript
 * @lcpr version=30204
 *
 * [LCP 60] 力扣泡泡龙
 *
 * https://leetcode.cn/problems/WInSav/description/
 *
 * algorithms
 * Hard (20.56%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    1.5K
 * Total Submissions: 7.4K
 * Testcase Example:  '[6,0,3,null,8]'
 *
 * 欢迎各位勇者来到力扣城，本次试炼主题为「力扣泡泡龙」。
 * 
 * 游戏初始状态的泡泡形如二叉树 `root`，每个节点值对应了该泡泡的分值。勇者最多可以击破一个节点泡泡，要求满足：
 * - 被击破的节点泡泡 **至多** 只有一个子节点泡泡
 * - 当被击破的节点泡泡有子节点泡泡时，则子节点泡泡将取代被击破泡泡的位置
 * ⁠   > 注：即整棵子树泡泡上移
 * 
 * 请问在击破一个节点泡泡操作或无击破操作后，二叉泡泡树的最大「层和」是多少。
 * 
 * **注意：**
 * - 「层和」为同一高度的所有节点的分值之和
 * 
 * **示例 1：**
 * > 输入：`root = [6,0,3,null,8]`
 * >
 * > 输出：`11`
 * >
 * > 解释：勇者的最佳方案如图所示
 * 
 * >![image.png](https://pic.leetcode.cn/1648180809-XSWPLu-image.png){:height="100px"}
 * 
 * 
 * 
 * **示例 2：**
 * > 输入：`root = [5,6,2,4,null,null,1,3,5]`
 * >
 * > 输出：`9`
 * >
 * > 解释：勇者击破 6 节点，此时「层和」最大为 3+5+1 = 9
 * 
 * >![image.png](https://pic.leetcode.cn/1648180769-TLpYop-image.png){:height="200px"}
 * 
 * 
 * 
 * **示例 3：**
 * > 输入：`root = [-5,1,7]`
 * >
 * > 输出：`8`
 * >
 * > 解释：勇者不击破节点，「层和」最大为 1+7 = 8
 * 
 * 
 * **提示**：
 * - `2 <= 树中节点个数 <= 10^5`
 * - `-10000 <= 树中节点的值 <= 10000`
 * 
 */


// @lcpr-template-start
class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

/**
 * 力扣泡泡龙 解法说明
 * ====================
 *
 * 【整体思路】
 * 选择击破一个「至多只有一个子节点」的节点，使其子节点的整棵子树上移一层，
 * 求操作后最大可能的「层和」（同一深度所有节点的分值之和）。
 *
 * 算法分为三步：
 * 1. 迭代后序遍历，构建每层节点信息（前缀和 + 下一层后代区间），收集候选节点
 * 2. 计算不操作时的原始最大层和
 * 3. 枚举每个候选节点，逐层模拟子树上移：new[层] = 原总和 - 被击破部分 + 下层移入部分
 *
 * 【子树移位原理】
 * 对于候选节点 v（深度 d，唯一子节点 c），子树 c 上移一层后：
 *   new[d]   = original[d]   - v.val          + c及其后代在d+1的贡献
 *   new[d+1] = original[d+1] - 子树c在d+1部分  + 子树c在d+2部分
 *   new[d+i] = original[d+i] - 子树c在d+i部分  + 子树c在d+i+1部分
 * 即：每层的新和 = 该层总和 - 被移出的部分 + 从下面移入的部分
 *
 * 【数据结构】
 * levelInfos[层][i]：第 i 个节点（i=0 为哨兵，preSum=0）
 *   - preSum：该层前缀和，差值法快速求区间和
 *   - left/right：下一层中该节点后代在层数组中的起始/结束位置
 *   - finishId：剪枝标记，避免重复模拟相同子树的移位
 *
 * 【复杂度】O(n)：每个 (层, 区间) 通过 finishId 去重至多处理一次
 *
 * 【注意点】
 * - n≤10⁵，必须用迭代后序遍历，递归会栈溢出
 * - 哨兵节点（下标0）消除前缀和计算的边界判断
 * - 操作后某层若无任何节点，不计入最大层和比较
 */
function getMaxLayerSum(root: TreeNode | null): number {
    if (root === null) return 0;

    interface LevelInfo {
        preSum: number;
        left: number;
        right: number;
        finishId: number;
    }

    interface Job {
        nodeId: number;
        level: number;
    }

    // 步骤1 —— 迭代后序遍历，构建每层节点信息
    const levelInfos: LevelInfo[][] = [];
    const jobs: Job[] = [];

    interface Frame {
        node: TreeNode;
        level: number;
        visited: boolean;
    }

    const stack: Frame[] = [{ node: root, level: 0, visited: false }];
    const hasLeftStack: boolean[] = [];
    const hasRightStack: boolean[] = [];

    while (stack.length > 0) {
        const top = stack[stack.length - 1];
        const { node, level } = top;

        if (!top.visited) {
            // 确保 levelInfos 存在当前层和下一层（均含下标 0 的哨兵）
            while (levelInfos.length <= level) {
                levelInfos.push([{ preSum: 0, left: -1, right: -1, finishId: -1 }]);
            }
            while (levelInfos.length <= level + 1) {
                levelInfos.push([{ preSum: 0, left: -1, right: -1, finishId: -1 }]);
            }

            const curList = levelInfos[level];
            const prevPreSum = curList[curList.length - 1].preSum;
            const nextLevelSize = levelInfos[level + 1].length;

            curList.push({
                preSum: prevPreSum + node.val,
                left: nextLevelSize,
                right: -1,
                finishId: -1,
            });

            top.visited = true;
            const hasLeft = node.left !== null;
            const hasRight = node.right !== null;
            hasLeftStack.push(hasLeft);
            hasRightStack.push(hasRight);

            // 右子节点先入栈，左子节点后入栈，保证左子树先遍历
            if (hasRight) {
                stack.push({ node: node.right!, level: level + 1, visited: false });
            }
            if (hasLeft) {
                stack.push({ node: node.left!, level: level + 1, visited: false });
            }
        } else {
            const nodeId = levelInfos[level].length - 1;
            const hasLeft = hasLeftStack.pop()!;
            const hasRight = hasRightStack.pop()!;

            if (!hasLeft || !hasRight) {
                jobs.push({ nodeId, level });
            }

            levelInfos[level][nodeId].right = levelInfos[level + 1].length - 1;
            stack.pop();
        }
    }

    // 步骤2 —— 原始最大层和
    const height = levelInfos.length;
    let ans = -Infinity;

    for (let lev = 0; lev < height; lev++) {
        const list = levelInfos[lev];
        if (list.length > 1) {
            ans = Math.max(ans, list[list.length - 1].preSum);
        }
    }

    // 步骤3 —— 枚举候选节点，逐层模拟子树上移
    for (let jobIdx = 0; jobIdx < jobs.length; jobIdx++) {
        const { nodeId, level } = jobs[jobIdx];

        let left = nodeId;
        let right = nodeId;
        let curLevel = level;
        let curLevelSum =
            levelInfos[level][left].preSum - levelInfos[level][left - 1].preSum;

        while (curLevel < height) {
            if (left > right) break;

            const curList = levelInfos[curLevel];
            const leftInfo = curList[left];
            const rightInfo = curList[right];
            const nextLeft = leftInfo.left;
            const nextRight = rightInfo.right;
            const curLevelAll = curList[curList.length - 1].preSum;

            let nextLevelSum = 0;
            if (nextLeft <= nextRight && curLevel + 1 < height) {
                const nextList = levelInfos[curLevel + 1];
                nextLevelSum =
                    nextList[nextRight].preSum - nextList[nextLeft - 1].preSum;
            }

            const levelEmpty = curLevelAll === curLevelSum && nextLevelSum === 0;
            if (!levelEmpty) {
                ans = Math.max(ans, curLevelAll - curLevelSum + nextLevelSum);
            }

            // 剪枝1：子树覆盖整层，后续只是整层原样上移，无需继续
            if (right - left + 1 === curList.length - 1) {
                break;
            }

            // 剪枝2：相同区间已由之前的 job 处理过
            if (
                leftInfo.finishId !== -1 &&
                leftInfo.finishId === rightInfo.finishId
            ) {
                break;
            }
            leftInfo.finishId = jobIdx;
            rightInfo.finishId = jobIdx;

            left = nextLeft;
            right = nextRight;
            curLevelSum = nextLevelSum;
            curLevel++;
        }
    }

    return ans;
}
// @lc code=end



/*
// @lcpr case=start
// [6,0,3,null,8]`>\n
// @lcpr case=end

// @lcpr case=start
// [5,6,2,4,null,null,1,3,5]`>\n
// @lcpr case=end

// @lcpr case=start
// [-5,1,7]`>\n
// @lcpr case=end

 */

