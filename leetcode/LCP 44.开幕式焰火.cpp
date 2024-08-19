/*
 * @lc app=leetcode.cn id=LCP 44 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 44] 开幕式焰火
 *
 * https://leetcode.cn/problems/sZ59z6/description/
 *
 * algorithms
 * Easy (78.51%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 23.4K
 * Testcase Example:  '[1,3,2,1,null,2]'
 *
 * 「力扣挑战赛」开幕式开始了，空中绽放了一颗二叉树形的巨型焰火。
 * 给定一棵二叉树 `root` 代表焰火，节点值表示巨型焰火这一位置的颜色种类。请帮小扣计算巨型焰火有多少种不同的颜色。
 *
 *
 * **示例 1：**
 * >输入：`root = [1,3,2,1,null,2]`
 * >
 * >输出：`3`
 * >
 * >解释：焰火中有 3 个不同的颜色，值分别为 1、2、3
 *
 * **示例 2：**
 * >输入：`root = [3,3,3]`
 * >
 * >输出：`1`
 * >
 * >解释：焰火中仅出现 1 个颜色，值为 3
 *
 * **提示：**
 * - `1 <= 节点个数 <= 1000`
 * - `1 <= Node.val <= 1000`
 *
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
    int numColor(TreeNode *root) {

        unordered_set<int> uset;
        function<void(TreeNode *)> func = [&](TreeNode *node) {
            if (!node) return;
            uset.insert(node->val);
            func(node->left);
            func(node->right);
        };
        func(root);
        return uset.size();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,2,1,null,2]`>\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3]`>\n
// @lcpr case=end

 */
