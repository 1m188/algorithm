/**
 * @file JZ82 二叉树中和为某一值的路径(一).cpp
 * @date 2022-05-10
 */

/*
描述
给定一个二叉树root和一个值 sum ，判断是否有从根节点到叶子节点的节点值之和等于 sum 的路径。
1.该题路径定义为从树的根结点开始往下一直到叶子结点所经过的结点
2.叶子节点是指没有子节点的节点
3.路径只能从父节点到子节点，不能从子节点到父节点
4.总节点数目为n

例如：
给出如下的二叉树， sum=22，

返回true，因为存在一条路径  5→4→11→2的节点值之和为 22

数据范围：
1.树上的节点数满足 0≤n≤10000
2.每 个节点的值都满足 ∣val∣≤1000
要求：空间复杂度 O(n)，时间复杂度 O(n)
进阶：空间复杂度 O(树的高度)，时间复杂度 O(n)
示例1
输入：
{5,4,8,1,11,#,9,#,#,2,7},22

返回值：
true

示例2
输入：
{1,2},0

返回值：
false

示例3
输入：
{1,2},3

返回值：
true

示例4
输入：
{},0

返回值：
false
*/

/* 递归计算，注意根节点的判断和空树的判断 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
  private:
    int nsum = 0; // 递归时候用到的当前路径和

  public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode *root, int sum) {
        // write code here

        if (!root) // 空树
            return false;

        if (!root->left && !root->right) // 当前是叶子节点
            return nsum + root->val == sum;

        nsum += root->val;                             // 将当前节点作为路径的一部分加入
        if (root->left && hasPathSum(root->left, sum)) // 左边判定
            return true;
        if (root->right && hasPathSum(root->right, sum)) // 右边判定
            return true;
        nsum -= root->val;

        return false; // 都失败了，返回false
    }
};