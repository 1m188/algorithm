/**
 * @file JZ54 二叉搜索树的第k个节点.cpp
 * @date 2022-05-10
 */

/*
描述
给定一棵结点数为n 二叉搜索树，请找出其中的第 k 小的TreeNode结点值。
1.返回第k小的节点值即可
2.不能查找的情况，如二叉树为空，则返回-1，或者k大于n等等，也返回-1
3.保证n个节点的值不一样


数据范围： 0≤n≤1000，0≤k≤1000，树上每个结点的值满足0≤val≤1000
进阶：空间复杂度 O(n)，时间复杂度 O(n)


如输入{5,3,7,2,4,6,8},3时，二叉树{5,3,7,2,4,6,8}如下图所示：

该二叉树所有节点按结点值升序排列后可得[2,3,4,5,6,7,8]，所以第3个结点的结点值为4，
故返回对应结点值为4的结点即可。

示例1
输入：
{5,3,7,2,4,6,8},3

返回值：
4

示例2
输入：
{},1

返回值：
-1

备注：
当树是空
*/

/* 递归+计数 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  private:
    int count = 0;

  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int KthNode(TreeNode *proot, int k) {
        // write code here

        if (!proot) // 空节点情况
            return -1;

        int x = KthNode(proot->left, k); // 左边是否找到？
        if (x != -1)
            return x;
        count++;        // 当前节点计数
        if (count == k) // 当前是否找到？
            return proot->val;
        return KthNode(proot->right, k); // 否则只能从右边找
    }
};