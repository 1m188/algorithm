/*

描述
给定一棵二叉树，返回齐自底向上的层序遍历。

数据范围：二叉树上节点数满足
1
≤
�
≤
1000

1≤n≤1000  ，二叉树上的值满足
∣
�
�
�
∣
≤
1
0
9

∣val∣≤10
9


样例图：

示例1
输入：
{1,2,3,4,#,5,6}
复制
返回值：
[[4,5,6],[2,3],[1]]
复制
说明：
如题面图示
示例2
输入：
{1,2}
复制
返回值：
[[2],[1]]

*/

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write code here

        auto res = vector<vector<TreeNode *>>();

        auto vec = vector<TreeNode *>{root};
        while (!vec.empty()) {
            res.insert(res.begin(), vec);
            auto vec_new = vector<TreeNode *>();
            for (const auto &node : vec) {
                if (node->left) vec_new.push_back(node->left);
                if (node->right) vec_new.push_back(node->right);
            }
            vec = vec_new;
        }

        auto ret = vector<vector<int>>();
        for (const auto &vec : res) {
            ret.push_back(vector<int>());
            for (const auto &node : vec) {
                ret.back().push_back(node->val);
            }
        }
        return ret;
    }
};