/**
 * @file JZ37 序列化二叉树.cpp
 * @date 2022-05-10
 */

/*
描述
请实现两个函数，分别用来序列化和反序列化二叉树，不对序列化之后的字符串进行约束，
但要求能够根据序列化之后的字符串重新构造出一棵与原二叉树相同的树。

二叉树的序列化(Serialize)是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
从而使得内存中建立起来的二叉树可以持久保存。
序列化可以基于先序、中序、后序、层序的二叉树等遍历方式来进行修改，
序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#）

二叉树的反序列化(Deserialize)是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

例如，可以根据层序遍历的方案序列化，如下图:

层序序列化(即用函数Serialize转化)如上的二叉树转为"{1,2,3,#,#,6,7}"，
再能够调用反序列化(Deserialize)将"{1,2,3,#,#,6,7}"构造成如上的二叉树。

当然你也可以根据满二叉树结点位置的标号规律来序列化，还可以根据先序遍历和中序遍历的结果来序列化。
不对序列化之后的字符串进行约束，所以欢迎各种奇思妙想。

数据范围：节点数 n≤100，树上每个节点的值满足 0≤val≤150
要求：序列化和反序列化都是空间复杂度 O(n)，时间复杂度 O(n)
示例1
输入：
{1,2,3,#,#,6,7}

返回值：
{1,2,3,#,#,6,7}

说明：
如题面图    
示例2
输入：
{8,6,10,5,7,9,11}

返回值：
{8,6,10,5,7,9,11}
*/

/* 这里采用的方法是用先序遍历和中序遍历复现整棵树 */

#include <algorithm>
#include <cstddef>
#include <sstream>
#include <string>
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
    string serstr;        // 序列化后的字符串序列
    vector<int> preorder, // 先序遍历
        inorder;          // 中序遍历

    /**
     * @brief Get the preorder object 递归获取先序遍历序列
     * @param root 树根节点指针
     */
    void get_preorder(TreeNode *root) {
        if (root) {
            preorder.push_back(root->val);
            get_preorder(root->left);
            get_preorder(root->right);
        }
    }

    /**
     * @brief Get the inorder object 递归获取中序遍历序列
     * @param root 数根节点指针
     */
    void get_inorder(TreeNode *root) {
        if (root) {
            get_inorder(root->left);
            inorder.push_back(root->val);
            get_inorder(root->right);
        }
    }

    /**
     * @brief 数字转字符串
     * @param num 待转化的数字
     * @return string 转化结果字符串
     */
    string num2str(int num) {
        string s;
        while (num) {
            s.push_back(num % 10 + '0');
            num /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    /**
     * @brief 遍历序列数组序列化为字符串
     * @param vec 待序列化数组
     * @return string 序列化字符串
     */
    string vec2str(const vector<int> &vec) {
        string ans;
        for (const int &i : vec) {
            ans.append(num2str(i));
            ans.push_back(' '); // 两个数字之间用空格隔开
        }
        if (!ans.empty())
            ans.pop_back(); // 最后一个空格消掉
        return ans;
    }

    /**
     * @brief 先序中序遍历序列化为字符串
     */
    void prein2str() {
        // 两个序列中间用回车隔开
        serstr = vec2str(preorder) + '\n' + vec2str(inorder);
    }

    /**
     * @brief 序列化字符串反序列化为先序中序遍历
     */
    void str2prein() {
        stringstream ss(serstr); // 这里用的是stringstream来做空格和回车的分割工作

        string t;
        getline(ss, t);

        stringstream tss(t);

        int a = 0;
        while (tss >> a) {
            preorder.push_back(a);
        }

        getline(ss, t);
        tss = stringstream(t);
        while (tss >> a) {
            inorder.push_back(a);
        }
    }

    /**
     * @brief 通过先序遍历和中序遍历序列递归重构树
     * @param pl 先序遍历当前子树左索引
     * @param pr 先序遍历当前子树右索引
     * @param il 中序遍历当前子树左索引
     * @param ir 中序遍历当前子树右索引
     * @return TreeNode* 最终的数根节点
     */
    TreeNode *prein2tree(int pl, int pr, int il, int ir) {
        if (pr < pl)
            return nullptr;
        else if (pr == pl)
            return new TreeNode(preorder[pl]);

        int rootval = preorder[pl];
        TreeNode *root = new TreeNode(rootval);

        int idx = il;
        while (idx <= ir && inorder[idx] != rootval)
            idx++;
        int llen = idx - il, rlen = ir - idx;
        root->left = prein2tree(pl + 1, pl + llen, il, idx - 1);
        root->right = prein2tree(pl + llen + 1, pl + llen + rlen, idx + 1, ir);
        return root;
    }

  public:
    char *Serialize(TreeNode *root) {
        get_preorder(root);
        get_inorder(root);
        prein2str();
        preorder.clear();
        inorder.clear();

        char *s = new char[serstr.size() + 1]{'\0'};
        for (int i = 0; i < serstr.size(); i++) {
            s[i] = serstr[i];
        }
        return s;
    }
    TreeNode *Deserialize(char *str) {
        serstr = string(str);
        str2prein();
        return prein2tree(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};