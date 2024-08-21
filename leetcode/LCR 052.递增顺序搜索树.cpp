/*
 * @lc app=leetcode.cn id=LCR 052 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 052] 递增顺序搜索树
 *
 * https://leetcode.cn/problems/NYBBNL/description/
 *
 * algorithms
 * Easy (73.51%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    36.8K
 * Total Submissions: 50.1K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * 给你一棵二叉搜索树，请 按中序遍历
 * 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [5,1,7]
 * 输出：[1,null,5,null,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数的取值范围是 [1, 100]
 * 0 <= Node.val <= 1000
 *
 *
 *
 *
 * 注意：本题与主站 897 题相同：
 * https://leetcode-cn.com/problems/increasing-order-search-tree/
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
    TreeNode *increasingBST(TreeNode *root) {

        vector<int> vec;
        function<void(TreeNode *)> func = [&](TreeNode *node) {
            if (!node) return;
            func(node->left);
            vec.push_back(node->val);
            func(node->right);
        };
        func(root);

        TreeNode *head = new TreeNode();
        TreeNode *cur = head;
        for (const int &i : vec) {
            cur->right = new TreeNode(i);
            cur = cur->right;
        }
        cur = head->right;
        delete head;
        return cur;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,3,6,2,4,null,8,1,null,null,null,7,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,7]\n
// @lcpr case=end

 */
