/*
描述
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

数据范围：二叉树的节点数量满足
1
≤
�
≤
100

1≤n≤100  ，二叉树节点的值满足
1
≤
�
�
�
≤
100

1≤val≤100  ，树的各节点的值各不相同
示例 1：


示例1
输入：
{1,#,2,3}
复制
返回值：
[1,2,3]
*/

#include <functional>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write code here

        vector<int> res;

        function<void(TreeNode *)> prefunc = [&](TreeNode *root) {
            if (!root) return;
            res.push_back(root->val);
            prefunc(root->left);
            prefunc(root->right);
        };
        prefunc(root);

        return std::move(res);
    }
};