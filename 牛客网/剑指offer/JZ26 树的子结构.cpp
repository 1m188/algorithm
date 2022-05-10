/**
 * @file JZ26 树的子结构.cpp
 * @date 2022-05-10
 */

/*
描述
输入两棵二叉树A，B，判断B是不是A的子结构。（我们约定空树不是任意一个树的子结构）
假如给定A为{8,8,7,9,2,#,#,#,#,4,7}，B为{8,9,2}，2个树的结构如下，可以看出B是A的子结构


数据范围:
0 <= A的节点个数 <= 10000
0 <= B的节点个数 <= 10000
示例1
输入：
{8,8,7,9,2,#,#,#,#,4,7},{8,9,2}

返回值：
true

示例2
输入：
{1,2,3,4,5},{2,4}

返回值：
true

示例3
输入：
{1,2,3},{3,1}

返回值：
false
*/

/* 一次递归找到两树相同的根节点，第二次递归判断当前根节点以下是否匹配 */

#include <cstddef>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
  private:
    /**
     * @brief 递归判断一棵树是否在另一棵树里面
     * @param p1 树1
     * @param p2 树2（是否在树1里面）
     * @return true 是
     * @return false 否
     */
    bool judge(TreeNode *p1, TreeNode *p2) {
        if (!p2) // 树2没有了，到了树2的边界，之前的都匹配完了
            return true;
        else if (!p1) // 树1没有而树2还有，false
            return false;
        else if (p1->val != p2->val) // 两树当前节点不相等，false
            return false;

        // 递归判断两树的左右子树
        return judge(p1->left, p2->left) && judge(p1->right, p2->right);
    }

    /**
     * @brief 在树1中寻找树2根节点的值，从而开始匹配，返回最终所有的匹配结果判定树2是否是树1的子结构
     * @param p1 树1
     * @param p2 树2
     * @return true 是
     * @return false 否
     */
    bool find(TreeNode *p1, TreeNode *p2) {
        if (p1) {
            bool f = p1->val == p2->val ? judge(p1, p2) : false;   // 判断当前两树是否存在子结构关系
            return f || find(p1->left, p2) || find(p1->right, p2); // 当前，左子树，右子树，只要有一个满足字结构关系即可
        }
        return false; // 当前树1为空，则树2无论如何也不可能是树1的子结构
    }

  public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (!pRoot2) // 空树不是任何树的子结构
            return false;

        return find(pRoot1, pRoot2);
    }
};