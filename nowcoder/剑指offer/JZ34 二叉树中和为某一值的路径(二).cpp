/**
 * @file JZ34 二叉树中和为某一值的路径(二).cpp
 * @date 2022-05-10
 */

/*
描述
输入一颗二叉树的根节点root和一个整数expectNumber，找出二叉树中结点值的和为expectNumber的所有路径。
1.该题路径定义为从树的根结点开始往下一直到叶子结点所经过的结点
2.叶子节点是指没有子节点的节点
3.路径只能从父节点到子节点，不能从子节点到父节点
4.总节点数目为n

如二叉树root为{10,5,12,4,7},expectNumber为22

则合法路径有[[10,5,7],[10,12]]

数据范围:
树中节点总数在范围 [0, 5000] 内
-1000 <= 节点值 <= 1000
-1000 <= expectNumber <= 1000
示例1
输入：
{10,5,12,4,7},22

返回值：
[[10,5,7],[10,12]]

说明：
返回[[10,12],[10,5,7]]也是对的      
示例2
输入：
{10,5,12,4,7},15

返回值：
[]

示例3
输入：
{2,3},0

返回值：
[]

示例4
输入：
{1,3,4},7

返回值：
[]
*/

/* 和（一）类似，递归，注意到叶子节点后的结果push */

#include <cstddef>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
  private:
    vector<vector<int>> ans;
    int nsum = 0;

    void judge(TreeNode *root, vector<int> &vec, int sum) {

        if (!root->left && !root->right) {
            if (nsum + root->val == sum) {
                vec.push_back(root->val);
                ans.push_back(vec);
                vec.pop_back();
            }
            return;
        }

        nsum += root->val;
        vec.push_back(root->val);
        if (root->left)
            judge(root->left, vec, sum);
        if (root->right)
            judge(root->right, vec, sum);
        nsum -= root->val;
        vec.pop_back();
    }

  public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        if (!root)
            return {};

        vector<int> vec;
        judge(root, vec, expectNumber);
        return ans;
    }
};