/*
描述
操作给定的二叉树，将其变换为源二叉树的镜像。
数据范围：二叉树的节点数 0≤n≤1000 ， 二叉树每个节点的值 0≤val≤1000
要求： 空间复杂度 O(n) 。本题也有原地操作，即空间复杂度 O(1) 的解法，时间复杂度 O(n)

比如：
源二叉树

镜像二叉树

示例1
输入：
{8,6,10,5,7,9,11}

返回值：
{8,10,6,11,9,7,5}

说明：
如题面所示    

示例2
输入：
{}

返回值：
{}
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode *Mirror(TreeNode *pRoot) {
        // write code here

        if (!pRoot)
            return nullptr;

        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};