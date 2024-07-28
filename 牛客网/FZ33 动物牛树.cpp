/*
描述
在动物牛国度的森林中，有一种特殊的树叫做动物牛树。农场主想要判断一棵树是否为动物牛树，动物牛树的定义如下：

如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵动物牛树。

请你实现一个函数 bool isBalanced(TreeNode* root)，用于判断给定的二叉树是否为动物牛树。

示例1
输入：
{1,2,3,#,#,4,5}
复制
返回值：
true
复制
示例2
输入：
{1,2,3}
复制
返回值：
true
复制
示例3
输入：
{1,#,2,#,3,#,4}
复制
返回值：
false
复制
备注：
0 <= 树的结点个数 <= 20000
*/

#include <cmath>
#include <functional>

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
     * @return bool布尔型
     */
    bool isBalanced(TreeNode *root) {
        // write code here

        function<int(TreeNode *)> func = [&](TreeNode *root) -> int {
            if (!root) return 0;
            int left = func(root->left);
            if (left == -1) return -1;
            int right = func(root->right);
            if (right == -1) return -1;
            if (abs(left - right) > 1) return -1;
            return max(left, right) + 1;
        };

        return func(root) == -1 ? false : true;
    }
};