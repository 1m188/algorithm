/*
 * @lc app=leetcode.cn id=LCR 150 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 150] 彩灯装饰记录 II
 *
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/description/
 *
 * algorithms
 * Easy (68.74%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    297.1K
 * Total Submissions: 432.2K
 * Testcase Example:  '[8,17,21,18,null,null,6]'
 *
 * 一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从左到右的顺序返回每一层彩灯编号，每一层的结果记录于一行。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [8,17,21,18,null,null,6]
 * 输出：[[8],[17,21],[18,6]]
 *
 *
 * 提示：
 *
 *
 * 节点总数 <= 1000
 *
 *
 * 注意：本题与主站 102
 * 题相同：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> decorateRecord(TreeNode *root) {
        if (!root) return {};

        vector<vector<int>> res;

        vector<TreeNode *> vec{root};
        while (!vec.empty()) {
            vector<int> x;
            for (TreeNode *node : vec) {
                x.push_back(node->val);
            }
            res.push_back(x);

            vector<TreeNode *> vec1;
            for (TreeNode *node : vec) {
                if (node->left) vec1.push_back(node->left);
                if (node->right) vec1.push_back(node->right);
            }
            vec = vec1;
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [8,17,21,18,null,null,6]\n
// @lcpr case=end

 */
