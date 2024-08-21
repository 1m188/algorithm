/*
 * @lc app=leetcode.cn id=LCR 056 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 056] 两数之和 IV - 输入二叉搜索树
 *
 * https://leetcode.cn/problems/opLdQZ/description/
 *
 * algorithms
 * Easy (73.63%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    36.6K
 * Total Submissions: 49.8K
 * Testcase Example:  '[8,6,10,5,7,9,11]\n12'
 *
 * 给定一个二叉搜索树的 根节点 root 和一个整数 k , 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 k
 * 。假设二叉搜索树中节点的值均唯一。
 *
 *
 *
 * 示例 1：
 *
 * 输入: root = [8,6,10,5,7,9,11], k = 12
 * 输出: true
 * 解释: 节点 5 和节点 7 之和等于 12
 *
 *
 * 示例 2：
 *
 * 输入: root = [8,6,10,5,7,9,11], k = 22
 * 输出: false
 * 解释: 不存在两个节点值之和为 22 的节点
 *
 *
 *
 *
 * 提示：
 *
 *
 * 二叉树的节点个数的范围是  [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root 为二叉搜索树
 * -10^5 <= k <= 10^5
 *
 *
 *
 *
 * 注意：本题与主站 653 题相同：
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTarget(TreeNode *root, int k) {

        vector<int> vec;
        function<void(TreeNode *)> func = [&](TreeNode *node) {
            if (!node) return;
            func(node->left);
            vec.push_back(node->val);
            func(node->right);
        };
        func(root);

        bool res = false;
        for (int i = 0; i < vec.size(); i++) {
            bool f = false;
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[i] + vec[j] > k) break;
                if (vec[i] + vec[j] == k) {
                    res = true;
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [8,6,10,5,7,9,11]\n12\n
// @lcpr case=end

// @lcpr case=start
// [8,6,10,5,7,9,11]\n22\n
// @lcpr case=end

 */
