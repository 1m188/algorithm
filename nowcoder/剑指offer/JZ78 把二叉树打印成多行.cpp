/**
 * @file JZ78 把二叉树打印成多行.cpp
 * @date 2022-05-10
 */

/*
描述
给定一个节点数为 n 二叉树，要求从上到下按层打印二叉树的 val 值，同一层结点从左至右输出，
每一层输出一行，将输出的结果存放到一个二维数组中返回。
例如：
给定的二叉树是{1,2,3,#,#,4,5}

该二叉树多行打印层序遍历的结果是
[
[1],
[2,3],
[4,5]
]

数据范围：二叉树的节点数 0≤n≤1000，0≤val≤1000
要求：空间复杂度 O(n)，时间复杂度 O(n)
输入描述：
给定一个二叉树的根节点
示例1
输入：
{1,2,3,#,#,4,5}

返回值：
[[1],[2,3],[4,5]]

示例2
输入：
{8,6,10,5,7,9,11}

返回值：
[[8],[6,10],[5,7,9,11]]

示例3
输入：
{1,2,3,4,5}

返回值：
[[1],[2,3],[4,5]]

示例4
输入：
{}

返回值：
[]
*/

/* 层序遍历的变体，注意对每一层层序遍历的处理 */

#include <cstddef>
#include <queue>
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
  public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        if (!pRoot)
            return {};

        vector<vector<int>> ans;

        queue<TreeNode *> que({pRoot});
        while (!que.empty()) {
            vector<int> layer;
            int size = que.size();
            while (size--) { // 对这一层的所有内容加入layer
                TreeNode *p = que.front();
                que.pop();
                layer.push_back(p->val);
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
            ans.push_back(layer);
        }

        return ans;
    }
};