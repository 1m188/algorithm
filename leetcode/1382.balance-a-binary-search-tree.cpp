/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 * @lcpr version=30204
 *
 * [1382] 将二叉搜索树变平衡
 *
 * https://leetcode.cn/problems/balance-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (74.49%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 41.4K
 * Testcase Example:  '[1,null,2,null,3,null,4]'
 *
 * 给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。
 *
 * 如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [1,null,2,null,3,null,4,null,null]
 * 输出：[2,1,3,null,null,null,4]
 * 解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入: root = [2,1,3]
 * 输出: [2,1,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树节点的数目在 [1, 10^4] 范围内。
 * 1 <= Node.val <= 10^5
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
    TreeNode *balanceBST(TreeNode *root) {

        vector<int> vec;
        function<void(TreeNode *)> func = [&](TreeNode *node) {
            if (!node) return;
            func(node->left);
            vec.push_back(node->val);
            func(node->right);
        };
        func(root);

        function<TreeNode *(int, int)> fun = [&](int left, int right) -> TreeNode * {
            if (left > right) return nullptr;
            if (left == right) return new TreeNode(vec[left]);
            int mid = (left + right) / 2;
            TreeNode *root = new TreeNode(vec[mid]);
            root->left = fun(left, mid - 1);
            root->right = fun(mid + 1, right);
            return root;
        };
        return fun(0, vec.size() - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,null,3,null,4,null,null]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

 */
