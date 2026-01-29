/**
 * @file JZ32 从上往下打印二叉树.cpp
 * @date 2022-05-10
 */

/*
描述
不分行从上往下打印出二叉树的每个节点，同层节点从左至右打印。
例如输入{8,6,10,#,#,2,1}，如以下图中的示例二叉树，
则依次打印8,6,10,2,1(空节点不打印，跳过)，请你将打印的结果存放到一个数组里面，返回。

数据范围:
0<=节点总数<=1000
-1000<=节点值<=1000
示例1
输入：
{8,6,10,#,#,2,1}

返回值：
[8,6,10,2,1]

示例2
输入：
{5,4,#,3,#,2,#,1}

返回值：
[5,4,3,2,1]
*/

/* 层序遍历 */

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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        if (!root)
            return {};

        vector<int> ans;
        queue<TreeNode *> que({root});
        while (!que.empty()) {
            TreeNode *t = que.front();
            que.pop();
            ans.push_back(t->val);
            if (t->left)
                que.push(t->left);
            if (t->right)
                que.push(t->right);
        }

        return ans;
    }
};