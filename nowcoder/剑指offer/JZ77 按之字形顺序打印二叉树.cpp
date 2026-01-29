/**
 * @file JZ77 按之字形顺序打印二叉树.cpp
 * @date 2022-05-10
 */

/*
描述
给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）

数据范围：0≤n≤1500,树上每个节点的val满足 ∣val∣<=1500
要求：空间复杂度：O(n)，时间复杂度：O(n)
例如：
给定的二叉树是{1,2,3,#,#,4,5}

该二叉树之字形层序遍历的结果是
[
[1],
[3,2],
[4,5]
]
示例1
输入：
{1,2,3,#,#,4,5}

返回值：
[[1],[3,2],[4,5]]

说明：
如题面解释，第一层是根节点，从左到右打印结果，第二层从右到左，第三层从左到右。     
示例2
输入：
{8,6,10,5,7,9,11}

返回值：
[[8],[10,6],[5,7,9,11]]

示例3
输入：
{1,2,3,4,5}

返回值：
[[1],[3,2],[4,5]]
*/

/* 难倒不难，就是挺麻烦的，在层序遍历的基础上进行修改，注意左右反序遍历时候的设计 */

#include <algorithm>
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
  public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        if (!pRoot)
            return {};

        vector<vector<int>> ans;

        bool flag = true;
        vector<TreeNode *> que(1, pRoot);
        while (!que.empty()) {

            vector<int> vt;
            if (flag) {
                for (int i = 0; i < que.size(); i++)
                    vt.push_back(que[i]->val);
            } else {
                for (int i = que.size() - 1; i >= 0; i--)
                    vt.push_back(que[i]->val);
            }
            ans.push_back(vt);
            flag = !flag;

            vector<TreeNode *> qt;
            while (!que.empty()) {
                TreeNode *p = que.front();
                que.erase(que.begin());
                if (p->left)
                    qt.push_back(p->left);
                if (p->right)
                    qt.push_back(p->right);
            }
            que.swap(qt);
        }

        return ans;
    }
};