/*
 * @lc app=leetcode.cn id=LCP 60 lang=cpp
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
#include <algorithm>
#include <climits>
#include <cstddef>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int getMaxLayerSum(TreeNode *root) {
        levelInfos_.clear();
        jobs_.clear();

        // 步骤 1：迭代后序遍历构建每层的前缀和数组与子节点范围信息
        process_(root);

        int height = static_cast<int>(levelInfos_.size());
        // 步骤 2：不击破任何节点时的最大层和（仅考虑非空层）
        int ans = INT_MIN;
        for (int level = 0; level < height; ++level) {
            const auto &levelList = levelInfos_[level];
            // size() > 1 说明该层存在实际节点（下标 0 为哨兵）
            if (levelList.size() > 1) {
                ans = std::max(ans, levelList.back().preSum);
            }
        }

        // 步骤 3：逐一遍历所有候选节点（至多一个子节点）
        for (int jobId = 0; jobId < static_cast<int>(jobs_.size()); ++jobId) {
            const auto &job = jobs_[jobId];
            int nodeId = job.nodeId;
            int level = job.level;

            // 当前被击破子树在当前层的范围 [left, right]
            int left = nodeId;
            int right = nodeId;
            // 被击破子树在当前层的节点值之和
            int curLevelSum = levelInfos_[level][left].preSum - levelInfos_[level][left - 1].preSum;

            while (level < height) {
                // 子树范围为空则终止
                if (left > right) break;

                auto &levelList = levelInfos_[level];

                Info &leftInfo = levelList[left];
                Info &rightInfo = levelList[right];
                int nextLeft = leftInfo.left;
                int nextRight = rightInfo.right;

                // 当前层总和
                int curLevelAll = levelList.back().preSum;

                // 被击破子树在下一层的节点值之和
                int nextLevelSum = 0;
                if (nextLeft <= nextRight && level + 1 < height) {
                    nextLevelSum = levelInfos_[level + 1][nextRight].preSum - levelInfos_[level + 1][nextLeft - 1].preSum;
                }

                // 击破后当前层的新层和 = 层总和 - 被击破部分 + 上移部分
                // 注意：若整层原有节点全部移出且无新节点移入，则该层为空层，不应纳入考虑
                bool levelEmpty = (curLevelAll == curLevelSum && nextLevelSum == 0);
                if (!levelEmpty) {
                    ans = std::max(ans, curLevelAll - curLevelSum + nextLevelSum);
                }

                // 若子树覆盖整层，后续变化均为原始层和，提前终止
                if (right - left + 1 == static_cast<int>(levelList.size()) - 1) {
                    break;
                }

                // 之前相同范围已处理过则跳过（优化：避免重复计算同一子树移位效果）
                if (leftInfo.finshId != -1 && leftInfo.finshId == rightInfo.finshId) {
                    break;
                }
                leftInfo.finshId = jobId;
                rightInfo.finshId = jobId;

                // 向下传递范围和当前层的被击破子树贡献
                left = nextLeft;
                right = nextRight;
                curLevelSum = nextLevelSum;
                ++level;
            }
        }

        return ans;
    }

private:
    /** 每层每个节点的元信息 */
    struct Info {
        int preSum;  // 当前层前缀和（包含本节点）
        int left;    // 下一层中最左后代的位置索引
        int right;   // 下一层中最右后代的位置索引
        int finshId; // 去重优化标记，-1 表示未访问过
    };

    /** 候选任务：一个可被击破的节点 */
    struct Job {
        int nodeId; // 节点在其所在层的位置索引
        int level;  // 节点所在的层号
    };

    /** levelInfos_[层级][位置]：每个层级中所有节点的前缀和信息 */
    std::vector<std::vector<Info>> levelInfos_;
    /** jobs_：所有可选作击破目标的节点（至多一个子节点） */
    std::vector<Job> jobs_;

    /**
     * 迭代式后序遍历二叉树，构建每层的节点信息数组
     * 使用手动维护的栈避免深层递归导致的调用栈溢出
     * @param root 根节点
     */
    void process_(TreeNode *root) {
        if (root == nullptr) return;

        // 栈帧：节点、层号、是否为回访阶段
        struct Frame {
            TreeNode *node;
            int level;
            bool visited; // false=首次访问需创建 entry，true=子节点已处理完毕
        };
        std::vector<Frame> stack;
        stack.push_back({root, 0, false});

        // 记录每个节点是否拥有左/右子节点，用于判断候选资格
        std::vector<bool> hasLeftStack;
        std::vector<bool> hasRightStack;

        while (!stack.empty()) {
            Frame &top = stack.back();
            TreeNode *cur = top.node;
            int level = top.level;

            if (!top.visited) {
                // ---- 首次访问：创建层信息条目 ----
                // 确保 levelInfos_ 容纳到 level+1 层
                while (level >= static_cast<int>(levelInfos_.size())) {
                    levelInfos_.push_back({{0, -1, -1, -1}});
                }
                while (level + 1 >= static_cast<int>(levelInfos_.size())) {
                    levelInfos_.push_back({{0, -1, -1, -1}});
                }

                int preId = static_cast<int>(levelInfos_[level].size()) - 1;
                int nextLevelCurSize =
                    static_cast<int>(levelInfos_[level + 1].size());
                levelInfos_[level].push_back(
                    {levelInfos_[level][preId].preSum + cur->val,
                     nextLevelCurSize, -1, -1});

                // 标记为回访阶段，之后处理子节点
                top.visited = true;
                bool hasLeft = (cur->left != nullptr);
                bool hasRight = (cur->right != nullptr);
                hasLeftStack.push_back(hasLeft);
                hasRightStack.push_back(hasRight);

                // 先压入右子节点，再压入左子节点（保证左子树先处理）
                if (hasRight) {
                    stack.push_back({cur->right, level + 1, false});
                }
                if (hasLeft) {
                    stack.push_back({cur->left, level + 1, false});
                }
            } else {
                // ---- 回访阶段：子节点全部处理完毕 ----
                int nodeId = static_cast<int>(levelInfos_[level].size()) - 1;
                bool hasLeft = hasLeftStack.back();
                hasLeftStack.pop_back();
                bool hasRight = hasRightStack.back();
                hasRightStack.pop_back();

                // 至多有一个子节点时成为候选击破目标
                if (!hasLeft || !hasRight) {
                    jobs_.push_back({nodeId, level});
                }

                // 更新 right 指针：处理完子节点后下一层的最后一个位置
                levelInfos_[level][nodeId].right =
                    static_cast<int>(levelInfos_[level + 1].size()) - 1;

                stack.pop_back();
            }
        }
    }
};
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
