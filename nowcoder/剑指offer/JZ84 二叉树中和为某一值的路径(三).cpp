/**
 * @file JZ84 二叉树中和为某一值的路径(三).cpp
 * @date 2022-05-11
 */

/*
描述
给定一个二叉树root和一个整数值 sum ，求该树有多少路径的的节点值之和等于 sum 。
1.该题路径定义不需要从根节点开始，也不需要在叶子节点结束，但是一定是从父亲节点往下到孩子节点
2.总节点数目为n
3.保证最后返回的路径个数在整形范围内(即路径个数小于231-1)

数据范围:
0<=n<=1000
-10^9<=节点值<=10^9
 

假如二叉树root为{1,2,3,4,5,4,3,#,#,-1}，sum=6，那么总共如下所示，有3条路径符合要求

示例1
输入：
{1,2,3,4,5,4,3,#,#,-1},6

返回值：
3

说明：
如图所示，有3条路径符合      
示例2
输入：
{0,1},1

返回值：
2

示例3
输入：
{1,#,2,#,3},3

返回值：
2
*/

/* 双重递归，第一个递归找当前子树根节点，第二个递归从当前根节点到叶子节点计算
路径数目 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  private:
    int nsum = 0;
    int ans = 0;

    /**
     * @brief 递归计算从当前根节点到叶子节点有多少条符合要求的路径
     * @param root 当前子树根节点
     * @param sum 符合要求的和
     */
    void judge(TreeNode *root, int sum) {
        nsum += root->val;

        if (nsum == sum)
            ans++;

        if (root->left)
            judge(root->left, sum);
        if (root->right)
            judge(root->right, sum);

        nsum -= root->val;
    }

    /**
     * @brief 递归先序遍历对每个节点进行判断
     * @param root 整棵树的根节点
     * @param sum 符合要求的和
     */
    void preorder(TreeNode *root, int sum) {
        if (root) {
            judge(root, sum);
            preorder(root->left, sum);
            preorder(root->right, sum);
        }
    }

  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型
     */
    int FindPath(TreeNode *root, int sum) {
        // write code here

        if (!root) // 空树
            return 0;

        preorder(root, sum);
        return ans;
    }
};