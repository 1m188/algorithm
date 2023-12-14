/*

描述
已知两颗二叉树，将它们合并成一颗二叉树。合并规则是：都存在的结点，就将结点值加起来，否则空的位置就由另一个树的结点来代替。例如：
两颗二叉树是:
                                                                    Tree 1


                                                                        Tree 2

                                                                    合并后的树为

数据范围：树上节点数量满足
0
≤
�
≤
500
0≤n≤500，树上节点的值一定在32位整型范围内。
进阶：空间复杂度
�
(
1
)
O(1) ，时间复杂度
�
(
�
)
O(n)
示例1
输入：
{1,3,2,5},{2,1,3,#,4,#,7}
复制
返回值：
{3,4,5,5,4,#,7}
复制
说明：
如题面图
示例2
输入：
{1},{}
复制
返回值：
{1}

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
     * @param t1 TreeNode类
     * @param t2 TreeNode类
     * @return TreeNode类
     */
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        // write code here

        if (!t1) return t2;
        if (!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};