/*
描述
给定一棵二叉搜索树的根节点和一个插入值 val。请你把这个 val 插入二叉搜索树中并保持这棵树依然是二叉搜索树。你可以返回任意一个合法结果。

例如：输入二叉树，插入一个 4 ，可能的结果有，等等，返回任意一个即可。

数据范围：二叉搜索树节点数满足
1
≤
n
≤
1
0
5

1≤n≤10
5
   ，二叉搜索树上节点值满足
1
≤
v
a
l
≤
1
0
9

1≤val≤10
9

示例1
输入：
{2,1,3},4
复制
返回值：
{2,1,3,#,#,#,4}
*/

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
     * @param val int整型
     * @return TreeNode类
     */
    TreeNode *insertToBST(TreeNode *root, int val) {
        // write code here
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insertToBST(root->left, val);
        if (val > root->val) root->right = insertToBST(root->right, val);
        return root;
    }
};