/*
描述
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

1.对于该题的最近的公共祖先定义:对于有根树T的两个节点p、q，最近公共祖先LCA(T,p,q)表示一个节点x，满足x是p和q的祖先且x的深度尽可能大。
在这里，一个节点也可以是它自己的祖先.

2.二叉搜索树是若它的左子树不空，则左子树上所有节点的值均小于它的根节点的值； 
若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值

3.所有节点的值都是唯一的。

4.p、q 为不同节点且均存在于给定的二叉搜索树中。

数据范围:
3<=节点总数<=10000
0<=节点值<=10000

如果给定以下搜索二叉树: {7,1,12,0,4,11,14,#,#,3,5}，如下图:


示例1
输入：
{7,1,12,0,4,11,14,#,#,3,5},1,12

返回值：
7

说明：
节点1 和 节点12的最近公共祖先是7   

示例2
输入：
{7,1,12,0,4,11,14,#,#,3,5},12,11

返回值：
12

说明：
因为一个节点也可以是它自己的祖先.所以输出12   
*/

/* 这里的思路是从根节点到目标节点上的路径都记录下来，之后对齐头元素从两边最长的能够触碰到的最后一个元素开始往前
找，第一个相同元素即为最近的公共祖先。

事实上，路径数组的长度就是从根节点到对应节点的深度，对齐头元素指的就是找到二者深度对齐的部位。 */

#include <algorithm>
#include <vector>
using namespace std;

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
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode *root, int p, int q) {
        // write code here

        vector<int> pv, qv;

        for (TreeNode *cur = root; cur->val != p;) {
            pv.push_back(cur->val);
            if (p > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
        pv.push_back(p);

        for (TreeNode *cur = root; cur->val != q;) {
            qv.push_back(cur->val);
            if (q > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
        qv.push_back(q);

        int idx = min(pv.size(), qv.size()) - 1;
        while (pv[idx] != qv[idx])
            idx--;

        return pv[idx];
    }
};